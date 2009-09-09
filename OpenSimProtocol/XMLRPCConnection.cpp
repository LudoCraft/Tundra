// For conditions of distribution and use, see copyright notice in license.txt

#include "XMLRPCException.h"
#include "XMLRPCConnection.h"
#include "curl/curl.h"
#include "Poco/URI.h"
#include "boost/lexical_cast.hpp"
#include <vector>
#include <iostream>


namespace
{
/// The writer callback function used by cURL.
size_t WriteCallback(char *data, size_t size, size_t nmemb, std::vector<char> *buffer)  
{  
	if (buffer)
	{
		buffer->insert(buffer->end(), data, data + size * nmemb);
		return size * nmemb;
	}
	else
        return 0;
}
}

XMLRPCConnection::XMLRPCConnection(const std::string& address, const std::string& port)
{
    SetServerAddress(address, port);
}

void XMLRPCConnection::SetServerAddress(const std::string& address, const std::string& port) 
{ 
    std::string address_copy = address;
    if (address_copy.find("://") == std::string::npos)
        address_copy = "http://" + address_copy;
        
    Poco::URI uri = Poco::URI(address_copy);
    uri.setPort( boost::lexical_cast<int>(port) );
    
    strUrl_ = uri.toString();
}

XMLRPC_REQUEST XMLRPCConnection::Send(const char* data)
{
    curl_global_init(CURL_GLOBAL_ALL);

    CURL *pCurl = curl_easy_init();
	if (pCurl == 0)
        throw XMLRPCException(std::string("XMLRPCEPI exception in XMLRPCConnection::Send()() error: Curl object was zero pointer"));

	CURLcode result;
    char curl_error_buffer[CURL_ERROR_SIZE];
    curl_slist *headers = 0;
    std::vector<char> response_data;
    const unsigned int cTimeout = 5;
	const char *url = strUrl_.c_str(); 

	headers = curl_slist_append(headers, "Accept-Encoding: deflate, gzip");
	headers = curl_slist_append(headers, "Content-Type: text/xml");
	headers = curl_slist_append(headers, "Expect: 100-continue");
	headers = curl_slist_append(headers, "");

    curl_easy_setopt(pCurl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(pCurl, CURLOPT_URL, url);
	curl_easy_setopt(pCurl, CURLOPT_POSTFIELDS, &data[0]);
	curl_easy_setopt(pCurl, CURLOPT_POSTFIELDSIZE, strlen(data));
	curl_easy_setopt(pCurl, CURLOPT_POST, 1);
	curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(pCurl, CURLOPT_WRITEDATA, &response_data);
	curl_easy_setopt(pCurl, CURLOPT_ERRORBUFFER, curl_error_buffer);
    curl_easy_setopt(pCurl, CURLOPT_CONNECTTIMEOUT, cTimeout);
    
    result = curl_easy_perform(pCurl);
	
	// Clean up and free memory.
	curl_easy_cleanup(pCurl);
	curl_slist_free_all(headers);

	if (result != CURLE_OK)
        throw XMLRPCException(std::string("XMLRPCEPI exception in XMLRPCConnection::Send() Curl error: ")+ std::string(curl_error_buffer));		

    if (response_data.size() == 0)
        throw XMLRPCException(std::string("XMLRPCEPI exception in XMLRPCConnection::Send() response data size was zero: "));			
	
    // Convert the XML string to a XMLRPC reply structure.
    return XMLRPC_REQUEST_FromXML(&response_data[0], (int)(response_data.size()), 0);
}

// For conditions of distribution and use, see copyright notice in license.txt
#ifndef incl_OpenSimProtocolModule_XMLRPCConnection_h
#define incl_OpenSimProtocolModule_XMLRPCConnection_h

#include <xmlrpc.h>

/**
 * Represents a XMLRPC connection. You can do multiple XMLRPC requests/replies using the same connection.
 * @note use class throught XMLRPCEPI-class. 
 */
class XMLRPCConnection
{
public:
	
    /** 
     * Overrided constructor which creates url where xml-data is send. 
     * @param address is server address.
     * @param port is server port.
     */
    XMLRPCConnection(const std::string& address, const std::string& port);
	
    /**
     * Sets server address. 
     * @param address is server address. 
     * @param port is server port.
     */
    void SetServerAddress(const std::string& address, const std::string& port);

    void SetServer(const std::string& address) { strUrl_ = address; }
	
	/**
     * Sends the XMLRPC request data (pure xml) over to the server.
     * @param data is pure xml which is constructed in @p XMLRPCCall -class
     * @return request object.
     * @throw XMLRPCException is send failed for some reason.
     **/
	XMLRPC_REQUEST Send(const char* data);  

private:
    std::string strUrl_;
};

#endif

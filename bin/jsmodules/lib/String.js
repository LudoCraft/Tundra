/** For conditions of distribution and use, see copyright notice in LICENSE

    String.js - String utility functions. */

function ParseBool(str)
{
    str = str.trim().toLowerCase();
    return (str == "true" || str == "yes" || str == "1" || str == "y" || str == "on") ? true : false;
}

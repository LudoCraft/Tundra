// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#if defined (_WINDOWS)
#if defined(LIBROCKETPLUGIN_EXPORTS) 
#define LIBROCKETPLUGIN_API __declspec(dllexport)
#else
#define LIBROCKETPLUGIN_API __declspec(dllimport) 
#endif
#else
#define LIBROCKETPLUGIN_API
#endif


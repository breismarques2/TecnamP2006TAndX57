// Main configuration file for the libIGES project
#ifndef LIBIGESCONF_H
#define LIBIGESCONF_H

// Version
#define LIB_VERSION_MAJOR (0)
#define LIB_VERSION_MINOR (3)

// indicates if IGES is being built as a static lib
#define STATIC_IGES

#if defined( _MSC_VER )
    #if defined(_DLL)
        #define MCAD_API __declspec( dllexport )
    #else  // DLL import
        #define MCAD_API __declspec( dllimport )
    #endif
#else  // not an MSVC compiler
    #define MCAD_API
#endif  // defined( _MSC_VER )

// SISL
/* #undef USE_SISL */
/* #undef HAS_NURBS_LIB */

#endif  // LIBIGESCONF_H

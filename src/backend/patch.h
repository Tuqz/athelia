#ifndef PATCH_H_INCLUDED
#define PATCH_H_INCLUDED

#include <iostream>
#include <sstream>

/*!
    * \brief    This file provides patches for the Windows systems that use Mingw as their build system.
    * \author   Jacob843
    * \version  0.0.1a
*/

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

#endif // PATCH_H_INCLUDED

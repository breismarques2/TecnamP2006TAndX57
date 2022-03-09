//
// This file is released under the terms of the NASA Open Source Agreement (NOSA)
// version 1.3 as detailed in the LICENSE file which accompanies this software.
//

// main.h: version info
//
//////////////////////////////////////////////////////////////////////

#ifndef main_h
#define main_h

#define VSP_VERSION_MAJOR 3
#define VSP_VERSION_MINOR 21
#define VSP_VERSION_CHANGE 2
#define VSPVERSION1 "Vehicle Sketch Pad 3.21.2"
#define VSPVERSION2 "OpenVSP 3.21.2 - 11/03/20"
#define VSPVERSION3 "OpenVSP 3.21.2 : Vehicle Sketch Pad"
#define VSPVERSION4 "OpenVSP 3.21.2"

enum
{
    ESTATUS_NO_ERRORS = 0,
    ESTATUS_GENERAL_ERROR = 1,
    ESTATUS_INVALID_FILE_ERROR = 2
}; // Exit status error codes that can be bit masked together if multiple errors


int vsp_add_and_get_estatus( int ecode );
void vsp_exit();

#endif

#ifndef  ENTITY_SDAIFOUNDED_ITEM_CC
#define  ENTITY_SDAIFOUNDED_ITEM_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiFounded_item.h"

EntityDescriptor * config_control_design::e_founded_item = 0;

SdaiFounded_item::SdaiFounded_item() {
        /*  no SuperTypes */

    eDesc = config_control_design::e_founded_item;
}

SdaiFounded_item::SdaiFounded_item ( SdaiFounded_item & e ) : SDAI_Application_instance() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiFounded_item::~SdaiFounded_item() {
}

SdaiFounded_item::SdaiFounded_item( SDAI_Application_instance * se, bool addAttrs ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
    ( void ) addAttrs; /* quell potentially unused var */

        /*  no SuperTypes */

    eDesc = config_control_design::e_founded_item;
}


void init_SdaiFounded_item( Registry& reg ) {
    std::string str;

        reg.AddEntity( *config_control_design::e_founded_item );
}

#endif

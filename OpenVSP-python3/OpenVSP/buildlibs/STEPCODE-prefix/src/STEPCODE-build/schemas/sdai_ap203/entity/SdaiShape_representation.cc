#ifndef  ENTITY_SDAISHAPE_REPRESENTATION_CC
#define  ENTITY_SDAISHAPE_REPRESENTATION_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiShape_representation.h"

EntityDescriptor * config_control_design::e_shape_representation = 0;

SdaiShape_representation::SdaiShape_representation(): SdaiRepresentation() {
        /*  parent: SdaiRepresentation  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_shape_representation;
}

SdaiShape_representation::SdaiShape_representation ( SdaiShape_representation & e ) : SdaiRepresentation() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiShape_representation::~SdaiShape_representation() {
}

SdaiShape_representation::SdaiShape_representation( SDAI_Application_instance * se, bool addAttrs ) : SdaiRepresentation( se, addAttrs ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiRepresentation */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_shape_representation;
}


void init_SdaiShape_representation( Registry& reg ) {
    std::string str;

    config_control_design::e_shape_representation->AddSupertype(config_control_design::e_representation);
    config_control_design::e_representation->AddSubtype(config_control_design::e_shape_representation);
        reg.AddEntity( *config_control_design::e_shape_representation );
}

#endif

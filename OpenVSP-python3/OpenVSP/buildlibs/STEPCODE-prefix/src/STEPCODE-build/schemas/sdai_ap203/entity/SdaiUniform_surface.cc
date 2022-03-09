#ifndef  ENTITY_SDAIUNIFORM_SURFACE_CC
#define  ENTITY_SDAIUNIFORM_SURFACE_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiUniform_surface.h"

EntityDescriptor * config_control_design::e_uniform_surface = 0;

SdaiUniform_surface::SdaiUniform_surface(): SdaiB_spline_surface() {
        /*  parent: SdaiB_spline_surface  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_uniform_surface;
    MakeDerived( "dim", "geometric_representation_item" );
    MakeDerived( "u_upper", "b_spline_surface" );
    MakeDerived( "v_upper", "b_spline_surface" );
    MakeDerived( "control_points", "b_spline_surface" );
}

SdaiUniform_surface::SdaiUniform_surface ( SdaiUniform_surface & e ) : SdaiB_spline_surface() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiUniform_surface::~SdaiUniform_surface() {
}

SdaiUniform_surface::SdaiUniform_surface( SDAI_Application_instance * se, bool addAttrs ) : SdaiB_spline_surface( se, addAttrs ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiB_spline_surface */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_uniform_surface;
    MakeDerived( "dim", "geometric_representation_item" );
    MakeDerived( "u_upper", "b_spline_surface" );
    MakeDerived( "v_upper", "b_spline_surface" );
    MakeDerived( "control_points", "b_spline_surface" );
}


void init_SdaiUniform_surface( Registry& reg ) {
    std::string str;

    config_control_design::e_uniform_surface->AddSupertype(config_control_design::e_b_spline_surface);
    config_control_design::e_b_spline_surface->AddSubtype(config_control_design::e_uniform_surface);
        reg.AddEntity( *config_control_design::e_uniform_surface );
}

#endif

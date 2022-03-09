#ifndef  ENTITY_SDAIBEZIER_CURVE_CC
#define  ENTITY_SDAIBEZIER_CURVE_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiBezier_curve.h"

EntityDescriptor * config_control_design::e_bezier_curve = 0;

SdaiBezier_curve::SdaiBezier_curve(): SdaiB_spline_curve() {
        /*  parent: SdaiB_spline_curve  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_bezier_curve;
    MakeDerived( "dim", "geometric_representation_item" );
    MakeDerived( "upper_index_on_control_points", "b_spline_curve" );
    MakeDerived( "control_points", "b_spline_curve" );
}

SdaiBezier_curve::SdaiBezier_curve ( SdaiBezier_curve & e ) : SdaiB_spline_curve() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiBezier_curve::~SdaiBezier_curve() {
}

SdaiBezier_curve::SdaiBezier_curve( SDAI_Application_instance * se, bool addAttrs ) : SdaiB_spline_curve( se, addAttrs ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiB_spline_curve */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_bezier_curve;
    MakeDerived( "dim", "geometric_representation_item" );
    MakeDerived( "upper_index_on_control_points", "b_spline_curve" );
    MakeDerived( "control_points", "b_spline_curve" );
}


void init_SdaiBezier_curve( Registry& reg ) {
    std::string str;

    config_control_design::e_bezier_curve->AddSupertype(config_control_design::e_b_spline_curve);
    config_control_design::e_b_spline_curve->AddSubtype(config_control_design::e_bezier_curve);
        reg.AddEntity( *config_control_design::e_bezier_curve );
}

#endif
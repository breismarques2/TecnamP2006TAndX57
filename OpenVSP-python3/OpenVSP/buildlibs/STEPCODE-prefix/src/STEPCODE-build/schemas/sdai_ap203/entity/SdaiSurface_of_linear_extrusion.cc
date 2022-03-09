#ifndef  ENTITY_SDAISURFACE_OF_LINEAR_EXTRUSION_CC
#define  ENTITY_SDAISURFACE_OF_LINEAR_EXTRUSION_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiSurface_of_linear_extrusion.h"

EntityDescriptor * config_control_design::e_surface_of_linear_extrusion = 0;
AttrDescriptor * config_control_design::a_408extrusion_axis = 0;

SdaiSurface_of_linear_extrusion::SdaiSurface_of_linear_extrusion(): SdaiSwept_surface(), _extrusion_axis( 0 ) {
        /*  parent: SdaiSwept_surface  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_surface_of_linear_extrusion;
    STEPattribute * a = new STEPattribute( * config_control_design::a_408extrusion_axis, ( SDAI_Application_instance_ptr * ) & _extrusion_axis );
    a->set_null();
    attributes.push( a );
    MakeDerived( "dim", "geometric_representation_item" );
}

SdaiSurface_of_linear_extrusion::SdaiSurface_of_linear_extrusion ( SdaiSurface_of_linear_extrusion & e ) : SdaiSwept_surface() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiSurface_of_linear_extrusion::~SdaiSurface_of_linear_extrusion() {
}

SdaiSurface_of_linear_extrusion::SdaiSurface_of_linear_extrusion( SDAI_Application_instance * se, bool addAttrs ) : SdaiSwept_surface( se, addAttrs ), _extrusion_axis( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiSwept_surface */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_surface_of_linear_extrusion;
    STEPattribute * a = new STEPattribute( * config_control_design::a_408extrusion_axis, ( SDAI_Application_instance_ptr * ) &_extrusion_axis );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    MakeDerived( "dim", "geometric_representation_item" );
}


SdaiVector_ptr SdaiSurface_of_linear_extrusion::extrusion_axis_() {
    if( !_extrusion_axis ) {
        _extrusion_axis = new SdaiVector;
    }
    return (SdaiVector_ptr) _extrusion_axis;
}

SdaiVector_ptr_c SdaiSurface_of_linear_extrusion::extrusion_axis_() const {
    return (SdaiVector_ptr) _extrusion_axis;
}

void SdaiSurface_of_linear_extrusion::extrusion_axis_( const SdaiVector_ptr x ) {
    _extrusion_axis = x;
}

void init_SdaiSurface_of_linear_extrusion( Registry& reg ) {
    std::string str;

    config_control_design::e_surface_of_linear_extrusion->AddSupertype(config_control_design::e_swept_surface);
    config_control_design::e_swept_surface->AddSubtype(config_control_design::e_surface_of_linear_extrusion);
    config_control_design::a_408extrusion_axis =
      new AttrDescriptor( "extrusion_axis", config_control_design::e_vector, LFalse,
       LFalse, AttrType_Explicit, *config_control_design::e_surface_of_linear_extrusion);
        config_control_design::e_surface_of_linear_extrusion->AddExplicitAttr (config_control_design::a_408extrusion_axis);
        reg.AddEntity( *config_control_design::e_surface_of_linear_extrusion );
}

#endif
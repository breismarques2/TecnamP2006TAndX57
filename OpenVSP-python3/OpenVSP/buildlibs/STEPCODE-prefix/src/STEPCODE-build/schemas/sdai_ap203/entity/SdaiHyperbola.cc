#ifndef  ENTITY_SDAIHYPERBOLA_CC
#define  ENTITY_SDAIHYPERBOLA_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiHyperbola.h"

EntityDescriptor * config_control_design::e_hyperbola = 0;
AttrDescriptor * config_control_design::a_172semi_axis = 0;
AttrDescriptor * config_control_design::a_173semi_imag_axis = 0;

SdaiHyperbola::SdaiHyperbola(): SdaiConic() {
        /*  parent: SdaiConic  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_hyperbola;
    STEPattribute * a = new STEPattribute( * config_control_design::a_172semi_axis, & _semi_axis );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_173semi_imag_axis, & _semi_imag_axis );
    a->set_null();
    attributes.push( a );
    MakeDerived( "dim", "geometric_representation_item" );
}

SdaiHyperbola::SdaiHyperbola ( SdaiHyperbola & e ) : SdaiConic() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiHyperbola::~SdaiHyperbola() {
}

SdaiHyperbola::SdaiHyperbola( SDAI_Application_instance * se, bool addAttrs ) : SdaiConic( se, addAttrs ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiConic */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_hyperbola;
    STEPattribute * a = new STEPattribute( * config_control_design::a_172semi_axis,  &_semi_axis );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_173semi_imag_axis,  &_semi_imag_axis );
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


SdaiPositive_length_measure SdaiHyperbola::semi_axis_() const {
    return (SdaiPositive_length_measure) _semi_axis;
}

void SdaiHyperbola::semi_axis_( const SdaiPositive_length_measure x ) {
    _semi_axis = x;
}

SdaiPositive_length_measure SdaiHyperbola::semi_imag_axis_() const {
    return (SdaiPositive_length_measure) _semi_imag_axis;
}

void SdaiHyperbola::semi_imag_axis_( const SdaiPositive_length_measure x ) {
    _semi_imag_axis = x;
}

void init_SdaiHyperbola( Registry& reg ) {
    std::string str;

    config_control_design::e_hyperbola->AddSupertype(config_control_design::e_conic);
    config_control_design::e_conic->AddSubtype(config_control_design::e_hyperbola);
        config_control_design::a_172semi_axis =
          new AttrDescriptor("semi_axis",config_control_design::t_positive_length_measure,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_hyperbola);
        config_control_design::e_hyperbola->AddExplicitAttr (config_control_design::a_172semi_axis);
        config_control_design::a_173semi_imag_axis =
          new AttrDescriptor("semi_imag_axis",config_control_design::t_positive_length_measure,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_hyperbola);
        config_control_design::e_hyperbola->AddExplicitAttr (config_control_design::a_173semi_imag_axis);
        reg.AddEntity( *config_control_design::e_hyperbola );
}

#endif
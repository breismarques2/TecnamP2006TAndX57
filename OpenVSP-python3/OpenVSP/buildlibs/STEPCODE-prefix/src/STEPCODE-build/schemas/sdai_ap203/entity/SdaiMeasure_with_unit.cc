#ifndef  ENTITY_SDAIMEASURE_WITH_UNIT_CC
#define  ENTITY_SDAIMEASURE_WITH_UNIT_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiMeasure_with_unit.h"

EntityDescriptor * config_control_design::e_measure_with_unit = 0;
AttrDescriptor * config_control_design::a_128value_component = 0;
AttrDescriptor * config_control_design::a_129unit_component = 0;

SdaiMeasure_with_unit::SdaiMeasure_with_unit() {
        /*  no SuperTypes */

    eDesc = config_control_design::e_measure_with_unit;
    STEPattribute * a = new STEPattribute( * config_control_design::a_128value_component, & _value_component );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_129unit_component, & _unit_component );
    a->set_null();
    attributes.push( a );
}

SdaiMeasure_with_unit::SdaiMeasure_with_unit ( SdaiMeasure_with_unit & e ) : SDAI_Application_instance() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiMeasure_with_unit::~SdaiMeasure_with_unit() {
}

SdaiMeasure_with_unit::SdaiMeasure_with_unit( SDAI_Application_instance * se, bool addAttrs ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
    ( void ) addAttrs; /* quell potentially unused var */

        /*  no SuperTypes */

    eDesc = config_control_design::e_measure_with_unit;
    STEPattribute * a = new STEPattribute( * config_control_design::a_128value_component,  &_value_component );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_129unit_component,  &_unit_component );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
}


SdaiMeasure_value_ptr SdaiMeasure_with_unit::value_component_()  {
    return &_value_component;
}

SdaiMeasure_value_ptr_c SdaiMeasure_with_unit::value_component_() const {
    return (const SdaiMeasure_value_ptr) &_value_component;
}

void SdaiMeasure_with_unit::value_component_( const SdaiMeasure_value_ptr x )  {
    _value_component = x;
}

SdaiUnit_ptr SdaiMeasure_with_unit::unit_component_()  {
    return &_unit_component;
}

SdaiUnit_ptr_c SdaiMeasure_with_unit::unit_component_() const {
    return (const SdaiUnit_ptr) &_unit_component;
}

void SdaiMeasure_with_unit::unit_component_( const SdaiUnit_ptr x )  {
    _unit_component = x;
}

void init_SdaiMeasure_with_unit( Registry& reg ) {
    std::string str;

    config_control_design::e_measure_with_unit->_where_rules = new Where_rule__list;
        Where_rule * wr;
        str.clear();
        str.append( "wr1: (" );
    str.append( "valid_units( SELF )\n" );
        str.append( ");\n" );
        wr = new Where_rule( str.c_str() );
        config_control_design::e_measure_with_unit->_where_rules->Append( wr );
    str.clear();
    str.append( "SUPERTYPE OF ( " );
    str.append( "ONEOF ( length_measure_with_unit, mass_measure_with_unit, plane_angle_measure_with_unit, solid_angle_measure_with_unit, \n" );
    str.append( "          area_measure_with_unit, volume_measure_with_unit )\n" );
    str.append( ")" );
    config_control_design::e_measure_with_unit->AddSupertype_Stmt( str );
        config_control_design::a_128value_component =
          new AttrDescriptor("value_component",config_control_design::t_measure_value,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_measure_with_unit);
        config_control_design::e_measure_with_unit->AddExplicitAttr (config_control_design::a_128value_component);
        config_control_design::a_129unit_component =
          new AttrDescriptor("unit_component",config_control_design::t_unit,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_measure_with_unit);
        config_control_design::e_measure_with_unit->AddExplicitAttr (config_control_design::a_129unit_component);
        reg.AddEntity( *config_control_design::e_measure_with_unit );
}

#endif
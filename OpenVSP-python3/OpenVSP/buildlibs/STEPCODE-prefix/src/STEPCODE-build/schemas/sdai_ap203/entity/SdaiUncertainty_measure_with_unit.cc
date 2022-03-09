#ifndef  ENTITY_SDAIUNCERTAINTY_MEASURE_WITH_UNIT_CC
#define  ENTITY_SDAIUNCERTAINTY_MEASURE_WITH_UNIT_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiUncertainty_measure_with_unit.h"

EntityDescriptor * config_control_design::e_uncertainty_measure_with_unit = 0;
AttrDescriptor * config_control_design::a_341name = 0;
AttrDescriptor * config_control_design::a_342description = 0;

SdaiUncertainty_measure_with_unit::SdaiUncertainty_measure_with_unit(): SdaiMeasure_with_unit() {
        /*  parent: SdaiMeasure_with_unit  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_uncertainty_measure_with_unit;
    STEPattribute * a = new STEPattribute( * config_control_design::a_341name, & _name );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_342description, & _description );
    a->set_null();
    attributes.push( a );
}

SdaiUncertainty_measure_with_unit::SdaiUncertainty_measure_with_unit ( SdaiUncertainty_measure_with_unit & e ) : SdaiMeasure_with_unit() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiUncertainty_measure_with_unit::~SdaiUncertainty_measure_with_unit() {
}

SdaiUncertainty_measure_with_unit::SdaiUncertainty_measure_with_unit( SDAI_Application_instance * se, bool addAttrs ) : SdaiMeasure_with_unit( se, addAttrs ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiMeasure_with_unit */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_uncertainty_measure_with_unit;
    STEPattribute * a = new STEPattribute( * config_control_design::a_341name,  &_name );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_342description,  &_description );
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


SdaiLabel SdaiUncertainty_measure_with_unit::name_() {
    return _name;
}

const SdaiLabel SdaiUncertainty_measure_with_unit::name_() const {
    return (const SdaiLabel) _name;
}

void SdaiUncertainty_measure_with_unit::name_( const SdaiLabel x ) {
    _name = x;
}

SdaiText SdaiUncertainty_measure_with_unit::description_() {
    return _description;
}

const SdaiText SdaiUncertainty_measure_with_unit::description_() const {
    return (const SdaiText) _description;
}

void SdaiUncertainty_measure_with_unit::description_( const SdaiText x ) {
    _description = x;
}

void init_SdaiUncertainty_measure_with_unit( Registry& reg ) {
    std::string str;

    config_control_design::e_uncertainty_measure_with_unit->_where_rules = new Where_rule__list;
        Where_rule * wr;
        str.clear();
        str.append( "wr1: (" );
    str.append( "valid_measure_value( SELF\\measure_with_unit.value_component )\n" );
        str.append( ");\n" );
        wr = new Where_rule( str.c_str() );
        config_control_design::e_uncertainty_measure_with_unit->_where_rules->Append( wr );
    config_control_design::e_uncertainty_measure_with_unit->AddSupertype(config_control_design::e_measure_with_unit);
    config_control_design::e_measure_with_unit->AddSubtype(config_control_design::e_uncertainty_measure_with_unit);
        config_control_design::a_341name =
          new AttrDescriptor("name",config_control_design::t_label,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_uncertainty_measure_with_unit);
        config_control_design::e_uncertainty_measure_with_unit->AddExplicitAttr (config_control_design::a_341name);
        config_control_design::a_342description =
          new AttrDescriptor("description",config_control_design::t_text,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_uncertainty_measure_with_unit);
        config_control_design::e_uncertainty_measure_with_unit->AddExplicitAttr (config_control_design::a_342description);
        reg.AddEntity( *config_control_design::e_uncertainty_measure_with_unit );
}

#endif

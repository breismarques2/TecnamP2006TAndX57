#ifndef  ENTITY_SDAIORDINAL_DATE_CC
#define  ENTITY_SDAIORDINAL_DATE_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiOrdinal_date.h"

EntityDescriptor * config_control_design::e_ordinal_date = 0;
AttrDescriptor * config_control_design::a_325day_component = 0;

SdaiOrdinal_date::SdaiOrdinal_date(): SdaiDate() {
        /*  parent: SdaiDate  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_ordinal_date;
    STEPattribute * a = new STEPattribute( * config_control_design::a_325day_component, & _day_component );
    a->set_null();
    attributes.push( a );
}

SdaiOrdinal_date::SdaiOrdinal_date ( SdaiOrdinal_date & e ) : SdaiDate() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiOrdinal_date::~SdaiOrdinal_date() {
}

SdaiOrdinal_date::SdaiOrdinal_date( SDAI_Application_instance * se, bool addAttrs ) : SdaiDate( se, addAttrs ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiDate */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_ordinal_date;
    STEPattribute * a = new STEPattribute( * config_control_design::a_325day_component,  &_day_component );
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


SdaiDay_in_year_number SdaiOrdinal_date::day_component_() const {
    return (const SdaiDay_in_year_number) _day_component;
}

void SdaiOrdinal_date::day_component_( const SdaiDay_in_year_number x ) {
    _day_component = x;
}

void init_SdaiOrdinal_date( Registry& reg ) {
    std::string str;

    config_control_design::e_ordinal_date->_where_rules = new Where_rule__list;
        Where_rule * wr;
        str.clear();
        str.append( "wr1: (" );
    str.append( "( ( NOT leap_year( SELF.year_component ) ) AND ( 1 <= day_component ) AND ( day_component <= 365 ) ) OR ( leap_year( SELF.\n" );
    str.append( "      year_component ) AND ( 1 <= day_component ) AND ( day_component <= 366 ) )\n" );
        str.append( ");\n" );
        wr = new Where_rule( str.c_str() );
        config_control_design::e_ordinal_date->_where_rules->Append( wr );
    config_control_design::e_ordinal_date->AddSupertype(config_control_design::e_date);
    config_control_design::e_date->AddSubtype(config_control_design::e_ordinal_date);
        config_control_design::a_325day_component =
          new AttrDescriptor("day_component",config_control_design::t_day_in_year_number,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_ordinal_date);
        config_control_design::e_ordinal_date->AddExplicitAttr (config_control_design::a_325day_component);
        reg.AddEntity( *config_control_design::e_ordinal_date );
}

#endif

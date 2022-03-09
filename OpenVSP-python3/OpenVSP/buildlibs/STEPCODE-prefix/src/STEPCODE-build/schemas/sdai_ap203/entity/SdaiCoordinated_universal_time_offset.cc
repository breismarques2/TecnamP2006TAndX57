#ifndef  ENTITY_SDAICOORDINATED_UNIVERSAL_TIME_OFFSET_CC
#define  ENTITY_SDAICOORDINATED_UNIVERSAL_TIME_OFFSET_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiCoordinated_universal_time_offset.h"

EntityDescriptor * config_control_design::e_coordinated_universal_time_offset = 0;
AttrDescriptor * config_control_design::a_385hour_offset = 0;
AttrDescriptor * config_control_design::a_386minute_offset = 0;
AttrDescriptor * config_control_design::a_387sense = 0;

SdaiCoordinated_universal_time_offset::SdaiCoordinated_universal_time_offset() {
        /*  no SuperTypes */

    eDesc = config_control_design::e_coordinated_universal_time_offset;
    STEPattribute * a = new STEPattribute( * config_control_design::a_385hour_offset, & _hour_offset );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_386minute_offset, & _minute_offset );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_387sense, & _sense );
    a->set_null();
    attributes.push( a );
}

SdaiCoordinated_universal_time_offset::SdaiCoordinated_universal_time_offset ( SdaiCoordinated_universal_time_offset & e ) : SDAI_Application_instance() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiCoordinated_universal_time_offset::~SdaiCoordinated_universal_time_offset() {
}

SdaiCoordinated_universal_time_offset::SdaiCoordinated_universal_time_offset( SDAI_Application_instance * se, bool addAttrs ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
    ( void ) addAttrs; /* quell potentially unused var */

        /*  no SuperTypes */

    eDesc = config_control_design::e_coordinated_universal_time_offset;
    STEPattribute * a = new STEPattribute( * config_control_design::a_385hour_offset,  &_hour_offset );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_386minute_offset,  &_minute_offset );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_387sense,  &_sense );
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


SdaiHour_in_day SdaiCoordinated_universal_time_offset::hour_offset_() const {
    return (const SdaiHour_in_day) _hour_offset;
}

void SdaiCoordinated_universal_time_offset::hour_offset_( const SdaiHour_in_day x ) {
    _hour_offset = x;
}

SdaiMinute_in_hour SdaiCoordinated_universal_time_offset::minute_offset_() const {
    return (const SdaiMinute_in_hour) _minute_offset;
}

void SdaiCoordinated_universal_time_offset::minute_offset_( const SdaiMinute_in_hour x ) {
    _minute_offset = x;
}

SdaiAhead_or_behind_var SdaiCoordinated_universal_time_offset::sense_() {
    return (Ahead_or_behind) _sense;
}

const SdaiAhead_or_behind_var SdaiCoordinated_universal_time_offset::sense_() const {
    return (const Ahead_or_behind) _sense;
}

void SdaiCoordinated_universal_time_offset::sense_( const SdaiAhead_or_behind_var x ) {
    _sense.put( x );
}

void init_SdaiCoordinated_universal_time_offset( Registry& reg ) {
    std::string str;

        config_control_design::a_385hour_offset =
          new AttrDescriptor("hour_offset",config_control_design::t_hour_in_day,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_coordinated_universal_time_offset);
        config_control_design::e_coordinated_universal_time_offset->AddExplicitAttr (config_control_design::a_385hour_offset);
        config_control_design::a_386minute_offset =
          new AttrDescriptor("minute_offset",config_control_design::t_minute_in_hour,
          LTrue,LFalse, AttrType_Explicit,
          *config_control_design::e_coordinated_universal_time_offset);
        config_control_design::e_coordinated_universal_time_offset->AddExplicitAttr (config_control_design::a_386minute_offset);
        config_control_design::a_387sense =
          new AttrDescriptor("sense",config_control_design::t_ahead_or_behind,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_coordinated_universal_time_offset);
        config_control_design::e_coordinated_universal_time_offset->AddExplicitAttr (config_control_design::a_387sense);
        reg.AddEntity( *config_control_design::e_coordinated_universal_time_offset );
}

#endif

#ifndef  ENTITY_SDAIDATED_EFFECTIVITY_CC
#define  ENTITY_SDAIDATED_EFFECTIVITY_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiDated_effectivity.h"

EntityDescriptor * config_control_design::e_dated_effectivity = 0;
AttrDescriptor * config_control_design::a_396effectivity_start_date = 0;
AttrDescriptor * config_control_design::a_397effectivity_end_date = 0;

SdaiDated_effectivity::SdaiDated_effectivity(): SdaiEffectivity(), _effectivity_start_date( 0 ), _effectivity_end_date( 0 ) {
        /*  parent: SdaiEffectivity  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_dated_effectivity;
    STEPattribute * a = new STEPattribute( * config_control_design::a_396effectivity_start_date, ( SDAI_Application_instance_ptr * ) & _effectivity_start_date );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_397effectivity_end_date, ( SDAI_Application_instance_ptr * ) & _effectivity_end_date );
    a->set_null();
    attributes.push( a );
}

SdaiDated_effectivity::SdaiDated_effectivity ( SdaiDated_effectivity & e ) : SdaiEffectivity() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiDated_effectivity::~SdaiDated_effectivity() {
}

SdaiDated_effectivity::SdaiDated_effectivity( SDAI_Application_instance * se, bool addAttrs ) : SdaiEffectivity( se, addAttrs ), _effectivity_start_date( 0 ), _effectivity_end_date( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiEffectivity */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_dated_effectivity;
    STEPattribute * a = new STEPattribute( * config_control_design::a_396effectivity_start_date, ( SDAI_Application_instance_ptr * ) &_effectivity_start_date );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_397effectivity_end_date, ( SDAI_Application_instance_ptr * ) &_effectivity_end_date );
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


SdaiDate_and_time_ptr SdaiDated_effectivity::effectivity_start_date_() {
    if( !_effectivity_start_date ) {
        _effectivity_start_date = new SdaiDate_and_time;
    }
    return (SdaiDate_and_time_ptr) _effectivity_start_date;
}

SdaiDate_and_time_ptr_c SdaiDated_effectivity::effectivity_start_date_() const {
    return (SdaiDate_and_time_ptr) _effectivity_start_date;
}

void SdaiDated_effectivity::effectivity_start_date_( const SdaiDate_and_time_ptr x ) {
    _effectivity_start_date = x;
}

SdaiDate_and_time_ptr SdaiDated_effectivity::effectivity_end_date_() {
    if( !_effectivity_end_date ) {
        _effectivity_end_date = new SdaiDate_and_time;
    }
    return (SdaiDate_and_time_ptr) _effectivity_end_date;
}

SdaiDate_and_time_ptr_c SdaiDated_effectivity::effectivity_end_date_() const {
    return (SdaiDate_and_time_ptr) _effectivity_end_date;
}

void SdaiDated_effectivity::effectivity_end_date_( const SdaiDate_and_time_ptr x ) {
    _effectivity_end_date = x;
}

void init_SdaiDated_effectivity( Registry& reg ) {
    std::string str;

    config_control_design::e_dated_effectivity->AddSupertype(config_control_design::e_effectivity);
    config_control_design::e_effectivity->AddSubtype(config_control_design::e_dated_effectivity);
    config_control_design::a_396effectivity_start_date =
      new AttrDescriptor( "effectivity_start_date", config_control_design::e_date_and_time, LFalse,
       LFalse, AttrType_Explicit, *config_control_design::e_dated_effectivity);
        config_control_design::e_dated_effectivity->AddExplicitAttr (config_control_design::a_396effectivity_start_date);
    config_control_design::a_397effectivity_end_date =
      new AttrDescriptor( "effectivity_end_date", config_control_design::e_date_and_time, LTrue,
       LFalse, AttrType_Explicit, *config_control_design::e_dated_effectivity);
        config_control_design::e_dated_effectivity->AddExplicitAttr (config_control_design::a_397effectivity_end_date);
        reg.AddEntity( *config_control_design::e_dated_effectivity );
}

#endif
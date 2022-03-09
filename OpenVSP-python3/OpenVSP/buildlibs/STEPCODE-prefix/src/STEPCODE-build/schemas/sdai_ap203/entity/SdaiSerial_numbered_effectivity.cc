#ifndef  ENTITY_SDAISERIAL_NUMBERED_EFFECTIVITY_CC
#define  ENTITY_SDAISERIAL_NUMBERED_EFFECTIVITY_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiSerial_numbered_effectivity.h"

EntityDescriptor * config_control_design::e_serial_numbered_effectivity = 0;
AttrDescriptor * config_control_design::a_435effectivity_start_id = 0;
AttrDescriptor * config_control_design::a_436effectivity_end_id = 0;

SdaiSerial_numbered_effectivity::SdaiSerial_numbered_effectivity(): SdaiEffectivity() {
        /*  parent: SdaiEffectivity  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_serial_numbered_effectivity;
    STEPattribute * a = new STEPattribute( * config_control_design::a_435effectivity_start_id, & _effectivity_start_id );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_436effectivity_end_id, & _effectivity_end_id );
    a->set_null();
    attributes.push( a );
}

SdaiSerial_numbered_effectivity::SdaiSerial_numbered_effectivity ( SdaiSerial_numbered_effectivity & e ) : SdaiEffectivity() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiSerial_numbered_effectivity::~SdaiSerial_numbered_effectivity() {
}

SdaiSerial_numbered_effectivity::SdaiSerial_numbered_effectivity( SDAI_Application_instance * se, bool addAttrs ) : SdaiEffectivity( se, addAttrs ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiEffectivity */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_serial_numbered_effectivity;
    STEPattribute * a = new STEPattribute( * config_control_design::a_435effectivity_start_id,  &_effectivity_start_id );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_436effectivity_end_id,  &_effectivity_end_id );
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


SdaiIdentifier SdaiSerial_numbered_effectivity::effectivity_start_id_() {
    return _effectivity_start_id;
}

const SdaiIdentifier SdaiSerial_numbered_effectivity::effectivity_start_id_() const {
    return (const SdaiIdentifier) _effectivity_start_id;
}

void SdaiSerial_numbered_effectivity::effectivity_start_id_( const SdaiIdentifier x ) {
    _effectivity_start_id = x;
}

SdaiIdentifier SdaiSerial_numbered_effectivity::effectivity_end_id_() {
    return _effectivity_end_id;
}

const SdaiIdentifier SdaiSerial_numbered_effectivity::effectivity_end_id_() const {
    return (const SdaiIdentifier) _effectivity_end_id;
}

void SdaiSerial_numbered_effectivity::effectivity_end_id_( const SdaiIdentifier x ) {
    _effectivity_end_id = x;
}

void init_SdaiSerial_numbered_effectivity( Registry& reg ) {
    std::string str;

    config_control_design::e_serial_numbered_effectivity->AddSupertype(config_control_design::e_effectivity);
    config_control_design::e_effectivity->AddSubtype(config_control_design::e_serial_numbered_effectivity);
        config_control_design::a_435effectivity_start_id =
          new AttrDescriptor("effectivity_start_id",config_control_design::t_identifier,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_serial_numbered_effectivity);
        config_control_design::e_serial_numbered_effectivity->AddExplicitAttr (config_control_design::a_435effectivity_start_id);
        config_control_design::a_436effectivity_end_id =
          new AttrDescriptor("effectivity_end_id",config_control_design::t_identifier,
          LTrue,LFalse, AttrType_Explicit,
          *config_control_design::e_serial_numbered_effectivity);
        config_control_design::e_serial_numbered_effectivity->AddExplicitAttr (config_control_design::a_436effectivity_end_id);
        reg.AddEntity( *config_control_design::e_serial_numbered_effectivity );
}

#endif

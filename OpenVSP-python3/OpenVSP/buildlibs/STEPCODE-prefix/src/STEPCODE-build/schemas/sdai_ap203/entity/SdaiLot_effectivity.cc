#ifndef  ENTITY_SDAILOT_EFFECTIVITY_CC
#define  ENTITY_SDAILOT_EFFECTIVITY_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiLot_effectivity.h"

EntityDescriptor * config_control_design::e_lot_effectivity = 0;
AttrDescriptor * config_control_design::a_212effectivity_lot_id = 0;
AttrDescriptor * config_control_design::a_213effectivity_lot_size = 0;

SdaiLot_effectivity::SdaiLot_effectivity(): SdaiEffectivity(), _effectivity_lot_size( 0 ) {
        /*  parent: SdaiEffectivity  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_lot_effectivity;
    STEPattribute * a = new STEPattribute( * config_control_design::a_212effectivity_lot_id, & _effectivity_lot_id );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_213effectivity_lot_size, ( SDAI_Application_instance_ptr * ) & _effectivity_lot_size );
    a->set_null();
    attributes.push( a );
}

SdaiLot_effectivity::SdaiLot_effectivity ( SdaiLot_effectivity & e ) : SdaiEffectivity() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiLot_effectivity::~SdaiLot_effectivity() {
}

SdaiLot_effectivity::SdaiLot_effectivity( SDAI_Application_instance * se, bool addAttrs ) : SdaiEffectivity( se, addAttrs ), _effectivity_lot_size( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiEffectivity */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_lot_effectivity;
    STEPattribute * a = new STEPattribute( * config_control_design::a_212effectivity_lot_id,  &_effectivity_lot_id );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_213effectivity_lot_size, ( SDAI_Application_instance_ptr * ) &_effectivity_lot_size );
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


SdaiIdentifier SdaiLot_effectivity::effectivity_lot_id_() {
    return _effectivity_lot_id;
}

const SdaiIdentifier SdaiLot_effectivity::effectivity_lot_id_() const {
    return (const SdaiIdentifier) _effectivity_lot_id;
}

void SdaiLot_effectivity::effectivity_lot_id_( const SdaiIdentifier x ) {
    _effectivity_lot_id = x;
}

SdaiMeasure_with_unit_ptr SdaiLot_effectivity::effectivity_lot_size_() {
    if( !_effectivity_lot_size ) {
        _effectivity_lot_size = new SdaiMeasure_with_unit;
    }
    return (SdaiMeasure_with_unit_ptr) _effectivity_lot_size;
}

SdaiMeasure_with_unit_ptr_c SdaiLot_effectivity::effectivity_lot_size_() const {
    return (SdaiMeasure_with_unit_ptr) _effectivity_lot_size;
}

void SdaiLot_effectivity::effectivity_lot_size_( const SdaiMeasure_with_unit_ptr x ) {
    _effectivity_lot_size = x;
}

void init_SdaiLot_effectivity( Registry& reg ) {
    std::string str;

    config_control_design::e_lot_effectivity->AddSupertype(config_control_design::e_effectivity);
    config_control_design::e_effectivity->AddSubtype(config_control_design::e_lot_effectivity);
        config_control_design::a_212effectivity_lot_id =
          new AttrDescriptor("effectivity_lot_id",config_control_design::t_identifier,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_lot_effectivity);
        config_control_design::e_lot_effectivity->AddExplicitAttr (config_control_design::a_212effectivity_lot_id);
    config_control_design::a_213effectivity_lot_size =
      new AttrDescriptor( "effectivity_lot_size", config_control_design::e_measure_with_unit, LFalse,
       LFalse, AttrType_Explicit, *config_control_design::e_lot_effectivity);
        config_control_design::e_lot_effectivity->AddExplicitAttr (config_control_design::a_213effectivity_lot_size);
        reg.AddEntity( *config_control_design::e_lot_effectivity );
}

#endif

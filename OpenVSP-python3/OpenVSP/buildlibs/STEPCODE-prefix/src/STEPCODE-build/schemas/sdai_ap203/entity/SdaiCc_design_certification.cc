#ifndef  ENTITY_SDAICC_DESIGN_CERTIFICATION_CC
#define  ENTITY_SDAICC_DESIGN_CERTIFICATION_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiCc_design_certification.h"

EntityDescriptor * config_control_design::e_cc_design_certification = 0;
AttrDescriptor * config_control_design::a_300items = 0;

SdaiCc_design_certification::SdaiCc_design_certification(): SdaiCertification_assignment(), _items( 0 ) {
        /*  parent: SdaiCertification_assignment  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_cc_design_certification;
    _items = new SdaiCertified_item_agg;
    STEPattribute * a = new STEPattribute( * config_control_design::a_300items, _items );
    a->set_null();
    attributes.push( a );
}

SdaiCc_design_certification::SdaiCc_design_certification ( SdaiCc_design_certification & e ) : SdaiCertification_assignment() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiCc_design_certification::~SdaiCc_design_certification() {
    delete _items;
}

SdaiCc_design_certification::SdaiCc_design_certification( SDAI_Application_instance * se, bool addAttrs ) : SdaiCertification_assignment( se, addAttrs ), _items( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiCertification_assignment */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_cc_design_certification;
    _items = new SdaiCertified_item_agg;
    STEPattribute * a = new STEPattribute( * config_control_design::a_300items,  _items );
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


SdaiCertified_item_agg_ptr SdaiCc_design_certification::items_() {
    if( !_items ) {
        _items = new SdaiCertified_item_agg;
    }
    return ( SdaiCertified_item_agg_ptr ) _items;
}

SdaiCertified_item_agg_ptr_c SdaiCc_design_certification::items_() const {
    return ( SdaiCertified_item_agg_ptr ) _items;
}

void SdaiCc_design_certification::items_( const SdaiCertified_item_agg_ptr x ) {
    if( !_items ) {
        _items = new SdaiCertified_item_agg;
    }
    _items->ShallowCopy( * x );
}

void init_SdaiCc_design_certification( Registry& reg ) {
    std::string str;

    config_control_design::e_cc_design_certification->AddSupertype(config_control_design::e_certification_assignment);
    config_control_design::e_certification_assignment->AddSubtype(config_control_design::e_cc_design_certification);
        SetTypeDescriptor * t_57 = new SetTypeDescriptor;
        t_57->AssignAggrCreator((AggregateCreator) create_SdaiCertified_item_agg);        // Creator function
        t_57->SetBound1( 1 );
        t_57->SetBound2( 2147483647 );
        t_57->FundamentalType(SET_TYPE);
        t_57->Description("SET [1:?] OF certified_item");
        t_57->OriginatingSchema(config_control_design::schema);
        t_57->ReferentType(config_control_design::t_certified_item);
        config_control_design::schema->AddUnnamedType(t_57);
        config_control_design::a_300items =
          new AttrDescriptor("items",t_57,LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_cc_design_certification);
        config_control_design::e_cc_design_certification->AddExplicitAttr (config_control_design::a_300items);
        reg.AddEntity( *config_control_design::e_cc_design_certification );
}

#endif

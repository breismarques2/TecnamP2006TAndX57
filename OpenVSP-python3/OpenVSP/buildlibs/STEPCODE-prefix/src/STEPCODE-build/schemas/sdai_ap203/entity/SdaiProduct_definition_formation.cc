#ifndef  ENTITY_SDAIPRODUCT_DEFINITION_FORMATION_CC
#define  ENTITY_SDAIPRODUCT_DEFINITION_FORMATION_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiProduct_definition_formation.h"

EntityDescriptor * config_control_design::e_product_definition_formation = 0;
AttrDescriptor * config_control_design::a_29id = 0;
AttrDescriptor * config_control_design::a_30description = 0;
AttrDescriptor * config_control_design::a_31of_product = 0;

SdaiProduct_definition_formation::SdaiProduct_definition_formation() : _of_product( 0 ) {
        /*  no SuperTypes */

    eDesc = config_control_design::e_product_definition_formation;
    STEPattribute * a = new STEPattribute( * config_control_design::a_29id, & _id );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_30description, & _description );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_31of_product, ( SDAI_Application_instance_ptr * ) & _of_product );
    a->set_null();
    attributes.push( a );
}

SdaiProduct_definition_formation::SdaiProduct_definition_formation ( SdaiProduct_definition_formation & e ) : SDAI_Application_instance() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiProduct_definition_formation::~SdaiProduct_definition_formation() {
}

SdaiProduct_definition_formation::SdaiProduct_definition_formation( SDAI_Application_instance * se, bool addAttrs ) : _of_product( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
    ( void ) addAttrs; /* quell potentially unused var */

        /*  no SuperTypes */

    eDesc = config_control_design::e_product_definition_formation;
    STEPattribute * a = new STEPattribute( * config_control_design::a_29id,  &_id );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_30description,  &_description );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_31of_product, ( SDAI_Application_instance_ptr * ) &_of_product );
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


SdaiIdentifier SdaiProduct_definition_formation::id_() {
    return _id;
}

const SdaiIdentifier SdaiProduct_definition_formation::id_() const {
    return (const SdaiIdentifier) _id;
}

void SdaiProduct_definition_formation::id_( const SdaiIdentifier x ) {
    _id = x;
}

SdaiText SdaiProduct_definition_formation::description_() {
    return _description;
}

const SdaiText SdaiProduct_definition_formation::description_() const {
    return (const SdaiText) _description;
}

void SdaiProduct_definition_formation::description_( const SdaiText x ) {
    _description = x;
}

SdaiProduct_ptr SdaiProduct_definition_formation::of_product_() {
    if( !_of_product ) {
        _of_product = new SdaiProduct;
    }
    return (SdaiProduct_ptr) _of_product;
}

SdaiProduct_ptr_c SdaiProduct_definition_formation::of_product_() const {
    return (SdaiProduct_ptr) _of_product;
}

void SdaiProduct_definition_formation::of_product_( const SdaiProduct_ptr x ) {
    _of_product = x;
}

void init_SdaiProduct_definition_formation( Registry& reg ) {
    std::string str;

        config_control_design::e_product_definition_formation->_uniqueness_rules = new Uniqueness_rule__set;
        Uniqueness_rule * ur;
        str.clear();
    str.append( "UR1 : " );
    str.append( "id\n" );
    str.append( ", " );
    str.append( "of_product\n" );
    ur = new Uniqueness_rule( str.c_str() );
    config_control_design::e_product_definition_formation->_uniqueness_rules->Append(ur);
        config_control_design::a_29id =
          new AttrDescriptor("id",config_control_design::t_identifier,
          LFalse,LTrue, AttrType_Explicit,
          *config_control_design::e_product_definition_formation);
        config_control_design::e_product_definition_formation->AddExplicitAttr (config_control_design::a_29id);
        config_control_design::a_30description =
          new AttrDescriptor("description",config_control_design::t_text,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_product_definition_formation);
        config_control_design::e_product_definition_formation->AddExplicitAttr (config_control_design::a_30description);
    config_control_design::a_31of_product =
      new AttrDescriptor( "of_product", config_control_design::e_product, LFalse,
       LTrue, AttrType_Explicit, *config_control_design::e_product_definition_formation);
        config_control_design::e_product_definition_formation->AddExplicitAttr (config_control_design::a_31of_product);
        reg.AddEntity( *config_control_design::e_product_definition_formation );
}

#endif

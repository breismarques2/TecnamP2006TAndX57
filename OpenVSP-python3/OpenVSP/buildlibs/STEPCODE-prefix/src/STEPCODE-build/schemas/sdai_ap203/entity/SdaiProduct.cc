#ifndef  ENTITY_SDAIPRODUCT_CC
#define  ENTITY_SDAIPRODUCT_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiProduct.h"

EntityDescriptor * config_control_design::e_product = 0;
AttrDescriptor * config_control_design::a_310id = 0;
AttrDescriptor * config_control_design::a_311name = 0;
AttrDescriptor * config_control_design::a_312description = 0;
AttrDescriptor * config_control_design::a_313frame_of_reference = 0;

SdaiProduct::SdaiProduct() : _frame_of_reference( 0 ) {
        /*  no SuperTypes */

    eDesc = config_control_design::e_product;
    STEPattribute * a = new STEPattribute( * config_control_design::a_310id, & _id );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_311name, & _name );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_312description, & _description );
    a->set_null();
    attributes.push( a );
    _frame_of_reference = new EntityAggregate;
    a = new STEPattribute( * config_control_design::a_313frame_of_reference, _frame_of_reference );
    a->set_null();
    attributes.push( a );
}

SdaiProduct::SdaiProduct ( SdaiProduct & e ) : SDAI_Application_instance() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiProduct::~SdaiProduct() {
    delete _frame_of_reference;
}

SdaiProduct::SdaiProduct( SDAI_Application_instance * se, bool addAttrs ) : _frame_of_reference( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
    ( void ) addAttrs; /* quell potentially unused var */

        /*  no SuperTypes */

    eDesc = config_control_design::e_product;
    STEPattribute * a = new STEPattribute( * config_control_design::a_310id,  &_id );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_311name,  &_name );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_312description,  &_description );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    _frame_of_reference = new EntityAggregate;
    a = new STEPattribute( * config_control_design::a_313frame_of_reference,  _frame_of_reference );
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


SdaiIdentifier SdaiProduct::id_() {
    return _id;
}

const SdaiIdentifier SdaiProduct::id_() const {
    return (const SdaiIdentifier) _id;
}

void SdaiProduct::id_( const SdaiIdentifier x ) {
    _id = x;
}

SdaiLabel SdaiProduct::name_() {
    return _name;
}

const SdaiLabel SdaiProduct::name_() const {
    return (const SdaiLabel) _name;
}

void SdaiProduct::name_( const SdaiLabel x ) {
    _name = x;
}

SdaiText SdaiProduct::description_() {
    return _description;
}

const SdaiText SdaiProduct::description_() const {
    return (const SdaiText) _description;
}

void SdaiProduct::description_( const SdaiText x ) {
    _description = x;
}

EntityAggregate_ptr SdaiProduct::frame_of_reference_() {
    if( !_frame_of_reference ) {
        _frame_of_reference = new EntityAggregate;
    }
    return ( EntityAggregate_ptr ) _frame_of_reference;
}

EntityAggregate_ptr_c SdaiProduct::frame_of_reference_() const {
    return ( EntityAggregate_ptr ) _frame_of_reference;
}

void SdaiProduct::frame_of_reference_( const EntityAggregate_ptr x ) {
    if( !_frame_of_reference ) {
        _frame_of_reference = new EntityAggregate;
    }
    _frame_of_reference->ShallowCopy( * x );
}

void init_SdaiProduct( Registry& reg ) {
    std::string str;

        config_control_design::e_product->_uniqueness_rules = new Uniqueness_rule__set;
        Uniqueness_rule * ur;
        str.clear();
    str.append( "UR1 : " );
    str.append( "id\n" );
    ur = new Uniqueness_rule( str.c_str() );
    config_control_design::e_product->_uniqueness_rules->Append(ur);
        config_control_design::a_310id =
          new AttrDescriptor("id",config_control_design::t_identifier,
          LFalse,LTrue, AttrType_Explicit,
          *config_control_design::e_product);
        config_control_design::e_product->AddExplicitAttr (config_control_design::a_310id);
        config_control_design::a_311name =
          new AttrDescriptor("name",config_control_design::t_label,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_product);
        config_control_design::e_product->AddExplicitAttr (config_control_design::a_311name);
        config_control_design::a_312description =
          new AttrDescriptor("description",config_control_design::t_text,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_product);
        config_control_design::e_product->AddExplicitAttr (config_control_design::a_312description);
        SetTypeDescriptor * t_59 = new SetTypeDescriptor;
        t_59->AssignAggrCreator((AggregateCreator) create_EntityAggregate);        // Creator function
        t_59->SetBound1( 1 );
        t_59->SetBound2( 2147483647 );
        t_59->FundamentalType(SET_TYPE);
        t_59->Description("SET [1:?] OF product_context");
        t_59->OriginatingSchema(config_control_design::schema);
        t_59->ReferentType(config_control_design::e_product_context);
        config_control_design::schema->AddUnnamedType(t_59);
        config_control_design::a_313frame_of_reference =
          new AttrDescriptor("frame_of_reference",t_59,LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_product);
        config_control_design::e_product->AddExplicitAttr (config_control_design::a_313frame_of_reference);
        reg.AddEntity( *config_control_design::e_product );
}

#endif

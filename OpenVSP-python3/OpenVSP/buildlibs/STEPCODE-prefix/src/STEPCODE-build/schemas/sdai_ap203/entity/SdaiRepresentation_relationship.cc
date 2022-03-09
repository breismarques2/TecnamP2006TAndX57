#ifndef  ENTITY_SDAIREPRESENTATION_RELATIONSHIP_CC
#define  ENTITY_SDAIREPRESENTATION_RELATIONSHIP_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiRepresentation_relationship.h"

EntityDescriptor * config_control_design::e_representation_relationship = 0;
AttrDescriptor * config_control_design::a_23name = 0;
AttrDescriptor * config_control_design::a_24description = 0;
AttrDescriptor * config_control_design::a_25rep_1 = 0;
AttrDescriptor * config_control_design::a_26rep_2 = 0;

SdaiRepresentation_relationship::SdaiRepresentation_relationship() : _rep_1( 0 ), _rep_2( 0 ) {
        /*  no SuperTypes */

    eDesc = config_control_design::e_representation_relationship;
    STEPattribute * a = new STEPattribute( * config_control_design::a_23name, & _name );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_24description, & _description );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_25rep_1, ( SDAI_Application_instance_ptr * ) & _rep_1 );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_26rep_2, ( SDAI_Application_instance_ptr * ) & _rep_2 );
    a->set_null();
    attributes.push( a );
}

SdaiRepresentation_relationship::SdaiRepresentation_relationship ( SdaiRepresentation_relationship & e ) : SDAI_Application_instance() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiRepresentation_relationship::~SdaiRepresentation_relationship() {
}

SdaiRepresentation_relationship::SdaiRepresentation_relationship( SDAI_Application_instance * se, bool addAttrs ) : _rep_1( 0 ), _rep_2( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
    ( void ) addAttrs; /* quell potentially unused var */

        /*  no SuperTypes */

    eDesc = config_control_design::e_representation_relationship;
    STEPattribute * a = new STEPattribute( * config_control_design::a_23name,  &_name );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_24description,  &_description );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_25rep_1, ( SDAI_Application_instance_ptr * ) &_rep_1 );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_26rep_2, ( SDAI_Application_instance_ptr * ) &_rep_2 );
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


SdaiLabel SdaiRepresentation_relationship::name_() {
    return _name;
}

const SdaiLabel SdaiRepresentation_relationship::name_() const {
    return (const SdaiLabel) _name;
}

void SdaiRepresentation_relationship::name_( const SdaiLabel x ) {
    _name = x;
}

SdaiText SdaiRepresentation_relationship::description_() {
    return _description;
}

const SdaiText SdaiRepresentation_relationship::description_() const {
    return (const SdaiText) _description;
}

void SdaiRepresentation_relationship::description_( const SdaiText x ) {
    _description = x;
}

SdaiRepresentation_ptr SdaiRepresentation_relationship::rep_1_() {
    if( !_rep_1 ) {
        _rep_1 = new SdaiRepresentation;
    }
    return (SdaiRepresentation_ptr) _rep_1;
}

SdaiRepresentation_ptr_c SdaiRepresentation_relationship::rep_1_() const {
    return (SdaiRepresentation_ptr) _rep_1;
}

void SdaiRepresentation_relationship::rep_1_( const SdaiRepresentation_ptr x ) {
    _rep_1 = x;
}

SdaiRepresentation_ptr SdaiRepresentation_relationship::rep_2_() {
    if( !_rep_2 ) {
        _rep_2 = new SdaiRepresentation;
    }
    return (SdaiRepresentation_ptr) _rep_2;
}

SdaiRepresentation_ptr_c SdaiRepresentation_relationship::rep_2_() const {
    return (SdaiRepresentation_ptr) _rep_2;
}

void SdaiRepresentation_relationship::rep_2_( const SdaiRepresentation_ptr x ) {
    _rep_2 = x;
}

void init_SdaiRepresentation_relationship( Registry& reg ) {
    std::string str;

        config_control_design::a_23name =
          new AttrDescriptor("name",config_control_design::t_label,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_representation_relationship);
        config_control_design::e_representation_relationship->AddExplicitAttr (config_control_design::a_23name);
        config_control_design::a_24description =
          new AttrDescriptor("description",config_control_design::t_text,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_representation_relationship);
        config_control_design::e_representation_relationship->AddExplicitAttr (config_control_design::a_24description);
    config_control_design::a_25rep_1 =
      new AttrDescriptor( "rep_1", config_control_design::e_representation, LFalse,
       LFalse, AttrType_Explicit, *config_control_design::e_representation_relationship);
        config_control_design::e_representation_relationship->AddExplicitAttr (config_control_design::a_25rep_1);
    config_control_design::a_26rep_2 =
      new AttrDescriptor( "rep_2", config_control_design::e_representation, LFalse,
       LFalse, AttrType_Explicit, *config_control_design::e_representation_relationship);
        config_control_design::e_representation_relationship->AddExplicitAttr (config_control_design::a_26rep_2);
        reg.AddEntity( *config_control_design::e_representation_relationship );
}

#endif

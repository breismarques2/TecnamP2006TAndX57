#ifndef  ENTITY_SDAIVERSIONED_ACTION_REQUEST_CC
#define  ENTITY_SDAIVERSIONED_ACTION_REQUEST_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiVersioned_action_request.h"

EntityDescriptor * config_control_design::e_versioned_action_request = 0;
AttrDescriptor * config_control_design::a_318id = 0;
AttrDescriptor * config_control_design::a_319version = 0;
AttrDescriptor * config_control_design::a_320purpose = 0;
AttrDescriptor * config_control_design::a_321description = 0;

SdaiVersioned_action_request::SdaiVersioned_action_request() {
        /*  no SuperTypes */

    eDesc = config_control_design::e_versioned_action_request;
    STEPattribute * a = new STEPattribute( * config_control_design::a_318id, & _id );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_319version, & _version );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_320purpose, & _purpose );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_321description, & _description );
    a->set_null();
    attributes.push( a );
}

SdaiVersioned_action_request::SdaiVersioned_action_request ( SdaiVersioned_action_request & e ) : SDAI_Application_instance() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiVersioned_action_request::~SdaiVersioned_action_request() {
}

SdaiVersioned_action_request::SdaiVersioned_action_request( SDAI_Application_instance * se, bool addAttrs ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
    ( void ) addAttrs; /* quell potentially unused var */

        /*  no SuperTypes */

    eDesc = config_control_design::e_versioned_action_request;
    STEPattribute * a = new STEPattribute( * config_control_design::a_318id,  &_id );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_319version,  &_version );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_320purpose,  &_purpose );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_321description,  &_description );
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


SdaiIdentifier SdaiVersioned_action_request::id_() {
    return _id;
}

const SdaiIdentifier SdaiVersioned_action_request::id_() const {
    return (const SdaiIdentifier) _id;
}

void SdaiVersioned_action_request::id_( const SdaiIdentifier x ) {
    _id = x;
}

SdaiLabel SdaiVersioned_action_request::version_() {
    return _version;
}

const SdaiLabel SdaiVersioned_action_request::version_() const {
    return (const SdaiLabel) _version;
}

void SdaiVersioned_action_request::version_( const SdaiLabel x ) {
    _version = x;
}

SdaiText SdaiVersioned_action_request::purpose_() {
    return _purpose;
}

const SdaiText SdaiVersioned_action_request::purpose_() const {
    return (const SdaiText) _purpose;
}

void SdaiVersioned_action_request::purpose_( const SdaiText x ) {
    _purpose = x;
}

SdaiText SdaiVersioned_action_request::description_() {
    return _description;
}

const SdaiText SdaiVersioned_action_request::description_() const {
    return (const SdaiText) _description;
}

void SdaiVersioned_action_request::description_( const SdaiText x ) {
    _description = x;
}

void init_SdaiVersioned_action_request( Registry& reg ) {
    std::string str;

        config_control_design::a_318id =
          new AttrDescriptor("id",config_control_design::t_identifier,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_versioned_action_request);
        config_control_design::e_versioned_action_request->AddExplicitAttr (config_control_design::a_318id);
        config_control_design::a_319version =
          new AttrDescriptor("version",config_control_design::t_label,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_versioned_action_request);
        config_control_design::e_versioned_action_request->AddExplicitAttr (config_control_design::a_319version);
        config_control_design::a_320purpose =
          new AttrDescriptor("purpose",config_control_design::t_text,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_versioned_action_request);
        config_control_design::e_versioned_action_request->AddExplicitAttr (config_control_design::a_320purpose);
        config_control_design::a_321description =
          new AttrDescriptor("description",config_control_design::t_text,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_versioned_action_request);
        config_control_design::e_versioned_action_request->AddExplicitAttr (config_control_design::a_321description);
        reg.AddEntity( *config_control_design::e_versioned_action_request );
}

#endif

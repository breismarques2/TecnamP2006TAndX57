#ifndef  ENTITY_SDAIAPPLICATION_PROTOCOL_DEFINITION_CC
#define  ENTITY_SDAIAPPLICATION_PROTOCOL_DEFINITION_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiApplication_protocol_definition.h"

EntityDescriptor * config_control_design::e_application_protocol_definition = 0;
AttrDescriptor * config_control_design::a_217status = 0;
AttrDescriptor * config_control_design::a_218application_interpreted_model_schema_name = 0;
AttrDescriptor * config_control_design::a_219application_protocol_year = 0;
AttrDescriptor * config_control_design::a_220application = 0;

SdaiApplication_protocol_definition::SdaiApplication_protocol_definition() : _application( 0 ) {
        /*  no SuperTypes */

    eDesc = config_control_design::e_application_protocol_definition;
    STEPattribute * a = new STEPattribute( * config_control_design::a_217status, & _status );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_218application_interpreted_model_schema_name, & _application_interpreted_model_schema_name );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_219application_protocol_year, & _application_protocol_year );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_220application, ( SDAI_Application_instance_ptr * ) & _application );
    a->set_null();
    attributes.push( a );
}

SdaiApplication_protocol_definition::SdaiApplication_protocol_definition ( SdaiApplication_protocol_definition & e ) : SDAI_Application_instance() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiApplication_protocol_definition::~SdaiApplication_protocol_definition() {
}

SdaiApplication_protocol_definition::SdaiApplication_protocol_definition( SDAI_Application_instance * se, bool addAttrs ) : _application( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
    ( void ) addAttrs; /* quell potentially unused var */

        /*  no SuperTypes */

    eDesc = config_control_design::e_application_protocol_definition;
    STEPattribute * a = new STEPattribute( * config_control_design::a_217status,  &_status );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_218application_interpreted_model_schema_name,  &_application_interpreted_model_schema_name );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_219application_protocol_year,  &_application_protocol_year );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_220application, ( SDAI_Application_instance_ptr * ) &_application );
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


SdaiLabel SdaiApplication_protocol_definition::status_() {
    return _status;
}

const SdaiLabel SdaiApplication_protocol_definition::status_() const {
    return (const SdaiLabel) _status;
}

void SdaiApplication_protocol_definition::status_( const SdaiLabel x ) {
    _status = x;
}

SdaiLabel SdaiApplication_protocol_definition::application_interpreted_model_schema_name_() {
    return _application_interpreted_model_schema_name;
}

const SdaiLabel SdaiApplication_protocol_definition::application_interpreted_model_schema_name_() const {
    return (const SdaiLabel) _application_interpreted_model_schema_name;
}

void SdaiApplication_protocol_definition::application_interpreted_model_schema_name_( const SdaiLabel x ) {
    _application_interpreted_model_schema_name = x;
}

SdaiYear_number SdaiApplication_protocol_definition::application_protocol_year_() const {
    return (const SdaiYear_number) _application_protocol_year;
}

void SdaiApplication_protocol_definition::application_protocol_year_( const SdaiYear_number x ) {
    _application_protocol_year = x;
}

SdaiApplication_context_ptr SdaiApplication_protocol_definition::application_() {
    if( !_application ) {
        _application = new SdaiApplication_context;
    }
    return (SdaiApplication_context_ptr) _application;
}

SdaiApplication_context_ptr_c SdaiApplication_protocol_definition::application_() const {
    return (SdaiApplication_context_ptr) _application;
}

void SdaiApplication_protocol_definition::application_( const SdaiApplication_context_ptr x ) {
    _application = x;
}

void init_SdaiApplication_protocol_definition( Registry& reg ) {
    std::string str;

        config_control_design::a_217status =
          new AttrDescriptor("status",config_control_design::t_label,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_application_protocol_definition);
        config_control_design::e_application_protocol_definition->AddExplicitAttr (config_control_design::a_217status);
        config_control_design::a_218application_interpreted_model_schema_name =
          new AttrDescriptor("application_interpreted_model_schema_name",config_control_design::t_label,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_application_protocol_definition);
        config_control_design::e_application_protocol_definition->AddExplicitAttr (config_control_design::a_218application_interpreted_model_schema_name);
        config_control_design::a_219application_protocol_year =
          new AttrDescriptor("application_protocol_year",config_control_design::t_year_number,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_application_protocol_definition);
        config_control_design::e_application_protocol_definition->AddExplicitAttr (config_control_design::a_219application_protocol_year);
    config_control_design::a_220application =
      new AttrDescriptor( "application", config_control_design::e_application_context, LFalse,
       LFalse, AttrType_Explicit, *config_control_design::e_application_protocol_definition);
        config_control_design::e_application_protocol_definition->AddExplicitAttr (config_control_design::a_220application);
        reg.AddEntity( *config_control_design::e_application_protocol_definition );
}

#endif
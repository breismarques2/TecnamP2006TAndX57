#ifndef  ENTITY_SDAIDOCUMENT_USAGE_CONSTRAINT_CC
#define  ENTITY_SDAIDOCUMENT_USAGE_CONSTRAINT_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiDocument_usage_constraint.h"

EntityDescriptor * config_control_design::e_document_usage_constraint = 0;
AttrDescriptor * config_control_design::a_0source = 0;
AttrDescriptor * config_control_design::a_1subject_element = 0;
AttrDescriptor * config_control_design::a_2subject_element_value = 0;

SdaiDocument_usage_constraint::SdaiDocument_usage_constraint() : _source( 0 ) {
        /*  no SuperTypes */

    eDesc = config_control_design::e_document_usage_constraint;
    STEPattribute * a = new STEPattribute( * config_control_design::a_0source, ( SDAI_Application_instance_ptr * ) & _source );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_1subject_element, & _subject_element );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_2subject_element_value, & _subject_element_value );
    a->set_null();
    attributes.push( a );
}

SdaiDocument_usage_constraint::SdaiDocument_usage_constraint ( SdaiDocument_usage_constraint & e ) : SDAI_Application_instance() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiDocument_usage_constraint::~SdaiDocument_usage_constraint() {
}

SdaiDocument_usage_constraint::SdaiDocument_usage_constraint( SDAI_Application_instance * se, bool addAttrs ) : _source( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
    ( void ) addAttrs; /* quell potentially unused var */

        /*  no SuperTypes */

    eDesc = config_control_design::e_document_usage_constraint;
    STEPattribute * a = new STEPattribute( * config_control_design::a_0source, ( SDAI_Application_instance_ptr * ) &_source );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_1subject_element,  &_subject_element );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_2subject_element_value,  &_subject_element_value );
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


SdaiDocument_ptr SdaiDocument_usage_constraint::source_() {
    if( !_source ) {
        _source = new SdaiDocument;
    }
    return (SdaiDocument_ptr) _source;
}

SdaiDocument_ptr_c SdaiDocument_usage_constraint::source_() const {
    return (SdaiDocument_ptr) _source;
}

void SdaiDocument_usage_constraint::source_( const SdaiDocument_ptr x ) {
    _source = x;
}

SdaiLabel SdaiDocument_usage_constraint::subject_element_() {
    return _subject_element;
}

const SdaiLabel SdaiDocument_usage_constraint::subject_element_() const {
    return (const SdaiLabel) _subject_element;
}

void SdaiDocument_usage_constraint::subject_element_( const SdaiLabel x ) {
    _subject_element = x;
}

SdaiText SdaiDocument_usage_constraint::subject_element_value_() {
    return _subject_element_value;
}

const SdaiText SdaiDocument_usage_constraint::subject_element_value_() const {
    return (const SdaiText) _subject_element_value;
}

void SdaiDocument_usage_constraint::subject_element_value_( const SdaiText x ) {
    _subject_element_value = x;
}

void init_SdaiDocument_usage_constraint( Registry& reg ) {
    std::string str;

    config_control_design::a_0source =
      new AttrDescriptor( "source", config_control_design::e_document, LFalse,
       LFalse, AttrType_Explicit, *config_control_design::e_document_usage_constraint);
        config_control_design::e_document_usage_constraint->AddExplicitAttr (config_control_design::a_0source);
        config_control_design::a_1subject_element =
          new AttrDescriptor("subject_element",config_control_design::t_label,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_document_usage_constraint);
        config_control_design::e_document_usage_constraint->AddExplicitAttr (config_control_design::a_1subject_element);
        config_control_design::a_2subject_element_value =
          new AttrDescriptor("subject_element_value",config_control_design::t_text,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_document_usage_constraint);
        config_control_design::e_document_usage_constraint->AddExplicitAttr (config_control_design::a_2subject_element_value);
        reg.AddEntity( *config_control_design::e_document_usage_constraint );
}

#endif

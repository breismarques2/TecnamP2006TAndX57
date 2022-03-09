#ifndef  ENTITY_SDAIAPPLICATION_CONTEXT_CC
#define  ENTITY_SDAIAPPLICATION_CONTEXT_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiApplication_context.h"

EntityDescriptor * config_control_design::e_application_context = 0;
AttrDescriptor * config_control_design::a_273application = 0;
Inverse_attribute * config_control_design::a_274Icontext_elements = 0;

SdaiApplication_context::SdaiApplication_context() {
        /*  no SuperTypes */

    eDesc = config_control_design::e_application_context;
    STEPattribute * a = new STEPattribute( * config_control_design::a_273application, & _application );
    a->set_null();
    attributes.push( a );
}

SdaiApplication_context::SdaiApplication_context ( SdaiApplication_context & e ) : SDAI_Application_instance() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiApplication_context::~SdaiApplication_context() {
}

SdaiApplication_context::SdaiApplication_context( SDAI_Application_instance * se, bool addAttrs ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
    ( void ) addAttrs; /* quell potentially unused var */

        /*  no SuperTypes */

    eDesc = config_control_design::e_application_context;
    STEPattribute * a = new STEPattribute( * config_control_design::a_273application,  &_application );
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


SdaiText SdaiApplication_context::application_() {
    return _application;
}

const SdaiText SdaiApplication_context::application_() const {
    return (const SdaiText) _application;
}

void SdaiApplication_context::application_( const SdaiText x ) {
    _application = x;
}

EntityAggregate_ptr SdaiApplication_context::context_elements_() {
    iAstruct ias = getInvAttr( config_control_design::a_274Icontext_elements );
    if( !ias.a ) {
        ias.a = new EntityAggregate;
        setInvAttr( config_control_design::a_274Icontext_elements, ias );
    }
    return ias.a;
}

EntityAggregate_ptr_c SdaiApplication_context::context_elements_() const {
    return getInvAttr( config_control_design::a_274Icontext_elements ).a;
}

void SdaiApplication_context::context_elements_( const EntityAggregate_ptr x ) {
    iAstruct ias;
    ias.a = x;
    setInvAttr( config_control_design::a_274Icontext_elements, ias );
}

void init_SdaiApplication_context( Registry& reg ) {
    std::string str;

        config_control_design::a_273application =
          new AttrDescriptor("application",config_control_design::t_text,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_application_context);
        config_control_design::e_application_context->AddExplicitAttr (config_control_design::a_273application);
        SetTypeDescriptor * t_51 = new SetTypeDescriptor;
        t_51->AssignAggrCreator((AggregateCreator) create_EntityAggregate);        // Creator function
        t_51->SetBound1( 1 );
        t_51->SetBound2( 2147483647 );
        t_51->FundamentalType(SET_TYPE);
        t_51->Description("SET [1:?] OF application_context_element");
        t_51->OriginatingSchema(config_control_design::schema);
        t_51->ReferentType(config_control_design::e_application_context_element);
        config_control_design::schema->AddUnnamedType(t_51);
        config_control_design::a_274Icontext_elements =
          new Inverse_attribute("context_elements",t_51,LFalse,LFalse,
          *config_control_design::e_application_context);
        config_control_design::e_application_context->AddInverseAttr (config_control_design::a_274Icontext_elements);
        config_control_design::a_274Icontext_elements->inverted_attr_id_("frame_of_reference");
        config_control_design::a_274Icontext_elements->inverted_entity_id_("application_context_element");
// inverse entity 3 application_context_element
        reg.AddEntity( *config_control_design::e_application_context );
        config_control_design::schema->AddEntityWInverse( config_control_design::e_application_context );
}

#endif

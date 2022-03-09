#ifndef  ENTITY_SDAIORGANIZATIONAL_PROJECT_CC
#define  ENTITY_SDAIORGANIZATIONAL_PROJECT_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiOrganizational_project.h"

EntityDescriptor * config_control_design::e_organizational_project = 0;
AttrDescriptor * config_control_design::a_322name = 0;
AttrDescriptor * config_control_design::a_323description = 0;
AttrDescriptor * config_control_design::a_324responsible_organizations = 0;

SdaiOrganizational_project::SdaiOrganizational_project() : _responsible_organizations( 0 ) {
        /*  no SuperTypes */

    eDesc = config_control_design::e_organizational_project;
    STEPattribute * a = new STEPattribute( * config_control_design::a_322name, & _name );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_323description, & _description );
    a->set_null();
    attributes.push( a );
    _responsible_organizations = new EntityAggregate;
    a = new STEPattribute( * config_control_design::a_324responsible_organizations, _responsible_organizations );
    a->set_null();
    attributes.push( a );
}

SdaiOrganizational_project::SdaiOrganizational_project ( SdaiOrganizational_project & e ) : SDAI_Application_instance() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiOrganizational_project::~SdaiOrganizational_project() {
    delete _responsible_organizations;
}

SdaiOrganizational_project::SdaiOrganizational_project( SDAI_Application_instance * se, bool addAttrs ) : _responsible_organizations( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
    ( void ) addAttrs; /* quell potentially unused var */

        /*  no SuperTypes */

    eDesc = config_control_design::e_organizational_project;
    STEPattribute * a = new STEPattribute( * config_control_design::a_322name,  &_name );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_323description,  &_description );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    _responsible_organizations = new EntityAggregate;
    a = new STEPattribute( * config_control_design::a_324responsible_organizations,  _responsible_organizations );
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


SdaiLabel SdaiOrganizational_project::name_() {
    return _name;
}

const SdaiLabel SdaiOrganizational_project::name_() const {
    return (const SdaiLabel) _name;
}

void SdaiOrganizational_project::name_( const SdaiLabel x ) {
    _name = x;
}

SdaiText SdaiOrganizational_project::description_() {
    return _description;
}

const SdaiText SdaiOrganizational_project::description_() const {
    return (const SdaiText) _description;
}

void SdaiOrganizational_project::description_( const SdaiText x ) {
    _description = x;
}

EntityAggregate_ptr SdaiOrganizational_project::responsible_organizations_() {
    if( !_responsible_organizations ) {
        _responsible_organizations = new EntityAggregate;
    }
    return ( EntityAggregate_ptr ) _responsible_organizations;
}

EntityAggregate_ptr_c SdaiOrganizational_project::responsible_organizations_() const {
    return ( EntityAggregate_ptr ) _responsible_organizations;
}

void SdaiOrganizational_project::responsible_organizations_( const EntityAggregate_ptr x ) {
    if( !_responsible_organizations ) {
        _responsible_organizations = new EntityAggregate;
    }
    _responsible_organizations->ShallowCopy( * x );
}

void init_SdaiOrganizational_project( Registry& reg ) {
    std::string str;

        config_control_design::a_322name =
          new AttrDescriptor("name",config_control_design::t_label,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_organizational_project);
        config_control_design::e_organizational_project->AddExplicitAttr (config_control_design::a_322name);
        config_control_design::a_323description =
          new AttrDescriptor("description",config_control_design::t_text,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_organizational_project);
        config_control_design::e_organizational_project->AddExplicitAttr (config_control_design::a_323description);
        SetTypeDescriptor * t_60 = new SetTypeDescriptor;
        t_60->AssignAggrCreator((AggregateCreator) create_EntityAggregate);        // Creator function
        t_60->SetBound1( 1 );
        t_60->SetBound2( 2147483647 );
        t_60->FundamentalType(SET_TYPE);
        t_60->Description("SET [1:?] OF organization");
        t_60->OriginatingSchema(config_control_design::schema);
        t_60->ReferentType(config_control_design::e_organization);
        config_control_design::schema->AddUnnamedType(t_60);
        config_control_design::a_324responsible_organizations =
          new AttrDescriptor("responsible_organizations",t_60,LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_organizational_project);
        config_control_design::e_organizational_project->AddExplicitAttr (config_control_design::a_324responsible_organizations);
        reg.AddEntity( *config_control_design::e_organizational_project );
}

#endif
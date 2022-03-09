#ifndef  ENTITY_SDAIACTION_REQUEST_ASSIGNMENT_CC
#define  ENTITY_SDAIACTION_REQUEST_ASSIGNMENT_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiAction_request_assignment.h"

EntityDescriptor * config_control_design::e_action_request_assignment = 0;
AttrDescriptor * config_control_design::a_151assigned_action_request = 0;

SdaiAction_request_assignment::SdaiAction_request_assignment() : _assigned_action_request( 0 ) {
        /*  no SuperTypes */

    eDesc = config_control_design::e_action_request_assignment;
    STEPattribute * a = new STEPattribute( * config_control_design::a_151assigned_action_request, ( SDAI_Application_instance_ptr * ) & _assigned_action_request );
    a->set_null();
    attributes.push( a );
}

SdaiAction_request_assignment::SdaiAction_request_assignment ( SdaiAction_request_assignment & e ) : SDAI_Application_instance() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiAction_request_assignment::~SdaiAction_request_assignment() {
}

SdaiAction_request_assignment::SdaiAction_request_assignment( SDAI_Application_instance * se, bool addAttrs ) : _assigned_action_request( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
    ( void ) addAttrs; /* quell potentially unused var */

        /*  no SuperTypes */

    eDesc = config_control_design::e_action_request_assignment;
    STEPattribute * a = new STEPattribute( * config_control_design::a_151assigned_action_request, ( SDAI_Application_instance_ptr * ) &_assigned_action_request );
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


SdaiVersioned_action_request_ptr SdaiAction_request_assignment::assigned_action_request_() {
    if( !_assigned_action_request ) {
        _assigned_action_request = new SdaiVersioned_action_request;
    }
    return (SdaiVersioned_action_request_ptr) _assigned_action_request;
}

SdaiVersioned_action_request_ptr_c SdaiAction_request_assignment::assigned_action_request_() const {
    return (SdaiVersioned_action_request_ptr) _assigned_action_request;
}

void SdaiAction_request_assignment::assigned_action_request_( const SdaiVersioned_action_request_ptr x ) {
    _assigned_action_request = x;
}

void init_SdaiAction_request_assignment( Registry& reg ) {
    std::string str;

    config_control_design::e_action_request_assignment->AddSupertype_Stmt( "ABSTRACT SUPERTYPE" );
    config_control_design::a_151assigned_action_request =
      new AttrDescriptor( "assigned_action_request", config_control_design::e_versioned_action_request, LFalse,
       LFalse, AttrType_Explicit, *config_control_design::e_action_request_assignment);
        config_control_design::e_action_request_assignment->AddExplicitAttr (config_control_design::a_151assigned_action_request);
        reg.AddEntity( *config_control_design::e_action_request_assignment );
}

#endif

#ifndef  ENTITY_SDAIDIRECTED_ACTION_CC
#define  ENTITY_SDAIDIRECTED_ACTION_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiDirected_action.h"

EntityDescriptor * config_control_design::e_directed_action = 0;
AttrDescriptor * config_control_design::a_381directive = 0;

SdaiDirected_action::SdaiDirected_action(): SdaiExecuted_action(), _directive( 0 ) {
        /*  parent: SdaiExecuted_action  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_directed_action;
    STEPattribute * a = new STEPattribute( * config_control_design::a_381directive, ( SDAI_Application_instance_ptr * ) & _directive );
    a->set_null();
    attributes.push( a );
}

SdaiDirected_action::SdaiDirected_action ( SdaiDirected_action & e ) : SdaiExecuted_action() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiDirected_action::~SdaiDirected_action() {
}

SdaiDirected_action::SdaiDirected_action( SDAI_Application_instance * se, bool addAttrs ) : SdaiExecuted_action( se, addAttrs ), _directive( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiExecuted_action */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_directed_action;
    STEPattribute * a = new STEPattribute( * config_control_design::a_381directive, ( SDAI_Application_instance_ptr * ) &_directive );
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


SdaiAction_directive_ptr SdaiDirected_action::directive_() {
    if( !_directive ) {
        _directive = new SdaiAction_directive;
    }
    return (SdaiAction_directive_ptr) _directive;
}

SdaiAction_directive_ptr_c SdaiDirected_action::directive_() const {
    return (SdaiAction_directive_ptr) _directive;
}

void SdaiDirected_action::directive_( const SdaiAction_directive_ptr x ) {
    _directive = x;
}

void init_SdaiDirected_action( Registry& reg ) {
    std::string str;

    config_control_design::e_directed_action->AddSupertype(config_control_design::e_executed_action);
    config_control_design::e_executed_action->AddSubtype(config_control_design::e_directed_action);
    config_control_design::a_381directive =
      new AttrDescriptor( "directive", config_control_design::e_action_directive, LFalse,
       LFalse, AttrType_Explicit, *config_control_design::e_directed_action);
        config_control_design::e_directed_action->AddExplicitAttr (config_control_design::a_381directive);
        reg.AddEntity( *config_control_design::e_directed_action );
}

#endif

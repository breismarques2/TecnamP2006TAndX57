#ifndef  ENTITY_SDAISHELL_BASED_WIREFRAME_MODEL_CC
#define  ENTITY_SDAISHELL_BASED_WIREFRAME_MODEL_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiShell_based_wireframe_model.h"

EntityDescriptor * config_control_design::e_shell_based_wireframe_model = 0;
AttrDescriptor * config_control_design::a_272sbwm_boundary = 0;

SdaiShell_based_wireframe_model::SdaiShell_based_wireframe_model(): SdaiGeometric_representation_item(), _sbwm_boundary( 0 ) {
        /*  parent: SdaiGeometric_representation_item  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_shell_based_wireframe_model;
    _sbwm_boundary = new SdaiShell_agg;
    STEPattribute * a = new STEPattribute( * config_control_design::a_272sbwm_boundary, _sbwm_boundary );
    a->set_null();
    attributes.push( a );
    MakeDerived( "dim", "geometric_representation_item" );
}

SdaiShell_based_wireframe_model::SdaiShell_based_wireframe_model ( SdaiShell_based_wireframe_model & e ) : SdaiGeometric_representation_item() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiShell_based_wireframe_model::~SdaiShell_based_wireframe_model() {
    delete _sbwm_boundary;
}

SdaiShell_based_wireframe_model::SdaiShell_based_wireframe_model( SDAI_Application_instance * se, bool addAttrs ) : SdaiGeometric_representation_item( se, addAttrs ), _sbwm_boundary( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiGeometric_representation_item */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_shell_based_wireframe_model;
    _sbwm_boundary = new SdaiShell_agg;
    STEPattribute * a = new STEPattribute( * config_control_design::a_272sbwm_boundary,  _sbwm_boundary );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    MakeDerived( "dim", "geometric_representation_item" );
}


SdaiShell_agg_ptr SdaiShell_based_wireframe_model::sbwm_boundary_() {
    if( !_sbwm_boundary ) {
        _sbwm_boundary = new SdaiShell_agg;
    }
    return ( SdaiShell_agg_ptr ) _sbwm_boundary;
}

SdaiShell_agg_ptr_c SdaiShell_based_wireframe_model::sbwm_boundary_() const {
    return ( SdaiShell_agg_ptr ) _sbwm_boundary;
}

void SdaiShell_based_wireframe_model::sbwm_boundary_( const SdaiShell_agg_ptr x ) {
    if( !_sbwm_boundary ) {
        _sbwm_boundary = new SdaiShell_agg;
    }
    _sbwm_boundary->ShallowCopy( * x );
}

void init_SdaiShell_based_wireframe_model( Registry& reg ) {
    std::string str;

    config_control_design::e_shell_based_wireframe_model->_where_rules = new Where_rule__list;
        Where_rule * wr;
        str.clear();
        str.append( "wr1: (" );
    str.append( "constraints_geometry_shell_based_wireframe_model( SELF )\n" );
        str.append( ");\n" );
        wr = new Where_rule( str.c_str() );
        config_control_design::e_shell_based_wireframe_model->_where_rules->Append( wr );
    config_control_design::e_shell_based_wireframe_model->AddSupertype(config_control_design::e_geometric_representation_item);
    config_control_design::e_geometric_representation_item->AddSubtype(config_control_design::e_shell_based_wireframe_model);
        SetTypeDescriptor * t_50 = new SetTypeDescriptor;
        t_50->AssignAggrCreator((AggregateCreator) create_SdaiShell_agg);        // Creator function
        t_50->SetBound1( 1 );
        t_50->SetBound2( 2147483647 );
        t_50->FundamentalType(SET_TYPE);
        t_50->Description("SET [1:?] OF shell");
        t_50->OriginatingSchema(config_control_design::schema);
        t_50->ReferentType(config_control_design::t_shell);
        config_control_design::schema->AddUnnamedType(t_50);
        config_control_design::a_272sbwm_boundary =
          new AttrDescriptor("sbwm_boundary",t_50,LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_shell_based_wireframe_model);
        config_control_design::e_shell_based_wireframe_model->AddExplicitAttr (config_control_design::a_272sbwm_boundary);
        reg.AddEntity( *config_control_design::e_shell_based_wireframe_model );
}

#endif
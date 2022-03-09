#ifndef  ENTITY_SDAICONNECTED_EDGE_SET_CC
#define  ENTITY_SDAICONNECTED_EDGE_SET_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiConnected_edge_set.h"

EntityDescriptor * config_control_design::e_connected_edge_set = 0;
AttrDescriptor * config_control_design::a_402ces_edges = 0;

SdaiConnected_edge_set::SdaiConnected_edge_set(): SdaiTopological_representation_item(), _ces_edges( 0 ) {
        /*  parent: SdaiTopological_representation_item  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_connected_edge_set;
    _ces_edges = new EntityAggregate;
    STEPattribute * a = new STEPattribute( * config_control_design::a_402ces_edges, _ces_edges );
    a->set_null();
    attributes.push( a );
}

SdaiConnected_edge_set::SdaiConnected_edge_set ( SdaiConnected_edge_set & e ) : SdaiTopological_representation_item() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiConnected_edge_set::~SdaiConnected_edge_set() {
    delete _ces_edges;
}

SdaiConnected_edge_set::SdaiConnected_edge_set( SDAI_Application_instance * se, bool addAttrs ) : SdaiTopological_representation_item( se, addAttrs ), _ces_edges( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiTopological_representation_item */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_connected_edge_set;
    _ces_edges = new EntityAggregate;
    STEPattribute * a = new STEPattribute( * config_control_design::a_402ces_edges,  _ces_edges );
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


EntityAggregate_ptr SdaiConnected_edge_set::ces_edges_() {
    if( !_ces_edges ) {
        _ces_edges = new EntityAggregate;
    }
    return ( EntityAggregate_ptr ) _ces_edges;
}

EntityAggregate_ptr_c SdaiConnected_edge_set::ces_edges_() const {
    return ( EntityAggregate_ptr ) _ces_edges;
}

void SdaiConnected_edge_set::ces_edges_( const EntityAggregate_ptr x ) {
    if( !_ces_edges ) {
        _ces_edges = new EntityAggregate;
    }
    _ces_edges->ShallowCopy( * x );
}

void init_SdaiConnected_edge_set( Registry& reg ) {
    std::string str;

    config_control_design::e_connected_edge_set->AddSupertype(config_control_design::e_topological_representation_item);
    config_control_design::e_topological_representation_item->AddSubtype(config_control_design::e_connected_edge_set);
        SetTypeDescriptor * t_73 = new SetTypeDescriptor;
        t_73->AssignAggrCreator((AggregateCreator) create_EntityAggregate);        // Creator function
        t_73->SetBound1( 1 );
        t_73->SetBound2( 2147483647 );
        t_73->FundamentalType(SET_TYPE);
        t_73->Description("SET [1:?] OF edge");
        t_73->OriginatingSchema(config_control_design::schema);
        t_73->ReferentType(config_control_design::e_edge);
        config_control_design::schema->AddUnnamedType(t_73);
        config_control_design::a_402ces_edges =
          new AttrDescriptor("ces_edges",t_73,LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_connected_edge_set);
        config_control_design::e_connected_edge_set->AddExplicitAttr (config_control_design::a_402ces_edges);
        reg.AddEntity( *config_control_design::e_connected_edge_set );
}

#endif
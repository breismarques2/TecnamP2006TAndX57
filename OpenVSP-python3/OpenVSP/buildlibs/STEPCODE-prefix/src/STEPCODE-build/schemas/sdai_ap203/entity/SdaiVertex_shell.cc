#ifndef  ENTITY_SDAIVERTEX_SHELL_CC
#define  ENTITY_SDAIVERTEX_SHELL_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiVertex_shell.h"

EntityDescriptor * config_control_design::e_vertex_shell = 0;
AttrDescriptor * config_control_design::a_372vertex_shell_extent = 0;

SdaiVertex_shell::SdaiVertex_shell(): SdaiTopological_representation_item(), _vertex_shell_extent( 0 ) {
        /*  parent: SdaiTopological_representation_item  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_vertex_shell;
    STEPattribute * a = new STEPattribute( * config_control_design::a_372vertex_shell_extent, ( SDAI_Application_instance_ptr * ) & _vertex_shell_extent );
    a->set_null();
    attributes.push( a );
}

SdaiVertex_shell::SdaiVertex_shell ( SdaiVertex_shell & e ) : SdaiTopological_representation_item() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiVertex_shell::~SdaiVertex_shell() {
}

SdaiVertex_shell::SdaiVertex_shell( SDAI_Application_instance * se, bool addAttrs ) : SdaiTopological_representation_item( se, addAttrs ), _vertex_shell_extent( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiTopological_representation_item */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_vertex_shell;
    STEPattribute * a = new STEPattribute( * config_control_design::a_372vertex_shell_extent, ( SDAI_Application_instance_ptr * ) &_vertex_shell_extent );
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


SdaiVertex_loop_ptr SdaiVertex_shell::vertex_shell_extent_() {
    if( !_vertex_shell_extent ) {
        _vertex_shell_extent = new SdaiVertex_loop;
    }
    return (SdaiVertex_loop_ptr) _vertex_shell_extent;
}

SdaiVertex_loop_ptr_c SdaiVertex_shell::vertex_shell_extent_() const {
    return (SdaiVertex_loop_ptr) _vertex_shell_extent;
}

void SdaiVertex_shell::vertex_shell_extent_( const SdaiVertex_loop_ptr x ) {
    _vertex_shell_extent = x;
}

void init_SdaiVertex_shell( Registry& reg ) {
    std::string str;

    config_control_design::e_vertex_shell->AddSupertype(config_control_design::e_topological_representation_item);
    config_control_design::e_topological_representation_item->AddSubtype(config_control_design::e_vertex_shell);
    config_control_design::a_372vertex_shell_extent =
      new AttrDescriptor( "vertex_shell_extent", config_control_design::e_vertex_loop, LFalse,
       LFalse, AttrType_Explicit, *config_control_design::e_vertex_shell);
        config_control_design::e_vertex_shell->AddExplicitAttr (config_control_design::a_372vertex_shell_extent);
        reg.AddEntity( *config_control_design::e_vertex_shell );
}

#endif

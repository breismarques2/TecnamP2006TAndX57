#ifndef  ENTITY_SDAIBREP_WITH_VOIDS_CC
#define  ENTITY_SDAIBREP_WITH_VOIDS_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiBrep_with_voids.h"

EntityDescriptor * config_control_design::e_brep_with_voids = 0;
AttrDescriptor * config_control_design::a_401voids = 0;

SdaiBrep_with_voids::SdaiBrep_with_voids(): SdaiManifold_solid_brep(), _voids( 0 ) {
        /*  parent: SdaiManifold_solid_brep  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_brep_with_voids;
    _voids = new EntityAggregate;
    STEPattribute * a = new STEPattribute( * config_control_design::a_401voids, _voids );
    a->set_null();
    attributes.push( a );
    MakeDerived( "dim", "geometric_representation_item" );
}

SdaiBrep_with_voids::SdaiBrep_with_voids ( SdaiBrep_with_voids & e ) : SdaiManifold_solid_brep() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiBrep_with_voids::~SdaiBrep_with_voids() {
    delete _voids;
}

SdaiBrep_with_voids::SdaiBrep_with_voids( SDAI_Application_instance * se, bool addAttrs ) : SdaiManifold_solid_brep( se, addAttrs ), _voids( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiManifold_solid_brep */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_brep_with_voids;
    _voids = new EntityAggregate;
    STEPattribute * a = new STEPattribute( * config_control_design::a_401voids,  _voids );
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


EntityAggregate_ptr SdaiBrep_with_voids::voids_() {
    if( !_voids ) {
        _voids = new EntityAggregate;
    }
    return ( EntityAggregate_ptr ) _voids;
}

EntityAggregate_ptr_c SdaiBrep_with_voids::voids_() const {
    return ( EntityAggregate_ptr ) _voids;
}

void SdaiBrep_with_voids::voids_( const EntityAggregate_ptr x ) {
    if( !_voids ) {
        _voids = new EntityAggregate;
    }
    _voids->ShallowCopy( * x );
}

void init_SdaiBrep_with_voids( Registry& reg ) {
    std::string str;

    config_control_design::e_brep_with_voids->AddSupertype(config_control_design::e_manifold_solid_brep);
    config_control_design::e_manifold_solid_brep->AddSubtype(config_control_design::e_brep_with_voids);
        SetTypeDescriptor * t_72 = new SetTypeDescriptor;
        t_72->AssignAggrCreator((AggregateCreator) create_EntityAggregate);        // Creator function
        t_72->SetBound1( 1 );
        t_72->SetBound2( 2147483647 );
        t_72->FundamentalType(SET_TYPE);
        t_72->Description("SET [1:?] OF oriented_closed_shell");
        t_72->OriginatingSchema(config_control_design::schema);
        t_72->ReferentType(config_control_design::e_oriented_closed_shell);
        config_control_design::schema->AddUnnamedType(t_72);
        config_control_design::a_401voids =
          new AttrDescriptor("voids",t_72,LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_brep_with_voids);
        config_control_design::e_brep_with_voids->AddExplicitAttr (config_control_design::a_401voids);
        reg.AddEntity( *config_control_design::e_brep_with_voids );
}

#endif

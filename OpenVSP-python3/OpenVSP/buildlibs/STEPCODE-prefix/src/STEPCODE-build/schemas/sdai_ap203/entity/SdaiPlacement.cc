#ifndef  ENTITY_SDAIPLACEMENT_CC
#define  ENTITY_SDAIPLACEMENT_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiPlacement.h"

EntityDescriptor * config_control_design::e_placement = 0;
AttrDescriptor * config_control_design::a_13location = 0;

SdaiPlacement::SdaiPlacement(): SdaiGeometric_representation_item(), _location( 0 ) {
        /*  parent: SdaiGeometric_representation_item  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_placement;
    STEPattribute * a = new STEPattribute( * config_control_design::a_13location, ( SDAI_Application_instance_ptr * ) & _location );
    a->set_null();
    attributes.push( a );
    MakeDerived( "dim", "geometric_representation_item" );
}

SdaiPlacement::SdaiPlacement ( SdaiPlacement & e ) : SdaiGeometric_representation_item() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiPlacement::~SdaiPlacement() {
}

SdaiPlacement::SdaiPlacement( SDAI_Application_instance * se, bool addAttrs ) : SdaiGeometric_representation_item( se, addAttrs ), _location( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiGeometric_representation_item */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_placement;
    STEPattribute * a = new STEPattribute( * config_control_design::a_13location, ( SDAI_Application_instance_ptr * ) &_location );
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


SdaiCartesian_point_ptr SdaiPlacement::location_() {
    if( !_location ) {
        _location = new SdaiCartesian_point;
    }
    return (SdaiCartesian_point_ptr) _location;
}

SdaiCartesian_point_ptr_c SdaiPlacement::location_() const {
    return (SdaiCartesian_point_ptr) _location;
}

void SdaiPlacement::location_( const SdaiCartesian_point_ptr x ) {
    _location = x;
}

void init_SdaiPlacement( Registry& reg ) {
    std::string str;

    str.clear();
    str.append( "SUPERTYPE OF ( " );
    str.append( "ONEOF ( axis1_placement, axis2_placement_2d, axis2_placement_3d )\n" );
    str.append( ")" );
    config_control_design::e_placement->AddSupertype_Stmt( str );
    config_control_design::e_placement->AddSupertype(config_control_design::e_geometric_representation_item);
    config_control_design::e_geometric_representation_item->AddSubtype(config_control_design::e_placement);
    config_control_design::a_13location =
      new AttrDescriptor( "location", config_control_design::e_cartesian_point, LFalse,
       LFalse, AttrType_Explicit, *config_control_design::e_placement);
        config_control_design::e_placement->AddExplicitAttr (config_control_design::a_13location);
        reg.AddEntity( *config_control_design::e_placement );
}

#endif

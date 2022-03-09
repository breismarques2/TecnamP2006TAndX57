#ifndef  ENTITY_SDAIAXIS1_PLACEMENT_CC
#define  ENTITY_SDAIAXIS1_PLACEMENT_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiAxis1_placement.h"

EntityDescriptor * config_control_design::e_axis1_placement = 0;
AttrDescriptor * config_control_design::a_14axis = 0;
Derived_attribute * config_control_design::a_15Dz = 0;

SdaiAxis1_placement::SdaiAxis1_placement(): SdaiPlacement(), _axis( 0 ) {
        /*  parent: SdaiPlacement  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_axis1_placement;
    STEPattribute * a = new STEPattribute( * config_control_design::a_14axis, ( SDAI_Application_instance_ptr * ) & _axis );
    a->set_null();
    attributes.push( a );
    MakeDerived( "dim", "geometric_representation_item" );
    MakeDerived( "z", "axis1_placement" );
}

SdaiAxis1_placement::SdaiAxis1_placement ( SdaiAxis1_placement & e ) : SdaiPlacement() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiAxis1_placement::~SdaiAxis1_placement() {
}

SdaiAxis1_placement::SdaiAxis1_placement( SDAI_Application_instance * se, bool addAttrs ) : SdaiPlacement( se, addAttrs ), _axis( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiPlacement */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_axis1_placement;
    STEPattribute * a = new STEPattribute( * config_control_design::a_14axis, ( SDAI_Application_instance_ptr * ) &_axis );
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
    MakeDerived( "z", "axis1_placement" );
}


SdaiDirection_ptr SdaiAxis1_placement::axis_() {
    if( !_axis ) {
        _axis = new SdaiDirection;
    }
    return (SdaiDirection_ptr) _axis;
}

SdaiDirection_ptr_c SdaiAxis1_placement::axis_() const {
    return (SdaiDirection_ptr) _axis;
}

void SdaiAxis1_placement::axis_( const SdaiDirection_ptr x ) {
    _axis = x;
}

void init_SdaiAxis1_placement( Registry& reg ) {
    std::string str;

    config_control_design::e_axis1_placement->_where_rules = new Where_rule__list;
        Where_rule * wr;
        str.clear();
        str.append( "wr1: (" );
    str.append( "SELF\\geometric_representation_item.dim = 3\n" );
        str.append( ");\n" );
        wr = new Where_rule( str.c_str() );
        config_control_design::e_axis1_placement->_where_rules->Append( wr );
    config_control_design::e_axis1_placement->AddSupertype(config_control_design::e_placement);
    config_control_design::e_placement->AddSubtype(config_control_design::e_axis1_placement);
    config_control_design::a_14axis =
      new AttrDescriptor( "axis", config_control_design::e_direction, LTrue,
       LFalse, AttrType_Explicit, *config_control_design::e_axis1_placement);
        config_control_design::e_axis1_placement->AddExplicitAttr (config_control_design::a_14axis);
    config_control_design::a_15Dz =
      new Derived_attribute( "z", config_control_design::e_direction, LFalse,
       LFalse, AttrType_Deriving, *config_control_design::e_axis1_placement);
        config_control_design::e_axis1_placement->AddExplicitAttr (config_control_design::a_15Dz);
        config_control_design::a_15Dz->initializer_("NVL( normalise( axis ), dummy_gri || direction( [0, 0, 1] ) )");
        reg.AddEntity( *config_control_design::e_axis1_placement );
}

#endif

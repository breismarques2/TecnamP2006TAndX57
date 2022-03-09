#ifndef  ENTITY_SDAIAXIS2_PLACEMENT_3D_CC
#define  ENTITY_SDAIAXIS2_PLACEMENT_3D_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiAxis2_placement_3d.h"

EntityDescriptor * config_control_design::e_axis2_placement_3d = 0;
AttrDescriptor * config_control_design::a_275axis = 0;
AttrDescriptor * config_control_design::a_276ref_direction = 0;
Derived_attribute * config_control_design::a_277Dp = 0;

SdaiAxis2_placement_3d::SdaiAxis2_placement_3d(): SdaiPlacement(), _axis( 0 ), _ref_direction( 0 ) {
        /*  parent: SdaiPlacement  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_axis2_placement_3d;
    STEPattribute * a = new STEPattribute( * config_control_design::a_275axis, ( SDAI_Application_instance_ptr * ) & _axis );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_276ref_direction, ( SDAI_Application_instance_ptr * ) & _ref_direction );
    a->set_null();
    attributes.push( a );
    MakeDerived( "dim", "geometric_representation_item" );
    MakeDerived( "p", "axis2_placement_3d" );
}

SdaiAxis2_placement_3d::SdaiAxis2_placement_3d ( SdaiAxis2_placement_3d & e ) : SdaiPlacement() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiAxis2_placement_3d::~SdaiAxis2_placement_3d() {
}

SdaiAxis2_placement_3d::SdaiAxis2_placement_3d( SDAI_Application_instance * se, bool addAttrs ) : SdaiPlacement( se, addAttrs ), _axis( 0 ), _ref_direction( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiPlacement */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_axis2_placement_3d;
    STEPattribute * a = new STEPattribute( * config_control_design::a_275axis, ( SDAI_Application_instance_ptr * ) &_axis );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_276ref_direction, ( SDAI_Application_instance_ptr * ) &_ref_direction );
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
    MakeDerived( "p", "axis2_placement_3d" );
}


SdaiDirection_ptr SdaiAxis2_placement_3d::axis_() {
    if( !_axis ) {
        _axis = new SdaiDirection;
    }
    return (SdaiDirection_ptr) _axis;
}

SdaiDirection_ptr_c SdaiAxis2_placement_3d::axis_() const {
    return (SdaiDirection_ptr) _axis;
}

void SdaiAxis2_placement_3d::axis_( const SdaiDirection_ptr x ) {
    _axis = x;
}

SdaiDirection_ptr SdaiAxis2_placement_3d::ref_direction_() {
    if( !_ref_direction ) {
        _ref_direction = new SdaiDirection;
    }
    return (SdaiDirection_ptr) _ref_direction;
}

SdaiDirection_ptr_c SdaiAxis2_placement_3d::ref_direction_() const {
    return (SdaiDirection_ptr) _ref_direction;
}

void SdaiAxis2_placement_3d::ref_direction_( const SdaiDirection_ptr x ) {
    _ref_direction = x;
}

void init_SdaiAxis2_placement_3d( Registry& reg ) {
    std::string str;

    config_control_design::e_axis2_placement_3d->_where_rules = new Where_rule__list;
        Where_rule * wr;
        str.clear();
        str.append( "wr1: (" );
    str.append( "SELF\\placement.location.dim = 3\n" );
        str.append( ");\n" );
        wr = new Where_rule( str.c_str() );
        config_control_design::e_axis2_placement_3d->_where_rules->Append( wr );
        str.clear();
        str.append( "wr2: (" );
    str.append( "( NOT EXISTS( axis ) ) OR ( axis.dim = 3 )\n" );
        str.append( ");\n" );
        wr = new Where_rule( str.c_str() );
        config_control_design::e_axis2_placement_3d->_where_rules->Append( wr );
        str.clear();
        str.append( "wr3: (" );
    str.append( "( NOT EXISTS( ref_direction ) ) OR ( ref_direction.dim = 3 )\n" );
        str.append( ");\n" );
        wr = new Where_rule( str.c_str() );
        config_control_design::e_axis2_placement_3d->_where_rules->Append( wr );
        str.clear();
        str.append( "wr4: (" );
    str.append( "( NOT EXISTS( axis ) ) OR ( NOT EXISTS( ref_direction ) ) OR ( cross_product( axis, ref_direction ).magnitude > 0 )\n" );
        str.append( ");\n" );
        wr = new Where_rule( str.c_str() );
        config_control_design::e_axis2_placement_3d->_where_rules->Append( wr );
    config_control_design::e_axis2_placement_3d->AddSupertype(config_control_design::e_placement);
    config_control_design::e_placement->AddSubtype(config_control_design::e_axis2_placement_3d);
    config_control_design::a_275axis =
      new AttrDescriptor( "axis", config_control_design::e_direction, LTrue,
       LFalse, AttrType_Explicit, *config_control_design::e_axis2_placement_3d);
        config_control_design::e_axis2_placement_3d->AddExplicitAttr (config_control_design::a_275axis);
    config_control_design::a_276ref_direction =
      new AttrDescriptor( "ref_direction", config_control_design::e_direction, LTrue,
       LFalse, AttrType_Explicit, *config_control_design::e_axis2_placement_3d);
        config_control_design::e_axis2_placement_3d->AddExplicitAttr (config_control_design::a_276ref_direction);
        ListTypeDescriptor * t_52 = new ListTypeDescriptor;
        t_52->AssignAggrCreator((AggregateCreator) create_EntityAggregate);        // Creator function
        t_52->SetBound1( 3 );
        t_52->SetBound2( 3 );
        t_52->FundamentalType(LIST_TYPE);
        t_52->Description("LIST [3:3] OF direction");
        t_52->OriginatingSchema(config_control_design::schema);
        t_52->ReferentType(config_control_design::e_direction);
        config_control_design::schema->AddUnnamedType(t_52);
        config_control_design::a_277Dp =
          new Derived_attribute("p",t_52,LFalse,LFalse, AttrType_Deriving,
          *config_control_design::e_axis2_placement_3d);
        config_control_design::e_axis2_placement_3d->AddExplicitAttr (config_control_design::a_277Dp);
        config_control_design::a_277Dp->initializer_("build_axes( axis, ref_direction )");
        reg.AddEntity( *config_control_design::e_axis2_placement_3d );
}

#endif

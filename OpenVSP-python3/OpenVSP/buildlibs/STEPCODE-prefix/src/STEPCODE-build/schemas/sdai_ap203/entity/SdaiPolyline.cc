#ifndef  ENTITY_SDAIPOLYLINE_CC
#define  ENTITY_SDAIPOLYLINE_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiPolyline.h"

EntityDescriptor * config_control_design::e_polyline = 0;
AttrDescriptor * config_control_design::a_199points = 0;

SdaiPolyline::SdaiPolyline(): SdaiBounded_curve(), _points( 0 ) {
        /*  parent: SdaiBounded_curve  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_polyline;
    _points = new EntityAggregate;
    STEPattribute * a = new STEPattribute( * config_control_design::a_199points, _points );
    a->set_null();
    attributes.push( a );
    MakeDerived( "dim", "geometric_representation_item" );
}

SdaiPolyline::SdaiPolyline ( SdaiPolyline & e ) : SdaiBounded_curve() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiPolyline::~SdaiPolyline() {
    delete _points;
}

SdaiPolyline::SdaiPolyline( SDAI_Application_instance * se, bool addAttrs ) : SdaiBounded_curve( se, addAttrs ), _points( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiBounded_curve */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_polyline;
    _points = new EntityAggregate;
    STEPattribute * a = new STEPattribute( * config_control_design::a_199points,  _points );
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


EntityAggregate_ptr SdaiPolyline::points_() {
    if( !_points ) {
        _points = new EntityAggregate;
    }
    return ( EntityAggregate_ptr ) _points;
}

EntityAggregate_ptr_c SdaiPolyline::points_() const {
    return ( EntityAggregate_ptr ) _points;
}

void SdaiPolyline::points_( const EntityAggregate_ptr x ) {
    if( !_points ) {
        _points = new EntityAggregate;
    }
    _points->ShallowCopy( * x );
}

void init_SdaiPolyline( Registry& reg ) {
    std::string str;

    config_control_design::e_polyline->AddSupertype(config_control_design::e_bounded_curve);
    config_control_design::e_bounded_curve->AddSubtype(config_control_design::e_polyline);
        ListTypeDescriptor * t_41 = new ListTypeDescriptor;
        t_41->AssignAggrCreator((AggregateCreator) create_EntityAggregate);        // Creator function
        t_41->SetBound1( 2 );
        t_41->SetBound2( 2147483647 );
        t_41->FundamentalType(LIST_TYPE);
        t_41->Description("LIST [2:?] OF cartesian_point");
        t_41->OriginatingSchema(config_control_design::schema);
        t_41->ReferentType(config_control_design::e_cartesian_point);
        config_control_design::schema->AddUnnamedType(t_41);
        config_control_design::a_199points =
          new AttrDescriptor("points",t_41,LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_polyline);
        config_control_design::e_polyline->AddExplicitAttr (config_control_design::a_199points);
        reg.AddEntity( *config_control_design::e_polyline );
}

#endif
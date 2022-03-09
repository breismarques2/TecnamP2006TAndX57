#ifndef  ENTITY_SDAIORIENTED_FACE_CC
#define  ENTITY_SDAIORIENTED_FACE_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiOriented_face.h"

EntityDescriptor * config_control_design::e_oriented_face = 0;
AttrDescriptor * config_control_design::a_293face_element = 0;
AttrDescriptor * config_control_design::a_294orientation = 0;
Derived_attribute * config_control_design::a_295Dface_bounds = 0;

SdaiOriented_face::SdaiOriented_face(): SdaiFace(), _face_element( 0 ) {
        /*  parent: SdaiFace  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_oriented_face;
    STEPattribute * a = new STEPattribute( * config_control_design::a_293face_element, ( SDAI_Application_instance_ptr * ) & _face_element );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_294orientation, & _orientation );
    a->set_null();
    attributes.push( a );
    MakeDerived( "bounds", "face" );
}

SdaiOriented_face::SdaiOriented_face ( SdaiOriented_face & e ) : SdaiFace() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiOriented_face::~SdaiOriented_face() {
}

SdaiOriented_face::SdaiOriented_face( SDAI_Application_instance * se, bool addAttrs ) : SdaiFace( se, addAttrs ), _face_element( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiFace */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_oriented_face;
    STEPattribute * a = new STEPattribute( * config_control_design::a_293face_element, ( SDAI_Application_instance_ptr * ) &_face_element );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_294orientation,  &_orientation );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    MakeDerived( "bounds", "face" );
}


SdaiFace_ptr SdaiOriented_face::face_element_() {
    if( !_face_element ) {
        _face_element = new SdaiFace;
    }
    return (SdaiFace_ptr) _face_element;
}

SdaiFace_ptr_c SdaiOriented_face::face_element_() const {
    return (SdaiFace_ptr) _face_element;
}

void SdaiOriented_face::face_element_( const SdaiFace_ptr x ) {
    _face_element = x;
}

Boolean SdaiOriented_face::orientation_() const {
    return (const Boolean) _orientation;
}

void SdaiOriented_face::orientation_( const Boolean x ) {
    _orientation.put (x);
}

void init_SdaiOriented_face( Registry& reg ) {
    std::string str;

    config_control_design::e_oriented_face->_where_rules = new Where_rule__list;
        Where_rule * wr;
        str.clear();
        str.append( "wr1: (" );
    str.append( "NOT ( 'CONFIG_CONTROL_DESIGN.ORIENTED_FACE' IN TYPEOF( SELF.face_element ) )\n" );
        str.append( ");\n" );
        wr = new Where_rule( str.c_str() );
        config_control_design::e_oriented_face->_where_rules->Append( wr );
    config_control_design::e_oriented_face->AddSupertype(config_control_design::e_face);
    config_control_design::e_face->AddSubtype(config_control_design::e_oriented_face);
    config_control_design::a_293face_element =
      new AttrDescriptor( "face_element", config_control_design::e_face, LFalse,
       LFalse, AttrType_Explicit, *config_control_design::e_oriented_face);
        config_control_design::e_oriented_face->AddExplicitAttr (config_control_design::a_293face_element);
        config_control_design::a_294orientation =
          new AttrDescriptor("orientation",t_sdaiBOOLEAN,
          LFalse,LFalse, AttrType_Explicit,
          *config_control_design::e_oriented_face);
        config_control_design::e_oriented_face->AddExplicitAttr (config_control_design::a_294orientation);
        SetTypeDescriptor * t_56 = new SetTypeDescriptor;
        t_56->AssignAggrCreator((AggregateCreator) create_EntityAggregate);        // Creator function
        t_56->SetBound1( 1 );
        t_56->SetBound2( 2147483647 );
        t_56->FundamentalType(SET_TYPE);
        t_56->Description("SET [1:?] OF face_bound");
        t_56->OriginatingSchema(config_control_design::schema);
        t_56->ReferentType(config_control_design::e_face_bound);
        config_control_design::schema->AddUnnamedType(t_56);
        config_control_design::a_295Dface_bounds =
          new Derived_attribute("face.bounds",t_56,LFalse,LFalse, AttrType_Deriving,
          *config_control_design::e_oriented_face);
        config_control_design::e_oriented_face->AddExplicitAttr (config_control_design::a_295Dface_bounds);
        config_control_design::a_295Dface_bounds->initializer_("conditional_reverse( SELF.orientation, SELF.face_element.bounds )");
        reg.AddEntity( *config_control_design::e_oriented_face );
}

#endif

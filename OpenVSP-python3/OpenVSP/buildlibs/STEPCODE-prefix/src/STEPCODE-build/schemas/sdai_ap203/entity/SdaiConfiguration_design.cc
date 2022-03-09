#ifndef  ENTITY_SDAICONFIGURATION_DESIGN_CC
#define  ENTITY_SDAICONFIGURATION_DESIGN_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiConfiguration_design.h"

EntityDescriptor * config_control_design::e_configuration_design = 0;
AttrDescriptor * config_control_design::a_228configuration = 0;
AttrDescriptor * config_control_design::a_229design = 0;

SdaiConfiguration_design::SdaiConfiguration_design() : _configuration( 0 ), _design( 0 ) {
        /*  no SuperTypes */

    eDesc = config_control_design::e_configuration_design;
    STEPattribute * a = new STEPattribute( * config_control_design::a_228configuration, ( SDAI_Application_instance_ptr * ) & _configuration );
    a->set_null();
    attributes.push( a );
    a = new STEPattribute( * config_control_design::a_229design, ( SDAI_Application_instance_ptr * ) & _design );
    a->set_null();
    attributes.push( a );
}

SdaiConfiguration_design::SdaiConfiguration_design ( SdaiConfiguration_design & e ) : SDAI_Application_instance() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiConfiguration_design::~SdaiConfiguration_design() {
}

SdaiConfiguration_design::SdaiConfiguration_design( SDAI_Application_instance * se, bool addAttrs ) : _configuration( 0 ), _design( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
    ( void ) addAttrs; /* quell potentially unused var */

        /*  no SuperTypes */

    eDesc = config_control_design::e_configuration_design;
    STEPattribute * a = new STEPattribute( * config_control_design::a_228configuration, ( SDAI_Application_instance_ptr * ) &_configuration );
        /* initialize to NULL (even if not optional)  */
    a ->set_null();
        /* Put attribute on this class' attributes list so the access functions still work. */
    attributes.push( a );
        /* Put attribute on the attributes list for the main inheritance heirarchy.  **
        ** The push method rejects duplicates found by comparing attrDescriptor's.   */
    if( addAttrs ) {
        se->attributes.push( a );
    }
    a = new STEPattribute( * config_control_design::a_229design, ( SDAI_Application_instance_ptr * ) &_design );
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


SdaiConfiguration_item_ptr SdaiConfiguration_design::configuration_() {
    if( !_configuration ) {
        _configuration = new SdaiConfiguration_item;
    }
    return (SdaiConfiguration_item_ptr) _configuration;
}

SdaiConfiguration_item_ptr_c SdaiConfiguration_design::configuration_() const {
    return (SdaiConfiguration_item_ptr) _configuration;
}

void SdaiConfiguration_design::configuration_( const SdaiConfiguration_item_ptr x ) {
    _configuration = x;
}

SdaiProduct_definition_formation_ptr SdaiConfiguration_design::design_() {
    if( !_design ) {
        _design = new SdaiProduct_definition_formation;
    }
    return (SdaiProduct_definition_formation_ptr) _design;
}

SdaiProduct_definition_formation_ptr_c SdaiConfiguration_design::design_() const {
    return (SdaiProduct_definition_formation_ptr) _design;
}

void SdaiConfiguration_design::design_( const SdaiProduct_definition_formation_ptr x ) {
    _design = x;
}

void init_SdaiConfiguration_design( Registry& reg ) {
    std::string str;

        config_control_design::e_configuration_design->_uniqueness_rules = new Uniqueness_rule__set;
        Uniqueness_rule * ur;
        str.clear();
    str.append( "UR1 : " );
    str.append( "configuration\n" );
    str.append( ", " );
    str.append( "design\n" );
    ur = new Uniqueness_rule( str.c_str() );
    config_control_design::e_configuration_design->_uniqueness_rules->Append(ur);
    config_control_design::a_228configuration =
      new AttrDescriptor( "configuration", config_control_design::e_configuration_item, LFalse,
       LTrue, AttrType_Explicit, *config_control_design::e_configuration_design);
        config_control_design::e_configuration_design->AddExplicitAttr (config_control_design::a_228configuration);
    config_control_design::a_229design =
      new AttrDescriptor( "design", config_control_design::e_product_definition_formation, LFalse,
       LTrue, AttrType_Explicit, *config_control_design::e_configuration_design);
        config_control_design::e_configuration_design->AddExplicitAttr (config_control_design::a_229design);
        reg.AddEntity( *config_control_design::e_configuration_design );
}

#endif

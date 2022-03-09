#ifndef  ENTITY_SDAICONFIGURATION_EFFECTIVITY_CC
#define  ENTITY_SDAICONFIGURATION_EFFECTIVITY_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "entity/SdaiConfiguration_effectivity.h"

EntityDescriptor * config_control_design::e_configuration_effectivity = 0;
AttrDescriptor * config_control_design::a_309configuration = 0;

SdaiConfiguration_effectivity::SdaiConfiguration_effectivity(): SdaiProduct_definition_effectivity(), _configuration( 0 ) {
        /*  parent: SdaiProduct_definition_effectivity  */
        /* Ignore the first parent since it is */
        /* part of the main inheritance hierarchy */

    eDesc = config_control_design::e_configuration_effectivity;
    STEPattribute * a = new STEPattribute( * config_control_design::a_309configuration, ( SDAI_Application_instance_ptr * ) & _configuration );
    a->set_null();
    attributes.push( a );
}

SdaiConfiguration_effectivity::SdaiConfiguration_effectivity ( SdaiConfiguration_effectivity & e ) : SdaiProduct_definition_effectivity() {
    CopyAs( ( SDAI_Application_instance_ptr ) & e );
}

SdaiConfiguration_effectivity::~SdaiConfiguration_effectivity() {
}

SdaiConfiguration_effectivity::SdaiConfiguration_effectivity( SDAI_Application_instance * se, bool addAttrs ) : SdaiProduct_definition_effectivity( se, addAttrs ), _configuration( 0 ) {
    /* Set this to point to the head entity. */
    HeadEntity(se);
        /* parent: SdaiProduct_definition_effectivity */
        /* Ignore the first parent since it is part *
        ** of the main inheritance hierarchy        */

    eDesc = config_control_design::e_configuration_effectivity;
    STEPattribute * a = new STEPattribute( * config_control_design::a_309configuration, ( SDAI_Application_instance_ptr * ) &_configuration );
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


SdaiConfiguration_design_ptr SdaiConfiguration_effectivity::configuration_() {
    if( !_configuration ) {
        _configuration = new SdaiConfiguration_design;
    }
    return (SdaiConfiguration_design_ptr) _configuration;
}

SdaiConfiguration_design_ptr_c SdaiConfiguration_effectivity::configuration_() const {
    return (SdaiConfiguration_design_ptr) _configuration;
}

void SdaiConfiguration_effectivity::configuration_( const SdaiConfiguration_design_ptr x ) {
    _configuration = x;
}

void init_SdaiConfiguration_effectivity( Registry& reg ) {
    std::string str;

    config_control_design::e_configuration_effectivity->_where_rules = new Where_rule__list;
        Where_rule * wr;
        str.clear();
        str.append( "wr1: (" );
    str.append( " 'CONFIG_CONTROL_DESIGN.PRODUCT_DEFINITION_USAGE' IN TYPEOF( SELF\\product_definition_effectivity.usage )\n" );
        str.append( ");\n" );
        wr = new Where_rule( str.c_str() );
        config_control_design::e_configuration_effectivity->_where_rules->Append( wr );
        config_control_design::e_configuration_effectivity->_uniqueness_rules = new Uniqueness_rule__set;
        Uniqueness_rule * ur;
        str.clear();
    str.append( "UR1 : " );
    str.append( "configuration\n" );
    str.append( ", " );
    str.append( "usage\n" );
    str.append( ", " );
    str.append( "id\n" );
    ur = new Uniqueness_rule( str.c_str() );
    config_control_design::e_configuration_effectivity->_uniqueness_rules->Append(ur);
    config_control_design::e_configuration_effectivity->AddSupertype(config_control_design::e_product_definition_effectivity);
    config_control_design::e_product_definition_effectivity->AddSubtype(config_control_design::e_configuration_effectivity);
    config_control_design::a_309configuration =
      new AttrDescriptor( "configuration", config_control_design::e_configuration_design, LFalse,
       LTrue, AttrType_Explicit, *config_control_design::e_configuration_effectivity);
        config_control_design::e_configuration_effectivity->AddExplicitAttr (config_control_design::a_309configuration);
        reg.AddEntity( *config_control_design::e_configuration_effectivity );
}

#endif
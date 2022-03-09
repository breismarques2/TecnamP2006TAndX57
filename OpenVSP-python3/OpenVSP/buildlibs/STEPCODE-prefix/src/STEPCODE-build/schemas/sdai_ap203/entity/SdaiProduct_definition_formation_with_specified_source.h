#ifndef  ENTITY_SDAIPRODUCT_DEFINITION_FORMATION_WITH_SPECIFIED_SOURCE_H
#define  ENTITY_SDAIPRODUCT_DEFINITION_FORMATION_WITH_SPECIFIED_SOURCE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiProduct_definition_formation_with_specified_source : public SdaiProduct_definition_formation {
     protected:
        SdaiSource_var _make_or_buy;
    public: 
        SdaiProduct_definition_formation_with_specified_source();
        SdaiProduct_definition_formation_with_specified_source( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiProduct_definition_formation_with_specified_source( SdaiProduct_definition_formation_with_specified_source & e );
        ~SdaiProduct_definition_formation_with_specified_source();
        int opcode() {
            return 19;
        }
  const SdaiSource_var   make_or_buy_() const;
        SdaiSource_var   make_or_buy_();
        void make_or_buy_( const SdaiSource_var x );

};

inline SdaiProduct_definition_formation_with_specified_source * create_SdaiProduct_definition_formation_with_specified_source() {
    return new SdaiProduct_definition_formation_with_specified_source;
}

void init_SdaiProduct_definition_formation_with_specified_source(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_product_definition_formation_with_specified_source;
    extern AttrDescriptor *a_32make_or_buy;
}

#endif
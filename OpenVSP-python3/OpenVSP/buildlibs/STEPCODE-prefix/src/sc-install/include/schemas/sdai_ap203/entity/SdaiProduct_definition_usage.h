#ifndef  ENTITY_SDAIPRODUCT_DEFINITION_USAGE_H
#define  ENTITY_SDAIPRODUCT_DEFINITION_USAGE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiProduct_definition_usage : public SdaiProduct_definition_relationship {
     protected:
    public: 
        SdaiProduct_definition_usage();
        SdaiProduct_definition_usage( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiProduct_definition_usage( SdaiProduct_definition_usage & e );
        ~SdaiProduct_definition_usage();
        int opcode() {
            return 125;
        }
};

inline SdaiProduct_definition_usage * create_SdaiProduct_definition_usage() {
    return new SdaiProduct_definition_usage;
}

void init_SdaiProduct_definition_usage(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_product_definition_usage;
}

#endif
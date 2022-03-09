#ifndef  ENTITY_SDAIPRODUCT_DEFINITION_SHAPE_H
#define  ENTITY_SDAIPRODUCT_DEFINITION_SHAPE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiProduct_definition_shape : public SdaiProperty_definition {
     protected:
    public: 
        SdaiProduct_definition_shape();
        SdaiProduct_definition_shape( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiProduct_definition_shape( SdaiProduct_definition_shape & e );
        ~SdaiProduct_definition_shape();
        int opcode() {
            return 118;
        }
};

inline SdaiProduct_definition_shape * create_SdaiProduct_definition_shape() {
    return new SdaiProduct_definition_shape;
}

void init_SdaiProduct_definition_shape(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_product_definition_shape;
}

#endif
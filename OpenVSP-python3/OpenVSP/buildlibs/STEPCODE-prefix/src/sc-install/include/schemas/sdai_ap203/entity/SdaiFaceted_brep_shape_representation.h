#ifndef  ENTITY_SDAIFACETED_BREP_SHAPE_REPRESENTATION_H
#define  ENTITY_SDAIFACETED_BREP_SHAPE_REPRESENTATION_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiFaceted_brep_shape_representation : public SdaiShape_representation {
     protected:
    public: 
        SdaiFaceted_brep_shape_representation();
        SdaiFaceted_brep_shape_representation( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiFaceted_brep_shape_representation( SdaiFaceted_brep_shape_representation & e );
        ~SdaiFaceted_brep_shape_representation();
        int opcode() {
            return 3;
        }
};

inline SdaiFaceted_brep_shape_representation * create_SdaiFaceted_brep_shape_representation() {
    return new SdaiFaceted_brep_shape_representation;
}

void init_SdaiFaceted_brep_shape_representation(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_faceted_brep_shape_representation;
}

#endif
#ifndef  ENTITY_SDAIADVANCED_FACE_H
#define  ENTITY_SDAIADVANCED_FACE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiAdvanced_face : public SdaiFace_surface {
     protected:
    public: 
        SdaiAdvanced_face();
        SdaiAdvanced_face( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiAdvanced_face( SdaiAdvanced_face & e );
        ~SdaiAdvanced_face();
        int opcode() {
            return 245;
        }
};

inline SdaiAdvanced_face * create_SdaiAdvanced_face() {
    return new SdaiAdvanced_face;
}

void init_SdaiAdvanced_face(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_advanced_face;
}

#endif
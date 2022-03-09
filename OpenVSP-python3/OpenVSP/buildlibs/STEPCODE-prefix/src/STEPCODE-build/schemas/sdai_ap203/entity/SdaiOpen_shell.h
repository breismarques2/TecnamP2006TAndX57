#ifndef  ENTITY_SDAIOPEN_SHELL_H
#define  ENTITY_SDAIOPEN_SHELL_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiOpen_shell : public SdaiConnected_face_set {
     protected:
    public: 
        SdaiOpen_shell();
        SdaiOpen_shell( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiOpen_shell( SdaiOpen_shell & e );
        ~SdaiOpen_shell();
        int opcode() {
            return 151;
        }
};

inline SdaiOpen_shell * create_SdaiOpen_shell() {
    return new SdaiOpen_shell;
}

void init_SdaiOpen_shell(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_open_shell;
}

#endif
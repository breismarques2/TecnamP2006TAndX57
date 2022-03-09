#ifndef  ENTITY_SDAIDESIGN_CONTEXT_H
#define  ENTITY_SDAIDESIGN_CONTEXT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiDesign_context : public SdaiProduct_definition_context {
     protected:
    public: 
        SdaiDesign_context();
        SdaiDesign_context( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiDesign_context( SdaiDesign_context & e );
        ~SdaiDesign_context();
        int opcode() {
            return 132;
        }
};

inline SdaiDesign_context * create_SdaiDesign_context() {
    return new SdaiDesign_context;
}

void init_SdaiDesign_context(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_design_context;
}

#endif

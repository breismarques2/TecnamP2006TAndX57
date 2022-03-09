#ifndef  ENTITY_SDAIBOUNDED_SURFACE_H
#define  ENTITY_SDAIBOUNDED_SURFACE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiBounded_surface : public SdaiSurface {
     protected:
    public: 
        SdaiBounded_surface();
        SdaiBounded_surface( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiBounded_surface( SdaiBounded_surface & e );
        ~SdaiBounded_surface();
        int opcode() {
            return 32;
        }
};

inline SdaiBounded_surface * create_SdaiBounded_surface() {
    return new SdaiBounded_surface;
}

void init_SdaiBounded_surface(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_bounded_surface;
}

#endif

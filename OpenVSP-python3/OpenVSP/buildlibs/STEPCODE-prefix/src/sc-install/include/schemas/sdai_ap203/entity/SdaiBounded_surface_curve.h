#ifndef  ENTITY_SDAIBOUNDED_SURFACE_CURVE_H
#define  ENTITY_SDAIBOUNDED_SURFACE_CURVE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiBounded_surface_curve : public SdaiSurface_curve {
     protected:
    public: 
        SdaiBounded_surface_curve();
        SdaiBounded_surface_curve( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiBounded_surface_curve( SdaiBounded_surface_curve & e );
        ~SdaiBounded_surface_curve();
        int opcode() {
            return 83;
        }
};

inline SdaiBounded_surface_curve * create_SdaiBounded_surface_curve() {
    return new SdaiBounded_surface_curve;
}

void init_SdaiBounded_surface_curve(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_bounded_surface_curve;
}

#endif
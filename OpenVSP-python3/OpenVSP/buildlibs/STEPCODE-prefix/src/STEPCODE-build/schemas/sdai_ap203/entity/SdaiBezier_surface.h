#ifndef  ENTITY_SDAIBEZIER_SURFACE_H
#define  ENTITY_SDAIBEZIER_SURFACE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiBezier_surface : public SdaiB_spline_surface {
     protected:
    public: 
        SdaiBezier_surface();
        SdaiBezier_surface( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiBezier_surface( SdaiBezier_surface & e );
        ~SdaiBezier_surface();
        int opcode() {
            return 228;
        }
};

inline SdaiBezier_surface * create_SdaiBezier_surface() {
    return new SdaiBezier_surface;
}

void init_SdaiBezier_surface(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_bezier_surface;
}

#endif

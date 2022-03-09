#ifndef  ENTITY_SDAISEAM_CURVE_H
#define  ENTITY_SDAISEAM_CURVE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiSeam_curve : public SdaiSurface_curve {
     protected:
    public: 
        SdaiSeam_curve();
        SdaiSeam_curve( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiSeam_curve( SdaiSeam_curve & e );
        ~SdaiSeam_curve();
        int opcode() {
            return 119;
        }
};

inline SdaiSeam_curve * create_SdaiSeam_curve() {
    return new SdaiSeam_curve;
}

void init_SdaiSeam_curve(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_seam_curve;
}

#endif
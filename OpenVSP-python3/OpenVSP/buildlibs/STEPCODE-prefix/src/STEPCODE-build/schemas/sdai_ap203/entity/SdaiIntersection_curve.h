#ifndef  ENTITY_SDAIINTERSECTION_CURVE_H
#define  ENTITY_SDAIINTERSECTION_CURVE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiIntersection_curve : public SdaiSurface_curve {
     protected:
    public: 
        SdaiIntersection_curve();
        SdaiIntersection_curve( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiIntersection_curve( SdaiIntersection_curve & e );
        ~SdaiIntersection_curve();
        int opcode() {
            return 239;
        }
};

inline SdaiIntersection_curve * create_SdaiIntersection_curve() {
    return new SdaiIntersection_curve;
}

void init_SdaiIntersection_curve(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_intersection_curve;
}

#endif

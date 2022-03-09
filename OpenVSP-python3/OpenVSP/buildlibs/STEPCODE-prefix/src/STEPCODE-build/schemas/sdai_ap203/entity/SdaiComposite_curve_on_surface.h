#ifndef  ENTITY_SDAICOMPOSITE_CURVE_ON_SURFACE_H
#define  ENTITY_SDAICOMPOSITE_CURVE_ON_SURFACE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiComposite_curve_on_surface : public SdaiComposite_curve {
     protected:
    public: 
        SdaiComposite_curve_on_surface();
        SdaiComposite_curve_on_surface( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiComposite_curve_on_surface( SdaiComposite_curve_on_surface & e );
        ~SdaiComposite_curve_on_surface();
        int opcode() {
            return 56;
        }
};

inline SdaiComposite_curve_on_surface * create_SdaiComposite_curve_on_surface() {
    return new SdaiComposite_curve_on_surface;
}

void init_SdaiComposite_curve_on_surface(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_composite_curve_on_surface;
    extern Derived_attribute *a_119Dbasis_surface;
}

#endif
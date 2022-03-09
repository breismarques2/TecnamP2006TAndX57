#ifndef  ENTITY_SDAIPCURVE_H
#define  ENTITY_SDAIPCURVE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiPcurve : public SdaiCurve {
     protected:
        SDAI_Application_instance_ptr _basis_surface;
        SDAI_Application_instance_ptr _reference_to_curve;
    public: 
        SdaiPcurve();
        SdaiPcurve( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiPcurve( SdaiPcurve & e );
        ~SdaiPcurve();
        int opcode() {
            return 166;
        }
        SdaiSurface_ptr_c basis_surface_() const;
        SdaiSurface_ptr   basis_surface_();
        void basis_surface_( const SdaiSurface_ptr x );

        SdaiDefinitional_representation_ptr_c reference_to_curve_() const;
        SdaiDefinitional_representation_ptr   reference_to_curve_();
        void reference_to_curve_( const SdaiDefinitional_representation_ptr x );

};

inline SdaiPcurve * create_SdaiPcurve() {
    return new SdaiPcurve;
}

void init_SdaiPcurve(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_pcurve;
    extern AttrDescriptor *a_297basis_surface;
    extern AttrDescriptor *a_298reference_to_curve;
}

#endif

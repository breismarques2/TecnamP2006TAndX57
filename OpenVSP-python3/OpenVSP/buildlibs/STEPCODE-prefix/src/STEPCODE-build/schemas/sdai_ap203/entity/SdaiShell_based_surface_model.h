#ifndef  ENTITY_SDAISHELL_BASED_SURFACE_MODEL_H
#define  ENTITY_SDAISHELL_BASED_SURFACE_MODEL_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiShell_based_surface_model : public SdaiGeometric_representation_item {
     protected:
        SdaiShell_agg_ptr _sbsm_boundary;          //  of  shell

    public: 
        SdaiShell_based_surface_model();
        SdaiShell_based_surface_model( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiShell_based_surface_model( SdaiShell_based_surface_model & e );
        ~SdaiShell_based_surface_model();
        int opcode() {
            return 161;
        }
        SdaiShell_agg_ptr_c sbsm_boundary_() const;
        SdaiShell_agg_ptr   sbsm_boundary_();
        void sbsm_boundary_( const SdaiShell_agg_ptr x );

};

inline SdaiShell_based_surface_model * create_SdaiShell_based_surface_model() {
    return new SdaiShell_based_surface_model;
}

void init_SdaiShell_based_surface_model(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_shell_based_surface_model;
    extern AttrDescriptor *a_289sbsm_boundary;
}

#endif

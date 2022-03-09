#ifndef  ENTITY_SDAIDATED_EFFECTIVITY_H
#define  ENTITY_SDAIDATED_EFFECTIVITY_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiDated_effectivity : public SdaiEffectivity {
     protected:
        SDAI_Application_instance_ptr _effectivity_start_date;
        SDAI_Application_instance_ptr _effectivity_end_date;    //  OPTIONAL
    public: 
        SdaiDated_effectivity();
        SdaiDated_effectivity( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiDated_effectivity( SdaiDated_effectivity & e );
        ~SdaiDated_effectivity();
        int opcode() {
            return 226;
        }
        SdaiDate_and_time_ptr_c effectivity_start_date_() const;
        SdaiDate_and_time_ptr   effectivity_start_date_();
        void effectivity_start_date_( const SdaiDate_and_time_ptr x );

        SdaiDate_and_time_ptr_c effectivity_end_date_() const;
        SdaiDate_and_time_ptr   effectivity_end_date_();
        void effectivity_end_date_( const SdaiDate_and_time_ptr x );

};

inline SdaiDated_effectivity * create_SdaiDated_effectivity() {
    return new SdaiDated_effectivity;
}

void init_SdaiDated_effectivity(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_dated_effectivity;
    extern AttrDescriptor *a_396effectivity_start_date;
    extern AttrDescriptor *a_397effectivity_end_date;
}

#endif

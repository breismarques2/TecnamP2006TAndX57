#ifndef  ENTITY_SDAISI_UNIT_H
#define  ENTITY_SDAISI_UNIT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiSi_unit : public SdaiNamed_unit {
     protected:
        SdaiSi_prefix_var _prefix;    //  OPTIONAL
        SdaiSi_unit_name_var _name;
    public: 
        SdaiSi_unit();
        SdaiSi_unit( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiSi_unit( SdaiSi_unit & e );
        ~SdaiSi_unit();
        int opcode() {
            return 207;
        }
  const SdaiSi_prefix_var   prefix_() const;
        SdaiSi_prefix_var   prefix_();
        void prefix_( const SdaiSi_prefix_var x );

  const SdaiSi_unit_name_var   name_() const;
        SdaiSi_unit_name_var   name_();
        void name_( const SdaiSi_unit_name_var x );

};

inline SdaiSi_unit * create_SdaiSi_unit() {
    return new SdaiSi_unit;
}

void init_SdaiSi_unit(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_si_unit;
    extern AttrDescriptor *a_367prefix;
    extern AttrDescriptor *a_368name;
    extern Derived_attribute *a_369Dnamed_unit_dimensions;
}

#endif
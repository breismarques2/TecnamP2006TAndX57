#ifndef  ENTITY_SDAISECURITY_CLASSIFICATION_H
#define  ENTITY_SDAISECURITY_CLASSIFICATION_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiSecurity_classification : public SDAI_Application_instance {
    protected:
        SDAI_String _name;
        SDAI_String _purpose;
        SDAI_Application_instance_ptr _security_level;
    public: 
        SdaiSecurity_classification();
        SdaiSecurity_classification( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiSecurity_classification( SdaiSecurity_classification & e );
        ~SdaiSecurity_classification();
        int opcode() {
            return 235;
        }
  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );

  const SdaiText   purpose_() const;
        SdaiText   purpose_();
        void purpose_( const SdaiText x );

        SdaiSecurity_classification_level_ptr_c security_level_() const;
        SdaiSecurity_classification_level_ptr   security_level_();
        void security_level_( const SdaiSecurity_classification_level_ptr x );

};

inline SdaiSecurity_classification * create_SdaiSecurity_classification() {
    return new SdaiSecurity_classification;
}

void init_SdaiSecurity_classification(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_security_classification;
    extern AttrDescriptor *a_409name;
    extern AttrDescriptor *a_410purpose;
    extern AttrDescriptor *a_411security_level;
}

#endif

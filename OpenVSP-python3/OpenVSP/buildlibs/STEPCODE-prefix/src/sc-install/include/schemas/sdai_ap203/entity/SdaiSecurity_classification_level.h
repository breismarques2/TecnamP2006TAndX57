#ifndef  ENTITY_SDAISECURITY_CLASSIFICATION_LEVEL_H
#define  ENTITY_SDAISECURITY_CLASSIFICATION_LEVEL_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiSecurity_classification_level : public SDAI_Application_instance {
    protected:
        SDAI_String _name;
    public: 
        SdaiSecurity_classification_level();
        SdaiSecurity_classification_level( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiSecurity_classification_level( SdaiSecurity_classification_level & e );
        ~SdaiSecurity_classification_level();
        int opcode() {
            return 53;
        }
  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );

};

inline SdaiSecurity_classification_level * create_SdaiSecurity_classification_level() {
    return new SdaiSecurity_classification_level;
}

void init_SdaiSecurity_classification_level(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_security_classification_level;
    extern AttrDescriptor *a_101name;
}

#endif
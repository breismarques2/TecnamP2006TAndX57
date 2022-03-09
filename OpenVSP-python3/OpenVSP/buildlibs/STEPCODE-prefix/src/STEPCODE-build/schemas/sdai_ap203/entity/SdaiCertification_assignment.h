#ifndef  ENTITY_SDAICERTIFICATION_ASSIGNMENT_H
#define  ENTITY_SDAICERTIFICATION_ASSIGNMENT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiCertification_assignment : public SDAI_Application_instance {
    protected:
        SDAI_Application_instance_ptr _assigned_certification;
    public: 
        SdaiCertification_assignment();
        SdaiCertification_assignment( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiCertification_assignment( SdaiCertification_assignment & e );
        ~SdaiCertification_assignment();
        int opcode() {
            return 168;
        }
        SdaiCertification_ptr_c assigned_certification_() const;
        SdaiCertification_ptr   assigned_certification_();
        void assigned_certification_( const SdaiCertification_ptr x );

};

inline SdaiCertification_assignment * create_SdaiCertification_assignment() {
    return new SdaiCertification_assignment;
}

void init_SdaiCertification_assignment(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_certification_assignment;
    extern AttrDescriptor *a_299assigned_certification;
}

#endif
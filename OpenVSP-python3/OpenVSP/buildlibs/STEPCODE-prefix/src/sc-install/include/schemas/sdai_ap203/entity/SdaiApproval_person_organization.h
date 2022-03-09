#ifndef  ENTITY_SDAIAPPROVAL_PERSON_ORGANIZATION_H
#define  ENTITY_SDAIAPPROVAL_PERSON_ORGANIZATION_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiApproval_person_organization : public SDAI_Application_instance {
    protected:
        SdaiPerson_organization_select _person_organization;
        SDAI_Application_instance_ptr _authorized_approval;
        SDAI_Application_instance_ptr _role;
    public: 
        SdaiApproval_person_organization();
        SdaiApproval_person_organization( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiApproval_person_organization( SdaiApproval_person_organization & e );
        ~SdaiApproval_person_organization();
        int opcode() {
            return 186;
        }
        SdaiPerson_organization_select_ptr_c person_organization_() const;
        SdaiPerson_organization_select_ptr   person_organization_();
        void person_organization_( const SdaiPerson_organization_select_ptr x );

        SdaiApproval_ptr_c authorized_approval_() const;
        SdaiApproval_ptr   authorized_approval_();
        void authorized_approval_( const SdaiApproval_ptr x );

        SdaiApproval_role_ptr_c role_() const;
        SdaiApproval_role_ptr   role_();
        void role_( const SdaiApproval_role_ptr x );

};

inline SdaiApproval_person_organization * create_SdaiApproval_person_organization() {
    return new SdaiApproval_person_organization;
}

void init_SdaiApproval_person_organization(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_approval_person_organization;
    extern AttrDescriptor *a_334person_organization;
    extern AttrDescriptor *a_335authorized_approval;
    extern AttrDescriptor *a_336role;
}

#endif

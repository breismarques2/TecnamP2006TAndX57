#ifndef  ENTITY_SDAIAPPROVAL_ASSIGNMENT_H
#define  ENTITY_SDAIAPPROVAL_ASSIGNMENT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiApproval_assignment : public SDAI_Application_instance {
    protected:
        SDAI_Application_instance_ptr _assigned_approval;
    public: 
        SdaiApproval_assignment();
        SdaiApproval_assignment( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiApproval_assignment( SdaiApproval_assignment & e );
        ~SdaiApproval_assignment();
        int opcode() {
            return 129;
        }
        SdaiApproval_ptr_c assigned_approval_() const;
        SdaiApproval_ptr   assigned_approval_();
        void assigned_approval_( const SdaiApproval_ptr x );

};

inline SdaiApproval_assignment * create_SdaiApproval_assignment() {
    return new SdaiApproval_assignment;
}

void init_SdaiApproval_assignment(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_approval_assignment;
    extern AttrDescriptor *a_244assigned_approval;
}

#endif

#ifndef  ENTITY_SDAIAPPROVAL_DATE_TIME_H
#define  ENTITY_SDAIAPPROVAL_DATE_TIME_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiApproval_date_time : public SDAI_Application_instance {
    protected:
        SdaiDate_time_select _date_time;
        SDAI_Application_instance_ptr _dated_approval;
    public: 
        SdaiApproval_date_time();
        SdaiApproval_date_time( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiApproval_date_time( SdaiApproval_date_time & e );
        ~SdaiApproval_date_time();
        int opcode() {
            return 237;
        }
        SdaiDate_time_select_ptr_c date_time_() const;
        SdaiDate_time_select_ptr   date_time_();
        void date_time_( const SdaiDate_time_select_ptr x );

        SdaiApproval_ptr_c dated_approval_() const;
        SdaiApproval_ptr   dated_approval_();
        void dated_approval_( const SdaiApproval_ptr x );

};

inline SdaiApproval_date_time * create_SdaiApproval_date_time() {
    return new SdaiApproval_date_time;
}

void init_SdaiApproval_date_time(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_approval_date_time;
    extern AttrDescriptor *a_413date_time;
    extern AttrDescriptor *a_414dated_approval;
}

#endif

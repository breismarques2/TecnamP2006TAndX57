#ifndef  ENTITY_SDAIDATE_TIME_ROLE_H
#define  ENTITY_SDAIDATE_TIME_ROLE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiDate_time_role : public SDAI_Application_instance {
    protected:
        SDAI_String _name;
    public: 
        SdaiDate_time_role();
        SdaiDate_time_role( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiDate_time_role( SdaiDate_time_role & e );
        ~SdaiDate_time_role();
        int opcode() {
            return 246;
        }
  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );

};

inline SdaiDate_time_role * create_SdaiDate_time_role() {
    return new SdaiDate_time_role;
}

void init_SdaiDate_time_role(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_date_time_role;
    extern AttrDescriptor *a_429name;
}

#endif
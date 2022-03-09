#ifndef  ENTITY_SDAIPERSON_AND_ORGANIZATION_ROLE_H
#define  ENTITY_SDAIPERSON_AND_ORGANIZATION_ROLE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiPerson_and_organization_role : public SDAI_Application_instance {
    protected:
        SDAI_String _name;
    public: 
        SdaiPerson_and_organization_role();
        SdaiPerson_and_organization_role( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiPerson_and_organization_role( SdaiPerson_and_organization_role & e );
        ~SdaiPerson_and_organization_role();
        int opcode() {
            return 34;
        }
  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );

};

inline SdaiPerson_and_organization_role * create_SdaiPerson_and_organization_role() {
    return new SdaiPerson_and_organization_role;
}

void init_SdaiPerson_and_organization_role(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_person_and_organization_role;
    extern AttrDescriptor *a_53name;
}

#endif

#ifndef  ENTITY_SDAIORGANIZATION_H
#define  ENTITY_SDAIORGANIZATION_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiOrganization : public SDAI_Application_instance {
    protected:
        SDAI_String _id;    //  OPTIONAL
        SDAI_String _name;
        SDAI_String _description;
    public: 
        SdaiOrganization();
        SdaiOrganization( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiOrganization( SdaiOrganization & e );
        ~SdaiOrganization();
        int opcode() {
            return 142;
        }
  const SdaiIdentifier   id_() const;
        SdaiIdentifier   id_();
        void id_( const SdaiIdentifier x );

  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );

  const SdaiText   description_() const;
        SdaiText   description_();
        void description_( const SdaiText x );

};

inline SdaiOrganization * create_SdaiOrganization() {
    return new SdaiOrganization;
}

void init_SdaiOrganization(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_organization;
    extern AttrDescriptor *a_264id;
    extern AttrDescriptor *a_265name;
    extern AttrDescriptor *a_266description;
}

#endif

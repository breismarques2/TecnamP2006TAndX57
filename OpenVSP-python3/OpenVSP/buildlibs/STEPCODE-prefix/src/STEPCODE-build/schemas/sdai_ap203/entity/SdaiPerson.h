#ifndef  ENTITY_SDAIPERSON_H
#define  ENTITY_SDAIPERSON_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiPerson : public SDAI_Application_instance {
    protected:
        SDAI_String _id;
        SDAI_String _last_name;    //  OPTIONAL
        SDAI_String _first_name;    //  OPTIONAL
        StringAggregate_ptr _middle_names;    //  OPTIONAL          //  of  label

        StringAggregate_ptr _prefix_titles;    //  OPTIONAL          //  of  label

        StringAggregate_ptr _suffix_titles;    //  OPTIONAL          //  of  label

    public: 
        SdaiPerson();
        SdaiPerson( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiPerson( SdaiPerson & e );
        ~SdaiPerson();
        int opcode() {
            return 64;
        }
  const SdaiIdentifier   id_() const;
        SdaiIdentifier   id_();
        void id_( const SdaiIdentifier x );

  const SdaiLabel   last_name_() const;
        SdaiLabel   last_name_();
        void last_name_( const SdaiLabel x );

  const SdaiLabel   first_name_() const;
        SdaiLabel   first_name_();
        void first_name_( const SdaiLabel x );

        StringAggregate_ptr_c middle_names_() const;
        StringAggregate_ptr   middle_names_();
        void middle_names_( const StringAggregate_ptr x );

        StringAggregate_ptr_c prefix_titles_() const;
        StringAggregate_ptr   prefix_titles_();
        void prefix_titles_( const StringAggregate_ptr x );

        StringAggregate_ptr_c suffix_titles_() const;
        StringAggregate_ptr   suffix_titles_();
        void suffix_titles_( const StringAggregate_ptr x );

};

inline SdaiPerson * create_SdaiPerson() {
    return new SdaiPerson;
}

void init_SdaiPerson(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_person;
    extern AttrDescriptor *a_130id;
    extern AttrDescriptor *a_131last_name;
    extern AttrDescriptor *a_132first_name;
    extern AttrDescriptor *a_133middle_names;
    extern AttrDescriptor *a_134prefix_titles;
    extern AttrDescriptor *a_135suffix_titles;
}

#endif

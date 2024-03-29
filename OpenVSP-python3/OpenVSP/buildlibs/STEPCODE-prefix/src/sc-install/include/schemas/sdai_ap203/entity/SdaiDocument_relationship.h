#ifndef  ENTITY_SDAIDOCUMENT_RELATIONSHIP_H
#define  ENTITY_SDAIDOCUMENT_RELATIONSHIP_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiDocument_relationship : public SDAI_Application_instance {
    protected:
        SDAI_String _name;
        SDAI_String _description;
        SDAI_Application_instance_ptr _relating_document;
        SDAI_Application_instance_ptr _related_document;
    public: 
        SdaiDocument_relationship();
        SdaiDocument_relationship( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiDocument_relationship( SdaiDocument_relationship & e );
        ~SdaiDocument_relationship();
        int opcode() {
            return 178;
        }
  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );

  const SdaiText   description_() const;
        SdaiText   description_();
        void description_( const SdaiText x );

        SdaiDocument_ptr_c relating_document_() const;
        SdaiDocument_ptr   relating_document_();
        void relating_document_( const SdaiDocument_ptr x );

        SdaiDocument_ptr_c related_document_() const;
        SdaiDocument_ptr   related_document_();
        void related_document_( const SdaiDocument_ptr x );

};

inline SdaiDocument_relationship * create_SdaiDocument_relationship() {
    return new SdaiDocument_relationship;
}

void init_SdaiDocument_relationship(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_document_relationship;
    extern AttrDescriptor *a_314name;
    extern AttrDescriptor *a_315description;
    extern AttrDescriptor *a_316relating_document;
    extern AttrDescriptor *a_317related_document;
}

#endif

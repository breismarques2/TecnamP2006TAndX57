#ifndef  ENTITY_SDAISHAPE_ASPECT_RELATIONSHIP_H
#define  ENTITY_SDAISHAPE_ASPECT_RELATIONSHIP_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiShape_aspect_relationship : public SDAI_Application_instance {
    protected:
        SDAI_String _name;
        SDAI_String _description;
        SDAI_Application_instance_ptr _relating_shape_aspect;
        SDAI_Application_instance_ptr _related_shape_aspect;
    public: 
        SdaiShape_aspect_relationship();
        SdaiShape_aspect_relationship( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiShape_aspect_relationship( SdaiShape_aspect_relationship & e );
        ~SdaiShape_aspect_relationship();
        int opcode() {
            return 47;
        }
  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );

  const SdaiText   description_() const;
        SdaiText   description_();
        void description_( const SdaiText x );

        SdaiShape_aspect_ptr_c relating_shape_aspect_() const;
        SdaiShape_aspect_ptr   relating_shape_aspect_();
        void relating_shape_aspect_( const SdaiShape_aspect_ptr x );

        SdaiShape_aspect_ptr_c related_shape_aspect_() const;
        SdaiShape_aspect_ptr   related_shape_aspect_();
        void related_shape_aspect_( const SdaiShape_aspect_ptr x );

};

inline SdaiShape_aspect_relationship * create_SdaiShape_aspect_relationship() {
    return new SdaiShape_aspect_relationship;
}

void init_SdaiShape_aspect_relationship(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_shape_aspect_relationship;
    extern AttrDescriptor *a_92name;
    extern AttrDescriptor *a_93description;
    extern AttrDescriptor *a_94relating_shape_aspect;
    extern AttrDescriptor *a_95related_shape_aspect;
}

#endif
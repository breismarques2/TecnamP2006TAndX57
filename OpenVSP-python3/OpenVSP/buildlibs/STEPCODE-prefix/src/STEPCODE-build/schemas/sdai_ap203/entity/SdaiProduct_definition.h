#ifndef  ENTITY_SDAIPRODUCT_DEFINITION_H
#define  ENTITY_SDAIPRODUCT_DEFINITION_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiProduct_definition : public SDAI_Application_instance {
    protected:
        SDAI_String _id;
        SDAI_String _description;
        SDAI_Application_instance_ptr _formation;
        SDAI_Application_instance_ptr _frame_of_reference;
    public: 
        SdaiProduct_definition();
        SdaiProduct_definition( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiProduct_definition( SdaiProduct_definition & e );
        ~SdaiProduct_definition();
        int opcode() {
            return 88;
        }
  const SdaiIdentifier   id_() const;
        SdaiIdentifier   id_();
        void id_( const SdaiIdentifier x );

  const SdaiText   description_() const;
        SdaiText   description_();
        void description_( const SdaiText x );

        SdaiProduct_definition_formation_ptr_c formation_() const;
        SdaiProduct_definition_formation_ptr   formation_();
        void formation_( const SdaiProduct_definition_formation_ptr x );

        SdaiProduct_definition_context_ptr_c frame_of_reference_() const;
        SdaiProduct_definition_context_ptr   frame_of_reference_();
        void frame_of_reference_( const SdaiProduct_definition_context_ptr x );

};

inline SdaiProduct_definition * create_SdaiProduct_definition() {
    return new SdaiProduct_definition;
}

void init_SdaiProduct_definition(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_product_definition;
    extern AttrDescriptor *a_178id;
    extern AttrDescriptor *a_179description;
    extern AttrDescriptor *a_180formation;
    extern AttrDescriptor *a_181frame_of_reference;
}

#endif
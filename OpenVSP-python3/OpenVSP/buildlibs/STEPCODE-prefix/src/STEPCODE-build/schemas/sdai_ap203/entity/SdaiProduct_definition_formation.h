#ifndef  ENTITY_SDAIPRODUCT_DEFINITION_FORMATION_H
#define  ENTITY_SDAIPRODUCT_DEFINITION_FORMATION_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiProduct_definition_formation : public SDAI_Application_instance {
    protected:
        SDAI_String _id;
        SDAI_String _description;
        SDAI_Application_instance_ptr _of_product;
    public: 
        SdaiProduct_definition_formation();
        SdaiProduct_definition_formation( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiProduct_definition_formation( SdaiProduct_definition_formation & e );
        ~SdaiProduct_definition_formation();
        int opcode() {
            return 18;
        }
  const SdaiIdentifier   id_() const;
        SdaiIdentifier   id_();
        void id_( const SdaiIdentifier x );

  const SdaiText   description_() const;
        SdaiText   description_();
        void description_( const SdaiText x );

        SdaiProduct_ptr_c of_product_() const;
        SdaiProduct_ptr   of_product_();
        void of_product_( const SdaiProduct_ptr x );

};

inline SdaiProduct_definition_formation * create_SdaiProduct_definition_formation() {
    return new SdaiProduct_definition_formation;
}

void init_SdaiProduct_definition_formation(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_product_definition_formation;
    extern AttrDescriptor *a_29id;
    extern AttrDescriptor *a_30description;
    extern AttrDescriptor *a_31of_product;
}

#endif

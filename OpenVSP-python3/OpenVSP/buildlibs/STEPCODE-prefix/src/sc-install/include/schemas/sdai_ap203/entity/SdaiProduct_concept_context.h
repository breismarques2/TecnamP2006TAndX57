#ifndef  ENTITY_SDAIPRODUCT_CONCEPT_CONTEXT_H
#define  ENTITY_SDAIPRODUCT_CONCEPT_CONTEXT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiProduct_concept_context : public SdaiApplication_context_element {
     protected:
        SDAI_String _market_segment_type;
    public: 
        SdaiProduct_concept_context();
        SdaiProduct_concept_context( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiProduct_concept_context( SdaiProduct_concept_context & e );
        ~SdaiProduct_concept_context();
        int opcode() {
            return 195;
        }
  const SdaiLabel   market_segment_type_() const;
        SdaiLabel   market_segment_type_();
        void market_segment_type_( const SdaiLabel x );

};

inline SdaiProduct_concept_context * create_SdaiProduct_concept_context() {
    return new SdaiProduct_concept_context;
}

void init_SdaiProduct_concept_context(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_product_concept_context;
    extern AttrDescriptor *a_343market_segment_type;
}

#endif
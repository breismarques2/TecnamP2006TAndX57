#ifndef  ENTITY_SDAIPRODUCT_DEFINITION_CONTEXT_H
#define  ENTITY_SDAIPRODUCT_DEFINITION_CONTEXT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiProduct_definition_context : public SdaiApplication_context_element {
     protected:
        SDAI_String _life_cycle_stage;
    public: 
        SdaiProduct_definition_context();
        SdaiProduct_definition_context( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiProduct_definition_context( SdaiProduct_definition_context & e );
        ~SdaiProduct_definition_context();
        int opcode() {
            return 131;
        }
  const SdaiLabel   life_cycle_stage_() const;
        SdaiLabel   life_cycle_stage_();
        void life_cycle_stage_( const SdaiLabel x );

};

inline SdaiProduct_definition_context * create_SdaiProduct_definition_context() {
    return new SdaiProduct_definition_context;
}

void init_SdaiProduct_definition_context(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_product_definition_context;
    extern AttrDescriptor *a_246life_cycle_stage;
}

#endif

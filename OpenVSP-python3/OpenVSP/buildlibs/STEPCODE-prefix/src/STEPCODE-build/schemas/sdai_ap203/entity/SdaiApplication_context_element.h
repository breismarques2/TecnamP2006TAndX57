#ifndef  ENTITY_SDAIAPPLICATION_CONTEXT_ELEMENT_H
#define  ENTITY_SDAIAPPLICATION_CONTEXT_ELEMENT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiApplication_context_element : public SDAI_Application_instance {
    protected:
        SDAI_String _name;
        SDAI_Application_instance_ptr _frame_of_reference;
    public: 
        SdaiApplication_context_element();
        SdaiApplication_context_element( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiApplication_context_element( SdaiApplication_context_element & e );
        ~SdaiApplication_context_element();
        int opcode() {
            return 110;
        }
  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );

        SdaiApplication_context_ptr_c frame_of_reference_() const;
        SdaiApplication_context_ptr   frame_of_reference_();
        void frame_of_reference_( const SdaiApplication_context_ptr x );

};

inline SdaiApplication_context_element * create_SdaiApplication_context_element() {
    return new SdaiApplication_context_element;
}

void init_SdaiApplication_context_element(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_application_context_element;
    extern AttrDescriptor *a_214name;
    extern AttrDescriptor *a_215frame_of_reference;
}

#endif

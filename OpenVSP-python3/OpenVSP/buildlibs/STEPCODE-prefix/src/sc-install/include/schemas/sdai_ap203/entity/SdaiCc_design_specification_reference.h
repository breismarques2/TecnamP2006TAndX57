#ifndef  ENTITY_SDAICC_DESIGN_SPECIFICATION_REFERENCE_H
#define  ENTITY_SDAICC_DESIGN_SPECIFICATION_REFERENCE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiCc_design_specification_reference : public SdaiDocument_reference {
     protected:
        SdaiSpecified_item_agg_ptr _items;          //  of  specified_item

    public: 
        SdaiCc_design_specification_reference();
        SdaiCc_design_specification_reference( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiCc_design_specification_reference( SdaiCc_design_specification_reference & e );
        ~SdaiCc_design_specification_reference();
        int opcode() {
            return 220;
        }
        SdaiSpecified_item_agg_ptr_c items_() const;
        SdaiSpecified_item_agg_ptr   items_();
        void items_( const SdaiSpecified_item_agg_ptr x );

};

inline SdaiCc_design_specification_reference * create_SdaiCc_design_specification_reference() {
    return new SdaiCc_design_specification_reference;
}

void init_SdaiCc_design_specification_reference(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_cc_design_specification_reference;
    extern AttrDescriptor *a_384items;
}

#endif
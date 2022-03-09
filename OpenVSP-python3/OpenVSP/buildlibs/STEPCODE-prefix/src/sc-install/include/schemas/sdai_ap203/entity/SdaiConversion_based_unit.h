#ifndef  ENTITY_SDAICONVERSION_BASED_UNIT_H
#define  ENTITY_SDAICONVERSION_BASED_UNIT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiConversion_based_unit : public SdaiNamed_unit {
     protected:
        SDAI_String _name;
        SDAI_Application_instance_ptr _conversion_factor;
    public: 
        SdaiConversion_based_unit();
        SdaiConversion_based_unit( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiConversion_based_unit( SdaiConversion_based_unit & e );
        ~SdaiConversion_based_unit();
        int opcode() {
            return 199;
        }
  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );

        SdaiMeasure_with_unit_ptr_c conversion_factor_() const;
        SdaiMeasure_with_unit_ptr   conversion_factor_();
        void conversion_factor_( const SdaiMeasure_with_unit_ptr x );

};

inline SdaiConversion_based_unit * create_SdaiConversion_based_unit() {
    return new SdaiConversion_based_unit;
}

void init_SdaiConversion_based_unit(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_conversion_based_unit;
    extern AttrDescriptor *a_350name;
    extern AttrDescriptor *a_351conversion_factor;
}

#endif
#ifndef  ENTITY_SDAIVECTOR_H
#define  ENTITY_SDAIVECTOR_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiVector : public SdaiGeometric_representation_item {
     protected:
        SDAI_Application_instance_ptr _orientation;
        SDAI_Real _magnitude;
    public: 
        SdaiVector();
        SdaiVector( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiVector( SdaiVector & e );
        ~SdaiVector();
        int opcode() {
            return 135;
        }
        SdaiDirection_ptr_c orientation_() const;
        SdaiDirection_ptr   orientation_();
        void orientation_( const SdaiDirection_ptr x );

        SdaiLength_measure   magnitude_() const;
        void magnitude_( const SdaiLength_measure x );

};

inline SdaiVector * create_SdaiVector() {
    return new SdaiVector;
}

void init_SdaiVector(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_vector;
    extern AttrDescriptor *a_250orientation;
    extern AttrDescriptor *a_251magnitude;
}

#endif

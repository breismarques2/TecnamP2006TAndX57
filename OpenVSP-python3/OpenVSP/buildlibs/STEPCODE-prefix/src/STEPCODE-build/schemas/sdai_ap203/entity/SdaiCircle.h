#ifndef  ENTITY_SDAICIRCLE_H
#define  ENTITY_SDAICIRCLE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiCircle : public SdaiConic {
     protected:
        SDAI_Real _radius;
    public: 
        SdaiCircle();
        SdaiCircle( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiCircle( SdaiCircle & e );
        ~SdaiCircle();
        int opcode() {
            return 172;
        }
        SdaiPositive_length_measure   radius_() const;
        void radius_( const SdaiPositive_length_measure x );

};

inline SdaiCircle * create_SdaiCircle() {
    return new SdaiCircle;
}

void init_SdaiCircle(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_circle;
    extern AttrDescriptor *a_302radius;
}

#endif
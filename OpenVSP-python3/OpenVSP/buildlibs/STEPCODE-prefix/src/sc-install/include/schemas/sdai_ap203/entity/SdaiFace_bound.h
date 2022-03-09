#ifndef  ENTITY_SDAIFACE_BOUND_H
#define  ENTITY_SDAIFACE_BOUND_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiFace_bound : public SdaiTopological_representation_item {
     protected:
        SDAI_Application_instance_ptr _bound;
        SDAI_BOOLEAN _orientation;
    public: 
        SdaiFace_bound();
        SdaiFace_bound( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiFace_bound( SdaiFace_bound & e );
        ~SdaiFace_bound();
        int opcode() {
            return 162;
        }
        SdaiLoop_ptr_c bound_() const;
        SdaiLoop_ptr   bound_();
        void bound_( const SdaiLoop_ptr x );

        Boolean   orientation_() const;
        void orientation_( const Boolean x );

};

inline SdaiFace_bound * create_SdaiFace_bound() {
    return new SdaiFace_bound;
}

void init_SdaiFace_bound(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_face_bound;
    extern AttrDescriptor *a_290bound;
    extern AttrDescriptor *a_291orientation;
}

#endif
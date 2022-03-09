#ifndef  ENTITY_SDAIPLACEMENT_H
#define  ENTITY_SDAIPLACEMENT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiPlacement : public SdaiGeometric_representation_item {
     protected:
        SDAI_Application_instance_ptr _location;
    public: 
        SdaiPlacement();
        SdaiPlacement( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiPlacement( SdaiPlacement & e );
        ~SdaiPlacement();
        int opcode() {
            return 9;
        }
        SdaiCartesian_point_ptr_c location_() const;
        SdaiCartesian_point_ptr   location_();
        void location_( const SdaiCartesian_point_ptr x );

};

inline SdaiPlacement * create_SdaiPlacement() {
    return new SdaiPlacement;
}

void init_SdaiPlacement(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_placement;
    extern AttrDescriptor *a_13location;
}

#endif

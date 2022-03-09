#ifndef  ENTITY_SDAIAXIS2_PLACEMENT_2D_H
#define  ENTITY_SDAIAXIS2_PLACEMENT_2D_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiAxis2_placement_2d : public SdaiPlacement {
     protected:
        SDAI_Application_instance_ptr _ref_direction;    //  OPTIONAL
    public: 
        SdaiAxis2_placement_2d();
        SdaiAxis2_placement_2d( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiAxis2_placement_2d( SdaiAxis2_placement_2d & e );
        ~SdaiAxis2_placement_2d();
        int opcode() {
            return 215;
        }
        SdaiDirection_ptr_c ref_direction_() const;
        SdaiDirection_ptr   ref_direction_();
        void ref_direction_( const SdaiDirection_ptr x );

};

inline SdaiAxis2_placement_2d * create_SdaiAxis2_placement_2d() {
    return new SdaiAxis2_placement_2d;
}

void init_SdaiAxis2_placement_2d(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_axis2_placement_2d;
    extern AttrDescriptor *a_379ref_direction;
    extern Derived_attribute *a_380Dp;
}

#endif

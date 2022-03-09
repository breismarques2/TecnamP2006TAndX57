#ifndef  ENTITY_SDAIRECTANGULAR_COMPOSITE_SURFACE_H
#define  ENTITY_SDAIRECTANGULAR_COMPOSITE_SURFACE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiRectangular_composite_surface : public SdaiBounded_surface {
     protected:
        GenericAggregate_ptr _segments;          //  of  surface_patch

    public: 
        SdaiRectangular_composite_surface();
        SdaiRectangular_composite_surface( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiRectangular_composite_surface( SdaiRectangular_composite_surface & e );
        ~SdaiRectangular_composite_surface();
        int opcode() {
            return 33;
        }
        GenericAggregate_ptr_c segments_() const;
        GenericAggregate_ptr   segments_();
        void segments_( const GenericAggregate_ptr x );

};

inline SdaiRectangular_composite_surface * create_SdaiRectangular_composite_surface() {
    return new SdaiRectangular_composite_surface;
}

void init_SdaiRectangular_composite_surface(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_rectangular_composite_surface;
    extern AttrDescriptor *a_50segments;
    extern Derived_attribute *a_51Dn_u;
    extern Derived_attribute *a_52Dn_v;
}

#endif
#ifndef  ENTITY_SDAIB_SPLINE_CURVE_H
#define  ENTITY_SDAIB_SPLINE_CURVE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiB_spline_curve : public SdaiBounded_curve {
     protected:
        SDAI_Integer _degree;
        EntityAggregate_ptr _control_points_list;          //  of  cartesian_point

        SdaiB_spline_curve_form_var _curve_form;
        SDAI_LOGICAL _closed_curve;
        SDAI_LOGICAL _self_intersect;
    public: 
        SdaiB_spline_curve();
        SdaiB_spline_curve( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiB_spline_curve( SdaiB_spline_curve & e );
        ~SdaiB_spline_curve();
        int opcode() {
            return 13;
        }
        SDAI_Integer   degree_() const;
        void degree_( const SDAI_Integer x );

        EntityAggregate_ptr_c control_points_list_() const;
        EntityAggregate_ptr   control_points_list_();
        void control_points_list_( const EntityAggregate_ptr x );

  const SdaiB_spline_curve_form_var   curve_form_() const;
        SdaiB_spline_curve_form_var   curve_form_();
        void curve_form_( const SdaiB_spline_curve_form_var x );

        Logical   closed_curve_() const;
        void closed_curve_( const Logical x );

        Logical   self_intersect_() const;
        void self_intersect_( const Logical x );

};

inline SdaiB_spline_curve * create_SdaiB_spline_curve() {
    return new SdaiB_spline_curve;
}

void init_SdaiB_spline_curve(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_b_spline_curve;
    extern AttrDescriptor *a_16degree;
    extern AttrDescriptor *a_17control_points_list;
    extern AttrDescriptor *a_18curve_form;
    extern AttrDescriptor *a_19closed_curve;
    extern AttrDescriptor *a_20self_intersect;
    extern Derived_attribute *a_21Dupper_index_on_control_points;
    extern Derived_attribute *a_22Dcontrol_points;
}

#endif

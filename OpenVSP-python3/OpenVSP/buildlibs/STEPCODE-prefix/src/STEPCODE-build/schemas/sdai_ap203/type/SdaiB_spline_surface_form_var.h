#ifndef  TYPE_SDAIB_SPLINE_SURFACE_FORM_VAR_H
#define  TYPE_SDAIB_SPLINE_SURFACE_FORM_VAR_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

enum B_spline_surface_form {
        B_spline_surface_form__plane_surf,
        B_spline_surface_form__cylindrical_surf,
        B_spline_surface_form__conical_surf,
        B_spline_surface_form__spherical_surf,
        B_spline_surface_form__toroidal_surf,
        B_spline_surface_form__surf_of_revolution,
        B_spline_surface_form__ruled_surf,
        B_spline_surface_form__generalised_cone,
        B_spline_surface_form__quadric_surf,
        B_spline_surface_form__surf_of_linear_extrusion,
        B_spline_surface_form__unspecified,
        B_spline_surface_form_unset
};

class SC_SCHEMA_EXPORT SdaiB_spline_surface_form_var  :  public SDAI_Enum  {
  protected:
        EnumTypeDescriptor *type;

  public:
        SdaiB_spline_surface_form_var (const char * n =0, EnumTypeDescriptor *et =config_control_design::t_b_spline_surface_form);
        SdaiB_spline_surface_form_var (B_spline_surface_form e, EnumTypeDescriptor *et =config_control_design::t_b_spline_surface_form)
                : type(et) {  set_value (e);  }
        ~SdaiB_spline_surface_form_var () { }
        SdaiB_spline_surface_form_var& operator= (const SdaiB_spline_surface_form_var& e)
                {  set_value (e);  return *this;  }
        operator B_spline_surface_form () const;

        inline virtual const char * Name () const
                {  return type->Name();  }
        inline virtual int no_elements () const  {  return 11;  }
        virtual const char * element_at (int n) const;
};

typedef       SdaiB_spline_surface_form_var *   SdaiB_spline_surface_form_var_ptr;

typedef const SdaiB_spline_surface_form_var *   SdaiB_spline_surface_form_var_ptr_c;
  SDAI_Enum * create_SdaiB_spline_surface_form_var();

class SdaiB_spline_surface_form_var_agg  :  public EnumAggregate  {
  protected:
    EnumTypeDescriptor *enum_type;

  public:
    SdaiB_spline_surface_form_var_agg( EnumTypeDescriptor * =config_control_design::t_b_spline_surface_form);
    virtual ~SdaiB_spline_surface_form_var_agg();
    virtual SingleLinkNode * NewNode()
        { return new EnumNode (new SdaiB_spline_surface_form_var( "", enum_type )); }
};

typedef       SdaiB_spline_surface_form_var_agg *   SdaiB_spline_surface_form_var_agg_ptr;

typedef const SdaiB_spline_surface_form_var_agg *   SdaiB_spline_surface_form_var_agg_ptr_c;
  STEPaggregate * create_SdaiB_spline_surface_form_var_agg ();
void init_SdaiB_spline_surface_form_var(Registry& reg);

#endif

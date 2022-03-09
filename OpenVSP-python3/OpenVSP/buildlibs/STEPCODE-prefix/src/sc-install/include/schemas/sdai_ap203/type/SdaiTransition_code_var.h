#ifndef  TYPE_SDAITRANSITION_CODE_VAR_H
#define  TYPE_SDAITRANSITION_CODE_VAR_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

enum Transition_code {
        Transition_code__discontinuous,
        Transition_code__continuous,
        Transition_code__cont_same_gradient,
        Transition_code__cont_same_gradient_same_curvature,
        Transition_code_unset
};

class SC_SCHEMA_EXPORT SdaiTransition_code_var  :  public SDAI_Enum  {
  protected:
        EnumTypeDescriptor *type;

  public:
        SdaiTransition_code_var (const char * n =0, EnumTypeDescriptor *et =config_control_design::t_transition_code);
        SdaiTransition_code_var (Transition_code e, EnumTypeDescriptor *et =config_control_design::t_transition_code)
                : type(et) {  set_value (e);  }
        ~SdaiTransition_code_var () { }
        SdaiTransition_code_var& operator= (const SdaiTransition_code_var& e)
                {  set_value (e);  return *this;  }
        operator Transition_code () const;

        inline virtual const char * Name () const
                {  return type->Name();  }
        inline virtual int no_elements () const  {  return 4;  }
        virtual const char * element_at (int n) const;
};

typedef       SdaiTransition_code_var *   SdaiTransition_code_var_ptr;

typedef const SdaiTransition_code_var *   SdaiTransition_code_var_ptr_c;
  SDAI_Enum * create_SdaiTransition_code_var();

class SdaiTransition_code_var_agg  :  public EnumAggregate  {
  protected:
    EnumTypeDescriptor *enum_type;

  public:
    SdaiTransition_code_var_agg( EnumTypeDescriptor * =config_control_design::t_transition_code);
    virtual ~SdaiTransition_code_var_agg();
    virtual SingleLinkNode * NewNode()
        { return new EnumNode (new SdaiTransition_code_var( "", enum_type )); }
};

typedef       SdaiTransition_code_var_agg *   SdaiTransition_code_var_agg_ptr;

typedef const SdaiTransition_code_var_agg *   SdaiTransition_code_var_agg_ptr_c;
  STEPaggregate * create_SdaiTransition_code_var_agg ();
void init_SdaiTransition_code_var(Registry& reg);

#endif
#ifndef  TYPE_SDAISOURCE_VAR_H
#define  TYPE_SDAISOURCE_VAR_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

enum Source {
        Source__made,
        Source__bought,
        Source__not_known,
        Source_unset
};

class SC_SCHEMA_EXPORT SdaiSource_var  :  public SDAI_Enum  {
  protected:
        EnumTypeDescriptor *type;

  public:
        SdaiSource_var (const char * n =0, EnumTypeDescriptor *et =config_control_design::t_source);
        SdaiSource_var (Source e, EnumTypeDescriptor *et =config_control_design::t_source)
                : type(et) {  set_value (e);  }
        ~SdaiSource_var () { }
        SdaiSource_var& operator= (const SdaiSource_var& e)
                {  set_value (e);  return *this;  }
        operator Source () const;

        inline virtual const char * Name () const
                {  return type->Name();  }
        inline virtual int no_elements () const  {  return 3;  }
        virtual const char * element_at (int n) const;
};

typedef       SdaiSource_var *   SdaiSource_var_ptr;

typedef const SdaiSource_var *   SdaiSource_var_ptr_c;
  SDAI_Enum * create_SdaiSource_var();

class SdaiSource_var_agg  :  public EnumAggregate  {
  protected:
    EnumTypeDescriptor *enum_type;

  public:
    SdaiSource_var_agg( EnumTypeDescriptor * =config_control_design::t_source);
    virtual ~SdaiSource_var_agg();
    virtual SingleLinkNode * NewNode()
        { return new EnumNode (new SdaiSource_var( "", enum_type )); }
};

typedef       SdaiSource_var_agg *   SdaiSource_var_agg_ptr;

typedef const SdaiSource_var_agg *   SdaiSource_var_agg_ptr_c;
  STEPaggregate * create_SdaiSource_var_agg ();
void init_SdaiSource_var(Registry& reg);

#endif

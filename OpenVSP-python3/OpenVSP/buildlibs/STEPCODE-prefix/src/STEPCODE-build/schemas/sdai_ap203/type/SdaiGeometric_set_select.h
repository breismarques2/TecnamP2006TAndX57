#ifndef  TYPE_SDAIGEOMETRIC_SET_SELECT_H
#define  TYPE_SDAIGEOMETRIC_SET_SELECT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.


//////////  SELECT TYPE SdaiGeometric_set_select
class SC_SCHEMA_EXPORT SdaiGeometric_set_select  :  public SDAI_Select {
  protected:
    //  types in SELECT 
    //   POINT    --  sdaiINSTANCE
    //   CURVE    --  sdaiINSTANCE
    //   SURFACE    --  sdaiINSTANCE
       SDAI_Application_instance_ptr _app_inst;

  public:
    virtual const TypeDescriptor * AssignEntity (SDAI_Application_instance * se);
    virtual SDAI_Select * NewSelect ();

    virtual BASE_TYPE ValueType() const;


// STEP Part 21
    virtual void STEPwrite_content (ostream& out =std::cout,
                    const char *currSch =0) const;
    virtual void STEPwrite_verbose (ostream& out =std::cout,
                    const char *currSch =0) const;
    virtual Severity STEPread_content (istream& in =cin,
        InstMgrBase * instances =0, const char *utype =0,
        int addFileId =0, const char *currSch =0);
    virtual Severity StrToVal_content (const char *,
        InstMgrBase * instances =0);

// STEP Part 22:  SDAI

// constructors
    SdaiGeometric_set_select( const SelectTypeDescriptor * =config_control_design::t_geometric_set_select );
    //  part 1
    SdaiGeometric_set_select( const SdaiPoint_ptr&,
                              const SelectTypeDescriptor * =config_control_design::t_geometric_set_select );
    SdaiGeometric_set_select( const SdaiCurve_ptr&,
                              const SelectTypeDescriptor * =config_control_design::t_geometric_set_select );
    SdaiGeometric_set_select( const SdaiSurface_ptr&,
                              const SelectTypeDescriptor * =config_control_design::t_geometric_set_select );
    virtual ~SdaiGeometric_set_select();

    //  part 2
    operator SdaiPoint_ptr();
    operator SdaiCurve_ptr();
    operator SdaiSurface_ptr();

    //  part 3
  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );


    //  part 4
    SdaiGeometric_set_select& operator =( const SdaiPoint_ptr& );
    SdaiGeometric_set_select& operator =( const SdaiCurve_ptr& );
    SdaiGeometric_set_select& operator =( const SdaiSurface_ptr& );
    // not in SDAI
    SdaiGeometric_set_select& ShallowCopy ( const SdaiGeometric_set_select& );

#ifdef COMPILER_DEFINES_OPERATOR_EQ
#else
    SdaiGeometric_set_select& operator =( SdaiGeometric_set_select * const & );
    SDAI_Select& operator =( const SDAI_Select& );
#endif

    //  part 5
    Logical IsPoint() const;
    Logical IsCurve() const;
    Logical IsSurface() const;

    //  part 6 ... UnderlyingTypeName () implemented in SDAI_Select class ...

    //  part 7 ... NONE    only for complex selects...
};

inline SDAI_Select * create_SdaiGeometric_set_select () { return new SdaiGeometric_set_select; }
typedef SdaiGeometric_set_select * SdaiGeometric_set_selectH;
typedef SdaiGeometric_set_select_ptr SdaiGeometric_set_select_var;


class SdaiGeometric_set_select_agg : public SelectAggregate {
  protected:
    SelectTypeDescriptor *sel_type;

  public:
    SdaiGeometric_set_select_agg( SelectTypeDescriptor * =config_control_design::t_geometric_set_select );
    ~SdaiGeometric_set_select_agg();
    virtual SingleLinkNode * NewNode()
     { return new SelectNode (new SdaiGeometric_set_select( sel_type )); }
};
inline STEPaggregate * create_SdaiGeometric_set_select_agg () { return new SdaiGeometric_set_select_agg; }
typedef SdaiGeometric_set_select_agg_ptr SdaiGeometric_set_select_agg_var;

/////  END SELECT TYPE geometric_set_select

void init_SdaiGeometric_set_select(Registry& reg);

#endif
#ifndef  TYPE_SDAIBOOLEAN_OPERAND_H
#define  TYPE_SDAIBOOLEAN_OPERAND_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.


//////////  SELECT TYPE SdaiBoolean_operand
class SC_SCHEMA_EXPORT SdaiBoolean_operand  :  public SDAI_Select {
  protected:
    //  types in SELECT 
    //   SOLID_MODEL    --  sdaiINSTANCE
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
    SdaiBoolean_operand( const SelectTypeDescriptor * =config_control_design::t_boolean_operand );
    //  part 1
    SdaiBoolean_operand( const SdaiSolid_model_ptr&,
                         const SelectTypeDescriptor * =config_control_design::t_boolean_operand );
    virtual ~SdaiBoolean_operand();

    //  part 2
    operator SdaiSolid_model_ptr();

    //  part 3
  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );


    //  part 4
    SdaiBoolean_operand& operator =( const SdaiSolid_model_ptr& );
    // not in SDAI
    SdaiBoolean_operand& ShallowCopy ( const SdaiBoolean_operand& );

#ifdef COMPILER_DEFINES_OPERATOR_EQ
#else
    SdaiBoolean_operand& operator =( SdaiBoolean_operand * const & );
    SDAI_Select& operator =( const SDAI_Select& );
#endif

    //  part 5
    Logical IsSolid_model() const;

    //  part 6 ... UnderlyingTypeName () implemented in SDAI_Select class ...

    //  part 7 ... NONE    only for complex selects...
};

inline SDAI_Select * create_SdaiBoolean_operand () { return new SdaiBoolean_operand; }
typedef SdaiBoolean_operand * SdaiBoolean_operandH;
typedef SdaiBoolean_operand_ptr SdaiBoolean_operand_var;


class SdaiBoolean_operand_agg : public SelectAggregate {
  protected:
    SelectTypeDescriptor *sel_type;

  public:
    SdaiBoolean_operand_agg( SelectTypeDescriptor * =config_control_design::t_boolean_operand );
    ~SdaiBoolean_operand_agg();
    virtual SingleLinkNode * NewNode()
     { return new SelectNode (new SdaiBoolean_operand( sel_type )); }
};
inline STEPaggregate * create_SdaiBoolean_operand_agg () { return new SdaiBoolean_operand_agg; }
typedef SdaiBoolean_operand_agg_ptr SdaiBoolean_operand_agg_var;

/////  END SELECT TYPE boolean_operand

void init_SdaiBoolean_operand(Registry& reg);

#endif
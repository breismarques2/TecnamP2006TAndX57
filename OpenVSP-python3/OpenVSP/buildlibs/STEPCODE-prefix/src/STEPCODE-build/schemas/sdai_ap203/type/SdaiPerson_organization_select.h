#ifndef  TYPE_SDAIPERSON_ORGANIZATION_SELECT_H
#define  TYPE_SDAIPERSON_ORGANIZATION_SELECT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.


//////////  SELECT TYPE SdaiPerson_organization_select
class SC_SCHEMA_EXPORT SdaiPerson_organization_select  :  public SDAI_Select {
  protected:
    //  types in SELECT 
    //   PERSON    --  sdaiINSTANCE
    //   ORGANIZATION    --  sdaiINSTANCE
    //   PERSON_AND_ORGANIZATION    --  sdaiINSTANCE
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
    SdaiPerson_organization_select( const SelectTypeDescriptor * =config_control_design::t_person_organization_select );
    //  part 1
    SdaiPerson_organization_select( const SdaiPerson_ptr&,
                                    const SelectTypeDescriptor * =config_control_design::t_person_organization_select );
    SdaiPerson_organization_select( const SdaiOrganization_ptr&,
                                    const SelectTypeDescriptor * =config_control_design::t_person_organization_select );
    SdaiPerson_organization_select( const SdaiPerson_and_organization_ptr&,
                                    const SelectTypeDescriptor * =config_control_design::t_person_organization_select );
    virtual ~SdaiPerson_organization_select();

    //  part 2
    operator SdaiPerson_ptr();
    operator SdaiOrganization_ptr();
    operator SdaiPerson_and_organization_ptr();

    //  part 3
        SdaiOrganization_ptr_c the_organization_() const;
        SdaiOrganization_ptr   the_organization_();
        void the_organization_( const SdaiOrganization_ptr x );

        SdaiPerson_ptr_c the_person_() const;
        SdaiPerson_ptr   the_person_();
        void the_person_( const SdaiPerson_ptr x );

  const SdaiText   description_() const;
        SdaiText   description_();
        void description_( const SdaiText x );

  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );

        StringAggregate_ptr_c suffix_titles_() const;
        StringAggregate_ptr   suffix_titles_();
        void suffix_titles_( const StringAggregate_ptr x );

        StringAggregate_ptr_c prefix_titles_() const;
        StringAggregate_ptr   prefix_titles_();
        void prefix_titles_( const StringAggregate_ptr x );

        StringAggregate_ptr_c middle_names_() const;
        StringAggregate_ptr   middle_names_();
        void middle_names_( const StringAggregate_ptr x );

  const SdaiLabel   first_name_() const;
        SdaiLabel   first_name_();
        void first_name_( const SdaiLabel x );

  const SdaiLabel   last_name_() const;
        SdaiLabel   last_name_();
        void last_name_( const SdaiLabel x );

  const SdaiIdentifier   id_() const;
        SdaiIdentifier   id_();
        void id_( const SdaiIdentifier x );


    //  part 4
    SdaiPerson_organization_select& operator =( const SdaiPerson_ptr& );
    SdaiPerson_organization_select& operator =( const SdaiOrganization_ptr& );
    SdaiPerson_organization_select& operator =( const SdaiPerson_and_organization_ptr& );
    // not in SDAI
    SdaiPerson_organization_select& ShallowCopy ( const SdaiPerson_organization_select& );

#ifdef COMPILER_DEFINES_OPERATOR_EQ
#else
    SdaiPerson_organization_select& operator =( SdaiPerson_organization_select * const & );
    SDAI_Select& operator =( const SDAI_Select& );
#endif

    //  part 5
    Logical IsPerson() const;
    Logical IsOrganization() const;
    Logical IsPerson_and_organization() const;

    //  part 6 ... UnderlyingTypeName () implemented in SDAI_Select class ...

    //  part 7 ... NONE    only for complex selects...
};

inline SDAI_Select * create_SdaiPerson_organization_select () { return new SdaiPerson_organization_select; }
typedef SdaiPerson_organization_select * SdaiPerson_organization_selectH;
typedef SdaiPerson_organization_select_ptr SdaiPerson_organization_select_var;


class SdaiPerson_organization_select_agg : public SelectAggregate {
  protected:
    SelectTypeDescriptor *sel_type;

  public:
    SdaiPerson_organization_select_agg( SelectTypeDescriptor * =config_control_design::t_person_organization_select );
    ~SdaiPerson_organization_select_agg();
    virtual SingleLinkNode * NewNode()
     { return new SelectNode (new SdaiPerson_organization_select( sel_type )); }
};
inline STEPaggregate * create_SdaiPerson_organization_select_agg () { return new SdaiPerson_organization_select_agg; }
typedef SdaiPerson_organization_select_agg_ptr SdaiPerson_organization_select_agg_var;

/////  END SELECT TYPE person_organization_select

void init_SdaiPerson_organization_select(Registry& reg);

#endif

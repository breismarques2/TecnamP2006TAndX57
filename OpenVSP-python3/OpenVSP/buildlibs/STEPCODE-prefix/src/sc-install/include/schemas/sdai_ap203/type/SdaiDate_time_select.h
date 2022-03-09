#ifndef  TYPE_SDAIDATE_TIME_SELECT_H
#define  TYPE_SDAIDATE_TIME_SELECT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.


//////////  SELECT TYPE SdaiDate_time_select
class SC_SCHEMA_EXPORT SdaiDate_time_select  :  public SDAI_Select {
  protected:
    //  types in SELECT 
    //   DATE    --  sdaiINSTANCE
    //   LOCAL_TIME    --  sdaiINSTANCE
    //   DATE_AND_TIME    --  sdaiINSTANCE
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
    SdaiDate_time_select( const SelectTypeDescriptor * =config_control_design::t_date_time_select );
    //  part 1
    SdaiDate_time_select( const SdaiDate_ptr&,
                          const SelectTypeDescriptor * =config_control_design::t_date_time_select );
    SdaiDate_time_select( const SdaiLocal_time_ptr&,
                          const SelectTypeDescriptor * =config_control_design::t_date_time_select );
    SdaiDate_time_select( const SdaiDate_and_time_ptr&,
                          const SelectTypeDescriptor * =config_control_design::t_date_time_select );
    virtual ~SdaiDate_time_select();

    //  part 2
    operator SdaiDate_ptr();
    operator SdaiLocal_time_ptr();
    operator SdaiDate_and_time_ptr();

    //  part 3
        SdaiLocal_time_ptr_c time_component_() const;
        SdaiLocal_time_ptr   time_component_();
        void time_component_( const SdaiLocal_time_ptr x );

        SdaiDate_ptr_c date_component_() const;
        SdaiDate_ptr   date_component_();
        void date_component_( const SdaiDate_ptr x );

        SdaiCoordinated_universal_time_offset_ptr_c zone_() const;
        SdaiCoordinated_universal_time_offset_ptr   zone_();
        void zone_( const SdaiCoordinated_universal_time_offset_ptr x );

        SdaiSecond_in_minute   second_component_() const;
        void second_component_( const SdaiSecond_in_minute x );

        SdaiMinute_in_hour   minute_component_() const;
        void minute_component_( const SdaiMinute_in_hour x );

        SdaiHour_in_day   hour_component_() const;
        void hour_component_( const SdaiHour_in_day x );

        SdaiYear_number   year_component_() const;
        void year_component_( const SdaiYear_number x );


    //  part 4
    SdaiDate_time_select& operator =( const SdaiDate_ptr& );
    SdaiDate_time_select& operator =( const SdaiLocal_time_ptr& );
    SdaiDate_time_select& operator =( const SdaiDate_and_time_ptr& );
    // not in SDAI
    SdaiDate_time_select& ShallowCopy ( const SdaiDate_time_select& );

#ifdef COMPILER_DEFINES_OPERATOR_EQ
#else
    SdaiDate_time_select& operator =( SdaiDate_time_select * const & );
    SDAI_Select& operator =( const SDAI_Select& );
#endif

    //  part 5
    Logical IsDate() const;
    Logical IsLocal_time() const;
    Logical IsDate_and_time() const;

    //  part 6 ... UnderlyingTypeName () implemented in SDAI_Select class ...

    //  part 7 ... NONE    only for complex selects...
};

inline SDAI_Select * create_SdaiDate_time_select () { return new SdaiDate_time_select; }
typedef SdaiDate_time_select * SdaiDate_time_selectH;
typedef SdaiDate_time_select_ptr SdaiDate_time_select_var;


class SdaiDate_time_select_agg : public SelectAggregate {
  protected:
    SelectTypeDescriptor *sel_type;

  public:
    SdaiDate_time_select_agg( SelectTypeDescriptor * =config_control_design::t_date_time_select );
    ~SdaiDate_time_select_agg();
    virtual SingleLinkNode * NewNode()
     { return new SelectNode (new SdaiDate_time_select( sel_type )); }
};
inline STEPaggregate * create_SdaiDate_time_select_agg () { return new SdaiDate_time_select_agg; }
typedef SdaiDate_time_select_agg_ptr SdaiDate_time_select_agg_var;

/////  END SELECT TYPE date_time_select

void init_SdaiDate_time_select(Registry& reg);

#endif

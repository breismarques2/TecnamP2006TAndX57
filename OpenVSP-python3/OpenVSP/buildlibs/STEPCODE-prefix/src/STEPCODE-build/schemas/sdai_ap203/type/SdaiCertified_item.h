#ifndef  TYPE_SDAICERTIFIED_ITEM_H
#define  TYPE_SDAICERTIFIED_ITEM_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.


//////////  SELECT TYPE SdaiCertified_item
class SC_SCHEMA_EXPORT SdaiCertified_item  :  public SDAI_Select {
  protected:
    //  types in SELECT 
    //   SUPPLIED_PART_RELATIONSHIP    --  sdaiINSTANCE
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
    SdaiCertified_item( const SelectTypeDescriptor * =config_control_design::t_certified_item );
    //  part 1
    SdaiCertified_item( const SdaiSupplied_part_relationship_ptr&,
                        const SelectTypeDescriptor * =config_control_design::t_certified_item );
    virtual ~SdaiCertified_item();

    //  part 2
    operator SdaiSupplied_part_relationship_ptr();

    //  part 3
        SdaiProduct_definition_ptr_c related_product_definition_() const;
        SdaiProduct_definition_ptr   related_product_definition_();
        void related_product_definition_( const SdaiProduct_definition_ptr x );

        SdaiProduct_definition_ptr_c relating_product_definition_() const;
        SdaiProduct_definition_ptr   relating_product_definition_();
        void relating_product_definition_( const SdaiProduct_definition_ptr x );

  const SdaiText   description_() const;
        SdaiText   description_();
        void description_( const SdaiText x );

  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );

  const SdaiIdentifier   id_() const;
        SdaiIdentifier   id_();
        void id_( const SdaiIdentifier x );


    //  part 4
    SdaiCertified_item& operator =( const SdaiSupplied_part_relationship_ptr& );
    // not in SDAI
    SdaiCertified_item& ShallowCopy ( const SdaiCertified_item& );

#ifdef COMPILER_DEFINES_OPERATOR_EQ
#else
    SdaiCertified_item& operator =( SdaiCertified_item * const & );
    SDAI_Select& operator =( const SDAI_Select& );
#endif

    //  part 5
    Logical IsSupplied_part_relationship() const;

    //  part 6 ... UnderlyingTypeName () implemented in SDAI_Select class ...

    //  part 7 ... NONE    only for complex selects...
};

inline SDAI_Select * create_SdaiCertified_item () { return new SdaiCertified_item; }
typedef SdaiCertified_item * SdaiCertified_itemH;
typedef SdaiCertified_item_ptr SdaiCertified_item_var;


class SdaiCertified_item_agg : public SelectAggregate {
  protected:
    SelectTypeDescriptor *sel_type;

  public:
    SdaiCertified_item_agg( SelectTypeDescriptor * =config_control_design::t_certified_item );
    ~SdaiCertified_item_agg();
    virtual SingleLinkNode * NewNode()
     { return new SelectNode (new SdaiCertified_item( sel_type )); }
};
inline STEPaggregate * create_SdaiCertified_item_agg () { return new SdaiCertified_item_agg; }
typedef SdaiCertified_item_agg_ptr SdaiCertified_item_agg_var;

/////  END SELECT TYPE certified_item

void init_SdaiCertified_item(Registry& reg);

#endif

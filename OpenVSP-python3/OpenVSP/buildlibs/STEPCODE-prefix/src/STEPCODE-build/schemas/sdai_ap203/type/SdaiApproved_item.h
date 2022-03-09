#ifndef  TYPE_SDAIAPPROVED_ITEM_H
#define  TYPE_SDAIAPPROVED_ITEM_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.


//////////  SELECT TYPE SdaiApproved_item
class SC_SCHEMA_EXPORT SdaiApproved_item  :  public SDAI_Select {
  protected:
    //  types in SELECT 
    //   PRODUCT_DEFINITION_FORMATION    --  sdaiINSTANCE
    //   PRODUCT_DEFINITION    --  sdaiINSTANCE
    //   CONFIGURATION_EFFECTIVITY    --  sdaiINSTANCE
    //   CONFIGURATION_ITEM    --  sdaiINSTANCE
    //   SECURITY_CLASSIFICATION    --  sdaiINSTANCE
    //   CHANGE_REQUEST    --  sdaiINSTANCE
    //   CHANGE    --  sdaiINSTANCE
    //   START_REQUEST    --  sdaiINSTANCE
    //   START_WORK    --  sdaiINSTANCE
    //   CERTIFICATION    --  sdaiINSTANCE
    //   CONTRACT    --  sdaiINSTANCE
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
    SdaiApproved_item( const SelectTypeDescriptor * =config_control_design::t_approved_item );
    //  part 1
    SdaiApproved_item( const SdaiProduct_definition_formation_ptr&,
                       const SelectTypeDescriptor * =config_control_design::t_approved_item );
    SdaiApproved_item( const SdaiProduct_definition_ptr&,
                       const SelectTypeDescriptor * =config_control_design::t_approved_item );
    SdaiApproved_item( const SdaiConfiguration_effectivity_ptr&,
                       const SelectTypeDescriptor * =config_control_design::t_approved_item );
    SdaiApproved_item( const SdaiConfiguration_item_ptr&,
                       const SelectTypeDescriptor * =config_control_design::t_approved_item );
    SdaiApproved_item( const SdaiSecurity_classification_ptr&,
                       const SelectTypeDescriptor * =config_control_design::t_approved_item );
    SdaiApproved_item( const SdaiChange_request_ptr&,
                       const SelectTypeDescriptor * =config_control_design::t_approved_item );
    SdaiApproved_item( const SdaiChange_ptr&,
                       const SelectTypeDescriptor * =config_control_design::t_approved_item );
    SdaiApproved_item( const SdaiStart_request_ptr&,
                       const SelectTypeDescriptor * =config_control_design::t_approved_item );
    SdaiApproved_item( const SdaiStart_work_ptr&,
                       const SelectTypeDescriptor * =config_control_design::t_approved_item );
    SdaiApproved_item( const SdaiCertification_ptr&,
                       const SelectTypeDescriptor * =config_control_design::t_approved_item );
    SdaiApproved_item( const SdaiContract_ptr&,
                       const SelectTypeDescriptor * =config_control_design::t_approved_item );
    virtual ~SdaiApproved_item();

    //  part 2
    operator SdaiProduct_definition_formation_ptr();
    operator SdaiProduct_definition_ptr();
    operator SdaiConfiguration_effectivity_ptr();
    operator SdaiConfiguration_item_ptr();
    operator SdaiSecurity_classification_ptr();
    operator SdaiChange_request_ptr();
    operator SdaiChange_ptr();
    operator SdaiStart_request_ptr();
    operator SdaiStart_work_ptr();
    operator SdaiCertification_ptr();
    operator SdaiContract_ptr();

    //  part 3
        SdaiCertification_type_ptr_c kind_() const;
        SdaiCertification_type_ptr   kind_();
        void kind_( const SdaiCertification_type_ptr x );

        SdaiAction_ptr_c assigned_action_() const;
        SdaiAction_ptr   assigned_action_();
        void assigned_action_( const SdaiAction_ptr x );

        SdaiChange_request_item_agg_ptr_c items_() const;
        SdaiChange_request_item_agg_ptr   items_();
        void items_( const SdaiChange_request_item_agg_ptr x );

        SdaiVersioned_action_request_ptr_c assigned_action_request_() const;
        SdaiVersioned_action_request_ptr   assigned_action_request_();
        void assigned_action_request_( const SdaiVersioned_action_request_ptr x );

        SdaiSecurity_classification_level_ptr_c security_level_() const;
        SdaiSecurity_classification_level_ptr   security_level_();
        void security_level_( const SdaiSecurity_classification_level_ptr x );

  const SdaiLabel   purpose_() const;
        SdaiLabel   purpose_();
        void purpose_( const SdaiLabel x );

        SdaiProduct_concept_ptr_c item_concept_() const;
        SdaiProduct_concept_ptr   item_concept_();
        void item_concept_( const SdaiProduct_concept_ptr x );

  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );

        SdaiConfiguration_design_ptr_c configuration_() const;
        SdaiConfiguration_design_ptr   configuration_();
        void configuration_( const SdaiConfiguration_design_ptr x );

        SdaiProduct_definition_relationship_ptr_c usage_() const;
        SdaiProduct_definition_relationship_ptr   usage_();
        void usage_( const SdaiProduct_definition_relationship_ptr x );

        SdaiProduct_definition_context_ptr_c frame_of_reference_() const;
        SdaiProduct_definition_context_ptr   frame_of_reference_();
        void frame_of_reference_( const SdaiProduct_definition_context_ptr x );

        SdaiProduct_definition_formation_ptr_c formation_() const;
        SdaiProduct_definition_formation_ptr   formation_();
        void formation_( const SdaiProduct_definition_formation_ptr x );

        SdaiProduct_ptr_c of_product_() const;
        SdaiProduct_ptr   of_product_();
        void of_product_( const SdaiProduct_ptr x );

  const SdaiText   description_() const;
        SdaiText   description_();
        void description_( const SdaiText x );

  const SdaiIdentifier   id_() const;
        SdaiIdentifier   id_();
        void id_( const SdaiIdentifier x );


    //  part 4
    SdaiApproved_item& operator =( const SdaiProduct_definition_formation_ptr& );
    SdaiApproved_item& operator =( const SdaiProduct_definition_ptr& );
    SdaiApproved_item& operator =( const SdaiConfiguration_effectivity_ptr& );
    SdaiApproved_item& operator =( const SdaiConfiguration_item_ptr& );
    SdaiApproved_item& operator =( const SdaiSecurity_classification_ptr& );
    SdaiApproved_item& operator =( const SdaiChange_request_ptr& );
    SdaiApproved_item& operator =( const SdaiChange_ptr& );
    SdaiApproved_item& operator =( const SdaiStart_request_ptr& );
    SdaiApproved_item& operator =( const SdaiStart_work_ptr& );
    SdaiApproved_item& operator =( const SdaiCertification_ptr& );
    SdaiApproved_item& operator =( const SdaiContract_ptr& );
    // not in SDAI
    SdaiApproved_item& ShallowCopy ( const SdaiApproved_item& );

#ifdef COMPILER_DEFINES_OPERATOR_EQ
#else
    SdaiApproved_item& operator =( SdaiApproved_item * const & );
    SDAI_Select& operator =( const SDAI_Select& );
#endif

    //  part 5
    Logical IsProduct_definition_formation() const;
    Logical IsProduct_definition() const;
    Logical IsConfiguration_effectivity() const;
    Logical IsConfiguration_item() const;
    Logical IsSecurity_classification() const;
    Logical IsChange_request() const;
    Logical IsChange() const;
    Logical IsStart_request() const;
    Logical IsStart_work() const;
    Logical IsCertification() const;
    Logical IsContract() const;

    //  part 6 ... UnderlyingTypeName () implemented in SDAI_Select class ...

    //  part 7 ... NONE    only for complex selects...
};

inline SDAI_Select * create_SdaiApproved_item () { return new SdaiApproved_item; }
typedef SdaiApproved_item * SdaiApproved_itemH;
typedef SdaiApproved_item_ptr SdaiApproved_item_var;


class SdaiApproved_item_agg : public SelectAggregate {
  protected:
    SelectTypeDescriptor *sel_type;

  public:
    SdaiApproved_item_agg( SelectTypeDescriptor * =config_control_design::t_approved_item );
    ~SdaiApproved_item_agg();
    virtual SingleLinkNode * NewNode()
     { return new SelectNode (new SdaiApproved_item( sel_type )); }
};
inline STEPaggregate * create_SdaiApproved_item_agg () { return new SdaiApproved_item_agg; }
typedef SdaiApproved_item_agg_ptr SdaiApproved_item_agg_var;

/////  END SELECT TYPE approved_item

void init_SdaiApproved_item(Registry& reg);

#endif

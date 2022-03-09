#ifndef  TYPE_SDAICURVE_ON_SURFACE_H
#define  TYPE_SDAICURVE_ON_SURFACE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.


//////////  SELECT TYPE SdaiCurve_on_surface
class SC_SCHEMA_EXPORT SdaiCurve_on_surface  :  public SDAI_Select {
  protected:
    //  types in SELECT 
    //   PCURVE    --  sdaiINSTANCE
    //   SURFACE_CURVE    --  sdaiINSTANCE
    //   COMPOSITE_CURVE_ON_SURFACE    --  sdaiINSTANCE
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
    SdaiCurve_on_surface( const SelectTypeDescriptor * =config_control_design::t_curve_on_surface );
    //  part 1
    SdaiCurve_on_surface( const SdaiPcurve_ptr&,
                          const SelectTypeDescriptor * =config_control_design::t_curve_on_surface );
    SdaiCurve_on_surface( const SdaiSurface_curve_ptr&,
                          const SelectTypeDescriptor * =config_control_design::t_curve_on_surface );
    SdaiCurve_on_surface( const SdaiComposite_curve_on_surface_ptr&,
                          const SelectTypeDescriptor * =config_control_design::t_curve_on_surface );
    virtual ~SdaiCurve_on_surface();

    //  part 2
    operator SdaiPcurve_ptr();
    operator SdaiSurface_curve_ptr();
    operator SdaiComposite_curve_on_surface_ptr();

    //  part 3
        Logical   self_intersect_() const;
        void self_intersect_( const Logical x );

        EntityAggregate_ptr_c segments_() const;
        EntityAggregate_ptr   segments_();
        void segments_( const EntityAggregate_ptr x );

  const SdaiPreferred_surface_curve_representation_var   master_representation_() const;
        SdaiPreferred_surface_curve_representation_var   master_representation_();
        void master_representation_( const SdaiPreferred_surface_curve_representation_var x );

        SdaiPcurve_or_surface_agg_ptr_c associated_geometry_() const;
        SdaiPcurve_or_surface_agg_ptr   associated_geometry_();
        void associated_geometry_( const SdaiPcurve_or_surface_agg_ptr x );

        SdaiCurve_ptr_c curve_3d_() const;
        SdaiCurve_ptr   curve_3d_();
        void curve_3d_( const SdaiCurve_ptr x );

        SdaiDefinitional_representation_ptr_c reference_to_curve_() const;
        SdaiDefinitional_representation_ptr   reference_to_curve_();
        void reference_to_curve_( const SdaiDefinitional_representation_ptr x );

        SdaiSurface_ptr_c basis_surface_() const;
        SdaiSurface_ptr   basis_surface_();
        void basis_surface_( const SdaiSurface_ptr x );

  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );


    //  part 4
    SdaiCurve_on_surface& operator =( const SdaiPcurve_ptr& );
    SdaiCurve_on_surface& operator =( const SdaiSurface_curve_ptr& );
    SdaiCurve_on_surface& operator =( const SdaiComposite_curve_on_surface_ptr& );
    // not in SDAI
    SdaiCurve_on_surface& ShallowCopy ( const SdaiCurve_on_surface& );

#ifdef COMPILER_DEFINES_OPERATOR_EQ
#else
    SdaiCurve_on_surface& operator =( SdaiCurve_on_surface * const & );
    SDAI_Select& operator =( const SDAI_Select& );
#endif

    //  part 5
    Logical IsPcurve() const;
    Logical IsSurface_curve() const;
    Logical IsComposite_curve_on_surface() const;

    //  part 6 ... UnderlyingTypeName () implemented in SDAI_Select class ...

    //  part 7 ... NONE    only for complex selects...
};

inline SDAI_Select * create_SdaiCurve_on_surface () { return new SdaiCurve_on_surface; }
typedef SdaiCurve_on_surface * SdaiCurve_on_surfaceH;
typedef SdaiCurve_on_surface_ptr SdaiCurve_on_surface_var;


class SdaiCurve_on_surface_agg : public SelectAggregate {
  protected:
    SelectTypeDescriptor *sel_type;

  public:
    SdaiCurve_on_surface_agg( SelectTypeDescriptor * =config_control_design::t_curve_on_surface );
    ~SdaiCurve_on_surface_agg();
    virtual SingleLinkNode * NewNode()
     { return new SelectNode (new SdaiCurve_on_surface( sel_type )); }
};
inline STEPaggregate * create_SdaiCurve_on_surface_agg () { return new SdaiCurve_on_surface_agg; }
typedef SdaiCurve_on_surface_agg_ptr SdaiCurve_on_surface_agg_var;

/////  END SELECT TYPE curve_on_surface

void init_SdaiCurve_on_surface(Registry& reg);

#endif
#ifndef  ENTITY_SDAIGLOBAL_UNIT_ASSIGNED_CONTEXT_H
#define  ENTITY_SDAIGLOBAL_UNIT_ASSIGNED_CONTEXT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiGlobal_unit_assigned_context : public SdaiRepresentation_context {
     protected:
        SdaiUnit_agg_ptr _units;          //  of  unit

    public: 
        SdaiGlobal_unit_assigned_context();
        SdaiGlobal_unit_assigned_context( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiGlobal_unit_assigned_context( SdaiGlobal_unit_assigned_context & e );
        ~SdaiGlobal_unit_assigned_context();
        int opcode() {
            return 43;
        }
        SdaiUnit_agg_ptr_c units_() const;
        SdaiUnit_agg_ptr   units_();
        void units_( const SdaiUnit_agg_ptr x );

};

inline SdaiGlobal_unit_assigned_context * create_SdaiGlobal_unit_assigned_context() {
    return new SdaiGlobal_unit_assigned_context;
}

void init_SdaiGlobal_unit_assigned_context(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_global_unit_assigned_context;
    extern AttrDescriptor *a_75units;
}

#endif

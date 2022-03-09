#ifndef  ENTITY_SDAIACTION_H
#define  ENTITY_SDAIACTION_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiAction : public SDAI_Application_instance {
    protected:
        SDAI_String _name;
        SDAI_String _description;
        SDAI_Application_instance_ptr _chosen_method;
    public: 
        SdaiAction();
        SdaiAction( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiAction( SdaiAction & e );
        ~SdaiAction();
        int opcode() {
            return 122;
        }
  const SdaiLabel   name_() const;
        SdaiLabel   name_();
        void name_( const SdaiLabel x );

  const SdaiText   description_() const;
        SdaiText   description_();
        void description_( const SdaiText x );

        SdaiAction_method_ptr_c chosen_method_() const;
        SdaiAction_method_ptr   chosen_method_();
        void chosen_method_( const SdaiAction_method_ptr x );

};

inline SdaiAction * create_SdaiAction() {
    return new SdaiAction;
}

void init_SdaiAction(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_action;
    extern AttrDescriptor *a_231name;
    extern AttrDescriptor *a_232description;
    extern AttrDescriptor *a_233chosen_method;
}

#endif

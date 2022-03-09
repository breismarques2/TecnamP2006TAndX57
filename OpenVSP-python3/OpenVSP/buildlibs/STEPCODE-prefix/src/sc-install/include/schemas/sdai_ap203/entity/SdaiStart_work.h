#ifndef  ENTITY_SDAISTART_WORK_H
#define  ENTITY_SDAISTART_WORK_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiStart_work : public SdaiAction_assignment {
     protected:
        SdaiWork_item_agg_ptr _items;          //  of  work_item

    public: 
        SdaiStart_work();
        SdaiStart_work( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiStart_work( SdaiStart_work & e );
        ~SdaiStart_work();
        int opcode() {
            return 92;
        }
        SdaiWork_item_agg_ptr_c items_() const;
        SdaiWork_item_agg_ptr   items_();
        void items_( const SdaiWork_item_agg_ptr x );

};

inline SdaiStart_work * create_SdaiStart_work() {
    return new SdaiStart_work;
}

void init_SdaiStart_work(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_start_work;
    extern AttrDescriptor *a_185items;
}

#endif

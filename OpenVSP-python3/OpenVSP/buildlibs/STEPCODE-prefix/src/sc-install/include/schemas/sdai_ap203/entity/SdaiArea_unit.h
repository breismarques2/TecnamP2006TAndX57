#ifndef  ENTITY_SDAIAREA_UNIT_H
#define  ENTITY_SDAIAREA_UNIT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiArea_unit : public SdaiNamed_unit {
     protected:
    public: 
        SdaiArea_unit();
        SdaiArea_unit( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiArea_unit( SdaiArea_unit & e );
        ~SdaiArea_unit();
        int opcode() {
            return 242;
        }
};

inline SdaiArea_unit * create_SdaiArea_unit() {
    return new SdaiArea_unit;
}

void init_SdaiArea_unit(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_area_unit;
}

#endif
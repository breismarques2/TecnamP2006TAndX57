#ifndef  ENTITY_SDAIVOLUME_UNIT_H
#define  ENTITY_SDAIVOLUME_UNIT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiVolume_unit : public SdaiNamed_unit {
     protected:
    public: 
        SdaiVolume_unit();
        SdaiVolume_unit( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiVolume_unit( SdaiVolume_unit & e );
        ~SdaiVolume_unit();
        int opcode() {
            return 227;
        }
};

inline SdaiVolume_unit * create_SdaiVolume_unit() {
    return new SdaiVolume_unit;
}

void init_SdaiVolume_unit(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_volume_unit;
}

#endif
#ifndef  ENTITY_SDAISOLID_ANGLE_MEASURE_WITH_UNIT_H
#define  ENTITY_SDAISOLID_ANGLE_MEASURE_WITH_UNIT_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiSolid_angle_measure_with_unit : public SdaiMeasure_with_unit {
     protected:
    public: 
        SdaiSolid_angle_measure_with_unit();
        SdaiSolid_angle_measure_with_unit( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiSolid_angle_measure_with_unit( SdaiSolid_angle_measure_with_unit & e );
        ~SdaiSolid_angle_measure_with_unit();
        int opcode() {
            return 136;
        }
};

inline SdaiSolid_angle_measure_with_unit * create_SdaiSolid_angle_measure_with_unit() {
    return new SdaiSolid_angle_measure_with_unit;
}

void init_SdaiSolid_angle_measure_with_unit(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_solid_angle_measure_with_unit;
}

#endif

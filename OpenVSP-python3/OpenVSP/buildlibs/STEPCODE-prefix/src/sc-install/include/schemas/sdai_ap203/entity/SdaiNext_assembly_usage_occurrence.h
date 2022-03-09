#ifndef  ENTITY_SDAINEXT_ASSEMBLY_USAGE_OCCURRENCE_H
#define  ENTITY_SDAINEXT_ASSEMBLY_USAGE_OCCURRENCE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiNext_assembly_usage_occurrence : public SdaiAssembly_component_usage {
     protected:
    public: 
        SdaiNext_assembly_usage_occurrence();
        SdaiNext_assembly_usage_occurrence( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiNext_assembly_usage_occurrence( SdaiNext_assembly_usage_occurrence & e );
        ~SdaiNext_assembly_usage_occurrence();
        int opcode() {
            return 198;
        }
};

inline SdaiNext_assembly_usage_occurrence * create_SdaiNext_assembly_usage_occurrence() {
    return new SdaiNext_assembly_usage_occurrence;
}

void init_SdaiNext_assembly_usage_occurrence(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_next_assembly_usage_occurrence;
}

#endif

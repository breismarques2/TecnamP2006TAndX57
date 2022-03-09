#ifndef  ENTITY_SDAISURFACE_H
#define  ENTITY_SDAISURFACE_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiSurface : public SdaiGeometric_representation_item {
     protected:
    public: 
        SdaiSurface();
        SdaiSurface( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiSurface( SdaiSurface & e );
        ~SdaiSurface();
        int opcode() {
            return 20;
        }
};

inline SdaiSurface * create_SdaiSurface() {
    return new SdaiSurface;
}

void init_SdaiSurface(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_surface;
}

#endif

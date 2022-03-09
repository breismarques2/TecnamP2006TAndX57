#ifndef  ENTITY_SDAIPOLY_LOOP_H
#define  ENTITY_SDAIPOLY_LOOP_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiPoly_loop : public SdaiLoop {
     protected:
        EntityAggregate_ptr _polygon;          //  of  cartesian_point

    public: 
        SdaiPoly_loop();
        SdaiPoly_loop( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiPoly_loop( SdaiPoly_loop & e );
        ~SdaiPoly_loop();
        int opcode() {
            return 95;
        }
        EntityAggregate_ptr_c polygon_() const;
        EntityAggregate_ptr   polygon_();
        void polygon_( const EntityAggregate_ptr x );

};

inline SdaiPoly_loop * create_SdaiPoly_loop() {
    return new SdaiPoly_loop;
}

void init_SdaiPoly_loop(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_poly_loop;
    extern AttrDescriptor *a_188polygon;
}

#endif
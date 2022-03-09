#ifndef  ENTITY_SDAILOCAL_TIME_H
#define  ENTITY_SDAILOCAL_TIME_H

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

class SC_SCHEMA_EXPORT SdaiLocal_time : public SDAI_Application_instance {
    protected:
        SDAI_Integer _hour_component;
        SDAI_Integer _minute_component;    //  OPTIONAL
        SDAI_Real _second_component;    //  OPTIONAL
        SDAI_Application_instance_ptr _zone;
    public: 
        SdaiLocal_time();
        SdaiLocal_time( SDAI_Application_instance *se, bool addAttrs = true );
        SdaiLocal_time( SdaiLocal_time & e );
        ~SdaiLocal_time();
        int opcode() {
            return 197;
        }
        SdaiHour_in_day   hour_component_() const;
        void hour_component_( const SdaiHour_in_day x );

        SdaiMinute_in_hour   minute_component_() const;
        void minute_component_( const SdaiMinute_in_hour x );

        SdaiSecond_in_minute   second_component_() const;
        void second_component_( const SdaiSecond_in_minute x );

        SdaiCoordinated_universal_time_offset_ptr_c zone_() const;
        SdaiCoordinated_universal_time_offset_ptr   zone_();
        void zone_( const SdaiCoordinated_universal_time_offset_ptr x );

};

inline SdaiLocal_time * create_SdaiLocal_time() {
    return new SdaiLocal_time;
}

void init_SdaiLocal_time(Registry& reg);

namespace config_control_design {
    extern EntityDescriptor *e_local_time;
    extern AttrDescriptor *a_346hour_component;
    extern AttrDescriptor *a_347minute_component;
    extern AttrDescriptor *a_348second_component;
    extern AttrDescriptor *a_349zone;
}

#endif

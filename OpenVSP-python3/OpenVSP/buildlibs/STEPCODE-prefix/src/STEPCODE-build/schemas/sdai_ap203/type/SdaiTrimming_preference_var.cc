#ifndef  TYPE_SDAITRIMMING_PREFERENCE_VAR_CC
#define  TYPE_SDAITRIMMING_PREFERENCE_VAR_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "type/SdaiTrimming_preference_var.h"

const char *
SdaiTrimming_preference_var::element_at (int n) const  {
  switch (n)  {
  case Trimming_preference__parameter:  return "PARAMETER";
  case Trimming_preference__unspecified:  return "UNSPECIFIED";
  case Trimming_preference__cartesian:  return "CARTESIAN";
  case Trimming_preference_unset        :
  default                :  return "UNSET";
  }
}

SdaiTrimming_preference_var::SdaiTrimming_preference_var (const char * n, EnumTypeDescriptor *et)
  : type(et)
{
  set_value (n);
}

SdaiTrimming_preference_var::operator Trimming_preference () const {
  switch (v) {
        case Trimming_preference__parameter        :  return Trimming_preference__parameter;
        case Trimming_preference__unspecified        :  return Trimming_preference__unspecified;
        case Trimming_preference__cartesian        :  return Trimming_preference__cartesian;
        case Trimming_preference_unset        :
        default                :  return Trimming_preference_unset;
  }
}

SDAI_Enum *
create_SdaiTrimming_preference_var ()
{
    return new SdaiTrimming_preference_var( "", config_control_design::t_trimming_preference );
}


SdaiTrimming_preference_var_agg::SdaiTrimming_preference_var_agg( EnumTypeDescriptor *et )
    : enum_type(et)
{
}

SdaiTrimming_preference_var_agg::~SdaiTrimming_preference_var_agg()
{
}

STEPaggregate *
create_SdaiTrimming_preference_var_agg ()
{
    return new SdaiTrimming_preference_var_agg( config_control_design::t_trimming_preference );
}

void init_SdaiTrimming_preference_var( Registry& reg ) {
    std::string str;
        config_control_design::t_trimming_preference = new EnumTypeDescriptor (
                  "Trimming_Preference",        // Name
                  sdaiENUMERATION,        // FundamentalType
                  config_control_design::schema,        // Originating Schema
                  "ENUMERATION of (cartesian, parameter, unspecified)",        // Description
                  (EnumCreator) create_SdaiTrimming_preference_var);        // Creator function
        config_control_design::schema->AddType(config_control_design::t_trimming_preference);
    reg.AddType (*config_control_design::t_trimming_preference);
}

#endif

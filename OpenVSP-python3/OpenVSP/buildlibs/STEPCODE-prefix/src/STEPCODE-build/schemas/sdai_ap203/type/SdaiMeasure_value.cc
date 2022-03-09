#ifndef  TYPE_SDAIMEASURE_VALUE_CC
#define  TYPE_SDAIMEASURE_VALUE_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "type/SdaiMeasure_value.h"


//////////  SELECT TYPE measure_value

const TypeDescriptor * 
SdaiMeasure_value::AssignEntity (SDAI_Application_instance * se)
{
  (void)se;
  // should never be here - done in Select class

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
#ifdef __SUNCPLUSPLUS__
  std::cerr << se -> EntityName () << std::endl;
#endif
  return 0;
}

SDAI_Select * 
SdaiMeasure_value::NewSelect ()
{
    SdaiMeasure_value * tmp = new SdaiMeasure_value();
    return tmp;
}


// STEP Part 21

void
SdaiMeasure_value::STEPwrite_content (ostream& out, const char * currSch) const {
  (void)currSch;
      if (CurrentUnderlyingType () == config_control_design::t_length_measure) {
        WriteReal(_real,out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::t_mass_measure) {
        WriteReal(_real,out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::t_plane_angle_measure) {
        WriteReal(_real,out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::t_solid_angle_measure) {
        WriteReal(_real,out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::t_area_measure) {
        WriteReal(_real,out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::t_volume_measure) {
        WriteReal(_real,out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::t_parameter_value) {
        WriteReal(_real,out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::t_context_dependent_measure) {
        WriteReal(_real,out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::t_descriptive_measure) {
        _string.STEPwrite (out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::t_positive_length_measure) {
        WriteReal(_real,out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::t_positive_plane_angle_measure) {
        WriteReal(_real,out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::t_count_measure) {
        WriteReal(_real,out);
        return;
    }
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
}

BASE_TYPE
SdaiMeasure_value::ValueType() const {
    if (CurrentUnderlyingType() == config_control_design::t_length_measure)
        return sdaiREAL;
    if (CurrentUnderlyingType() == config_control_design::t_mass_measure)
        return sdaiREAL;
    if (CurrentUnderlyingType() == config_control_design::t_plane_angle_measure)
        return sdaiREAL;
    if (CurrentUnderlyingType() == config_control_design::t_solid_angle_measure)
        return sdaiREAL;
    if (CurrentUnderlyingType() == config_control_design::t_area_measure)
        return sdaiREAL;
    if (CurrentUnderlyingType() == config_control_design::t_volume_measure)
        return sdaiREAL;
    if (CurrentUnderlyingType() == config_control_design::t_parameter_value)
        return sdaiREAL;
    if (CurrentUnderlyingType() == config_control_design::t_context_dependent_measure)
        return sdaiREAL;
    if (CurrentUnderlyingType() == config_control_design::t_descriptive_measure)
        return sdaiSTRING;
    if (CurrentUnderlyingType() == config_control_design::t_positive_length_measure)
        return sdaiREAL;
    if (CurrentUnderlyingType() == config_control_design::t_positive_plane_angle_measure)
        return sdaiREAL;
    if (CurrentUnderlyingType() == config_control_design::t_count_measure)
        return sdaiNUMBER;
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
    return (BASE_TYPE)0;
}

void
SdaiMeasure_value::STEPwrite_verbose (ostream& out, const char *currSch) const
{
    const TypeDescriptor *td = CurrentUnderlyingType();
    std::string tmp;

    if ( td ) {
        // If we have a legal underlying type, get its name acc
        // to the current schema.
        StrToUpper( td->Name(currSch), tmp );
    }
    if (td == config_control_design::t_length_measure) {
        out << tmp << "(";
        WriteReal(_real,out);
        out << ")";
        return;
    }
    if (td == config_control_design::t_mass_measure) {
        out << tmp << "(";
        WriteReal(_real,out);
        out << ")";
        return;
    }
    if (td == config_control_design::t_plane_angle_measure) {
        out << tmp << "(";
        WriteReal(_real,out);
        out << ")";
        return;
    }
    if (td == config_control_design::t_solid_angle_measure) {
        out << tmp << "(";
        WriteReal(_real,out);
        out << ")";
        return;
    }
    if (td == config_control_design::t_area_measure) {
        out << tmp << "(";
        WriteReal(_real,out);
        out << ")";
        return;
    }
    if (td == config_control_design::t_volume_measure) {
        out << tmp << "(";
        WriteReal(_real,out);
        out << ")";
        return;
    }
    if (td == config_control_design::t_parameter_value) {
        out << tmp << "(";
        WriteReal(_real,out);
        out << ")";
        return;
    }
    if (td == config_control_design::t_context_dependent_measure) {
        out << tmp << "(";
        WriteReal(_real,out);
        out << ")";
        return;
    }
    if (td == config_control_design::t_descriptive_measure) {
        out << tmp << "(";
        _string.STEPwrite (out);
        out << ")";
        return;
    }
    if (td == config_control_design::t_positive_length_measure) {
        out << tmp << "(";
        WriteReal(_real,out);
        out << ")";
        return;
    }
    if (td == config_control_design::t_positive_plane_angle_measure) {
        out << tmp << "(";
        WriteReal(_real,out);
        out << ")";
        return;
    }
    if (td == config_control_design::t_count_measure) {
        out << tmp << "(";
        WriteReal(_real,out);
        out << ")";
        return;
    }
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
    return;
}

Severity
SdaiMeasure_value::STEPread_content (istream& in, InstMgrBase * instances,
            const char *utype, int addFileId, const char *currSch)
{
  (void)instances;
  (void)utype;
  (void)addFileId;
  (void)currSch;
      if (CurrentUnderlyingType () == config_control_design::t_length_measure) {
        ReadReal (_real, in, &_error, "),");
        return severity ();
    }
    if (CurrentUnderlyingType () == config_control_design::t_mass_measure) {
        ReadReal (_real, in, &_error, "),");
        return severity ();
    }
    if (CurrentUnderlyingType () == config_control_design::t_plane_angle_measure) {
        ReadReal (_real, in, &_error, "),");
        return severity ();
    }
    if (CurrentUnderlyingType () == config_control_design::t_solid_angle_measure) {
        ReadReal (_real, in, &_error, "),");
        return severity ();
    }
    if (CurrentUnderlyingType () == config_control_design::t_area_measure) {
        ReadReal (_real, in, &_error, "),");
        return severity ();
    }
    if (CurrentUnderlyingType () == config_control_design::t_volume_measure) {
        ReadReal (_real, in, &_error, "),");
        return severity ();
    }
    if (CurrentUnderlyingType () == config_control_design::t_parameter_value) {
        ReadReal (_real, in, &_error, "),");
        return severity ();
    }
    if (CurrentUnderlyingType () == config_control_design::t_context_dependent_measure) {
        ReadReal (_real, in, &_error, "),");
        return severity ();
    }
    if (CurrentUnderlyingType () == config_control_design::t_descriptive_measure) {
        _string.STEPread (in, &_error);
        return severity ();
    }
    if (CurrentUnderlyingType () == config_control_design::t_positive_length_measure) {
        ReadReal (_real, in, &_error, "),");
        return severity ();
    }
    if (CurrentUnderlyingType () == config_control_design::t_positive_plane_angle_measure) {
        ReadReal (_real, in, &_error, "),");
        return severity ();
    }
    if (CurrentUnderlyingType () == config_control_design::t_count_measure) {
        ReadReal (_real, in, &_error, "),");
        return severity ();
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
    return severity ();
}

Severity
SdaiMeasure_value::StrToVal_content (const char * str, InstMgrBase * instances)
{
  (void)str;
  (void)instances;
  switch (base_type)  {
  case sdaiSTRING :  
    return _string.StrToVal (str);
  default:  // should never be here - done in Select class

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
#ifdef __SUNCPLUSPLUS__
std::cerr << str << "  " << instances << std::endl;
#endif
    return SEVERITY_WARNING;
  }
#ifdef __GNUG__

  return SEVERITY_NULL;
#endif
}

// STEP Part 22:  SDAI

    //  part 0
SdaiMeasure_value::SdaiMeasure_value( const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript)
{
#ifdef SC_LOGGING
    if( *logStream )
    {
    *logStream << "DAVE ERR entering SdaiMeasure_value constructor." << std::endl;
    }
#endif
   nullify();
#ifdef SC_LOGGING
    if( *logStream )
    {
//    *logStream << "DAVE ERR exiting SdaiMeasure_value constructor." << std::endl;
    }
#endif
}

    //  part 1
SdaiMeasure_value::SdaiMeasure_value( const SdaiDescriptive_measure& o,
                                      const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript, config_control_design::t_descriptive_measure)
{
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR entering SdaiMeasure_value constructor." << std::endl; }
#endif
   _string = o;
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR exiting SdaiMeasure_value constructor." << std::endl; }
#endif
}

SdaiMeasure_value::SdaiMeasure_value( const SDAI_Real& o,
                                      const SelectTypeDescriptor *typedescript )
  : SDAI_Select ( typedescript, config_control_design::t_mass_measure )
{
   _real = o;
//  NOTE:  Underlying type defaults to config_control_design::t_mass_measure instead of NULL
#ifdef SC_LOGGING
    if( *logStream )
    {
//    *logStream << "DAVE ERR exiting SdaiMeasure_value constructor." << std::endl;
    }
#endif
}

SdaiMeasure_value::~SdaiMeasure_value() {
}

SdaiMeasure_value_agg::SdaiMeasure_value_agg( SelectTypeDescriptor *s)
  : SelectAggregate(), sel_type(s)
{
}

SdaiMeasure_value_agg::~SdaiMeasure_value_agg() { }


    //  part 2
SdaiMeasure_value::operator SdaiDescriptive_measure()
{
   if( CurrentUnderlyingType () == config_control_design::t_descriptive_measure )
      return  _string;

   severity( SEVERITY_WARNING );
   Error( "Underlying type is not SdaiDescriptive_measure" );

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
   return 0;
}

SdaiMeasure_value::operator SDAI_Real()
{
   if( CurrentUnderlyingType () == config_control_design::t_length_measure )
      return  _real;
   if( CurrentUnderlyingType () == config_control_design::t_mass_measure )
      return  _real;
   if( CurrentUnderlyingType () == config_control_design::t_plane_angle_measure )
      return  _real;
   if( CurrentUnderlyingType () == config_control_design::t_solid_angle_measure )
      return  _real;
   if( CurrentUnderlyingType () == config_control_design::t_area_measure )
      return  _real;
   if( CurrentUnderlyingType () == config_control_design::t_volume_measure )
      return  _real;
   if( CurrentUnderlyingType () == config_control_design::t_parameter_value )
      return  _real;
   if( CurrentUnderlyingType () == config_control_design::t_context_dependent_measure )
      return  _real;
   if( CurrentUnderlyingType () == config_control_design::t_positive_length_measure )
      return  _real;
   if( CurrentUnderlyingType () == config_control_design::t_positive_plane_angle_measure )
      return  _real;
   if( CurrentUnderlyingType () == config_control_design::t_count_measure )
      return  _real;

   severity( SEVERITY_WARNING );
   Error( "Underlying type is not SDAI_Real" );

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
   return (SDAI_Real)0;
}


    //  part 3

    //  part 4
SdaiMeasure_value& SdaiMeasure_value::operator =( const SdaiDescriptive_measure& o )
{
   nullify ();
   _string = o;
   SetUnderlyingType( config_control_design::t_descriptive_measure );
   return *this;
}

SdaiMeasure_value& SdaiMeasure_value::operator =( const SDAI_Real& o )
{
   _real = o;
   underlying_type = 0; // MUST BE SET BY USER
   //	discriminator = UNSET
   return *this;
}

#ifndef COMPILER_DEFINES_OPERATOR_EQ

SdaiMeasure_value& SdaiMeasure_value::operator =( const SdaiMeasure_value_ptr& o ) {
    SDAI_Select::operator=( *o );
    if ( o -> CurrentUnderlyingType() == config_control_design::t_length_measure ) {
        _real = o -> _real;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::t_mass_measure ) {
        _real = o -> _real;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::t_plane_angle_measure ) {
        _real = o -> _real;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::t_solid_angle_measure ) {
        _real = o -> _real;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::t_area_measure ) {
        _real = o -> _real;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::t_volume_measure ) {
        _real = o -> _real;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::t_parameter_value ) {
        _real = o -> _real;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::t_context_dependent_measure ) {
        _real = o -> _real;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::t_descriptive_measure ) {
        _string =  o -> _string;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::t_positive_length_measure ) {
        _real = o -> _real;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::t_positive_plane_angle_measure ) {
        _real = o -> _real;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::t_count_measure ) {
        _real = o -> _real;
        return *this;
    }
    return *this;
}

SDAI_Select& SdaiMeasure_value::operator =( const SDAI_Select& o ) {
    SDAI_Select::operator=( o );
    if ( o.CurrentUnderlyingType() == config_control_design::t_length_measure ) {
        _real = ( ( SdaiMeasure_value& ) o )._real;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::t_mass_measure ) {
        _real = ( ( SdaiMeasure_value& ) o )._real;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::t_plane_angle_measure ) {
        _real = ( ( SdaiMeasure_value& ) o )._real;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::t_solid_angle_measure ) {
        _real = ( ( SdaiMeasure_value& ) o )._real;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::t_area_measure ) {
        _real = ( ( SdaiMeasure_value& ) o )._real;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::t_volume_measure ) {
        _real = ( ( SdaiMeasure_value& ) o )._real;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::t_parameter_value ) {
        _real = ( ( SdaiMeasure_value& ) o )._real;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::t_context_dependent_measure ) {
        _real = ( ( SdaiMeasure_value& ) o )._real;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::t_descriptive_measure ) {
        _string = ( ( SdaiMeasure_value& ) o )._string;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::t_positive_length_measure ) {
        _real = ( ( SdaiMeasure_value& ) o )._real;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::t_positive_plane_angle_measure ) {
        _real = ( ( SdaiMeasure_value& ) o )._real;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::t_count_measure ) {
        _real = ( ( SdaiMeasure_value& ) o )._real;
        return *this;
    }
   return *this;
}

#endif //ndef COMPILER_DEFINES_OPERATOR_EQ

    //  part 5
Logical SdaiMeasure_value::IsLength_measure() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::t_length_measure )
      return LTrue;
   return LFalse;
}

Logical SdaiMeasure_value::IsMass_measure() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::t_mass_measure )
      return LTrue;
   return LFalse;
}

Logical SdaiMeasure_value::IsPlane_angle_measure() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::t_plane_angle_measure )
      return LTrue;
   return LFalse;
}

Logical SdaiMeasure_value::IsSolid_angle_measure() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::t_solid_angle_measure )
      return LTrue;
   return LFalse;
}

Logical SdaiMeasure_value::IsArea_measure() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::t_area_measure )
      return LTrue;
   return LFalse;
}

Logical SdaiMeasure_value::IsVolume_measure() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::t_volume_measure )
      return LTrue;
   return LFalse;
}

Logical SdaiMeasure_value::IsParameter_value() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::t_parameter_value )
      return LTrue;
   return LFalse;
}

Logical SdaiMeasure_value::IsContext_dependent_measure() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::t_context_dependent_measure )
      return LTrue;
   return LFalse;
}

Logical SdaiMeasure_value::IsDescriptive_measure() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::t_descriptive_measure )
      return LTrue;
   return LFalse;
}

Logical SdaiMeasure_value::IsPositive_length_measure() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::t_positive_length_measure )
      return LTrue;
   return LFalse;
}

Logical SdaiMeasure_value::IsPositive_plane_angle_measure() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::t_positive_plane_angle_measure )
      return LTrue;
   return LFalse;
}

Logical SdaiMeasure_value::IsCount_measure() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::t_count_measure )
      return LTrue;
   return LFalse;
}


    //  part 7
const TypeDescriptor * 
SdaiMeasure_value::SetUnderlyingType (const TypeDescriptor * td)
{
  return SDAI_Select::SetUnderlyingType (td);
}
//////////  END SELECT TYPE SdaiMeasure_value


void init_SdaiMeasure_value( Registry& reg ) {
    std::string str;
        config_control_design::t_measure_value = new SelectTypeDescriptor (
                  ~(sdaiREAL),        //unique elements,
                  "Measure_Value",        // Name
                  sdaiSELECT,        // FundamentalType
                  config_control_design::schema,        // Originating Schema
                  "SELECT (Length_Measure, Mass_Measure, Plane_Angle_Measure, Solid_Angle_Measure, Area_Measure, Volume_Measure, Parameter_Value, Context_Dependent_Measure, Descriptive_Measure, Positive_Length_Measure, Positive_Plane_Angle_Measure, Count_Measure)",        // Description
                  (SelectCreator) create_SdaiMeasure_value);        // Creator function
        config_control_design::schema->AddType(config_control_design::t_measure_value);
    config_control_design::t_measure_value -> Elements ().AddNode (config_control_design::t_length_measure);
    config_control_design::t_measure_value -> Elements ().AddNode (config_control_design::t_mass_measure);
    config_control_design::t_measure_value -> Elements ().AddNode (config_control_design::t_plane_angle_measure);
    config_control_design::t_measure_value -> Elements ().AddNode (config_control_design::t_solid_angle_measure);
    config_control_design::t_measure_value -> Elements ().AddNode (config_control_design::t_area_measure);
    config_control_design::t_measure_value -> Elements ().AddNode (config_control_design::t_volume_measure);
    config_control_design::t_measure_value -> Elements ().AddNode (config_control_design::t_parameter_value);
    config_control_design::t_measure_value -> Elements ().AddNode (config_control_design::t_context_dependent_measure);
    config_control_design::t_measure_value -> Elements ().AddNode (config_control_design::t_descriptive_measure);
    config_control_design::t_measure_value -> Elements ().AddNode (config_control_design::t_positive_length_measure);
    config_control_design::t_measure_value -> Elements ().AddNode (config_control_design::t_positive_plane_angle_measure);
    config_control_design::t_measure_value -> Elements ().AddNode (config_control_design::t_count_measure);
    reg.AddType (*config_control_design::t_measure_value);
}

#endif
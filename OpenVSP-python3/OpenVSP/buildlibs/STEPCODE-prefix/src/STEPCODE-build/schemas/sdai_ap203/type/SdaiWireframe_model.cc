#ifndef  TYPE_SDAIWIREFRAME_MODEL_CC
#define  TYPE_SDAIWIREFRAME_MODEL_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "type/SdaiWireframe_model.h"


//////////  SELECT TYPE wireframe_model

const TypeDescriptor * 
SdaiWireframe_model::AssignEntity (SDAI_Application_instance * se)
{
  (void)se;
  //  SHELL_BASED_WIREFRAME_MODEL
  if (se -> IsA (config_control_design::e_shell_based_wireframe_model))
  {  
    _app_inst = (SdaiShell_based_wireframe_model_ptr) se;
    return SetUnderlyingType (config_control_design::e_shell_based_wireframe_model);
  }
  //  EDGE_BASED_WIREFRAME_MODEL
  if (se -> IsA (config_control_design::e_edge_based_wireframe_model))
  {  
    _app_inst = (SdaiEdge_based_wireframe_model_ptr) se;
    return SetUnderlyingType (config_control_design::e_edge_based_wireframe_model);
  }
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
SdaiWireframe_model::NewSelect ()
{
    SdaiWireframe_model * tmp = new SdaiWireframe_model();
    return tmp;
}


// STEP Part 21

void
SdaiWireframe_model::STEPwrite_content (ostream& out, const char * currSch) const {
  (void)currSch;
      if (CurrentUnderlyingType () == config_control_design::e_shell_based_wireframe_model) {
        _app_inst -> STEPwrite_reference (out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::e_edge_based_wireframe_model) {
        _app_inst -> STEPwrite_reference (out);
        return;
    }
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
}

BASE_TYPE
SdaiWireframe_model::ValueType() const {
    if (CurrentUnderlyingType() == config_control_design::e_shell_based_wireframe_model)
        return sdaiINSTANCE;
    if (CurrentUnderlyingType() == config_control_design::e_edge_based_wireframe_model)
        return sdaiINSTANCE;
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
    return (BASE_TYPE)0;
}

void
SdaiWireframe_model::STEPwrite_verbose (ostream& out, const char *currSch) const
{
    const TypeDescriptor *td = CurrentUnderlyingType();
    std::string tmp;

    if ( td ) {
        // If we have a legal underlying type, get its name acc
        // to the current schema.
        StrToUpper( td->Name(currSch), tmp );
    }
    if (td == config_control_design::e_shell_based_wireframe_model) {
        out <<  tmp << "(";
        _app_inst -> STEPwrite_reference (out);
        out << ")";
        return;
    }
    if (td == config_control_design::e_edge_based_wireframe_model) {
        out <<  tmp << "(";
        _app_inst -> STEPwrite_reference (out);
        out << ")";
        return;
    }
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
    return;
}

Severity
SdaiWireframe_model::STEPread_content (istream& in, InstMgrBase * instances,
            const char *utype, int addFileId, const char *currSch)
{
  (void)instances;
  (void)utype;
  (void)addFileId;
  (void)currSch;
      if (CurrentUnderlyingType () == config_control_design::e_shell_based_wireframe_model) {
        // set Underlying Type in Select class
        _app_inst = ReadEntityRef(in, &_error, ",)", instances, addFileId);
        if( _app_inst && ( _app_inst != S_ENTITY_NULL) &&
               ( CurrentUnderlyingType()->CanBe( _app_inst->getEDesc() ) ) ) {
            return severity();
        } else {
             Error ("Reference to instance that is not indicated type\n");
            _app_inst = 0;
            nullify ();
            return severity (SEVERITY_USERMSG);
        }
    }
    if (CurrentUnderlyingType () == config_control_design::e_edge_based_wireframe_model) {
        // set Underlying Type in Select class
        _app_inst = ReadEntityRef(in, &_error, ",)", instances, addFileId);
        if( _app_inst && ( _app_inst != S_ENTITY_NULL) &&
               ( CurrentUnderlyingType()->CanBe( _app_inst->getEDesc() ) ) ) {
            return severity();
        } else {
             Error ("Reference to instance that is not indicated type\n");
            _app_inst = 0;
            nullify ();
            return severity (SEVERITY_USERMSG);
        }
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
    return severity ();
}

Severity
SdaiWireframe_model::StrToVal_content (const char * str, InstMgrBase * instances)
{
  (void)str;
  (void)instances;
  switch (base_type)  {
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
SdaiWireframe_model::SdaiWireframe_model( const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript)
{
#ifdef SC_LOGGING
    if( *logStream )
    {
    *logStream << "DAVE ERR entering SdaiWireframe_model constructor." << std::endl;
    }
#endif
   nullify();
#ifdef SC_LOGGING
    if( *logStream )
    {
//    *logStream << "DAVE ERR exiting SdaiWireframe_model constructor." << std::endl;
    }
#endif
}

    //  part 1
SdaiWireframe_model::SdaiWireframe_model( const SdaiShell_based_wireframe_model_ptr& o,
                                          const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript, config_control_design::e_shell_based_wireframe_model)
{
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR entering SdaiWireframe_model constructor." << std::endl; }
#endif
   _app_inst = o;
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR exiting SdaiWireframe_model constructor." << std::endl; }
#endif
}

SdaiWireframe_model::SdaiWireframe_model( const SdaiEdge_based_wireframe_model_ptr& o,
                                          const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript, config_control_design::e_edge_based_wireframe_model)
{
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR entering SdaiWireframe_model constructor." << std::endl; }
#endif
   _app_inst = o;
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR exiting SdaiWireframe_model constructor." << std::endl; }
#endif
}

SdaiWireframe_model::~SdaiWireframe_model() {
}

SdaiWireframe_model_agg::SdaiWireframe_model_agg( SelectTypeDescriptor *s)
  : SelectAggregate(), sel_type(s)
{
}

SdaiWireframe_model_agg::~SdaiWireframe_model_agg() { }


    //  part 2
SdaiWireframe_model::operator SdaiShell_based_wireframe_model_ptr()
{
   if( CurrentUnderlyingType () == config_control_design::e_shell_based_wireframe_model )
      return ((SdaiShell_based_wireframe_model_ptr) _app_inst);

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
   return NULL;
}

SdaiWireframe_model::operator SdaiEdge_based_wireframe_model_ptr()
{
   if( CurrentUnderlyingType () == config_control_design::e_edge_based_wireframe_model )
      return ((SdaiEdge_based_wireframe_model_ptr) _app_inst);

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
   return NULL;
}


    //  part 3

EntityAggregate_ptr SdaiWireframe_model::ebwm_boundary_() {
  if( CurrentUnderlyingType () == config_control_design::e_edge_based_wireframe_model ) 
    //  EDGE_BASED_WIREFRAME_MODEL
    return ((SdaiEdge_based_wireframe_model_ptr) _app_inst) ->ebwm_boundary_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


EntityAggregate_ptr_c SdaiWireframe_model::ebwm_boundary_() const {
  if( CurrentUnderlyingType () == config_control_design::e_edge_based_wireframe_model ) 
    //  EDGE_BASED_WIREFRAME_MODEL
    return ((const SdaiEdge_based_wireframe_model_ptr) _app_inst) ->ebwm_boundary_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiWireframe_model::ebwm_boundary_( const EntityAggregate_ptr x ) {
  if( CurrentUnderlyingType () == config_control_design::e_edge_based_wireframe_model ) 
    //  EDGE_BASED_WIREFRAME_MODEL
    {  ((SdaiEdge_based_wireframe_model_ptr) _app_inst) ->ebwm_boundary_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

SdaiShell_agg_ptr SdaiWireframe_model::sbwm_boundary_() {
  if( CurrentUnderlyingType () == config_control_design::e_shell_based_wireframe_model ) 
    //  SHELL_BASED_WIREFRAME_MODEL
    return ((SdaiShell_based_wireframe_model_ptr) _app_inst) ->sbwm_boundary_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


SdaiShell_agg_ptr_c SdaiWireframe_model::sbwm_boundary_() const {
  if( CurrentUnderlyingType () == config_control_design::e_shell_based_wireframe_model ) 
    //  SHELL_BASED_WIREFRAME_MODEL
    return ((const SdaiShell_based_wireframe_model_ptr) _app_inst) ->sbwm_boundary_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiWireframe_model::sbwm_boundary_( const SdaiShell_agg_ptr x ) {
  if( CurrentUnderlyingType () == config_control_design::e_shell_based_wireframe_model ) 
    //  SHELL_BASED_WIREFRAME_MODEL
    {  ((SdaiShell_based_wireframe_model_ptr) _app_inst) ->sbwm_boundary_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

SdaiLabel SdaiWireframe_model::name_() {
  if( CurrentUnderlyingType () == config_control_design::e_shell_based_wireframe_model ) 
    //  SHELL_BASED_WIREFRAME_MODEL
    return ((SdaiShell_based_wireframe_model_ptr) _app_inst) ->name_();
  if( CurrentUnderlyingType () == config_control_design::e_edge_based_wireframe_model ) 
    //  EDGE_BASED_WIREFRAME_MODEL
    return ((SdaiEdge_based_wireframe_model_ptr) _app_inst) ->name_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


const SdaiLabel SdaiWireframe_model::name_() const {
  if( CurrentUnderlyingType () == config_control_design::e_shell_based_wireframe_model ) 
    //  SHELL_BASED_WIREFRAME_MODEL
    return ((const SdaiShell_based_wireframe_model_ptr) _app_inst) ->name_();
  if( CurrentUnderlyingType () == config_control_design::e_edge_based_wireframe_model ) 
    //  EDGE_BASED_WIREFRAME_MODEL
    return ((const SdaiEdge_based_wireframe_model_ptr) _app_inst) ->name_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiWireframe_model::name_( const SdaiLabel x ) {
  if( CurrentUnderlyingType () == config_control_design::e_shell_based_wireframe_model ) 
    //  SHELL_BASED_WIREFRAME_MODEL
    {  ((SdaiShell_based_wireframe_model_ptr) _app_inst) ->name_( x );
      return;
    }
  if( CurrentUnderlyingType () == config_control_design::e_edge_based_wireframe_model ) 
    //  EDGE_BASED_WIREFRAME_MODEL
    {  ((SdaiEdge_based_wireframe_model_ptr) _app_inst) ->name_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

    //  part 4
SdaiWireframe_model& SdaiWireframe_model::operator =( const SdaiShell_based_wireframe_model_ptr& o )
{
   nullify ();
   _app_inst = o;
   SetUnderlyingType( config_control_design::e_shell_based_wireframe_model );
   return *this;
}

SdaiWireframe_model& SdaiWireframe_model::operator =( const SdaiEdge_based_wireframe_model_ptr& o )
{
   nullify ();
   _app_inst = o;
   SetUnderlyingType( config_control_design::e_edge_based_wireframe_model );
   return *this;
}


#ifndef COMPILER_DEFINES_OPERATOR_EQ

SdaiWireframe_model& SdaiWireframe_model::operator =( const SdaiWireframe_model_ptr& o ) {
    SDAI_Select::operator=( *o );
    if ( o -> CurrentUnderlyingType() == config_control_design::e_shell_based_wireframe_model ) {
        _app_inst =  o -> _app_inst;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::e_edge_based_wireframe_model ) {
        _app_inst =  o -> _app_inst;
        return *this;
    }
    return *this;
}

SDAI_Select& SdaiWireframe_model::operator =( const SDAI_Select& o ) {
    SDAI_Select::operator=( o );
    if ( o.CurrentUnderlyingType() == config_control_design::e_shell_based_wireframe_model ) {
        _app_inst = ( ( SdaiWireframe_model& ) o )._app_inst;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::e_edge_based_wireframe_model ) {
        _app_inst = ( ( SdaiWireframe_model& ) o )._app_inst;
        return *this;
    }
   return *this;
}

#endif //ndef COMPILER_DEFINES_OPERATOR_EQ

    //  part 5
Logical SdaiWireframe_model::IsShell_based_wireframe_model() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::e_shell_based_wireframe_model )
      return LTrue;
   return LFalse;
}

Logical SdaiWireframe_model::IsEdge_based_wireframe_model() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::e_edge_based_wireframe_model )
      return LTrue;
   return LFalse;
}

//////////  END SELECT TYPE SdaiWireframe_model


void init_SdaiWireframe_model( Registry& reg ) {
    std::string str;
        config_control_design::t_wireframe_model = new SelectTypeDescriptor (
                  ~(sdaiINSTANCE),        //unique elements,
                  "Wireframe_Model",        // Name
                  sdaiSELECT,        // FundamentalType
                  config_control_design::schema,        // Originating Schema
                  "SELECT (Shell_Based_Wireframe_Model, Edge_Based_Wireframe_Model)",        // Description
                  (SelectCreator) create_SdaiWireframe_model);        // Creator function
        config_control_design::schema->AddType(config_control_design::t_wireframe_model);
    config_control_design::t_wireframe_model -> Elements ().AddNode (config_control_design::e_shell_based_wireframe_model);
    config_control_design::t_wireframe_model -> Elements ().AddNode (config_control_design::e_edge_based_wireframe_model);
    reg.AddType (*config_control_design::t_wireframe_model);
}

#endif

#ifndef  TYPE_SDAISHELL_CC
#define  TYPE_SDAISHELL_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "type/SdaiShell.h"


//////////  SELECT TYPE shell

const TypeDescriptor * 
SdaiShell::AssignEntity (SDAI_Application_instance * se)
{
  (void)se;
  //  VERTEX_SHELL
  if (se -> IsA (config_control_design::e_vertex_shell))
  {  
    _app_inst = (SdaiVertex_shell_ptr) se;
    return SetUnderlyingType (config_control_design::e_vertex_shell);
  }
  //  WIRE_SHELL
  if (se -> IsA (config_control_design::e_wire_shell))
  {  
    _app_inst = (SdaiWire_shell_ptr) se;
    return SetUnderlyingType (config_control_design::e_wire_shell);
  }
  //  OPEN_SHELL
  if (se -> IsA (config_control_design::e_open_shell))
  {  
    _app_inst = (SdaiOpen_shell_ptr) se;
    return SetUnderlyingType (config_control_design::e_open_shell);
  }
  //  CLOSED_SHELL
  if (se -> IsA (config_control_design::e_closed_shell))
  {  
    _app_inst = (SdaiClosed_shell_ptr) se;
    return SetUnderlyingType (config_control_design::e_closed_shell);
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
SdaiShell::NewSelect ()
{
    SdaiShell * tmp = new SdaiShell();
    return tmp;
}


// STEP Part 21

void
SdaiShell::STEPwrite_content (ostream& out, const char * currSch) const {
  (void)currSch;
      if (CurrentUnderlyingType () == config_control_design::e_vertex_shell) {
        _app_inst -> STEPwrite_reference (out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::e_wire_shell) {
        _app_inst -> STEPwrite_reference (out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::e_open_shell) {
        _app_inst -> STEPwrite_reference (out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::e_closed_shell) {
        _app_inst -> STEPwrite_reference (out);
        return;
    }
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
}

BASE_TYPE
SdaiShell::ValueType() const {
    if (CurrentUnderlyingType() == config_control_design::e_vertex_shell)
        return sdaiINSTANCE;
    if (CurrentUnderlyingType() == config_control_design::e_wire_shell)
        return sdaiINSTANCE;
    if (CurrentUnderlyingType() == config_control_design::e_open_shell)
        return sdaiINSTANCE;
    if (CurrentUnderlyingType() == config_control_design::e_closed_shell)
        return sdaiINSTANCE;
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
    return (BASE_TYPE)0;
}

void
SdaiShell::STEPwrite_verbose (ostream& out, const char *currSch) const
{
    const TypeDescriptor *td = CurrentUnderlyingType();
    std::string tmp;

    if ( td ) {
        // If we have a legal underlying type, get its name acc
        // to the current schema.
        StrToUpper( td->Name(currSch), tmp );
    }
    if (td == config_control_design::e_vertex_shell) {
        out <<  tmp << "(";
        _app_inst -> STEPwrite_reference (out);
        out << ")";
        return;
    }
    if (td == config_control_design::e_wire_shell) {
        out <<  tmp << "(";
        _app_inst -> STEPwrite_reference (out);
        out << ")";
        return;
    }
    if (td == config_control_design::e_open_shell) {
        out <<  tmp << "(";
        _app_inst -> STEPwrite_reference (out);
        out << ")";
        return;
    }
    if (td == config_control_design::e_closed_shell) {
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
SdaiShell::STEPread_content (istream& in, InstMgrBase * instances,
            const char *utype, int addFileId, const char *currSch)
{
  (void)instances;
  (void)utype;
  (void)addFileId;
  (void)currSch;
      if (CurrentUnderlyingType () == config_control_design::e_vertex_shell) {
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
    if (CurrentUnderlyingType () == config_control_design::e_wire_shell) {
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
    if (CurrentUnderlyingType () == config_control_design::e_open_shell) {
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
    if (CurrentUnderlyingType () == config_control_design::e_closed_shell) {
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
SdaiShell::StrToVal_content (const char * str, InstMgrBase * instances)
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
SdaiShell::SdaiShell( const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript)
{
#ifdef SC_LOGGING
    if( *logStream )
    {
    *logStream << "DAVE ERR entering SdaiShell constructor." << std::endl;
    }
#endif
   nullify();
#ifdef SC_LOGGING
    if( *logStream )
    {
//    *logStream << "DAVE ERR exiting SdaiShell constructor." << std::endl;
    }
#endif
}

    //  part 1
SdaiShell::SdaiShell( const SdaiVertex_shell_ptr& o,
                      const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript, config_control_design::e_vertex_shell)
{
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR entering SdaiShell constructor." << std::endl; }
#endif
   _app_inst = o;
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR exiting SdaiShell constructor." << std::endl; }
#endif
}

SdaiShell::SdaiShell( const SdaiWire_shell_ptr& o,
                      const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript, config_control_design::e_wire_shell)
{
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR entering SdaiShell constructor." << std::endl; }
#endif
   _app_inst = o;
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR exiting SdaiShell constructor." << std::endl; }
#endif
}

SdaiShell::SdaiShell( const SdaiOpen_shell_ptr& o,
                      const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript, config_control_design::e_open_shell)
{
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR entering SdaiShell constructor." << std::endl; }
#endif
   _app_inst = o;
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR exiting SdaiShell constructor." << std::endl; }
#endif
}

SdaiShell::SdaiShell( const SdaiClosed_shell_ptr& o,
                      const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript, config_control_design::e_closed_shell)
{
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR entering SdaiShell constructor." << std::endl; }
#endif
   _app_inst = o;
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR exiting SdaiShell constructor." << std::endl; }
#endif
}

SdaiShell::~SdaiShell() {
}

SdaiShell_agg::SdaiShell_agg( SelectTypeDescriptor *s)
  : SelectAggregate(), sel_type(s)
{
}

SdaiShell_agg::~SdaiShell_agg() { }


    //  part 2
SdaiShell::operator SdaiVertex_shell_ptr()
{
   if( CurrentUnderlyingType () == config_control_design::e_vertex_shell )
      return ((SdaiVertex_shell_ptr) _app_inst);

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
   return NULL;
}

SdaiShell::operator SdaiWire_shell_ptr()
{
   if( CurrentUnderlyingType () == config_control_design::e_wire_shell )
      return ((SdaiWire_shell_ptr) _app_inst);

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
   return NULL;
}

SdaiShell::operator SdaiOpen_shell_ptr()
{
   if( CurrentUnderlyingType () == config_control_design::e_open_shell )
      return ((SdaiOpen_shell_ptr) _app_inst);

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
   return NULL;
}

SdaiShell::operator SdaiClosed_shell_ptr()
{
   if( CurrentUnderlyingType () == config_control_design::e_closed_shell )
      return ((SdaiClosed_shell_ptr) _app_inst);

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
   return NULL;
}


    //  part 3

EntityAggregate_ptr SdaiShell::cfs_faces_() {
  if( CurrentUnderlyingType () == config_control_design::e_open_shell ) 
    //  OPEN_SHELL
    return ((SdaiOpen_shell_ptr) _app_inst) ->cfs_faces_();
  if( CurrentUnderlyingType () == config_control_design::e_closed_shell ) 
    //  CLOSED_SHELL
    return ((SdaiClosed_shell_ptr) _app_inst) ->cfs_faces_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


EntityAggregate_ptr_c SdaiShell::cfs_faces_() const {
  if( CurrentUnderlyingType () == config_control_design::e_open_shell ) 
    //  OPEN_SHELL
    return ((const SdaiOpen_shell_ptr) _app_inst) ->cfs_faces_();
  if( CurrentUnderlyingType () == config_control_design::e_closed_shell ) 
    //  CLOSED_SHELL
    return ((const SdaiClosed_shell_ptr) _app_inst) ->cfs_faces_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiShell::cfs_faces_( const EntityAggregate_ptr x ) {
  if( CurrentUnderlyingType () == config_control_design::e_open_shell ) 
    //  OPEN_SHELL
    {  ((SdaiOpen_shell_ptr) _app_inst) ->cfs_faces_( x );
      return;
    }
  if( CurrentUnderlyingType () == config_control_design::e_closed_shell ) 
    //  CLOSED_SHELL
    {  ((SdaiClosed_shell_ptr) _app_inst) ->cfs_faces_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

EntityAggregate_ptr SdaiShell::wire_shell_extent_() {
  if( CurrentUnderlyingType () == config_control_design::e_wire_shell ) 
    //  WIRE_SHELL
    return ((SdaiWire_shell_ptr) _app_inst) ->wire_shell_extent_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


EntityAggregate_ptr_c SdaiShell::wire_shell_extent_() const {
  if( CurrentUnderlyingType () == config_control_design::e_wire_shell ) 
    //  WIRE_SHELL
    return ((const SdaiWire_shell_ptr) _app_inst) ->wire_shell_extent_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiShell::wire_shell_extent_( const EntityAggregate_ptr x ) {
  if( CurrentUnderlyingType () == config_control_design::e_wire_shell ) 
    //  WIRE_SHELL
    {  ((SdaiWire_shell_ptr) _app_inst) ->wire_shell_extent_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

SdaiVertex_loop_ptr SdaiShell::vertex_shell_extent_() {
  if( CurrentUnderlyingType () == config_control_design::e_vertex_shell ) 
    //  VERTEX_SHELL
    return ((SdaiVertex_shell_ptr) _app_inst) ->vertex_shell_extent_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


SdaiVertex_loop_ptr_c SdaiShell::vertex_shell_extent_() const {
  if( CurrentUnderlyingType () == config_control_design::e_vertex_shell ) 
    //  VERTEX_SHELL
    return ((const SdaiVertex_shell_ptr) _app_inst) ->vertex_shell_extent_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiShell::vertex_shell_extent_( const SdaiVertex_loop_ptr x ) {
  if( CurrentUnderlyingType () == config_control_design::e_vertex_shell ) 
    //  VERTEX_SHELL
    {  ((SdaiVertex_shell_ptr) _app_inst) ->vertex_shell_extent_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

SdaiLabel SdaiShell::name_() {
  if( CurrentUnderlyingType () == config_control_design::e_vertex_shell ) 
    //  VERTEX_SHELL
    return ((SdaiVertex_shell_ptr) _app_inst) ->name_();
  if( CurrentUnderlyingType () == config_control_design::e_wire_shell ) 
    //  WIRE_SHELL
    return ((SdaiWire_shell_ptr) _app_inst) ->name_();
  if( CurrentUnderlyingType () == config_control_design::e_open_shell ) 
    //  OPEN_SHELL
    return ((SdaiOpen_shell_ptr) _app_inst) ->name_();
  if( CurrentUnderlyingType () == config_control_design::e_closed_shell ) 
    //  CLOSED_SHELL
    return ((SdaiClosed_shell_ptr) _app_inst) ->name_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


const SdaiLabel SdaiShell::name_() const {
  if( CurrentUnderlyingType () == config_control_design::e_vertex_shell ) 
    //  VERTEX_SHELL
    return ((const SdaiVertex_shell_ptr) _app_inst) ->name_();
  if( CurrentUnderlyingType () == config_control_design::e_wire_shell ) 
    //  WIRE_SHELL
    return ((const SdaiWire_shell_ptr) _app_inst) ->name_();
  if( CurrentUnderlyingType () == config_control_design::e_open_shell ) 
    //  OPEN_SHELL
    return ((const SdaiOpen_shell_ptr) _app_inst) ->name_();
  if( CurrentUnderlyingType () == config_control_design::e_closed_shell ) 
    //  CLOSED_SHELL
    return ((const SdaiClosed_shell_ptr) _app_inst) ->name_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiShell::name_( const SdaiLabel x ) {
  if( CurrentUnderlyingType () == config_control_design::e_vertex_shell ) 
    //  VERTEX_SHELL
    {  ((SdaiVertex_shell_ptr) _app_inst) ->name_( x );
      return;
    }
  if( CurrentUnderlyingType () == config_control_design::e_wire_shell ) 
    //  WIRE_SHELL
    {  ((SdaiWire_shell_ptr) _app_inst) ->name_( x );
      return;
    }
  if( CurrentUnderlyingType () == config_control_design::e_open_shell ) 
    //  OPEN_SHELL
    {  ((SdaiOpen_shell_ptr) _app_inst) ->name_( x );
      return;
    }
  if( CurrentUnderlyingType () == config_control_design::e_closed_shell ) 
    //  CLOSED_SHELL
    {  ((SdaiClosed_shell_ptr) _app_inst) ->name_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

    //  part 4
SdaiShell& SdaiShell::operator =( const SdaiVertex_shell_ptr& o )
{
   nullify ();
   _app_inst = o;
   SetUnderlyingType( config_control_design::e_vertex_shell );
   return *this;
}

SdaiShell& SdaiShell::operator =( const SdaiWire_shell_ptr& o )
{
   nullify ();
   _app_inst = o;
   SetUnderlyingType( config_control_design::e_wire_shell );
   return *this;
}

SdaiShell& SdaiShell::operator =( const SdaiOpen_shell_ptr& o )
{
   nullify ();
   _app_inst = o;
   SetUnderlyingType( config_control_design::e_open_shell );
   return *this;
}

SdaiShell& SdaiShell::operator =( const SdaiClosed_shell_ptr& o )
{
   nullify ();
   _app_inst = o;
   SetUnderlyingType( config_control_design::e_closed_shell );
   return *this;
}


#ifndef COMPILER_DEFINES_OPERATOR_EQ

SdaiShell& SdaiShell::operator =( const SdaiShell_ptr& o ) {
    SDAI_Select::operator=( *o );
    if ( o -> CurrentUnderlyingType() == config_control_design::e_vertex_shell ) {
        _app_inst =  o -> _app_inst;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::e_wire_shell ) {
        _app_inst =  o -> _app_inst;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::e_open_shell ) {
        _app_inst =  o -> _app_inst;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::e_closed_shell ) {
        _app_inst =  o -> _app_inst;
        return *this;
    }
    return *this;
}

SDAI_Select& SdaiShell::operator =( const SDAI_Select& o ) {
    SDAI_Select::operator=( o );
    if ( o.CurrentUnderlyingType() == config_control_design::e_vertex_shell ) {
        _app_inst = ( ( SdaiShell& ) o )._app_inst;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::e_wire_shell ) {
        _app_inst = ( ( SdaiShell& ) o )._app_inst;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::e_open_shell ) {
        _app_inst = ( ( SdaiShell& ) o )._app_inst;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::e_closed_shell ) {
        _app_inst = ( ( SdaiShell& ) o )._app_inst;
        return *this;
    }
   return *this;
}

#endif //ndef COMPILER_DEFINES_OPERATOR_EQ

    //  part 5
Logical SdaiShell::IsVertex_shell() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::e_vertex_shell )
      return LTrue;
   return LFalse;
}

Logical SdaiShell::IsWire_shell() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::e_wire_shell )
      return LTrue;
   return LFalse;
}

Logical SdaiShell::IsOpen_shell() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::e_open_shell )
      return LTrue;
   return LFalse;
}

Logical SdaiShell::IsClosed_shell() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::e_closed_shell )
      return LTrue;
   return LFalse;
}

//////////  END SELECT TYPE SdaiShell


void init_SdaiShell( Registry& reg ) {
    std::string str;
        config_control_design::t_shell = new SelectTypeDescriptor (
                  ~(sdaiINSTANCE),        //unique elements,
                  "Shell",        // Name
                  sdaiSELECT,        // FundamentalType
                  config_control_design::schema,        // Originating Schema
                  "SELECT (Vertex_Shell, Wire_Shell, Open_Shell, Closed_Shell)",        // Description
                  (SelectCreator) create_SdaiShell);        // Creator function
        config_control_design::schema->AddType(config_control_design::t_shell);
    config_control_design::t_shell -> Elements ().AddNode (config_control_design::e_vertex_shell);
    config_control_design::t_shell -> Elements ().AddNode (config_control_design::e_wire_shell);
    config_control_design::t_shell -> Elements ().AddNode (config_control_design::e_open_shell);
    config_control_design::t_shell -> Elements ().AddNode (config_control_design::e_closed_shell);
    reg.AddType (*config_control_design::t_shell);
}

#endif
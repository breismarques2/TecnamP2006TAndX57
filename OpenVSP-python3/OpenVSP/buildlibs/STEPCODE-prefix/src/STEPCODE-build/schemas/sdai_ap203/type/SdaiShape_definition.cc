#ifndef  TYPE_SDAISHAPE_DEFINITION_CC
#define  TYPE_SDAISHAPE_DEFINITION_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "type/SdaiShape_definition.h"


//////////  SELECT TYPE shape_definition

const TypeDescriptor * 
SdaiShape_definition::AssignEntity (SDAI_Application_instance * se)
{
  (void)se;
  //  PRODUCT_DEFINITION_SHAPE
  if (se -> IsA (config_control_design::e_product_definition_shape))
  {  
    _app_inst = (SdaiProduct_definition_shape_ptr) se;
    return SetUnderlyingType (config_control_design::e_product_definition_shape);
  }
  //  SHAPE_ASPECT
  if (se -> IsA (config_control_design::e_shape_aspect))
  {  
    _app_inst = (SdaiShape_aspect_ptr) se;
    return SetUnderlyingType (config_control_design::e_shape_aspect);
  }
  //  SHAPE_ASPECT_RELATIONSHIP
  if (se -> IsA (config_control_design::e_shape_aspect_relationship))
  {  
    _app_inst = (SdaiShape_aspect_relationship_ptr) se;
    return SetUnderlyingType (config_control_design::e_shape_aspect_relationship);
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
SdaiShape_definition::NewSelect ()
{
    SdaiShape_definition * tmp = new SdaiShape_definition();
    return tmp;
}


// STEP Part 21

void
SdaiShape_definition::STEPwrite_content (ostream& out, const char * currSch) const {
  (void)currSch;
      if (CurrentUnderlyingType () == config_control_design::e_product_definition_shape) {
        _app_inst -> STEPwrite_reference (out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::e_shape_aspect) {
        _app_inst -> STEPwrite_reference (out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship) {
        _app_inst -> STEPwrite_reference (out);
        return;
    }
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
}

BASE_TYPE
SdaiShape_definition::ValueType() const {
    if (CurrentUnderlyingType() == config_control_design::e_product_definition_shape)
        return sdaiINSTANCE;
    if (CurrentUnderlyingType() == config_control_design::e_shape_aspect)
        return sdaiINSTANCE;
    if (CurrentUnderlyingType() == config_control_design::e_shape_aspect_relationship)
        return sdaiINSTANCE;
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
    return (BASE_TYPE)0;
}

void
SdaiShape_definition::STEPwrite_verbose (ostream& out, const char *currSch) const
{
    const TypeDescriptor *td = CurrentUnderlyingType();
    std::string tmp;

    if ( td ) {
        // If we have a legal underlying type, get its name acc
        // to the current schema.
        StrToUpper( td->Name(currSch), tmp );
    }
    if (td == config_control_design::e_product_definition_shape) {
        out <<  tmp << "(";
        _app_inst -> STEPwrite_reference (out);
        out << ")";
        return;
    }
    if (td == config_control_design::e_shape_aspect) {
        out <<  tmp << "(";
        _app_inst -> STEPwrite_reference (out);
        out << ")";
        return;
    }
    if (td == config_control_design::e_shape_aspect_relationship) {
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
SdaiShape_definition::STEPread_content (istream& in, InstMgrBase * instances,
            const char *utype, int addFileId, const char *currSch)
{
  (void)instances;
  (void)utype;
  (void)addFileId;
  (void)currSch;
      if (CurrentUnderlyingType () == config_control_design::e_product_definition_shape) {
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
    if (CurrentUnderlyingType () == config_control_design::e_shape_aspect) {
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
    if (CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship) {
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
SdaiShape_definition::StrToVal_content (const char * str, InstMgrBase * instances)
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
SdaiShape_definition::SdaiShape_definition( const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript)
{
#ifdef SC_LOGGING
    if( *logStream )
    {
    *logStream << "DAVE ERR entering SdaiShape_definition constructor." << std::endl;
    }
#endif
   nullify();
#ifdef SC_LOGGING
    if( *logStream )
    {
//    *logStream << "DAVE ERR exiting SdaiShape_definition constructor." << std::endl;
    }
#endif
}

    //  part 1
SdaiShape_definition::SdaiShape_definition( const SdaiProduct_definition_shape_ptr& o,
                                            const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript, config_control_design::e_product_definition_shape)
{
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR entering SdaiShape_definition constructor." << std::endl; }
#endif
   _app_inst = o;
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR exiting SdaiShape_definition constructor." << std::endl; }
#endif
}

SdaiShape_definition::SdaiShape_definition( const SdaiShape_aspect_ptr& o,
                                            const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript, config_control_design::e_shape_aspect)
{
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR entering SdaiShape_definition constructor." << std::endl; }
#endif
   _app_inst = o;
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR exiting SdaiShape_definition constructor." << std::endl; }
#endif
}

SdaiShape_definition::SdaiShape_definition( const SdaiShape_aspect_relationship_ptr& o,
                                            const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript, config_control_design::e_shape_aspect_relationship)
{
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR entering SdaiShape_definition constructor." << std::endl; }
#endif
   _app_inst = o;
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR exiting SdaiShape_definition constructor." << std::endl; }
#endif
}

SdaiShape_definition::~SdaiShape_definition() {
}

SdaiShape_definition_agg::SdaiShape_definition_agg( SelectTypeDescriptor *s)
  : SelectAggregate(), sel_type(s)
{
}

SdaiShape_definition_agg::~SdaiShape_definition_agg() { }


    //  part 2
SdaiShape_definition::operator SdaiProduct_definition_shape_ptr()
{
   if( CurrentUnderlyingType () == config_control_design::e_product_definition_shape )
      return ((SdaiProduct_definition_shape_ptr) _app_inst);

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
   return NULL;
}

SdaiShape_definition::operator SdaiShape_aspect_ptr()
{
   if( CurrentUnderlyingType () == config_control_design::e_shape_aspect )
      return ((SdaiShape_aspect_ptr) _app_inst);

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
   return NULL;
}

SdaiShape_definition::operator SdaiShape_aspect_relationship_ptr()
{
   if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship )
      return ((SdaiShape_aspect_relationship_ptr) _app_inst);

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
   return NULL;
}


    //  part 3

SdaiShape_aspect_ptr SdaiShape_definition::related_shape_aspect_() {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship ) 
    //  SHAPE_ASPECT_RELATIONSHIP
    return ((SdaiShape_aspect_relationship_ptr) _app_inst) ->related_shape_aspect_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


SdaiShape_aspect_ptr_c SdaiShape_definition::related_shape_aspect_() const {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship ) 
    //  SHAPE_ASPECT_RELATIONSHIP
    return ((const SdaiShape_aspect_relationship_ptr) _app_inst) ->related_shape_aspect_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiShape_definition::related_shape_aspect_( const SdaiShape_aspect_ptr x ) {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship ) 
    //  SHAPE_ASPECT_RELATIONSHIP
    {  ((SdaiShape_aspect_relationship_ptr) _app_inst) ->related_shape_aspect_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

SdaiShape_aspect_ptr SdaiShape_definition::relating_shape_aspect_() {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship ) 
    //  SHAPE_ASPECT_RELATIONSHIP
    return ((SdaiShape_aspect_relationship_ptr) _app_inst) ->relating_shape_aspect_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


SdaiShape_aspect_ptr_c SdaiShape_definition::relating_shape_aspect_() const {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship ) 
    //  SHAPE_ASPECT_RELATIONSHIP
    return ((const SdaiShape_aspect_relationship_ptr) _app_inst) ->relating_shape_aspect_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiShape_definition::relating_shape_aspect_( const SdaiShape_aspect_ptr x ) {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship ) 
    //  SHAPE_ASPECT_RELATIONSHIP
    {  ((SdaiShape_aspect_relationship_ptr) _app_inst) ->relating_shape_aspect_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

Logical SdaiShape_definition::product_definitional_() const {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((SdaiShape_aspect_ptr) _app_inst) ->product_definitional_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return (Logical) 0;
}


void SdaiShape_definition::product_definitional_( const Logical x ) {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    {  ((SdaiShape_aspect_ptr) _app_inst) ->product_definitional_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

SdaiProduct_definition_shape_ptr SdaiShape_definition::of_shape_() {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((SdaiShape_aspect_ptr) _app_inst) ->of_shape_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


SdaiProduct_definition_shape_ptr_c SdaiShape_definition::of_shape_() const {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((const SdaiShape_aspect_ptr) _app_inst) ->of_shape_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiShape_definition::of_shape_( const SdaiProduct_definition_shape_ptr x ) {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    {  ((SdaiShape_aspect_ptr) _app_inst) ->of_shape_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

SdaiCharacterized_definition_ptr SdaiShape_definition::definition_() {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition_shape ) 
    //  PRODUCT_DEFINITION_SHAPE
    return ((SdaiProduct_definition_shape_ptr) _app_inst) ->definition_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


SdaiCharacterized_definition_ptr_c SdaiShape_definition::definition_() const {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition_shape ) 
    //  PRODUCT_DEFINITION_SHAPE
    return ((const SdaiProduct_definition_shape_ptr) _app_inst) ->definition_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiShape_definition::definition_( const SdaiCharacterized_definition_ptr x ) {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition_shape ) 
    //  PRODUCT_DEFINITION_SHAPE
    {  ((SdaiProduct_definition_shape_ptr) _app_inst) ->definition_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

SdaiText SdaiShape_definition::description_() {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition_shape ) 
    //  PRODUCT_DEFINITION_SHAPE
    return ((SdaiProduct_definition_shape_ptr) _app_inst) ->description_();
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((SdaiShape_aspect_ptr) _app_inst) ->description_();
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship ) 
    //  SHAPE_ASPECT_RELATIONSHIP
    return ((SdaiShape_aspect_relationship_ptr) _app_inst) ->description_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


const SdaiText SdaiShape_definition::description_() const {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition_shape ) 
    //  PRODUCT_DEFINITION_SHAPE
    return ((const SdaiProduct_definition_shape_ptr) _app_inst) ->description_();
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((const SdaiShape_aspect_ptr) _app_inst) ->description_();
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship ) 
    //  SHAPE_ASPECT_RELATIONSHIP
    return ((const SdaiShape_aspect_relationship_ptr) _app_inst) ->description_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiShape_definition::description_( const SdaiText x ) {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition_shape ) 
    //  PRODUCT_DEFINITION_SHAPE
    {  ((SdaiProduct_definition_shape_ptr) _app_inst) ->description_( x );
      return;
    }
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    {  ((SdaiShape_aspect_ptr) _app_inst) ->description_( x );
      return;
    }
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship ) 
    //  SHAPE_ASPECT_RELATIONSHIP
    {  ((SdaiShape_aspect_relationship_ptr) _app_inst) ->description_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

SdaiLabel SdaiShape_definition::name_() {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition_shape ) 
    //  PRODUCT_DEFINITION_SHAPE
    return ((SdaiProduct_definition_shape_ptr) _app_inst) ->name_();
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((SdaiShape_aspect_ptr) _app_inst) ->name_();
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship ) 
    //  SHAPE_ASPECT_RELATIONSHIP
    return ((SdaiShape_aspect_relationship_ptr) _app_inst) ->name_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


const SdaiLabel SdaiShape_definition::name_() const {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition_shape ) 
    //  PRODUCT_DEFINITION_SHAPE
    return ((const SdaiProduct_definition_shape_ptr) _app_inst) ->name_();
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((const SdaiShape_aspect_ptr) _app_inst) ->name_();
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship ) 
    //  SHAPE_ASPECT_RELATIONSHIP
    return ((const SdaiShape_aspect_relationship_ptr) _app_inst) ->name_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiShape_definition::name_( const SdaiLabel x ) {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition_shape ) 
    //  PRODUCT_DEFINITION_SHAPE
    {  ((SdaiProduct_definition_shape_ptr) _app_inst) ->name_( x );
      return;
    }
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    {  ((SdaiShape_aspect_ptr) _app_inst) ->name_( x );
      return;
    }
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship ) 
    //  SHAPE_ASPECT_RELATIONSHIP
    {  ((SdaiShape_aspect_relationship_ptr) _app_inst) ->name_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

    //  part 4
SdaiShape_definition& SdaiShape_definition::operator =( const SdaiProduct_definition_shape_ptr& o )
{
   nullify ();
   _app_inst = o;
   SetUnderlyingType( config_control_design::e_product_definition_shape );
   return *this;
}

SdaiShape_definition& SdaiShape_definition::operator =( const SdaiShape_aspect_ptr& o )
{
   nullify ();
   _app_inst = o;
   SetUnderlyingType( config_control_design::e_shape_aspect );
   return *this;
}

SdaiShape_definition& SdaiShape_definition::operator =( const SdaiShape_aspect_relationship_ptr& o )
{
   nullify ();
   _app_inst = o;
   SetUnderlyingType( config_control_design::e_shape_aspect_relationship );
   return *this;
}


#ifndef COMPILER_DEFINES_OPERATOR_EQ

SdaiShape_definition& SdaiShape_definition::operator =( const SdaiShape_definition_ptr& o ) {
    SDAI_Select::operator=( *o );
    if ( o -> CurrentUnderlyingType() == config_control_design::e_product_definition_shape ) {
        _app_inst =  o -> _app_inst;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::e_shape_aspect ) {
        _app_inst =  o -> _app_inst;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::e_shape_aspect_relationship ) {
        _app_inst =  o -> _app_inst;
        return *this;
    }
    return *this;
}

SDAI_Select& SdaiShape_definition::operator =( const SDAI_Select& o ) {
    SDAI_Select::operator=( o );
    if ( o.CurrentUnderlyingType() == config_control_design::e_product_definition_shape ) {
        _app_inst = ( ( SdaiShape_definition& ) o )._app_inst;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::e_shape_aspect ) {
        _app_inst = ( ( SdaiShape_definition& ) o )._app_inst;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::e_shape_aspect_relationship ) {
        _app_inst = ( ( SdaiShape_definition& ) o )._app_inst;
        return *this;
    }
   return *this;
}

#endif //ndef COMPILER_DEFINES_OPERATOR_EQ

    //  part 5
Logical SdaiShape_definition::IsProduct_definition_shape() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::e_product_definition_shape )
      return LTrue;
   return LFalse;
}

Logical SdaiShape_definition::IsShape_aspect() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::e_shape_aspect )
      return LTrue;
   return LFalse;
}

Logical SdaiShape_definition::IsShape_aspect_relationship() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::e_shape_aspect_relationship )
      return LTrue;
   return LFalse;
}

//////////  END SELECT TYPE SdaiShape_definition


void init_SdaiShape_definition( Registry& reg ) {
    std::string str;
        config_control_design::t_shape_definition = new SelectTypeDescriptor (
                  ~(sdaiINSTANCE),        //unique elements,
                  "Shape_Definition",        // Name
                  sdaiSELECT,        // FundamentalType
                  config_control_design::schema,        // Originating Schema
                  "SELECT (Product_Definition_Shape, Shape_Aspect, Shape_Aspect_Relationship)",        // Description
                  (SelectCreator) create_SdaiShape_definition);        // Creator function
        config_control_design::schema->AddType(config_control_design::t_shape_definition);
    config_control_design::t_shape_definition -> Elements ().AddNode (config_control_design::e_product_definition_shape);
    config_control_design::t_shape_definition -> Elements ().AddNode (config_control_design::e_shape_aspect);
    config_control_design::t_shape_definition -> Elements ().AddNode (config_control_design::e_shape_aspect_relationship);
    reg.AddType (*config_control_design::t_shape_definition);
}

#endif

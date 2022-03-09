#ifndef  TYPE_SDAISPECIFIED_ITEM_CC
#define  TYPE_SDAISPECIFIED_ITEM_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.

#include "schema.h"
#include "sc_memmgr.h"
#include "type/SdaiSpecified_item.h"


//////////  SELECT TYPE specified_item

const TypeDescriptor * 
SdaiSpecified_item::AssignEntity (SDAI_Application_instance * se)
{
  (void)se;
  //  PRODUCT_DEFINITION
  if (se -> IsA (config_control_design::e_product_definition))
  {  
    _app_inst = (SdaiProduct_definition_ptr) se;
    return SetUnderlyingType (config_control_design::e_product_definition);
  }
  //  SHAPE_ASPECT
  if (se -> IsA (config_control_design::e_shape_aspect))
  {  
    _app_inst = (SdaiShape_aspect_ptr) se;
    return SetUnderlyingType (config_control_design::e_shape_aspect);
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
SdaiSpecified_item::NewSelect ()
{
    SdaiSpecified_item * tmp = new SdaiSpecified_item();
    return tmp;
}


// STEP Part 21

void
SdaiSpecified_item::STEPwrite_content (ostream& out, const char * currSch) const {
  (void)currSch;
      if (CurrentUnderlyingType () == config_control_design::e_product_definition) {
        _app_inst -> STEPwrite_reference (out);
        return;
    }
    if (CurrentUnderlyingType () == config_control_design::e_shape_aspect) {
        _app_inst -> STEPwrite_reference (out);
        return;
    }
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
}

BASE_TYPE
SdaiSpecified_item::ValueType() const {
    if (CurrentUnderlyingType() == config_control_design::e_product_definition)
        return sdaiINSTANCE;
    if (CurrentUnderlyingType() == config_control_design::e_shape_aspect)
        return sdaiINSTANCE;
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
    return (BASE_TYPE)0;
}

void
SdaiSpecified_item::STEPwrite_verbose (ostream& out, const char *currSch) const
{
    const TypeDescriptor *td = CurrentUnderlyingType();
    std::string tmp;

    if ( td ) {
        // If we have a legal underlying type, get its name acc
        // to the current schema.
        StrToUpper( td->Name(currSch), tmp );
    }
    if (td == config_control_design::e_product_definition) {
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
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
    return;
}

Severity
SdaiSpecified_item::STEPread_content (istream& in, InstMgrBase * instances,
            const char *utype, int addFileId, const char *currSch)
{
  (void)instances;
  (void)utype;
  (void)addFileId;
  (void)currSch;
      if (CurrentUnderlyingType () == config_control_design::e_product_definition) {
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

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
    return severity ();
}

Severity
SdaiSpecified_item::StrToVal_content (const char * str, InstMgrBase * instances)
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
SdaiSpecified_item::SdaiSpecified_item( const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript)
{
#ifdef SC_LOGGING
    if( *logStream )
    {
    *logStream << "DAVE ERR entering SdaiSpecified_item constructor." << std::endl;
    }
#endif
   nullify();
#ifdef SC_LOGGING
    if( *logStream )
    {
//    *logStream << "DAVE ERR exiting SdaiSpecified_item constructor." << std::endl;
    }
#endif
}

    //  part 1
SdaiSpecified_item::SdaiSpecified_item( const SdaiProduct_definition_ptr& o,
                                        const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript, config_control_design::e_product_definition)
{
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR entering SdaiSpecified_item constructor." << std::endl; }
#endif
   _app_inst = o;
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR exiting SdaiSpecified_item constructor." << std::endl; }
#endif
}

SdaiSpecified_item::SdaiSpecified_item( const SdaiShape_aspect_ptr& o,
                                        const SelectTypeDescriptor *typedescript )
  : SDAI_Select (typedescript, config_control_design::e_shape_aspect)
{
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR entering SdaiSpecified_item constructor." << std::endl; }
#endif
   _app_inst = o;
#ifdef SC_LOGGING
    if( *logStream ) { *logStream << "DAVE ERR exiting SdaiSpecified_item constructor." << std::endl; }
#endif
}

SdaiSpecified_item::~SdaiSpecified_item() {
}

SdaiSpecified_item_agg::SdaiSpecified_item_agg( SelectTypeDescriptor *s)
  : SelectAggregate(), sel_type(s)
{
}

SdaiSpecified_item_agg::~SdaiSpecified_item_agg() { }


    //  part 2
SdaiSpecified_item::operator SdaiProduct_definition_ptr()
{
   if( CurrentUnderlyingType () == config_control_design::e_product_definition )
      return ((SdaiProduct_definition_ptr) _app_inst);

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
   return NULL;
}

SdaiSpecified_item::operator SdaiShape_aspect_ptr()
{
   if( CurrentUnderlyingType () == config_control_design::e_shape_aspect )
      return ((SdaiShape_aspect_ptr) _app_inst);

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
   return NULL;
}


    //  part 3

Logical SdaiSpecified_item::product_definitional_() const {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((SdaiShape_aspect_ptr) _app_inst) ->product_definitional_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return (Logical) 0;
}


void SdaiSpecified_item::product_definitional_( const Logical x ) {
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

SdaiProduct_definition_shape_ptr SdaiSpecified_item::of_shape_() {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((SdaiShape_aspect_ptr) _app_inst) ->of_shape_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


SdaiProduct_definition_shape_ptr_c SdaiSpecified_item::of_shape_() const {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((const SdaiShape_aspect_ptr) _app_inst) ->of_shape_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiSpecified_item::of_shape_( const SdaiProduct_definition_shape_ptr x ) {
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

SdaiLabel SdaiSpecified_item::name_() {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((SdaiShape_aspect_ptr) _app_inst) ->name_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


const SdaiLabel SdaiSpecified_item::name_() const {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((const SdaiShape_aspect_ptr) _app_inst) ->name_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiSpecified_item::name_( const SdaiLabel x ) {
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    {  ((SdaiShape_aspect_ptr) _app_inst) ->name_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

SdaiProduct_definition_context_ptr SdaiSpecified_item::frame_of_reference_() {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition ) 
    //  PRODUCT_DEFINITION
    return ((SdaiProduct_definition_ptr) _app_inst) ->frame_of_reference_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


SdaiProduct_definition_context_ptr_c SdaiSpecified_item::frame_of_reference_() const {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition ) 
    //  PRODUCT_DEFINITION
    return ((const SdaiProduct_definition_ptr) _app_inst) ->frame_of_reference_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiSpecified_item::frame_of_reference_( const SdaiProduct_definition_context_ptr x ) {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition ) 
    //  PRODUCT_DEFINITION
    {  ((SdaiProduct_definition_ptr) _app_inst) ->frame_of_reference_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

SdaiProduct_definition_formation_ptr SdaiSpecified_item::formation_() {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition ) 
    //  PRODUCT_DEFINITION
    return ((SdaiProduct_definition_ptr) _app_inst) ->formation_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


SdaiProduct_definition_formation_ptr_c SdaiSpecified_item::formation_() const {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition ) 
    //  PRODUCT_DEFINITION
    return ((const SdaiProduct_definition_ptr) _app_inst) ->formation_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiSpecified_item::formation_( const SdaiProduct_definition_formation_ptr x ) {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition ) 
    //  PRODUCT_DEFINITION
    {  ((SdaiProduct_definition_ptr) _app_inst) ->formation_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

SdaiText SdaiSpecified_item::description_() {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition ) 
    //  PRODUCT_DEFINITION
    return ((SdaiProduct_definition_ptr) _app_inst) ->description_();
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((SdaiShape_aspect_ptr) _app_inst) ->description_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


const SdaiText SdaiSpecified_item::description_() const {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition ) 
    //  PRODUCT_DEFINITION
    return ((const SdaiProduct_definition_ptr) _app_inst) ->description_();
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    return ((const SdaiShape_aspect_ptr) _app_inst) ->description_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiSpecified_item::description_( const SdaiText x ) {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition ) 
    //  PRODUCT_DEFINITION
    {  ((SdaiProduct_definition_ptr) _app_inst) ->description_( x );
      return;
    }
  if( CurrentUnderlyingType () == config_control_design::e_shape_aspect ) 
    //  SHAPE_ASPECT
    {  ((SdaiShape_aspect_ptr) _app_inst) ->description_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

SdaiIdentifier SdaiSpecified_item::id_() {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition ) 
    //  PRODUCT_DEFINITION
    return ((SdaiProduct_definition_ptr) _app_inst) ->id_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


const SdaiIdentifier SdaiSpecified_item::id_() const {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition ) 
    //  PRODUCT_DEFINITION
    return ((const SdaiProduct_definition_ptr) _app_inst) ->id_();
    std::cerr << __FILE__ << ":" << __LINE__ <<  ":  ERROR in schema library:  \n" 
    << _POC_ << "\n\n";
   return 0;
}


void SdaiSpecified_item::id_( const SdaiIdentifier x ) {
  if( CurrentUnderlyingType () == config_control_design::e_product_definition ) 
    //  PRODUCT_DEFINITION
    {  ((SdaiProduct_definition_ptr) _app_inst) ->id_( x );
      return;
    }

   severity( SEVERITY_WARNING );
   std::cerr << __FILE__ << ":" << __LINE__ <<  ":  WARNING:  possible misuse of"
        << " SELECT TYPE from schema library.\n";
   Error( "Mismatch in underlying type." );
}

    //  part 4
SdaiSpecified_item& SdaiSpecified_item::operator =( const SdaiProduct_definition_ptr& o )
{
   nullify ();
   _app_inst = o;
   SetUnderlyingType( config_control_design::e_product_definition );
   return *this;
}

SdaiSpecified_item& SdaiSpecified_item::operator =( const SdaiShape_aspect_ptr& o )
{
   nullify ();
   _app_inst = o;
   SetUnderlyingType( config_control_design::e_shape_aspect );
   return *this;
}


#ifndef COMPILER_DEFINES_OPERATOR_EQ

SdaiSpecified_item& SdaiSpecified_item::operator =( const SdaiSpecified_item_ptr& o ) {
    SDAI_Select::operator=( *o );
    if ( o -> CurrentUnderlyingType() == config_control_design::e_product_definition ) {
        _app_inst =  o -> _app_inst;
        return *this;
    }
    if ( o -> CurrentUnderlyingType() == config_control_design::e_shape_aspect ) {
        _app_inst =  o -> _app_inst;
        return *this;
    }
    return *this;
}

SDAI_Select& SdaiSpecified_item::operator =( const SDAI_Select& o ) {
    SDAI_Select::operator=( o );
    if ( o.CurrentUnderlyingType() == config_control_design::e_product_definition ) {
        _app_inst = ( ( SdaiSpecified_item& ) o )._app_inst;
        return *this;
    }
    if ( o.CurrentUnderlyingType() == config_control_design::e_shape_aspect ) {
        _app_inst = ( ( SdaiSpecified_item& ) o )._app_inst;
        return *this;
    }
   return *this;
}

#endif //ndef COMPILER_DEFINES_OPERATOR_EQ

    //  part 5
Logical SdaiSpecified_item::IsProduct_definition() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::e_product_definition )
      return LTrue;
   return LFalse;
}

Logical SdaiSpecified_item::IsShape_aspect() const
{
   if( !exists() )
      return LUnknown;
   if( CurrentUnderlyingType () == config_control_design::e_shape_aspect )
      return LTrue;
   return LFalse;
}

//////////  END SELECT TYPE SdaiSpecified_item


void init_SdaiSpecified_item( Registry& reg ) {
    std::string str;
        config_control_design::t_specified_item = new SelectTypeDescriptor (
                  ~(sdaiINSTANCE),        //unique elements,
                  "Specified_Item",        // Name
                  sdaiSELECT,        // FundamentalType
                  config_control_design::schema,        // Originating Schema
                  "SELECT (Product_Definition, Shape_Aspect)",        // Description
                  (SelectCreator) create_SdaiSpecified_item);        // Creator function
        config_control_design::schema->AddType(config_control_design::t_specified_item);
    config_control_design::t_specified_item -> Elements ().AddNode (config_control_design::e_product_definition);
    config_control_design::t_specified_item -> Elements ().AddNode (config_control_design::e_shape_aspect);
    reg.AddType (*config_control_design::t_specified_item);
}

#endif

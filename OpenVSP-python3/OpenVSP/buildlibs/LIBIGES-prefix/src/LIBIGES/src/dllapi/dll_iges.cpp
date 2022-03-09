/*
 * file: dll_iges.cpp
 *
 * Copyright 2015, Dr. Cirilo Bernardo (cirilo.bernardo@gmail.com)
 *
 * Description: IGES top level DLL API object for input, output and manipulation
 * of IGES entity data.
 *
 * This file is part of libIGES.
 *
 * libIGES is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * libIGES is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, If not, see
 * <http://www.gnu.org/licenses/> or write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#include <string>
#include <api/dll_iges.h>
//#include <api/dll_entity308.h>
#include <core/iges.h>
#include <core/all_entities.h>
#include <api/all_api_entities.h>
#include <error_macros.h>


DLL_IGES::DLL_IGES()
{
    m_valid = false;
    m_iges = new IGES;

    if( m_iges )
        m_iges->AttachValidFlag( &m_valid );

    return;
}


DLL_IGES::~DLL_IGES()
{
    if( m_iges && m_valid )
    {
        m_iges->DetachValidFlag( &m_valid );
        delete m_iges;
    }

    m_iges = NULL;
    return;
}


IGES* DLL_IGES::GetRawPtr( void )
{
    if( m_iges && m_valid )
        return m_iges;

    m_valid = false;
    m_iges = NULL;
    return NULL;
}


void DLL_IGES::Compact( void )
{
    if( m_iges && m_valid )
    {
        m_iges->Compact();
        return;
    }

    ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
    return;
}


void DLL_IGES::Cull( bool vicious )
{
    if( m_valid && NULL != m_iges )
    {
        m_iges->Cull(vicious);
        return;
    }

    ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
    return;
}


bool DLL_IGES::Clear( void )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    m_iges->Clear();
    return true;
}


bool DLL_IGES::Read( const char* aFileName )
{
    if( m_valid && NULL != m_iges )
        return m_iges->Read( aFileName );

    ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
    return false;
}


bool DLL_IGES::Write( const char* aFileName, bool fOverwrite )
{
    if( m_valid && NULL != m_iges )
        return m_iges->Write( aFileName, fOverwrite );

    ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
    return false;
}


bool DLL_IGES::Export( DLL_IGES* newParent, IGES_ENTITY_308** packagedEntity )
{
    if( NULL == newParent )
    {
        ERRMSG << "\n + [BUG] invoked with NULL newParent\n";
        return false;
    }

    if( m_valid && NULL != m_iges )
    {
        IGES* ip = newParent->GetRawPtr();
        return m_iges->Export( ip, packagedEntity );
    }

    ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
    return false;
}


bool DLL_IGES::Export( IGES* newParent, IGES_ENTITY_308** packagedEntity )
{
    if( NULL == newParent )
    {
        ERRMSG << "\n + [BUG] invoked with NULL newParent\n";
        return false;
    }

    if( m_valid && NULL != m_iges )
        return m_iges->Export( newParent, packagedEntity );

    ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
    return false;
}


char* DLL_IGES::GetNewPartName( void )
{
    if( m_valid && NULL != m_iges )
    {
        std::string npn;
        m_iges->GetNewPartName( npn );

        char* cp = new char[npn.size() + 1];
        size_t sz = npn.size();

        for( size_t i = 0; i < sz; ++i )
            cp[i] = npn[i];

        cp[sz] = 0;

        return cp;
    }

    ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
    return NULL;
}


char* DLL_IGES::GetNewAssemblyName( char* )
{
    if( m_valid && NULL != m_iges )
    {
        std::string npn;
        m_iges->GetNewAssemblyName( npn );

        char* cp = new char[npn.size() + 1];
        size_t sz = npn.size();

        for( size_t i = 0; i < sz; ++i )
            cp[i] = npn[i];

        cp[sz] = 0;

        return cp;
    }

    ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
    return NULL;
}


bool DLL_IGES::NewAPIEntity( IGES_ENTITY_TYPE aEntityType, DLL_IGES_ENTITY*& aEntityPointer )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    if( NULL != aEntityPointer )
    {
        aEntityPointer->Detach();
        delete aEntityPointer;
        aEntityPointer = NULL;
    }

    IGES_ENTITY* ep = NULL;

    if( !m_iges->NewEntity( aEntityType, &ep ) )
        return false;

    switch( aEntityType )
    {
    case ENT_CIRCULAR_ARC:
        aEntityPointer = new DLL_IGES_ENTITY_100( this->m_iges, true );
        break;

    case ENT_COMPOSITE_CURVE:
        aEntityPointer = new DLL_IGES_ENTITY_102( this->m_iges, true );
        break;

    case ENT_CONIC_ARC:
        aEntityPointer = new DLL_IGES_ENTITY_104( this->m_iges, true );
        break;

    case ENT_LINE:
        aEntityPointer = new DLL_IGES_ENTITY_110( this->m_iges, true );
        break;

    case ENT_SURFACE_OF_REVOLUTION:
        aEntityPointer = new DLL_IGES_ENTITY_120( this->m_iges, true );
        break;

    case ENT_TABULATED_CYLINDER:
        aEntityPointer = new DLL_IGES_ENTITY_122( this->m_iges, true );
        break;

    case ENT_TRANSFORMATION_MATRIX:
        aEntityPointer = new DLL_IGES_ENTITY_124( this->m_iges, true );
        break;

    case ENT_NURBS_CURVE:
        aEntityPointer = new DLL_IGES_ENTITY_126( this->m_iges, true );
        break;

    case ENT_NURBS_SURFACE:
        aEntityPointer = new DLL_IGES_ENTITY_128( this->m_iges, true );
        break;

    case ENT_CURVE_ON_PARAMETRIC_SURFACE:
        aEntityPointer = new DLL_IGES_ENTITY_142( this->m_iges, true );
        break;

    case ENT_TRIMMED_PARAMETRIC_SURFACE:
        aEntityPointer = new DLL_IGES_ENTITY_144( this->m_iges, true );
        break;

    /*
    case ENT_RIGHT_CIRCULAR_CYLINDER:
        aEntityPointer = new DLL_IGES_ENTITY_154( this->m_iges, true );
        break;

    case ENT_SOLID_OF_LINEAR_EXTRUSION:
        aEntityPointer = new DLL_IGES_ENTITY_164( this->m_iges, true );
        break;

    case ENT_BOOLEAN_TREE:
        aEntityPointer = new DLL_IGES_ENTITY_180( this->m_iges, true );
        break;

    case ENT_MANIFOLD_SOLID_BREP:
        aEntityPointer = new DLL_IGES_ENTITY_186( this->m_iges, true );
        break;
    */

    case ENT_SUBFIGURE_DEFINITION:
        aEntityPointer = new DLL_IGES_ENTITY_308( this->m_iges, true );
        break;

    case ENT_COLOR_DEFINITION:
        aEntityPointer = new DLL_IGES_ENTITY_314( this->m_iges, true );
        break;

    case ENT_SINGULAR_SUBFIGURE_INSTANCE:
        aEntityPointer = new DLL_IGES_ENTITY_408( this->m_iges, true );
        break;

    /*
    case ENT_VERTEX:
        aEntityPointer = new DLL_IGES_ENTITY_502( this->m_iges, true );
        break;

    case ENT_EDGE:
        aEntityPointer = new DLL_IGES_ENTITY_504( this->m_iges, true );
        break;

    case ENT_LOOP:
        aEntityPointer = new DLL_IGES_ENTITY_508( this->m_iges, true );
        break;

    case ENT_FACE:
        aEntityPointer = new DLL_IGES_ENTITY_510( this->m_iges, true );
        break;

    case ENT_SHELL:
        aEntityPointer = new DLL_IGES_ENTITY_514( this->m_iges, true );
        break;
        */

    default:
        delete ep;
        ERRMSG << "\n + [INFO] entity unsupported in API, ID " << aEntityType << "\n";
        return false;
        break;
    }

    if( NULL == aEntityPointer )
    {
        delete ep;
        ERRMSG << "\n + [INFO] failed to instantiate DLL_IGES_ENTITY object\n";
        return false;
    }

    if( !aEntityPointer->Attach( ep ) )
    {
        delete ep;
        delete aEntityPointer;
        aEntityPointer = NULL;
        ERRMSG << "\n + [INFO] failed to attach object to DLL_IGES_ENTITY\n";
        return false;
    }

    return true;
}


bool DLL_IGES::NewIGESEntity( IGES_ENTITY_TYPE aEntityType, IGES_ENTITY** aEntityPointer )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    aEntityPointer = NULL;
    return m_iges->NewEntity( aEntityType, aEntityPointer );
}


bool DLL_IGES::AddEntity( DLL_IGES_ENTITY* aEntity )
{
    if( NULL == aEntity )
    {
        ERRMSG << "\n + [BUG] invoked with invalid DLL_IGES_ENTITY object\n";
        return false;
    }

    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    return m_iges->AddEntity( aEntity->GetRawPtr() );
}


bool DLL_IGES::AddEntity( IGES_ENTITY* aEntity )
{
    if( NULL == aEntity )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES_ENTITY object\n";
        return false;
    }

    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    return m_iges->AddEntity( aEntity );
}


bool DLL_IGES::DelEntity( DLL_IGES_ENTITY* aEntity )
{
    if( NULL == aEntity )
    {
        ERRMSG << "\n + [BUG] invoked with invalid DLL_IGES_ENTITY object\n";
        return false;
    }

    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    return m_iges->DelEntity( aEntity->GetRawPtr() );
}


bool DLL_IGES::DelEntity( IGES_ENTITY* aEntity )
{
    if( NULL == aEntity )
    {
        ERRMSG << "\n + [BUG] invoked with invalid DLL_IGES_ENTITY object\n";
        return false;
    }

    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    return m_iges->DelEntity( aEntity );
}


bool DLL_IGES::UnlinkEntity( DLL_IGES_ENTITY* aEntity )
{
    if( NULL == aEntity )
    {
        ERRMSG << "\n + [BUG] invoked with invalid DLL_IGES_ENTITY object\n";
        return false;
    }

    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    return m_iges->UnlinkEntity( aEntity->GetRawPtr() );
}


bool DLL_IGES::UnlinkEntity( IGES_ENTITY* aEntity )
{
    if( NULL == aEntity )
    {
        ERRMSG << "\n + [BUG] invoked with invalid DLL_IGES_ENTITY object\n";
        return false;
    }

    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    return m_iges->UnlinkEntity( aEntity );
}


bool DLL_IGES::ConvertUnits( IGES_UNIT newUnit )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    return m_iges->ConvertUnits( newUnit );
}


bool DLL_IGES::ChangeModelScale( double aScale )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    return m_iges->ChangeModelScale( aScale );
}


bool DLL_IGES::GetHeaders( size_t& aListSize, char const**& aHeaderList )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    return m_iges->GetHeaders( aListSize, aHeaderList );
}


size_t DLL_IGES::GetNHeaderLines(void)
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return 0;
    }

    return m_iges->GetNHeaderLines();
}


bool DLL_IGES::AddToHeader( char const*& comment )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return 0;
    }

    return m_iges->AddToHeader( comment );
}


bool DLL_IGES::GetProductID_SendingSystem( char const*& aProductIDSS )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aProductIDSS = NULL;
        return false;
    }

    aProductIDSS = m_iges->globalData.productIDSS.c_str();
    return true;
}


bool DLL_IGES::SetProductID_SendingSystem( char const* aProductIDSS )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    if( NULL == aProductIDSS || 0 == aProductIDSS[0] )
        m_iges->globalData.productIDSS.clear();
    else
        m_iges->globalData.productIDSS = aProductIDSS;

    return true;
}


bool DLL_IGES::GetNativeSystemID( char const*& aNativeSoftwareName )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aNativeSoftwareName = NULL;
        return false;
    }

    aNativeSoftwareName = m_iges->globalData.nativeSystemID.c_str();
    return true;
}


bool DLL_IGES::SetNativeSystemID( char const* aNativeSoftwareName )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    if( NULL == aNativeSoftwareName || 0 == aNativeSoftwareName[0] )
        m_iges->globalData.nativeSystemID.clear();
    else
        m_iges->globalData.nativeSystemID = aNativeSoftwareName;

    return true;
}


bool DLL_IGES::GetPreprocessorVersion( char const*& aIGES_PreprocessorVersion )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aIGES_PreprocessorVersion = NULL;
        return false;
    }

    aIGES_PreprocessorVersion = m_iges->globalData.preprocessorVersion.c_str();
    return true;
}


bool DLL_IGES::GetProductID_ReceivingSystem( char const*& aProductIDRS )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aProductIDRS = NULL;
        return false;
    }

    if( m_iges->globalData.productIDRS.empty() && !m_iges->globalData.productIDSS.empty() )
        aProductIDRS = m_iges->globalData.productIDSS.c_str();
    else
        aProductIDRS = m_iges->globalData.productIDRS.c_str();

    return true;
}


bool DLL_IGES::SetProductID_ReceivingSystem( char const* aProductIDRS )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    m_iges->globalData.productIDRS = aProductIDRS;
    return true;
}


bool DLL_IGES::GetUnitsFlag( IGES_UNIT& aUnitFlag )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aUnitFlag = UNIT_MM;
        return false;
    }

    aUnitFlag = m_iges->globalData.unitsFlag;
    return true;
}


bool DLL_IGES::SetUnitsFlag( IGES_UNIT aUnitFlag )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    if( UNIT_EXTERN == aUnitFlag )
    {
        ERRMSG << "\n + [INFO] external unit type not supported\n";
        return false;
    }

    return m_iges->ConvertUnits( aUnitFlag );
}

bool DLL_IGES::GetUnitsName( char const*& aUnitName )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aUnitName = NULL;
        return false;
    }

    aUnitName = m_iges->GetUnitName();
    return true;
}


bool DLL_IGES::GetMaxLineWidthGrad( int& aMaxLWGrad )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aMaxLWGrad = 1;
        return false;
    }

    aMaxLWGrad = m_iges->globalData.maxLinewidthGrad;
    return true;
}


bool DLL_IGES::SetMaxLineWidthGrad( int aMaxLWGrad )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aMaxLWGrad = 1;
        return false;
    }

    if( 0 >= aMaxLWGrad )
    {
        ERRMSG << "\n + [INFO] Max Linewidth Gradation must be > 0\n";
        return false;
    }

    m_iges->globalData.maxLinewidthGrad = aMaxLWGrad;
    return true;
}


bool DLL_IGES::GetMaxLineWidth( double& aMaxLineWidth )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aMaxLineWidth = 1;
        return false;
    }

    aMaxLineWidth = m_iges->globalData.maxLinewidth;
    return true;
}


bool DLL_IGES::SetMaxLineWidth( double aMaxLineWidth )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aMaxLineWidth = 1.0;
        return false;
    }

    if( 0.0 >= aMaxLineWidth )
    {
        ERRMSG << "\n + [INFO] Max Linewidth must be > 0\n";
        return false;
    }

    m_iges->globalData.maxLinewidth = aMaxLineWidth;
    return true;
}


bool DLL_IGES::GetCreationDate( char const*& aDate )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aDate = NULL;
        return false;
    }

    aDate = m_iges->globalData.creationDate.c_str();
    return true;
}


bool DLL_IGES::GetMinResolution( double& aMinRes )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aMinRes = 1e-8;
        return false;
    }

    aMinRes = m_iges->globalData.minResolution;
    return true;
}


bool DLL_IGES::SetMinResolution( double aMinRes )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    if( aMinRes < 1e-9 )
    {
        ERRMSG << "\n + [INFO] minimum intended resolution must be >= 1e-9\n";
        return false;
    }

    m_iges->globalData.minResolution = aMinRes;
    return true;
}


bool DLL_IGES::GetAuthor( char const*& anAuthor )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        anAuthor = NULL;
        return false;
    }

    anAuthor = m_iges->globalData.author.c_str();
    return true;
}


bool DLL_IGES::SetAuthor( char const* anAuthor )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    if( NULL == anAuthor || 0 == anAuthor[0] )
        m_iges->globalData.author.clear();
    else
        m_iges->globalData.author = anAuthor;

    return true;
}


bool DLL_IGES::GetOrganization( char const*& anOrganization )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        anOrganization = NULL;
        return false;
    }

    anOrganization = m_iges->globalData.organization.c_str();
    return true;
}


bool DLL_IGES::SetOrganization( char const* anOrganization )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    if( NULL == anOrganization || 0 == anOrganization[0] )
        m_iges->globalData.organization.clear();
    else
        m_iges->globalData.organization = anOrganization;

    return true;
}

bool DLL_IGES::GetIGESVersionFlag( int& aIGESVersion )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aIGESVersion = 11;   // signal default IGES version
        return false;
    }

    aIGESVersion = m_iges->globalData.igesVersion;
    return true;
}


bool DLL_IGES::GetDraftingStandard( IGES_DRAFTING_STANDARD& aDraftingStd )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aDraftingStd = DRAFT_NONE;
        return false;
    }

    aDraftingStd = m_iges->globalData.draftStandard;
    return true;
}


bool DLL_IGES::SetDraftingStandard( IGES_DRAFTING_STANDARD aDraftingStd )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    m_iges->globalData.draftStandard = aDraftingStd;
    return true;
}


bool DLL_IGES::GetModificationDate( char const*& aDate )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aDate = NULL;
        return false;
    }

    aDate = m_iges->globalData.modificationDate.c_str();
    return true;
}


bool DLL_IGES::GetApplicationNote( char const*& aNote )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        aNote = NULL;
        return false;
    }

    aNote = m_iges->globalData.applicationNote.c_str();
    return true;
}


bool DLL_IGES::SetApplicationNote( char const* aNote )
{
    if( !m_valid || NULL == m_iges )
    {
        ERRMSG << "\n + [BUG] invoked with invalid IGES object\n";
        return false;
    }

    if( NULL == aNote || 0 == aNote[0] )
        m_iges->globalData.applicationNote.clear();
    else
        m_iges->globalData.applicationNote = aNote;

    return true;
}

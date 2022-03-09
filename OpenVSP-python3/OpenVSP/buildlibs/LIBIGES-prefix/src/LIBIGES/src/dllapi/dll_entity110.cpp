/*
 * file: dll_entity110.cpp
 *
 * Copyright 2015, Dr. Cirilo Bernardo (cirilo.bernardo@gmail.com)
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


#include <api/dll_entity110.h>
#include <api/dll_iges.h>
#include <core/iges.h>
#include <core/entity110.h>


DLL_IGES_ENTITY_110::DLL_IGES_ENTITY_110( IGES* aParent, bool create ) : DLL_IGES_CURVE( aParent )
{
    m_type = ENT_LINE;

    if( create )
    {
        if( NULL != aParent )
            aParent->NewEntity( ENT_LINE, &m_entity );
        else
            m_entity = new IGES_ENTITY_110( NULL );

        if( NULL != m_entity )
            m_entity->AttachValidFlag( &m_valid );
    }

    return;
}


DLL_IGES_ENTITY_110::DLL_IGES_ENTITY_110( DLL_IGES& aParent, bool create ) : DLL_IGES_CURVE( aParent )
{
    m_type = ENT_LINE;
    IGES* ip = aParent.GetRawPtr();

    if( !create || NULL == ip )
        return;

    ip->NewEntity( ENT_LINE, &m_entity );

    if( NULL != m_entity )
        m_entity->AttachValidFlag( &m_valid );

    return;
}


DLL_IGES_ENTITY_110::~DLL_IGES_ENTITY_110()
{
    return;
}


bool DLL_IGES_ENTITY_110::NewEntity( void )
{
    if( m_valid && NULL != m_entity )
    {
        m_entity->DetachValidFlag( &m_valid );
        m_entity = NULL;
    }

    if( NULL != m_parent && m_hasParent )
        m_parent->NewEntity( ENT_LINE, &m_entity );
    else
        m_entity = new IGES_ENTITY_110( NULL );

    if( NULL != m_entity )
    {
        m_entity->AttachValidFlag(&m_valid);
        return true;
    }

    return false;
}


bool DLL_IGES_ENTITY_110::GetLineStart( MCAD_POINT& pt )
{
    if( !m_valid || NULL == m_entity )
        return false;

    pt.x = ((IGES_ENTITY_110*)m_entity)->X1;
    pt.y = ((IGES_ENTITY_110*)m_entity)->Y1;
    pt.z = ((IGES_ENTITY_110*)m_entity)->Z1;
    return true;
}


bool DLL_IGES_ENTITY_110::GetLineStart( double& aX, double& aY, double& aZ )
{
    if( !m_valid || NULL == m_entity )
        return false;

    aX = ((IGES_ENTITY_110*)m_entity)->X1;
    aY = ((IGES_ENTITY_110*)m_entity)->Y1;
    aZ = ((IGES_ENTITY_110*)m_entity)->Z1;
    return true;
}


bool DLL_IGES_ENTITY_110::GetLineEnd( MCAD_POINT& pt )
{
    if( !m_valid || NULL == m_entity )
        return false;

    pt.x = ((IGES_ENTITY_110*)m_entity)->X2;
    pt.y = ((IGES_ENTITY_110*)m_entity)->Y2;
    pt.z = ((IGES_ENTITY_110*)m_entity)->Z2;
    return true;
}


bool DLL_IGES_ENTITY_110::GetLineEnd( double& aX, double& aY, double& aZ )
{
    if( !m_valid || NULL == m_entity )
        return false;

    aX = ((IGES_ENTITY_110*)m_entity)->X2;
    aY = ((IGES_ENTITY_110*)m_entity)->Y2;
    aZ = ((IGES_ENTITY_110*)m_entity)->Z2;
    return true;
}


bool DLL_IGES_ENTITY_110::SetLineStart( MCAD_POINT pt )
{
    if( !m_valid || NULL == m_entity )
        return false;

    ((IGES_ENTITY_110*)m_entity)->X1 = pt.x;
    ((IGES_ENTITY_110*)m_entity)->Y1 = pt.y;
    ((IGES_ENTITY_110*)m_entity)->Z1 = pt.z;
    return true;
}


bool DLL_IGES_ENTITY_110::SetLineStart( double aX, double aY, double aZ )
{
    if( !m_valid || NULL == m_entity )
        return false;

    ((IGES_ENTITY_110*)m_entity)->X1 = aX;
    ((IGES_ENTITY_110*)m_entity)->Y1 = aY;
    ((IGES_ENTITY_110*)m_entity)->Z1 = aZ;
    return true;
}


bool DLL_IGES_ENTITY_110::SetLineEnd( MCAD_POINT pt )
{
    if( !m_valid || NULL == m_entity )
        return false;

    ((IGES_ENTITY_110*)m_entity)->X2 = pt.x;
    ((IGES_ENTITY_110*)m_entity)->Y2 = pt.y;
    ((IGES_ENTITY_110*)m_entity)->Z2 = pt.z;
    return true;
}


bool DLL_IGES_ENTITY_110::SetLineEnd( double aX, double aY, double aZ )
{
    if( !m_valid || NULL == m_entity )
        return false;

    ((IGES_ENTITY_110*)m_entity)->X2 = aX;
    ((IGES_ENTITY_110*)m_entity)->Y2 = aY;
    ((IGES_ENTITY_110*)m_entity)->Z2 = aZ;
    return true;
}

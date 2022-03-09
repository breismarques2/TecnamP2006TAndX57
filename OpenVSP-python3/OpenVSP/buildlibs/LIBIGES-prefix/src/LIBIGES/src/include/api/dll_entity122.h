/*
 * file: dll_entity122.h
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

/*
 * Description: IGES Entity 122: Tabulated Cylinder, Section 4.19, p.119(147+)
 */

#ifndef DLL_ENTITY_122_H
#define DLL_ENTITY_122_H

#include <libigesconf.h>
#include <geom/mcad_elements.h>
#include <api/dll_iges_curve.h>

class MCAD_API DLL_IGES_ENTITY_122 : public DLL_IGES_ENTITY
{
public:
    DLL_IGES_ENTITY_122( IGES* aParent, bool create );
    DLL_IGES_ENTITY_122( DLL_IGES& aParent, bool create );
    virtual ~DLL_IGES_ENTITY_122();

    virtual bool NewEntity( void );

    bool GetGeneratrixEnd( MCAD_POINT& pt );
    bool GetGeneratrixEnd( double& aX, double& aY, double& aZ );
    bool GetDirectrix( IGES_CURVE*& aPtr );
    bool SetGeneratrixEnd( MCAD_POINT pt );
    bool SetGeneratrixEnd( double aX, double aY, double aZ );
    bool SetDirectrix( IGES_CURVE* aPtr );
};

#endif  // DLL_ENTITY_122_H

/*
 * file: iges_curve.h
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
 * Description: Base entity of all IGES Entity classes which represent curves.
 * These include:
 *      100 ENT_CIRCULAR_ARC
 *      104 ENT_CONIC_ARC
 *      110 ENT_LINE
 *      112 ENT_PARAM_SPLINE_CURVE
 *      116 *ENT_POINT
 *      126 ENT_NURBS_CURVE
 *      132 *ENT_CONNECT_POINT
 *      106 ENT_COPIOUS_DATA FORMS:
 *          1, 2, 3
 *          11, 12, 13
 *          63
 */

#ifndef IGES_CURVE_H
#define IGES_CURVE_H

#include <iostream>
#include <string>
#include <list>

#include <libigesconf.h>
#include <core/iges_base.h>
#include <core/iges_entity.h>
#include <geom/mcad_elements.h>

class IGES;             // Overarching data structure and parent to all entities
struct IGES_RECORD;     // Partially parsed single line of data from an IGES file

/**
 * Class IGES_CURVE
 * is the base class of all IGES Curve entities
 */
class IGES_CURVE : public IGES_ENTITY
{
protected:

    // members inherited from IGES_ENTITY
    virtual bool format( int &index ) = 0;
    virtual bool rescale( double sf ) = 0;

public:
    // public functions for libIGES only
    virtual bool associate(std::vector<IGES_ENTITY *> *entities) = 0;
    virtual bool unlink(IGES_ENTITY *aChild) = 0;
    virtual bool isOrphaned( void ) = 0;
    virtual bool addReference(IGES_ENTITY *aParentEntity, bool &isDuplicate) = 0;
    virtual bool delReference(IGES_ENTITY *aParentEntity) = 0;
    virtual bool readDE(IGES_RECORD *aRecord, std::ifstream &aFile, int &aSequenceVar) = 0;
    virtual bool readPD(std::ifstream &aFile, int &aSequenceVar) = 0;

public:
    IGES_CURVE( IGES* aParent );
    virtual ~IGES_CURVE();

    // specialized members of this class
    // methods required of parameterized curve entities

    /**
     * Function IsClosed
     * returns true if this entity represents a closed curve
     */
    virtual bool IsClosed( void ) = 0;


    /**
     * Function GetNCurves
     * returns the number of curves in this object; return values are:
     * -2 = Point or Point Association entity (no curves)
     * -1 = no valid curve entities assigned
     *  0 = simple curve entity such as a circle or NURBS curve
     * 1+ = # of internal curve entities, each of which may also be composite
     */
    virtual int GetNCurves( void ) = 0;


    /**
     * Function GetCurve
     * returns the a pointer to the associated curve entity with the given index
     * or NULL if no such entity exists.
     */
    virtual IGES_CURVE* GetCurve( int index ) = 0;


    /**
     * Function GetStartPoint
     * retrieves the start point of this curve entity and returns true
     * on success.
     *
     * @param pt = variable to store the start point
     * @param xform = set to true to apply any associated transforms to the point
     */
    virtual bool GetStartPoint( MCAD_POINT& pt, bool xform = true ) = 0;


    /**
     * Function GetEndPoint
     * retrieves the end point of this curve entity and returns true
     * on success.
     *
     * @param pt = variable to store the end point
     * @param xform = set to true to apply any associated transforms to the point
     */
    virtual bool GetEndPoint( MCAD_POINT& pt, bool xform = true ) = 0;


    /**
     * Function GetNSegments
     * returns the number of segments within this curve entity; for
     * composite curves this may be the same as GetNCurves but in the
     * case of piece-wise linear collections this would be the number
     * of segments to iterate over
     */
    virtual int GetNSegments( void ) = 0;


    // members inherited from IGES_ENTITY
    virtual bool SetEntityForm( int aForm ) = 0;
};

#endif  // IGES_CURVE_H

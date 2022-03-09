/*
 * file: entity126.h
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
 * Description: IGES Entity 126: NURBS Curve, Section 4.23, p.133(161+)
 */

#ifndef ENTITY_126_H
#define ENTITY_126_H

#include <libigesconf.h>
#include <core/iges_curve.h>
#include <geom/mcad_elements.h>

// XXX - NOTE: for now if we build with SISL support we can calculate
// the first and last points on a NURBS curve. Since the aim is to
// remove SISL from the core IGES code this should be deprecated in
// favor of a libIGES implementation of the de Boors - Cox algorithm.
#ifdef USE_SISL
    #include <sisl.h>
#endif


// NOTE:
// The associated parameter data are:
// K: int: Upper index of sum (note: not the number of knots)
// M: int: Degree of basis functions
// PROP1: int: 0/1 = nonplanar/planar
// PROP2: int: 0/1 = open/closed curve
// PROP3: int: 0/1 = rational/polynomial
// PROP4: int: 0/1 = nonperiodic/periodic
// ++ Let N = 1 + K - M,  and A = N + 2*M
// [Items 7 .. 7 + A]: Real: knot values (total items = A + 1 = 2 + K + M)
// [Items 8+A .. 8+A+K]: Real: weights (total items = K + 1)
// [Items 9+A+K .. 9+A+4*K]: Real[3]: Control points (total control points = K + 1)
// [Item 12+A+4*K] V0: starting parameter value
// [Item 13+A+4*K] V1: ending parameter value
// [Item 14+A+4*K] XNORM, YNORM, ZNORM: Real[3]: unit normal vector (ignored if curve is not planar)
//
// Forms:
//  0: Form of the curve is determined by BSPLINE parameters
//  1: line
//  2: Circular arc
//  3: Elliptical arc
//  4: Parabolic arc
//  5: Hyperbolic arc
//
// Unused DE items:
// + Structure
//


/**
 * Class IGES_ENTITY_126
 * represents a BSPLINE curve; depending on the context of the
 * entity referencing this curve, the curve may be a Parameter
 * Space Curve (such as when it is referenced by the BPTR entity
 * of a Curve on a Parametric Surface Entity) or a Model Space
 * Curve (such as when it is referenced by the CPTR entity of a
 * Curve on a Parametric Surface Entity).
 */
class IGES_ENTITY_126 : public IGES_CURVE
{
private:
    // norm: if provided the normal to the plane will be returned
    bool hasUniquePlane( MCAD_POINT* norm = NULL );
#ifdef USE_SISL
    SISLCurve* scurve;
#endif

protected:

    friend class IGES;
    virtual bool format( int &index );
    virtual bool rescale( double sf );
    // note: IGES specifies knots, weights, and control points
    // while SISL merges control points and weights (x, y, z, w)
    // for rational B-splines and omits weights in the case of
    // polynomial B-splines. The internal representation here
    // has been devised to integrate easily with SISL.
    int nKnots;         // number of knots
    int nCoeffs;        // number of weights and control points
    double *knots;
    double *coeffs;

    int K;
    int M;
    int PROP1;  // 0,1: Nonplanar, Planar and Unique
    int PROP2;  // 0,1: Open, Closed curve
    int PROP3;  // 0,1: Rational, Polynomial
    int PROP4;  // 0,1: Nonperiodic, Periodic
    double V0;
    double V1;
    MCAD_POINT vnorm;

public:
    // public functions for libIGES only
    virtual bool associate(std::vector<IGES_ENTITY *> *entities);
    virtual bool unlink(IGES_ENTITY *aChild);
    virtual bool isOrphaned( void );
    virtual bool addReference(IGES_ENTITY *aParentEntity, bool &isDuplicate);
    virtual bool delReference(IGES_ENTITY *aParentEntity);
    virtual bool readDE(IGES_RECORD *aRecord, std::ifstream &aFile, int &aSequenceVar);
    virtual bool readPD(std::ifstream &aFile, int &aSequenceVar);

public:
    IGES_ENTITY_126( IGES* aParent );
    virtual ~IGES_ENTITY_126();

    // virtual functions inherited from IGES_ENTITY
    virtual bool SetEntityForm( int aForm );
    virtual bool SetHierarchy( IGES_STAT_HIER aHierarchy );

    // virtual functions inherited from IGES_CURVE
    virtual bool IsClosed( void );
    virtual int GetNCurves( void );
    virtual IGES_CURVE* GetCurve( int index );
    virtual bool GetStartPoint( MCAD_POINT& pt, bool xform = true );
    virtual bool GetEndPoint( MCAD_POINT& pt, bool xform = true );
    virtual int GetNSegments( void );

    /**
     * Function GetNURBSData
     * retrieves parameters from the internal SISLCurve
     * representation of the curve and returns true
     * on success; if there is no defined curve the
     * function returns false.
     *
     * @param nCoeff = number of control points + weights
     * @param order = polynomial/spline order of the curve
     * @param knot = knot vectors
     * @param coeff = X, Y, Z, (and Weight if applicable) values for the curve
     * @param isRational = set to true if the curve is rational (unequal weights)
     * @param isClosed = set to true if the curve is closed
     * @param isPeriodic = set to true if the curve has been flagged as periodic
     */
    bool GetNURBSData( int& nCoeff, int& order, double** knot, double** coeff,
        bool& isRational, bool& isClosed, bool& isPeriodic, double& v0, double& v1 );

    /**
     * Function SetNURBSData
     * set parameters of the internal SISLCurve representation of the curve and
     * returns true on success.
     *
     * @param nCoeff = number of control points + weights
     * @param order = polynomial/spline order of the curve
     * @param knot = knot vectors
     * @param coeff = X, Y, Z, (and Weight if applicable) values for the curve
     * @param isRational = set to true if the curve is rational (unequal weights)
     */
    bool SetNURBSData( int nCoeff, int order, const double* knot,
        const double* coeff, bool isRational, double v0, double v1 );

    /**
     * Function IsPlanar
     * returns true if the curve lies on a plane
     */
    bool IsPlanar( void );

    /**
     * Function IsRational
     * returns true if the curve is a Rational B-Spline and
     * false if the curve is a Polynomial Curve.
     */
    bool IsRational( void );

    /**
     * Function isPeriodic
     * returns true if the curve is periodic
     */
    bool isPeriodic( void );

    /**
     * Function GetNormal
     * calculates the normal vector if the curve is planar and
     * returns true if the curve is planar.
     */
    bool GetNormal( MCAD_POINT& aNorm );
};

#endif  // ENTITY_126_H

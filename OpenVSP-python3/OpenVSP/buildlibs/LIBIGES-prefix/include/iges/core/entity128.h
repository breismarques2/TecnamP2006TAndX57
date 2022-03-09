/*
 * file: entity128.h
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
 * Description: IGES Entity 128: NURBS Surface, Section 4.24, p.137(165+)
 */

#ifndef ENTITY_128_H
#define ENTITY_128_H

#include <libigesconf.h>
#include <core/iges_entity.h>
#include <geom/mcad_elements.h>

// NOTE:
// The associated parameter data are:
// K1: int: Upper index of sum of first parameter (note: not the number of knots)
// K2: int: Upper index of sum of second parameter
// M1: int: Degree of basis functions of first parameter
// M2: int: Degree of basis functions of second parameter
// PROP1: int: 0/1 = curve 2 is closed for all values of Parameter 1
// PROP2: int: 0/1 = curve 1 is closed for all values of Parameter 2
// PROP3: int: 0/1 = rational/polynomial
// PROP4: int: 0/1 = nonperiodic/periodic with respect to first parameter
// PROP5: int: 0/1 = nonperiodic/periodic with respect to second parameter
// ++ Let N1 = 1 + K1 - M1
//        N2 = 1 + K2 - M2
//        A  = N1 + 2*M1
//        B  = N2 + 2*M2
//        C  = (1 + K1)*(1 + K2)
// [Items 10 .. 10 + A]: Real: knot values for Parameter 1 (total items = A + 1 = 2 + K1 + M1)
// [Items 11 + A .. 11 + A + B]: Real: knot values for Parameter 2 (total items = B + 1 = 2 + K2 + M2)
// [Items 12+A+B .. 11+A+B+C]: Real: weight[k1+1][k2+1] (total items = C)
// [Items 12+A+B+C .. 9+A+B+4*C]: Real[3]: Control points[k1+1][k2+1] (total control points = K + 1)
// [Item 12+A+B+4*C] U0: starting value parameter 1
// [Item 13+A+B+4*C] U1: ending value parameter 1
// [Item 14+A+B+4*C] V0: starting value parameter 2
// [Item 15+A+B+4*C] V1: ending value parameter 2
//
// Forms:
//  0: Form of the curve is determined by BSPLINE parameters
//  1: plane
//  2: right circular cylinder
//  3: cone
//  4: sphere
//  5: torus
//  6: surface of revolution
//  7: tabulated cylinder
//  8: ruled surface
//  9: general quadric surface
//
// Unused DE items:
// + Structure
//


/**
 * Class IGES_ENTITY_128
 * represents a BSPLINE Surface
 */
class IGES_ENTITY_128 : public IGES_ENTITY
{
protected:

    friend class IGES;
    virtual bool format( int &index );
    virtual bool rescale( double sf );

    int nKnots1;    // number of knots in parameter 1
    int nKnots2;    // number of knots in parameter 2
    int nCoeffs1;   // number of weights and control points in parameter 1
    int nCoeffs2;   // number of weights and control points in parameter 2
    double *knots1; // knots in patameter 1
    double *knots2; // knots in patameter 2
    double *coeffs; // control points and weights

    int K1;
    int K2;
    int M1;
    int M2;
    int PROP1;
    int PROP2;
    int PROP3;
    int PROP4;
    int PROP5;

    double U0;  // first parameter
    double U1;
    double V0;  // second parameter
    double V1;

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
    IGES_ENTITY_128( IGES* aParent );
    virtual ~IGES_ENTITY_128();

    // virtual functions inherited from IGES_ENTITY
    virtual bool SetEntityForm( int aForm );
    virtual bool SetHierarchy( IGES_STAT_HIER aHierarchy );

    /**
     * Function GetNURBSData
     * retrieves parameters from the internal SISLSurf
     * representation of the surface and returns true
     * on success; if there is no defined surface the
     * function returns false.
     *
     * @param nCoeff1 = number of control points + weights for Parameter U
     * @param nCoeff2 = number of control points + weights for Parameter V
     * @param order1 = polynomial/spline order of Parameter U
     * @param order2 = polynomial/spline order of Parameter V
     * @param knot1 = knot vectors for Parameter U
     * @param knot2 = knot vectors for Parameter V
     * @param coeff = X, Y, Z, (and Weight if applicable) values for UV surface
     * @param isRational = set to true if the surface is rational (unequal weights)
     * @param isClosed1 = set to true if the surface is closed in Parameter U
     * @param isClosed2 = set to true if the surface is closed in Parameter V
     * @param isPeriodic1 = set to true if the surface is periodic in U
     * @param isPeriodic2 = set to true if the surface is periodic in V
     */
    bool GetNURBSData( int& nCoeff1, int& nCoeff2, int& order1, int& order2,
                       double** knot1, double** knot2, double** coeff,
                       bool& isRational, bool& isClosed1, bool& isClosed2,
                       bool& isPeriodic1, bool& isPeriodic2,
                       double& u0, double& u1, double& v0, double& v1 );

    /**
     * Function SetNURBSData
     * Sets the parameters for the internal SISLSurf
     * representation of the surface and returns true
     * on success.
     *
     * @param nCoeff1 = number of control points + weights for Parameter U
     * @param nCoeff2 = number of control points + weights for Parameter V
     * @param order1 = polynomial/spline order of Parameter U
     * @param order2 = polynomial/spline order of Parameter V
     * @param knot1 = knot vectors for Parameter U
     * @param knot2 = knot vectors for Parameter V
     * @param coeff = X, Y, Z, (and Weight if applicable) values for UV surface
     * @param isRational = set to true if the surface is rational (unequal weights)
     * @param isPeriodic1 = set to true if the surface is periodic in U
     * @param isPeriodic2 = set to true if the surface is periodic in V
     */
    bool SetNURBSData( int nCoeff1, int nCoeff2, int order1, int order2,
                       const double* knot1, const double* knot2,
                       const double* coeff, bool isRational,
                       bool isPeriodic1, bool isPeriodic2,
                       double u0, double u1, double v0, double v1 );

    /**
     * Function IsRational
     * returns true if the surface is a rational B-Spline and
     * false if the surface is a polynomial.
     */
    bool IsRational( void );

    /**
     * Function isClosed1
     * returns true if the surface is closed in Parameter U
     */
    bool isClosed1( void );

    /**
     * Function isClosed1
     * returns true if the surface is closed in Parameter V
     */
    bool isClosed2( void );

    /**
     * Function isPeriodic1
     * returns true if the surface has been flagged as periodic in Parameter U
     */
    bool isPeriodic1( void );

    /**
     * Function isPeriodic2
     * returns true if the surface has been flagged as periodic in Parameter V
     */
    bool isPeriodic2( void );

};

#endif  // ENTITY_128_H

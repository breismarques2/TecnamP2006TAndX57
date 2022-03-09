/*
 * file: iges_geom_pcb.cpp
 *
 * Copyright 2015, Dr. Cirilo Bernardo (cirilo.bernardo@gmail.com)
 *
 * Description: This class represents an outline which consists of
 * a list of segments. Once the segments form a closed loop no
 * more segments may be added and the internal segments are arranged
 * in a counterclockwise fashion.
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

#include <sstream>
#include <cmath>
#include <core/iges.h>
#include <error_macros.h>
#include <geom/mcad_helpers.h>
#include <geom/mcad_segment.h>
#include <geom/geom_wall.h>
#include <geom/geom_cylinder.h>
#include <geom/iges_geom_pcb.h>
#include <core/entity100.h>
#include <core/entity102.h>
#include <core/entity110.h>
#include <core/entity124.h>
#include <core/entity126.h>
#include <core/entity128.h>
#include <core/entity142.h>
#include <core/entity144.h>
#include <sisl.h>


using namespace std;

#define GEOM_ERR( msg ) do { \
    msg.str(""); \
    msg << __FILE__ << ":" << __LINE__ << ":" << __FUNCTION__ << ": "; \
} while( 0 )


static bool newEnt102( IGES* aModel, IGES_ENTITY_102** cp )
{
    IGES_ENTITY* ep;

    if( !aModel->NewEntity( ENT_COMPOSITE_CURVE, &ep ) )
        return false;

    *cp = dynamic_cast<IGES_ENTITY_102*>( ep );

    if( !(*cp) )
    {
        aModel->DelEntity( ep );
        return false;
    }

    return true;
}


static bool newEnt142( IGES* aModel, IGES_ENTITY_142** cp )
{
    IGES_ENTITY* ep;

    if( !aModel->NewEntity( ENT_CURVE_ON_PARAMETRIC_SURFACE, &ep ) )
        return false;

    *cp = dynamic_cast<IGES_ENTITY_142*>( ep );

    if( !(*cp) )
    {
        aModel->DelEntity( ep );
        return false;
    }

    return true;
}


static bool newArc100( IGES* aModel, IGES_ENTITY_100** ap )
{
    IGES_ENTITY* ep;

    if( !aModel->NewEntity( ENT_CIRCULAR_ARC, &ep ) )
        return false;

    *ap = dynamic_cast<IGES_ENTITY_100*>( ep );

    if( !(*ap) )
    {
        aModel->DelEntity( ep );
        return false;
    }

    return true;
}


static bool newTx124( IGES* aModel, IGES_ENTITY_124** tp )
{
    IGES_ENTITY* ep;

    if( !aModel->NewEntity( ENT_TRANSFORMATION_MATRIX, &ep ) )
        return false;

    *tp = dynamic_cast<IGES_ENTITY_124*>(ep);

    if( !(*tp) )
    {
        aModel->DelEntity( ep );
        return false;
    }

    return true;
}


static bool newArc126( IGES* aModel, IGES_ENTITY_126** ap )
{
    IGES_ENTITY* ep;

    if( !aModel->NewEntity( ENT_NURBS_CURVE, &ep ) )
        return false;

    *ap = dynamic_cast<IGES_ENTITY_126*>( ep );

    if( !(*ap) )
    {
        aModel->DelEntity( ep );
        return false;
    }

    return true;
}


IGES_GEOM_PCB::IGES_GEOM_PCB()
{
    mIsClosed = false;
    mWinding = 0.0;
    mBBisOK = false;
    m_OutlineType = MCAD_OT_PCB;
    return;
}


IGES_GEOM_PCB::~IGES_GEOM_PCB()
{
    while( !msegments.empty() )
    {
        delete msegments.back();
        msegments.pop_back();
    }

    while( !mcutouts.empty() )
    {
        delete mcutouts.back();
        mcutouts.pop_back();
    }

    while( !mholes.empty() )
    {
        delete mholes.back();
        mholes.pop_back();
    }

    return;
}


// retrieve trimmed parametric surfaces representing vertical sides
// of the main outline and all cutouts
bool IGES_GEOM_PCB::GetVerticalSurface( IGES* aModel, bool& error,
                                            std::vector<IGES_ENTITY_144*>& aSurface,
                                            double aTopZ, double aBotZ )
{
    error = false;

    if( !mIsClosed )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[ERROR] outline is not closed";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );
        error = true;
        return false;
    }

    if( msegments.empty() )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[ERROR] outline is empty";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );
        error = true;
        return false;
    }

    list<MCAD_SEGMENT*>::iterator sSeg = msegments.begin();
    list<MCAD_SEGMENT*>::iterator eSeg = msegments.end();

    while( sSeg != eSeg )
    {
        if( !GetSegmentWall( aModel, aSurface, aTopZ, aBotZ, *sSeg, false ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not render a vertical surface of a segment";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }

        ++sSeg;
    }

    if( !mholes.empty() )
    {
        sSeg = mholes.begin();
        eSeg = mholes.end();

        while( sSeg != eSeg )
        {

            if( !GetSegmentWall( aModel, aSurface, aTopZ, aBotZ, *sSeg, true ) )
            {
                ostringstream msg;
                GEOM_ERR( msg );
                msg << "[ERROR] could not render a vertical surface of a hole";
                ERRMSG << msg.str() << "\n";
                errors.push_back( msg.str() );
                error = true;
                return false;
            }

            ++sSeg;
        }
    }

    if( !mcutouts.empty() )
    {
        list<MCAD_OUTLINE*>* cutouts = GetCutouts();
        list<MCAD_OUTLINE*>::iterator sOtln = cutouts->begin();
        list<MCAD_OUTLINE*>::iterator eOtln = cutouts->end();

        while( sOtln != eOtln )
        {
            list<MCAD_SEGMENT*>* segments = (*sOtln)->GetSegments();
            sSeg = segments->begin();
            eSeg = segments->end();

            while( sSeg != eSeg )
            {
                if( !GetSegmentWall( aModel, aSurface, aTopZ, aBotZ, *sSeg, true ) )
                {
                    ostringstream msg;
                    GEOM_ERR( msg );
                    msg << "[ERROR] could not render a vertical surface of a cutout";
                    ERRMSG << msg.str() << "\n";
                    errors.push_back( msg.str() );
                    error = true;
                    return false;
                }

                ++sSeg;
            }

            ++sOtln;
        }
    }

    return true;
}


// retrieve the trimmed parametric surfaces representing the
// top or bottom plane of the board
bool IGES_GEOM_PCB::GetTrimmedPlane( IGES* aModel, bool& error,
                      std::vector<IGES_ENTITY_144*>& aSurface,
                      double aHeight, bool aReverse )
{
    error = false;

    calcBoundingBox();

    if( !mIsClosed )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[ERROR] outline is not closed";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );
        error = true;
        return false;
    }

    if( msegments.empty() )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[ERROR] outline is empty";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );
        error = true;
        return false;
    }

    // Step 1: create the plane to be trimmed;
    IGES_ENTITY_144* plane = getUntrimmedPlane( aModel, aHeight, aReverse );

    if( !plane )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[ERROR] outline is not closed";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );
        error = true;
        return false;
    }

    // Step 2: create the outer bound (PTO); this is a Curve on Parametric Surface
    list<MCAD_SEGMENT*>::iterator sSeg = msegments.begin();
    list<MCAD_SEGMENT*>::iterator eSeg = msegments.end();
    list<IGES_CURVE*> ncurves;      // curves representing outlines in geometric representation
    list<IGES_ENTITY_126*> bcurves; // BREP curves representing outlines
    IGES_ENTITY_102*  ccurve[2];    // composite curve (BREP and geom representations)

    for( int i = 0; i < 2; ++i )
    {
        if( !newEnt102( aModel, &ccurve[i] ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not create a composite curve";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }
    }

    int acc = 0;
    while( sSeg != eSeg )
    {
        if( !GetCurveOnPlane( aModel, bcurves, mBottomLeft.x, mTopRight.x,
            mBottomLeft.y, mTopRight.y, aHeight, *sSeg, aReverse ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not render BREP curve on surface";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }

        if( !GetCurves( aModel, ncurves, aHeight, *sSeg ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not render geometric curve on surface";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }

        ++sSeg;
    }

    // stuff contents of ncurves, bcurves, and isurf->GetPTS() into ENTITY 142
    IGES_ENTITY_142* scurve;    // Curve on Surface

    if( !newEnt142( aModel, &scurve ) )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[ERROR] could not instantiate curve on surface";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );
        error = true;
        return false;
    }

    IGES_ENTITY* pts;
    plane->GetPTS( pts );
    scurve->SetSPTR( pts );
    list<IGES_ENTITY_126*>::iterator sBC = bcurves.begin();
    list<IGES_ENTITY_126*>::iterator eBC = bcurves.end();

    while( sBC != eBC )
    {
        if( !ccurve[0]->AddSegment( (IGES_CURVE*)(*sBC) ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not add BREP curve to composite curve";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }

        ++sBC;
    }

    list<IGES_CURVE*>::iterator sNC = ncurves.begin();
    list<IGES_CURVE*>::iterator eNC = ncurves.end();

    while( sNC != eNC )
    {
        if( !ccurve[1]->AddSegment( *sNC ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not add geom curve to composite curve";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }

        ++sNC;
    }

    scurve->CRTN = 1;
    scurve->PREF = 1;

    if( !scurve->SetBPTR( (IGES_ENTITY*)ccurve[0] )
        || !scurve->SetCPTR( (IGES_ENTITY*)ccurve[1] ) )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[ERROR] could not add composite curves to curve on surface";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );
        error = true;
        return false;
    }

    if( !plane->SetPTO( scurve ) )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[ERROR] could not add curve on surface to trimmed surface";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );
        error = true;
        return false;
    }

    // Step 3: create the irregular cutouts (PTI); these are Curves on Parametric Surface
    list<MCAD_OUTLINE*>::iterator sCO = mcutouts.begin();
    list<MCAD_OUTLINE*>::iterator eCO = mcutouts.end();

    acc = 0;
    while( sCO != eCO )
    {
        if( !newEnt142( aModel, &scurve ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not instantiate curve on surface";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }

        bcurves.clear();
        ncurves.clear();
        scurve->CRTN = 1;
        scurve->PREF = 1;

        for( int i = 0; i < 2; ++i )
        {
            if( !newEnt102( aModel, &ccurve[i] ) )
            {
                ostringstream msg;
                GEOM_ERR( msg );
                msg << "[ERROR] could not create a composite curve";
                ERRMSG << msg.str() << "\n";
                errors.push_back( msg.str() );
                error = true;
                return false;
            }
        }

        list<MCAD_SEGMENT*>* pSegList = (*sCO)->GetSegments();
        sSeg = pSegList->begin();
        eSeg = pSegList->end();

        while( sSeg != eSeg )
        {
            if( !GetCurveOnPlane( aModel, bcurves, mBottomLeft.x, mTopRight.x,
                mBottomLeft.y, mTopRight.y, aHeight, *sSeg, aReverse ) )
            {
                ostringstream msg;
                GEOM_ERR( msg );
                msg << "[ERROR] could not render BREP curve on surface";
                ERRMSG << msg.str() << "\n";
                errors.push_back( msg.str() );
                error = true;
                return false;
            }

            if( !GetCurves( aModel, ncurves, aHeight, *sSeg ) )
            {
                ostringstream msg;
                GEOM_ERR( msg );
                msg << "[ERROR] could not render geometric curve on surface";
                ERRMSG << msg.str() << "\n";
                errors.push_back( msg.str() );
                error = true;
                return false;
            }

            ++sSeg;
        }

        scurve->SetSPTR( pts );
        sBC = bcurves.begin();
        eBC = bcurves.end();

        while( sBC != eBC )
        {
            if( !ccurve[0]->AddSegment( (IGES_CURVE*)(*sBC) ) )
            {
                ostringstream msg;
                GEOM_ERR( msg );
                msg << "[ERROR] could not add BREP curve to composite curve";
                ERRMSG << msg.str() << "\n";
                errors.push_back( msg.str() );
                error = true;
                return false;
            }

            ++sBC;
        }


        sNC = ncurves.begin();
        eNC = ncurves.end();

        while( sNC != eNC )
        {
            if( !ccurve[1]->AddSegment( *sNC ) )
            {
                ostringstream msg;
                GEOM_ERR( msg );
                msg << "[ERROR] could not add geom curve to composite curve";
                ERRMSG << msg.str() << "\n";
                errors.push_back( msg.str() );
                error = true;
                return false;
            }

            ++sNC;
        }
        if( !scurve->SetBPTR( (IGES_ENTITY*)ccurve[0] )
            || !scurve->SetCPTR( (IGES_ENTITY*)ccurve[1] ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not add composite curves to curve on surface";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }

        if( !plane->AddPTI( scurve ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not add curve on surface to trimmed surface PTI list";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }

        ++sCO;
    }

    // Step 4: create the circular cutouts (PTI); these are Curves on Parametric Surface
    list<MCAD_SEGMENT*>::iterator sDH = mholes.begin();
    list<MCAD_SEGMENT*>::iterator eDH = mholes.end();

    acc = 0;
    while( sDH != eDH )
    {
        if( !newEnt142( aModel, &scurve ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not instantiate curve on surface";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }

        bcurves.clear();
        ncurves.clear();
        scurve->CRTN = 1;
        scurve->PREF = 1;

        for( int i = 0; i < 2; ++i )
        {
            if( !newEnt102( aModel, &ccurve[i] ) )
            {
                ostringstream msg;
                GEOM_ERR( msg );
                msg << "[ERROR] could not create a composite curve";
                ERRMSG << msg.str() << "\n";
                errors.push_back( msg.str() );
                error = true;
                return false;
            }
        }

        if( !GetCurveOnPlane( aModel, bcurves, mBottomLeft.x, mTopRight.x,
            mBottomLeft.y, mTopRight.y, aHeight, *sDH, aReverse ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not render BREP curve on surface";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }

        if( !GetCurves( aModel, ncurves, aHeight, *sDH ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not render geometric curve on surface";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }

        scurve->SetSPTR( pts );
        sBC = bcurves.begin();
        eBC = bcurves.end();

        while( sBC != eBC )
        {
            if( !ccurve[0]->AddSegment( (IGES_CURVE*)(*sBC) ) )
            {
                ostringstream msg;
                GEOM_ERR( msg );
                msg << "[ERROR] could not add BREP curve to composite curve";
                ERRMSG << msg.str() << "\n";
                errors.push_back( msg.str() );
                error = true;
                return false;
            }

            ++sBC;
        }


        sNC = ncurves.begin();
        eNC = ncurves.end();

        while( sNC != eNC )
        {
            if( !ccurve[1]->AddSegment( *sNC ) )
            {
                ostringstream msg;
                GEOM_ERR( msg );
                msg << "[ERROR] could not add geom curve to composite curve";
                ERRMSG << msg.str() << "\n";
                errors.push_back( msg.str() );
                error = true;
                return false;
            }

            ++sNC;
        }

        if( !scurve->SetBPTR( (IGES_ENTITY*)ccurve[0] )
            || !scurve->SetCPTR( (IGES_ENTITY*)ccurve[1] ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not add composite curves to curve on surface";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }

        if( !plane->AddPTI( scurve ) )
        {
            ostringstream msg;
            GEOM_ERR( msg );
            msg << "[ERROR] could not add curve on surface to trimmed surface PTI list";
            ERRMSG << msg.str() << "\n";
            errors.push_back( msg.str() );
            error = true;
            return false;
        }

        ++sDH;
    }

    aSurface.push_back( plane );
    return true;
}


// create a Trimmed Parametric Surface entity with only the PTS member instantiated
IGES_ENTITY_144* IGES_GEOM_PCB::getUntrimmedPlane( IGES* aModel, double aHeight, bool aReverse )
{
    double data[12];

    // note: the vertex order used here ensures that X is parameterized
    // in U (parameter 1) and Y is parameterized in V (parameter 2)

    if( aReverse )
    {
        // vertex 1, top left
        data[0] = mBottomLeft.x;
        data[1] = mTopRight.y;
        data[2] = aHeight;

        // vertex 2, top right
        data[3] = mTopRight.x;
        data[4] = mTopRight.y;
        data[5] = aHeight;

        // vertex 3, bottom left
        data[6] = mBottomLeft.x;
        data[7] = mBottomLeft.y;
        data[8] = aHeight;

        // vertex 4, bottom right
        data[9] = mTopRight.x;
        data[10] = mBottomLeft.y;
        data[11] = aHeight;
    }
    else
    {
        // vertex 1, bottom left
        data[0] = mBottomLeft.x;
        data[1] = mBottomLeft.y;
        data[2] = aHeight;

        // vertex 2, bottom right
        data[3] = mTopRight.x;
        data[4] = mBottomLeft.y;
        data[5] = aHeight;

        // vertex 3, top left
        data[6] = mBottomLeft.x;
        data[7] = mTopRight.y;
        data[8] = aHeight;

        // vertex 4, top right
        data[9] = mTopRight.x;
        data[10] = mTopRight.y;
        data[11] = aHeight;
    }

    int stat = 0;
    SISLSurf* plane;

    // create the NURBS representation of the surface
    s1536( data, 2, 2, 3, 2, 0, 0, 0, 0, 2, 2, 1, 1, &plane, &stat );

    switch( stat )
    {
        case 0:
            break;

        case 1:
            ERRMSG << "\n + [WARNING] unspecified problems creating NURBS plane\n";
            break;

        default:
            do
            {
                ostringstream msg;
                GEOM_ERR( msg );
                msg << "[ERROR] could not create NURBS plane";
                ERRMSG << msg.str() << "\n";
                errors.push_back( msg.str() );
            } while( 0 );

            return NULL;
            break;
    }

    // create the planar NURBS surface
    IGES_ENTITY* ep;
    IGES_ENTITY_128* isurf;

    if( !aModel->NewEntity( ENT_NURBS_SURFACE, &ep ) )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[INFO] could not instantiate new entity (type 128)";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );
        freeSurf( plane );
        plane = NULL;
        return NULL;
    }

    isurf = dynamic_cast<IGES_ENTITY_128*>( ep );
    isurf->SetDependency( STAT_DEP_PHY );

    if( NULL == isurf )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[BUG] cast failed on NURBS surface entity";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );
        aModel->DelEntity( ep );
        freeSurf( plane );
        plane = NULL;
        return NULL;
    }

    // copy the NURBS surface data to isurf
    int ike1 = plane->in1 + plane->ik1 - 1;
    int ike2 = plane->in2 + plane->ik2 - 1;

    if( !isurf->SetNURBSData( plane->in1, plane->in2, plane->ik1, plane->ik2,
        plane->et1, plane->et2, plane->ecoef, false, false, false,
        plane->et1[0], plane->et1[ike1], plane->et2[0], plane->et2[ike2] ) )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[BUG] failed to transfer data to surface entity";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );
        aModel->DelEntity( ep );
        freeSurf( plane );
        plane = NULL;
        return NULL;
    }

    freeSurf( plane );
    plane = NULL;

    // instantiate the trimmed parametric surface entity
    IGES_ENTITY_144* itps;

    if( !aModel->NewEntity( ENT_TRIMMED_PARAMETRIC_SURFACE, &ep ) )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[INFO] could not instantiate new entity (type 144)";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );
        aModel->DelEntity( (IGES_ENTITY*)isurf );
        return NULL;
    }

    itps = dynamic_cast<IGES_ENTITY_144*>( ep );

    if( NULL == itps )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[BUG] cast failed on curve on trimmed surface entity";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );
        aModel->DelEntity( ep );
        aModel->DelEntity( (IGES_ENTITY*)isurf );
        return NULL;
    }

    itps->N1 = 1;   // surface is to be trimmed by specified entities

    if( !itps->SetPTS( (IGES_ENTITY*)isurf ) )
    {
        ostringstream msg;
        GEOM_ERR( msg );
        msg << "[BUG] failed to transfer data to parametric curve on surface";
        ERRMSG << msg.str() << "\n";
        errors.push_back( msg.str() );

        aModel->DelEntity( (IGES_ENTITY*)isurf );
        aModel->DelEntity( (IGES_ENTITY*)itps );
        return NULL;
    }

    return itps;
}


// retrieve the representation of the curve as IGES 2D primitives which
// are suitable as a subordinate to the CPTR of a Trimmed Parametric Surface.
// It is essential that a list of curves be returned as it is up to the
// user to decide whether these curves shall be part of a loop consiting
// of multiple segments.
bool IGES_GEOM_PCB::GetCurves( IGES* aModel, std::list<IGES_CURVE*>& aCurves,
    double zHeight, MCAD_SEGMENT* aSegment )
{
    bool ok;

    switch( aSegment->GetSegType() )
    {
        case MCAD_SEGTYPE_LINE:
            ok = getCurveLine( aModel, aCurves, zHeight, aSegment );
            break;

        case MCAD_SEGTYPE_ARC:
            ok = getCurveArc( aModel, aCurves, zHeight, aSegment );
            break;

        case MCAD_SEGTYPE_CIRCLE:
            ok = getCurveCircle( aModel, aCurves, zHeight, aSegment );
            break;

        default:
            ERRMSG << "\n + [ERROR] invalid segment type (" << aSegment->GetSegType() << ")\n";
            ok = false;
            break;
    }

    return ok;
}


// retrieve the curve as a list of parametric curves on plane which arc suitable
// as subordinates to the BPTR of a Trimmed Parametric Surface. It is up to the
// user to determine whether these curves shall be part of a loop consisting of
// multiple segments.
bool IGES_GEOM_PCB::GetCurveOnPlane(  IGES* aModel, std::list<IGES_ENTITY_126*>& aCurves,
                                          double aMinX, double aMaxX, double aMinY, double aMaxY,
                                          double zHeight, MCAD_SEGMENT* aSegment, bool aReverse )
{
    double scale = 1.0 / ( aMaxX - aMinX ); // scale factor (must be same for X and Y axes)
    bool ok;

    switch( aSegment->GetSegType() )
    {
        case MCAD_SEGTYPE_CIRCLE:
            ok = copCircle( aModel, aCurves, aMinX, aMinY, scale, zHeight, aSegment, aReverse );
            break;

        case MCAD_SEGTYPE_ARC:
            ok = copArc( aModel, aCurves, aMinX, aMinY, scale, zHeight, aSegment, aReverse );
            break;

        case MCAD_SEGTYPE_LINE:
            ok = copLine(aModel, aCurves, aMinX, aMinY, scale, zHeight, aSegment, aReverse);
            break;

        default:
            do
            {
                ERRMSG << "\n + [INFO] invalid segment type: " << aSegment->GetSegType() << "\n";
                return false;
            } while( 0 );

            break;
    }

    if( !ok )
    {
        ERRMSG << "\n + [INFO] failure; see messages above\n";
        return false;
    }

    return true;
}


// retrieve a trimmed parametric surface representing a vertical side
bool IGES_GEOM_PCB::GetSegmentWall( IGES* aModel, std::vector<IGES_ENTITY_144*>& aSurface,
    double aTopZ, double aBotZ, MCAD_SEGMENT* aSegment, bool aReverse )
{
    if( !aModel )
    {
        ERRMSG << "\n + [ERROR] null pointer passed for IGES model\n";
        return false;
    }

    if( abs( aTopZ - aBotZ ) < 1e-6 )
    {
        ERRMSG << "\n + [ERROR] degenerate surface\n";
        return false;
    }

    if( !aSegment->GetSegType() )
    {
        ERRMSG << "\n + [ERROR] no model data to work with\n";
        return false;
    }

    bool ok = false;

    switch( aSegment->GetSegType() )
    {
        case MCAD_SEGTYPE_CIRCLE:
        case MCAD_SEGTYPE_ARC:
            do
            {
                IGES_GEOM_CYLINDER cyl;

                cyl.SetParams( aSegment->GetCenter(), aSegment->GetStart(),
                    aSegment->GetEnd() );

                IGES_ENTITY_144** surfs = NULL;
                int nParts;

                if( ( aSegment->IsCW() && !aReverse ) || ( !aSegment->IsCW() && aReverse ) )
                    ok = cyl.Instantiate( aModel, aTopZ, aBotZ, surfs, nParts, true );
                else
                    ok = cyl.Instantiate( aModel, aTopZ, aBotZ, surfs, nParts, false );

                if( ok )
                {
                    for( int i = 0; i < nParts; ++i )
                        aSurface.push_back( surfs[i] );

                    delete [] surfs;
                }

            } while( 0 );

            break;

        default:
            do
            {
                IGES_GEOM_WALL wall;
                MCAD_POINT p0 = aSegment->GetMStart();
                p0.z = aTopZ;
                MCAD_POINT p1 = aSegment->GetMEnd();
                p1.z = aTopZ;
                MCAD_POINT p2 = aSegment->GetMEnd();
                p2.z = aBotZ;
                MCAD_POINT p3 = aSegment->GetMStart();
                p3.z = aBotZ;

                if( aReverse )
                    wall.SetParams( p0, p1, p2, p3 );
                else
                    wall.SetParams( p3, p2, p1, p0 );

                IGES_ENTITY_144* ep = wall.Instantiate( aModel );

                if( NULL == ep )
                {
                    ERRMSG << "\n + [ERROR] could not create solid model feature\n";
                    ok = false;
                }
                else
                {
                    aSurface.push_back( ep );
                    ok = true;
                }

            } while( 0 );

            break;
    }

    return ok;
}


bool IGES_GEOM_PCB::getCurveCircle( IGES* aModel, std::list<IGES_CURVE*>& aCurves,
    double zHeight, MCAD_SEGMENT* aSegment )
{
    IGES_ENTITY_100* arcs[2];
    arcs[0] = NULL;
    arcs[1] = NULL;

    for( int i = 0; i < 2; ++i )
    {
        if( !newArc100( aModel, &arcs[i] ) )
        {
            for( int j = 0; j < i; ++j )
                aModel->DelEntity( (IGES_ENTITY*)arcs[j] );

            ERRMSG << "\n + [INFO] could not create circular arc #" << i << "\n";
            return false;
        }
    }

    MCAD_POINT mcenter = aSegment->GetCenter();
    double mradius = aSegment->GetRadius();

    arcs[0]->zOffset = zHeight;
    arcs[0]->xCenter = mcenter.x;
    arcs[0]->yCenter = mcenter.y;
    arcs[0]->xStart = mcenter.x + mradius;
    arcs[0]->yStart = mcenter.y;
    arcs[0]->xEnd = mcenter.x - mradius;
    arcs[0]->yEnd = mcenter.y;

    arcs[1]->zOffset = zHeight;
    arcs[1]->xCenter = mcenter.x;
    arcs[1]->yCenter = mcenter.y;
    arcs[1]->xStart = mcenter.x - mradius;
    arcs[1]->yStart = mcenter.y;
    arcs[1]->xEnd = mcenter.x + mradius;
    arcs[1]->yEnd = mcenter.y;

    for( int i = 0; i < 2; ++i )
    {
        IGES_CURVE* cp = dynamic_cast<IGES_CURVE*>( arcs[i] );

        if( !cp )
        {
            for( int j = i; j < 2; ++j )
                aModel->DelEntity( (IGES_ENTITY*)arcs[j] );

            ERRMSG << "\n + [BUG] could not typecast arcs to IGES_CURVE\n";
            return false;
        }

        aCurves.push_back( cp );
    }

    return true;
}


bool IGES_GEOM_PCB::getCurveArc( IGES* aModel, std::list<IGES_CURVE*>& aCurves,
                                     double zHeight, MCAD_SEGMENT* aSegment )
{
    int na = 0; // number of arcs (and transforms if we have a CW arc)

    IGES_ENTITY_100* arcs[3];   // the arc may consist of up to 3 segments
    IGES_ENTITY_124* tx[3];     // for CW arcs each arc has a corresponding transform

    double a0;
    double a1;
    double mradius = aSegment->GetRadius();
    MCAD_POINT p0 = aSegment->GetMStart();
    MCAD_POINT p1 = aSegment->GetMEnd();
    MCAD_POINT pc = aSegment->GetCenter();
    MCAD_POINT mcenter = pc;

    if( aSegment->IsCW() )
    {
        p0.x = pc.x - p0.x;
        p1.x = pc.x - p1.x;
        pc.x = 0.0;

        a0 = atan2( p0.y - pc.y, p0.x );
        a1 = atan2( p1.y - pc.y, p1.x );

        if( a1 < a0 )
            a1 += 2.0 * M_PI;

    }
    else
    {
        a0 = aSegment->GetMSAngle();
        a1 = aSegment->GetMEAngle();
    }

    if( a0 >= 0.0 && a0 < M_PI )
    {
        if( a1 <= M_PI )
        {
            if( !newArc100( aModel, &arcs[0] ) )
            {
                ERRMSG << "\n + [INFO] could not instantiate IGES arc\n";
                return false;
            }

            arcs[0]->zOffset = zHeight;
            arcs[0]->xCenter = pc.x;
            arcs[0]->yCenter = pc.y;
            arcs[0]->xStart = p0.x;
            arcs[0]->yStart = p0.y;
            arcs[0]->xEnd = p1.x;
            arcs[0]->yEnd = p1.y;
            na = 1;
        }
        else
        {
            if( a1 <= 2.0 * M_PI )
            {
                for( int i = 0; i < 2; ++i )
                {
                    if( !newArc100( aModel, &arcs[i] ) )
                    {
                        for( int j = 0; j < i; ++j )
                            aModel->DelEntity( (IGES_ENTITY*)arcs[j] );

                        ERRMSG << "\n + [INFO] could not create circular arc #" << i << "\n";
                        return false;
                    }
                }

                arcs[0]->zOffset = zHeight;
                arcs[0]->xCenter = pc.x;
                arcs[0]->yCenter = pc.y;
                arcs[0]->xStart = p0.x;
                arcs[0]->yStart = p0.y;
                arcs[0]->xEnd = pc.x - mradius;
                arcs[0]->yEnd = pc.y;

                arcs[1]->zOffset = zHeight;
                arcs[1]->xCenter = pc.x;
                arcs[1]->yCenter = pc.y;
                arcs[1]->xStart = pc.x - mradius;
                arcs[1]->yStart = pc.y;
                arcs[1]->xEnd = p1.x;
                arcs[1]->yEnd = p1.y;

                na = 2;
            } // M_PI < a1 <= 2*M_PI
            else
            {
                for( int i = 0; i < 3; ++i )
                {
                    if( !newArc100( aModel, &arcs[i] ) )
                    {
                        for( int j = 0; j < i; ++j )
                            aModel->DelEntity( (IGES_ENTITY*)arcs[j] );

                        ERRMSG << "\n + [INFO] could not create circular arc #" << i << "\n";
                        return false;
                    }
                }

                arcs[0]->zOffset = zHeight;
                arcs[0]->xCenter = pc.x;
                arcs[0]->yCenter = pc.y;
                arcs[0]->xStart = p0.x;
                arcs[0]->yStart = p0.y;
                arcs[0]->xEnd = pc.x - mradius;
                arcs[0]->yEnd = pc.y;

                arcs[1]->zOffset = zHeight;
                arcs[1]->xCenter = pc.x;
                arcs[1]->yCenter = pc.y;
                arcs[1]->xStart = pc.x - mradius;
                arcs[1]->yStart = pc.y;
                arcs[1]->xEnd = pc.x + mradius;
                arcs[1]->yEnd = pc.y;

                arcs[2]->zOffset = zHeight;
                arcs[2]->xCenter = pc.x;
                arcs[2]->yCenter = pc.y;
                arcs[2]->xStart = pc.x + mradius;
                arcs[2]->yStart = pc.y;
                arcs[2]->xEnd = p1.x;
                arcs[2]->yEnd = p1.y;

                na = 3;
            }   // a1 > 2*M_PI
        }   // ( 0.0 <= a0 < M_PI )

    }
    else if( a0 == M_PI )
    {
        if( a1 <= 2.0 * M_PI )
        {
            if( !newArc100( aModel, &arcs[0] ) )
            {
                ERRMSG << "\n + [INFO] could not instantiate IGES arc\n";
                return false;
            }

            arcs[0]->zOffset = zHeight;
            arcs[0]->xCenter = pc.x;
            arcs[0]->yCenter = pc.y;
            arcs[0]->xStart = p0.x;
            arcs[0]->yStart = p0.y;
            arcs[0]->xEnd = p1.x;
            arcs[0]->yEnd = p1.y;
            na = 1;
        }
        else
        {
            for( int i = 0; i < 2; ++i )
            {
                if( !newArc100( aModel, &arcs[i] ) )
                {
                    for( int j = 0; j < i; ++j )
                        aModel->DelEntity( (IGES_ENTITY*)arcs[j] );

                    ERRMSG << "\n + [INFO] could not create circular arc #" << i << "\n";
                    return false;
                }
            }

            arcs[0]->zOffset = zHeight;
            arcs[0]->xCenter = pc.x;
            arcs[0]->yCenter = pc.y;
            arcs[0]->xStart = p0.x;
            arcs[0]->yStart = p0.y;
            arcs[0]->xEnd = pc.x + mradius;
            arcs[0]->yEnd = pc.y;

            arcs[1]->zOffset = zHeight;
            arcs[1]->xCenter = pc.x;
            arcs[1]->yCenter = pc.y;
            arcs[1]->xStart = pc.x + mradius;
            arcs[1]->yStart = pc.y;
            arcs[1]->xEnd = p1.x;
            arcs[1]->yEnd = p1.y;

            na = 2;
        }
    }   // a0 == M_PI
    else
    {
        if( a1 <= 0.0 )
        {
            if( !newArc100( aModel, &arcs[0] ) )
            {
                ERRMSG << "\n + [INFO] could not instantiate IGES arc\n";
                return false;
            }

            arcs[0]->zOffset = zHeight;
            arcs[0]->xCenter = pc.x;
            arcs[0]->yCenter = pc.y;
            arcs[0]->xStart = p0.x;
            arcs[0]->yStart = p0.y;
            arcs[0]->xEnd = p1.x;
            arcs[0]->yEnd = p1.y;
            na = 1;
        }
        else if( a1 <= M_PI )
        {
            for( int i = 0; i < 2; ++i )
            {
                if( !newArc100( aModel, &arcs[i] ) )
                {
                    for( int j = 0; j < i; ++j )
                        aModel->DelEntity( (IGES_ENTITY*)arcs[j] );

                    ERRMSG << "\n + [INFO] could not create circular arc #" << i << "\n";
                    return false;
                }
            }

            arcs[0]->zOffset = zHeight;
            arcs[0]->xCenter = pc.x;
            arcs[0]->yCenter = pc.y;
            arcs[0]->xStart = p0.x;
            arcs[0]->yStart = p0.y;
            arcs[0]->xEnd = pc.x + mradius;
            arcs[0]->yEnd = pc.y;

            arcs[1]->zOffset = zHeight;
            arcs[1]->xCenter = pc.x;
            arcs[1]->yCenter = pc.y;
            arcs[1]->xStart = pc.x + mradius;
            arcs[1]->yStart = pc.y;
            arcs[1]->xEnd = p1.x;
            arcs[1]->yEnd = p1.y;

            na = 2;
        }   // a0 < 0 && a1 <= M_PI
        else
        {
            for( int i = 0; i < 3; ++i )
            {
                if( !newArc100( aModel, &arcs[i] ) )
                {
                    for( int j = 0; j < i; ++j )
                        aModel->DelEntity( (IGES_ENTITY*)arcs[j] );

                    ERRMSG << "\n + [INFO] could not create circular arc #" << i << "\n";
                    return false;
                }
            }

            arcs[0]->zOffset = zHeight;
            arcs[0]->xCenter = pc.x;
            arcs[0]->yCenter = pc.y;
            arcs[0]->xStart = p0.x;
            arcs[0]->yStart = p0.y;
            arcs[0]->xEnd = pc.x + mradius;
            arcs[0]->yEnd = pc.y;

            arcs[1]->zOffset = zHeight;
            arcs[1]->xCenter = pc.x;
            arcs[1]->yCenter = pc.y;
            arcs[1]->xStart = pc.x + mradius;
            arcs[1]->yStart = pc.y;
            arcs[1]->xEnd = pc.x - mradius;
            arcs[1]->yEnd = pc.y;

            arcs[2]->zOffset = zHeight;
            arcs[2]->xCenter = pc.x;
            arcs[2]->yCenter = pc.y;
            arcs[2]->xStart = pc.x - mradius;
            arcs[2]->yStart = pc.y;
            arcs[2]->xEnd = p1.x;
            arcs[2]->yEnd = p1.y;

            na = 3;
        }   // a0 < 0 && a1 > M_PI
    }   // a0 < 0.0

    if( aSegment->IsCW() )
    {
        // instantiate the transforms
        for( int i = 0; i < na; ++i )
        {
            if( !newTx124( aModel, &tx[i] ) )
            {
                ERRMSG << "\n + [INFO] could not instantiate IGES transform matrix\n";
                return false;
            }

            tx[i]->T.T.x = mcenter.x;
            tx[i]->T.T.z = 2.0 * zHeight;
            tx[i]->T.R.v[0][0] = -1.0;
            tx[i]->T.R.v[2][2] = -1.0;
            tx[i]->SetEntityForm( 1 );

            if( !arcs[i]->SetTransform( tx[i] ) )
            {
                ERRMSG << "\n + [INFO] could not set transform on arc\n";
                return false;
            }
        }
    }

    for( int i = 0; i < na; ++i )
        aCurves.push_back( (IGES_CURVE*)(arcs[i]) );

    return true;
}


bool IGES_GEOM_PCB::getCurveLine( IGES* aModel, std::list<IGES_CURVE*>& aCurves,
    double zHeight, MCAD_SEGMENT* aSegment )
{
    IGES_ENTITY*     ep;
    IGES_ENTITY_110* lp;
    IGES_CURVE*      cp;

    if( !aModel->NewEntity( ENT_LINE, &ep ) )
    {
        ERRMSG << "\n + [INFO] could not instantiate IGES line\n";
        return false;
    }

    lp = dynamic_cast<IGES_ENTITY_110*>(ep);

    if( !lp )
    {
        aModel->DelEntity( ep );
        ERRMSG << "\n + [BUG] could not typecast IGES line\n";
        return false;
    }

    MCAD_POINT mstart = aSegment->GetMStart();
    MCAD_POINT mend = aSegment->GetMEnd();

    lp->X1 = mstart.x;
    lp->Y1 = mstart.y;
    lp->Z1 = zHeight;
    lp->X2 = mend.x;
    lp->Y2 = mend.y;
    lp->Z2 = zHeight;

    cp = dynamic_cast<IGES_CURVE*>(ep);

    if( !cp )
    {
        aModel->DelEntity( ep );
        ERRMSG << "\n + [BUG] could not typecast line to IGES_CURVE\n";
        return false;
    }

    aCurves.push_back( cp );
    return true;
}


bool IGES_GEOM_PCB::copCircle( IGES* aModel, std::list<IGES_ENTITY_126*>& aCurves,
                                   double offX, double offY, double aScale,
                                   double zHeight, MCAD_SEGMENT* aSegment, bool aReverse )
{
    IGES_ENTITY_126* cp[2];

    for( int i = 0; i < 2; ++ i )
    {
        if( !newArc126( aModel, &cp[i] ) )
        {
            for( int j = 0; j < i; ++j )
                aModel->DelEntity( (IGES_ENTITY*)(cp[j]) );

            ERRMSG << "\n + [INFO] could not instantiate IGES NURBS curve\n";
            return false;
        }
    }

    MCAD_POINT mcenter = aSegment->GetCenter();
    double mradius = aSegment->GetRadius();
    double axis[3] = { 0.0, 0.0, 1.0 }; // normal to the plane of the arc
    double startp[3];
    double centrp[3];
    centrp[0] = ( mcenter.x - offX ) * aScale;
    centrp[1] = ( mcenter.y - offY ) * aScale;
    centrp[2] = zHeight;
    SISLCurve* pCurve[2] = { NULL, NULL };
    int stat = 0;

    if( aReverse )
    {
        axis[2] = -1.0;
        centrp[1] = 1.0 - centrp[1];
    }

    for( int i = 0; i < 2; ++i )
    {
        if( 0 == i )
        {
            startp[0] = centrp[0] + mradius * aScale;
            startp[1] = centrp[1];
            startp[2] = centrp[2];
        }
        else
        {
            startp[0] = centrp[0] - mradius * aScale;
            startp[1] = centrp[1];
            startp[2] = centrp[2];
        }

        s1303( startp, 1e-8, M_PI, centrp, axis, 3, &pCurve[i], &stat );

        switch( stat )
        {
            case 0:
                break;

            case 1:
                ERRMSG << "\n + [WARNING] unspecified problems creating NURBS arc\n";
                stat = 0;
                break;

            default:
                for( int j = 0; j < i; ++j )
                    freeCurve( pCurve[j] );

                for( int j = 0; j < 2; ++j )
                    aModel->DelEntity( (IGES_ENTITY*)(cp[j]) );

                ERRMSG << "\n + [ERROR] could not create NURBS arc\n";
                return false;
                break;
        }
    }

    for( int i = 0; i < 2; ++i )
    {
        int iKE = pCurve[i]->in + pCurve[i]->ik - 1;

        if( !cp[i]->SetNURBSData( pCurve[i]->in, pCurve[i]->ik, pCurve[i]->et,
            pCurve[i]->ecoef, false, pCurve[i]->et[0], pCurve[i]->et[iKE]) )
        {
            for( int j = 0; j < 2; ++j )
            {
                freeCurve( pCurve[j] );
                aModel->DelEntity( (IGES_ENTITY*)(cp[j]) );
            }

            ERRMSG << "\n + [WARNING] problems setting data in NURBS arc\n";
            return false;
        }
    }

    for( int i = 0; i < 2; ++i )
    {
        freeCurve( pCurve[i] );
        aCurves.push_back( cp[i] );
    }

    return true;
}


bool IGES_GEOM_PCB::copArc( IGES* aModel, std::list<IGES_ENTITY_126*>& aCurves,
                                double offX, double offY, double aScale,
                                double zHeight, MCAD_SEGMENT* aSegment, bool aReverse )
{
    IGES_ENTITY_126* cp[3]; // we may have up to 3 entities to describe a single arc

    for( int i = 0; i < 3; ++i )
        cp[i] = NULL;

    MCAD_POINT mstart = aSegment->GetStart();
    MCAD_POINT mend = aSegment->GetEnd();
    MCAD_POINT mcenter = aSegment->GetCenter();
    double mradius = aSegment->GetRadius();

    double sAng;
    double eAng;
    MCAD_POINT ptArc[2];    // start and end point of the arc; contingent on direction
    MCAD_POINT ptC;         // true center point; required for calculations for CW arcs
    double angles[3];       // up to 3 subtended angles
    double spt[3][3];       // start points for each angle
    double cpt[3];          // center point for all angles

    sAng = aSegment->GetStartAngle();
    eAng = aSegment->GetEndAngle();

    ptArc[0] = mstart;
    ptArc[0].x = ( ptArc[0].x - offX ) * aScale;
    ptArc[0].y = ( ptArc[0].y - offY ) * aScale;
    ptArc[0].z = zHeight;

    ptArc[1] = mend;
    ptArc[1].x = ( ptArc[1].x - offX ) * aScale;
    ptArc[1].y = ( ptArc[1].y - offY ) * aScale;
    ptArc[1].z = zHeight;

    cpt[0] = ( mcenter.x - offX ) * aScale;
    cpt[1] = ( mcenter.y - offY ) * aScale;
    cpt[2] = zHeight;

    if( aReverse )
    {
        ptArc[0].y = 1.0 - ptArc[0].y;
        ptArc[1].y = 1.0 - ptArc[1].y;
        cpt[1] = 1.0 - cpt[1];
    }

    if( sAng > M_PI )
    {
        sAng -= 2.0 * M_PI;
        eAng -= 2.0 * M_PI;
    }

    int na = 0; // number of arcs in the curve
    spt[0][0] = ptArc[0].x;
    spt[0][1] = ptArc[0].y;
    spt[0][2] = ptArc[0].z;

    if( sAng < 0.0 )
    {
        // range of angles will be > -M_PI .. < 2*M_PI
        if( eAng <= 0.0 )
        {
            angles[0] = eAng - sAng;
            na = 1;
        }
        else
        {
            angles[0] = -sAng;

            spt[1][0] = cpt[0] + mradius * aScale;
            spt[1][1] = cpt[1];
            spt[1][2] = cpt[2];

            if( eAng <= M_PI )
            {
                angles[1] = eAng;
                na = 2;
            }
            else
            {
                angles[1] = M_PI;
                angles[2] = eAng - M_PI;
                spt[2][0] = cpt[0] - mradius * aScale;
                spt[2][1] = cpt[1];
                spt[2][2] = cpt[2];
                na = 3;
            }
        }
    }
    else
    {
        // range of angles will be >= 0 .. < 3*M_PI
        if( eAng <= M_PI || ( sAng >= M_PI && eAng <= 2.0 * M_PI ) )
        {
            angles[0] = eAng - sAng;
            na = 1;
        }
        else
        {
            if( sAng < M_PI )
            {
                // CASE: sAng < M_PI && eAng > M_PI
                angles[0] = M_PI - sAng;
                spt[1][0] = cpt[0] - mradius * aScale;
                spt[1][1] = cpt[1];
                spt[1][2] = cpt[2];

                if( eAng <= 2.0 * M_PI )
                {
                    angles[1] = eAng - M_PI;
                    na = 2;
                }
                else
                {
                    angles[1] = M_PI;
                    angles[2] = eAng - 2.0 * M_PI;
                    spt[2][0] = cpt[0] + mradius * aScale;
                    spt[2][1] = cpt[1];
                    spt[2][2] = cpt[2];
                    na = 3;
                }
            }
            else
            {
                // CASE: sAng == M_PI && eAng > 2.0 * M_PI
                if( eAng <= 2.0 * M_PI )
                {
                    angles[0] = eAng - sAng;
                    na = 1;
                }
                else
                {
                    angles[0] = 2.0 * M_PI - sAng;
                    angles[1] = eAng - 2.0 * M_PI;
                    spt[1][0] = cpt[0] + mradius * aScale;
                    spt[1][1] = cpt[1];
                    spt[1][2] = cpt[2];
                    na = 2;
                }
            }
        }
    }

    for( int i = 0; i < na; ++ i )
    {
        if( !newArc126( aModel, &cp[i] ) )
        {
            for( int j = 0; j < i; ++j )
                aModel->DelEntity( (IGES_ENTITY*)(cp[j]) );

            ERRMSG << "\n + [INFO] could not instantiate IGES NURBS curve\n";
            return false;
        }
    }

    double axis[3] = { 0.0, 0.0, 1.0 }; // normal to the plane of the arc
    double startp[3];
    SISLCurve* pCurve[3] = { NULL, NULL, NULL };
    int stat = 0;

    if( (aSegment->IsCW() && !aReverse) || (!aSegment->IsCW() && aReverse) )
        axis[2] = -1.0;

    // set up the NURBS data
    for( int i = 0; i < na; ++i )
    {
        if( aSegment->IsCW() )
        {
            if( i < (na -1) )
            {
                startp[0] = spt[i+1][0];
                startp[1] = spt[i+1][1];
                startp[2] = spt[i+1][2];
            }
            else
            {
                startp[0] = ptArc[1].x;
                startp[1] = ptArc[1].y;
                startp[2] = ptArc[1].z;
            }
        }
        else
        {
            startp[0] = spt[i][0];
            startp[1] = spt[i][1];
            startp[2] = spt[i][2];
        }

        s1303( startp, 1e-8, angles[i], cpt, axis, 3, &pCurve[i], &stat );

        switch( stat )
        {
            case 0:
                break;

            case 1:
                ERRMSG << "\n + [WARNING] unspecified problems creating NURBS arc\n";
                stat = 0;
                break;

            default:
                for( int j = 0; j < i; ++j )
                    freeCurve( pCurve[j] );

                for( int j = 0; j < na; ++j )
                    aModel->DelEntity( (IGES_ENTITY*)(cp[j]) );

                ERRMSG << "\n + [ERROR] could not create NURBS arc\n";
                return false;
                break;
        }
    }

    for( int i = 0; i < na; ++i )
    {
        int idx;

        if( aSegment->IsCW()  )
            idx = na - i - 1;
        else
            idx = i;

        int iKE = pCurve[idx]->in + pCurve[idx]->ik - 1;

        if( !cp[i]->SetNURBSData( pCurve[idx]->in, pCurve[idx]->ik, pCurve[idx]->et,
            pCurve[idx]->ecoef, false, pCurve[idx]->et[0], pCurve[idx]->et[iKE] ) )
        {
            for( int j = 0; j < na; ++j )
            {
                if( pCurve[j] )
                    freeCurve( pCurve[j] );

                aModel->DelEntity( (IGES_ENTITY*)(cp[j]) );
            }

            ERRMSG << "\n + [WARNING] problems setting data in NURBS arc\n";
            return false;
        }
    }

    for( int i = 0; i < na; ++i )
    {
        freeCurve( pCurve[i] );
        aCurves.push_back( cp[i] );
    }

    return true;
}


bool IGES_GEOM_PCB::copLine( IGES* aModel, std::list<IGES_ENTITY_126*>& aCurves,
                                 double offX, double offY, double aScale,
                                 double zHeight, MCAD_SEGMENT* aSegment, bool aReverse )
{
    IGES_ENTITY_126* cp;

    if( !newArc126( aModel, &cp ) )
    {
        ERRMSG << "\n + [INFO] could not instantiate IGES NURBS curve\n";
        return false;
    }

    MCAD_POINT mstart = aSegment->GetMStart();
    MCAD_POINT mend = aSegment->GetMEnd();

    double startp[3];
    double endp[3];
    SISLCurve* pCurve = NULL;

    startp[0] = (mstart.x - offX) * aScale;
    startp[1] = (mstart.y - offY) * aScale;
    startp[2] = zHeight;
    endp[0] = (mend.x - offX) * aScale;
    endp[1] = (mend.y - offY) * aScale;
    endp[2] = zHeight;

    if( aReverse )
    {
        startp[1] = 1.0 - startp[1];
        endp[1] = 1.0 - endp[1];
    }

    double epar;
    int stat = 0;
    s1602( startp, endp, 2, 3, 0.0, &epar, &pCurve, &stat );

    switch( stat )
    {
        case 0:
            break;

        case 1:
            ERRMSG << "\n + [WARNING] unspecified problems creating NURBS curve\n";
            stat = 0;
            break;

        default:
            ERRMSG << "\n + [ERROR] could not create NURBS curve\n";
            return false;
            break;
    }

    int iKE = pCurve->in + pCurve->ik - 1;

    if( !cp->SetNURBSData( pCurve->in, pCurve->ik, pCurve->et, pCurve->ecoef, false,
        pCurve->et[0], pCurve->et[iKE] ) )
    {
        ERRMSG << "\n + [WARNING] problems setting data in NURBS curve\n";
        aModel->DelEntity( (IGES_ENTITY*)cp );
        freeCurve( pCurve );
        return false;
    }

    freeCurve( pCurve );
    aCurves.push_back( cp );
    return true;
}

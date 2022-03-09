/*
 * file: entity120.cpp
 *
 * Copyright 2015, Dr. Cirilo Bernardo (cirilo.bernardo@gmail.com)
 *
 * Description: IGES Entity 120: Surface of Revolution, Section 4.18, p.116+ (144+)
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
#include <error_macros.h>
#include <core/iges.h>
#include <core/iges_io.h>
#include <core/iges_curve.h>
#include <core/entity120.h>
#include <core/entity124.h>

using namespace std;

IGES_ENTITY_120::IGES_ENTITY_120( IGES* aParent ) : IGES_ENTITY( aParent )
{
    entityType = 120;
    form = 0;
    iL = 0;
    iC = 0;
    L = NULL;
    C = NULL;
    SA = 0;
    TA = M_PI;
}


IGES_ENTITY_120::~IGES_ENTITY_120()
{
    if( L )
        L->delReference(this);

    if( C )
        C->delReference(this);

    return;
}


bool IGES_ENTITY_120::associate(std::vector<IGES_ENTITY *> *entities)
{
    if( !IGES_ENTITY::associate(entities) )
    {
        ERRMSG << "\n + [INFO] could not register associations\n";
        return false;
    }

    int iEnt;
    bool dup = false;

    if( iL )
    {
        iEnt = iL >> 1;

        if( iEnt < 0 || iEnt >= (int)(*entities).size() )
        {
            ERRMSG << "\n + [INFO] invalid entity (DE:" << iL << ")\n";
            return false;
        }

        L = dynamic_cast<IGES_CURVE*>((*entities)[iEnt]);

        if( !L )
        {
            ERRMSG << "\n + [INFO] could not associate line entity with DE " << iL << "\n";
            return false;
        }

        iEnt = L->GetEntityType();

        if( iEnt != 110 )
        {
            L = NULL;
            ERRMSG << "\n + [VIOLATION] invalid entity (Type: " << iEnt << "); only Type 110 (Line) is permitted\n";
            return false;
        }

        if( !L->addReference(this, dup) )
        {
            L = NULL;
            ERRMSG << "\n + [INFO] could not associate line entity with DE " << iL << "\n";
        }

        if( dup )
        {
            ERRMSG << "\n + [CORRUPT FILE]: adding duplicate entry\n";
            L = NULL;
            return false;
        }
    }

    if( iC )
    {
        iEnt = iC >> 1;

        if( iEnt < 0 || iEnt >= (int)(*entities).size() )
        {
            ERRMSG << "\n + [INFO] invalid entity (DE:" << iC << ")\n";
            return false;
        }

        C = dynamic_cast<IGES_CURVE*>((*entities)[iEnt]);

        if( !C )
        {
            ERRMSG << "\n + [INFO] could not associate curve entity with DE " << iC << "\n";
            return false;
        }

        if( !C->addReference(this, dup) )
        {
            C = NULL;
            ERRMSG << "\n + [INFO] could not associate curve (generatrix) with DE " << iC << "\n";
        }

        if( dup )
        {
            ERRMSG << "\n + [CORRUPT FILE]: adding duplicate entry\n";
            C = NULL;
            return false;
        }
    }

    return true;
}


bool IGES_ENTITY_120::format( int &index )
{
    pdout.clear();

    if( index < 1 || index > 9999999 )
    {
        ERRMSG << "\n + [INFO] invalid Parameter Data Sequence Number\n";
        return false;
    }

    if( !L )
    {
        ERRMSG << "\n + [INFO] no valid Line Entity\n";
        return false;
    }

    if( !C )
    {
        ERRMSG << "\n + [INFO] no valid Curve Entity\n";
        return false;
    }

    parameterData = index;

    if( !parent )
    {
        ERRMSG << "\n + [INFO] method invoked with no parent IGES object\n";
        return false;
    }

    char pd = parent->globalData.pdelim;
    char rd = parent->globalData.rdelim;

    ostringstream ostr;
    ostr << entityType << pd;
    ostr << L->getDESequence() << pd;
    ostr << C->getDESequence() << pd;
    string lstr = ostr.str();
    string tstr;

    if( !FormatPDREal( tstr, SA, pd, IGES_ANGLE_RES ) )
    {
        ERRMSG << "\n + [INFO] could not format Start Angle\n";
        return false;
    }

    AddPDItem( tstr, lstr, pdout, index, sequenceNumber, pd, rd );

    if( extras.empty() )
    {
        if( !FormatPDREal( tstr, TA, rd, IGES_ANGLE_RES ) )
        {
            ERRMSG << "\n + [INFO] could not format Terminate Angle\n";
            return false;
        }
    }
    else
    {
        if( !FormatPDREal( tstr, TA, pd, IGES_ANGLE_RES ) )
        {
            ERRMSG << "\n + [INFO] could not format Terminate Angle\n";
            return false;
        }
    }

    AddPDItem( tstr, lstr, pdout, index, sequenceNumber, pd, rd );

    if( !extras.empty() && !formatExtraParams( lstr, index, pd, rd ) )
    {
        ERRMSG << "\n + [INFO] could not format optional parameters\n";
        pdout.clear();
        iExtras.clear();
        return false;
    }

    if( !formatComments( index ) )
    {
        ERRMSG << "\n + [INFO] could not format comments\n";
        pdout.clear();
        return false;
    }

    paramLineCount = index - parameterData;

    return true;
}


bool IGES_ENTITY_120::rescale( double sf )
{
    // nothing to do
    return true;
}


bool IGES_ENTITY_120::unlink(IGES_ENTITY *aChild)
{
    if(IGES_ENTITY::unlink(aChild) )
        return true;

    if( aChild == (IGES_ENTITY*)L )
    {
        L = NULL;
        return true;
    }

    if( aChild == (IGES_ENTITY*)C )
    {
        C = NULL;
        return true;
    }

    return false;
}


bool IGES_ENTITY_120::isOrphaned( void )
{
    if( (refs.empty() && depends != STAT_INDEPENDENT) || !L || !C )
        return true;

    return false;
}


bool IGES_ENTITY_120::addReference(IGES_ENTITY *aParentEntity, bool &isDuplicate)
{
    return IGES_ENTITY::addReference(aParentEntity, isDuplicate);
}


bool IGES_ENTITY_120::delReference(IGES_ENTITY *aParentEntity)
{
    return IGES_ENTITY::delReference(aParentEntity);
}


bool IGES_ENTITY_120::readDE(IGES_RECORD *aRecord, std::ifstream &aFile, int &aSequenceVar)
{
    if( !IGES_ENTITY::readDE(aRecord, aFile, aSequenceVar) )
    {
        ERRMSG << "\n + [INFO] failed to read Directory Entry\n";
        return false;
    }

    structure = 0;                  // N.A.
    hierarchy = STAT_HIER_ALL_SUB;  // field ignored

    if( form != 0 )
    {
        ERRMSG << "\n + [CORRUPT FILE] non-zero Form Number in Surface of Revolution\n";
        cerr << " + DE: " << aRecord->index << "\n";
        return false;
    }

    return true;
}


bool IGES_ENTITY_120::readPD(std::ifstream &aFile, int &aSequenceVar)
{
    if( !IGES_ENTITY::readPD(aFile, aSequenceVar) )
    {
        ERRMSG << "\n + [INFO] could not read data for Surface of Revolution\n";
        pdout.clear();
        return false;
    }

    int idx;
    bool eor = false;
    char pd = parent->globalData.pdelim;
    char rd = parent->globalData.rdelim;

    idx = (int)pdout.find( pd );

    if( idx < 1 || idx > 8 )
    {
        ERRMSG << "\n + [BAD FILE] strange index for first parameter delimeter (";
        cerr << idx << ")\n";
        pdout.clear();
        return false;
    }

    ++idx;

    int iPtr;

    if( !ParseInt( pdout, idx, iPtr, eor, pd, rd ) )
    {
        ERRMSG << "\n + [INFO] couldn't read the pointer to the line entity\n";
        pdout.clear();
        return false;
    }

    if( iPtr < 1 || iPtr > 9999997 )
    {
        ERRMSG << "\n + [INFO] invalid entity pointer: " << iPtr << "\n";
        pdout.clear();
        return false;
    }

    iL = iPtr;

    if( !ParseInt( pdout, idx, iPtr, eor, pd, rd ) )
    {
        ERRMSG << "\n + [INFO] couldn't read the pointer to the curve entity\n";
        pdout.clear();
        return false;
    }

    if( iPtr < 1 || iPtr > 9999997 )
    {
        ERRMSG << "\n + [INFO] invalid entity pointer: " << iPtr << "\n";
        pdout.clear();
        return false;
    }

    iC = iPtr;

    if( !ParseReal( pdout, idx, SA, eor, pd, rd ) )
    {
        ERRMSG << "\n + [INFO] couldn't read the Start Angle\n";
        pdout.clear();
        return false;
    }

    if( !ParseReal( pdout, idx, TA, eor, pd, rd ) )
    {
        ERRMSG << "\n + [INFO] couldn't read the Terminate Angle\n";
        pdout.clear();
        return false;
    }

    if( !eor && !readExtraParams( idx ) )
    {
        ERRMSG << "\n + [BAD FILE] could not read optional pointers\n";
        pdout.clear();
        return false;
    }

    if( !readComments( idx ) )
    {
        ERRMSG << "\n + [BAD FILE] could not read extra comments\n";
        pdout.clear();
        return false;
    }

    pdout.clear();
    return true;
}


bool IGES_ENTITY_120::SetEntityForm( int aForm )
{
    if( aForm == 0 )
        return true;

    ERRMSG << "\n + [BUG] Surface of Revolution only supports Form 0 (requested form: ";
    cerr << aForm << ")\n";
    return false;
}


bool IGES_ENTITY_120::SetHierarchy( IGES_STAT_HIER aHierarchy )
{
    // hierarchy is ignored so always return true
    return true;
}


bool IGES_ENTITY_120::GetL( IGES_CURVE** aCurve )
{
    *aCurve = L;

    if( L )
        return true;

    return false;
}

bool IGES_ENTITY_120::GetAxis( IGES_CURVE** aCurve )
{
    return GetL( aCurve );
}


bool IGES_ENTITY_120::SetL( IGES_CURVE* aCurve )
{
    if( NULL == aCurve )
    {
        ERRMSG << "\n + [ERROR] NULL pointer passed for axis\n";
        return false;
    }

    if( aCurve->GetEntityType() != ENT_LINE )
    {
        ERRMSG << "\n + [ERROR] invalid entity (type ";
        cerr << aCurve->GetEntityType() << ") passed for axis\n";
        return false;
    }

    if( L )
    {
        L->delReference(this);
        L = NULL;
    }

    bool dup = false;

    if( !aCurve->addReference(this, dup) )
        return false;

    if( dup )
    {
        ERRMSG << "\n + [BUG]: adding duplicate entry\n";
        return false;
    }

    L = aCurve;
    L->SetDependency( STAT_DEP_PHY );

    if( NULL != parent && parent != L->GetParentIGES() )
        parent->AddEntity( L );

    return true;
}


bool IGES_ENTITY_120::SetAxis( IGES_CURVE* aCurve )
{
    return SetL( aCurve );
}



bool IGES_ENTITY_120::GetC( IGES_CURVE** aCurve )
{
    *aCurve = C;

    if( C )
        return true;

    return false;
}


bool IGES_ENTITY_120::GetGeneratrix( IGES_CURVE** aCurve )
{
    return GetC( aCurve );
}


bool IGES_ENTITY_120::SetC( IGES_CURVE* aCurve )
{
    if( NULL == aCurve )
    {
        ERRMSG << "\n + [ERROR] NULL pointer passed for generatrix\n";
        return false;
    }

    if( C )
    {
        C->delReference(this);
        C = NULL;
    }

    bool dup = false;

    if( !aCurve->addReference(this, dup) )
        return false;

    if( dup )
    {
        ERRMSG << "\n + [BUG]: adding duplicate entry\n";
        return false;
    }

    C = aCurve;
    C->SetDependency( STAT_DEP_PHY );

    if( NULL != parent && parent != C->GetParentIGES() )
        parent->AddEntity( C );

    return true;
}


bool IGES_ENTITY_120::SetGeneratrix( IGES_CURVE* aCurve )
{
    return SetC( aCurve );
}

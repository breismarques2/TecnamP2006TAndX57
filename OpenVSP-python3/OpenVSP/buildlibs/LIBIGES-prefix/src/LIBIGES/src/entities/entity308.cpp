/*
 * file: entity308.cpp
 *
 * Copyright 2015, Dr. Cirilo Bernardo (cirilo.bernardo@gmail.com)
 *
 * Description: IGES Entity 308: Subfigure Definition Entity, Section 4.74, p.377(405+)
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
#include <error_macros.h>
#include <core/iges.h>
#include <core/iges_io.h>
#include <core/entity124.h>
#include <core/entity408.h>
#include <core/entity308.h>

using namespace std;


IGES_ENTITY_308::IGES_ENTITY_308( IGES* aParent ) : IGES_ENTITY( aParent )
{
    entityType = 308;
    form = 0;

    N = 0;
    DEPTH = 0;

    return;
}


IGES_ENTITY_308::~IGES_ENTITY_308()
{
    m_DE.clear();
    std::list<IGES_ENTITY*>::iterator sDE = DE.begin();
    std::list<IGES_ENTITY*>::iterator eDE = DE.end();

    while( sDE != eDE )
    {
        (*sDE)->delReference(this);
        ++sDE;
    }

    return;
}


void IGES_ENTITY_308::Compact( void )
{
    IGES_ENTITY::Compact();
    m_DE.clear();
    return;
}


bool IGES_ENTITY_308::associate(std::vector<IGES_ENTITY *> *entities)
{
    if( !IGES_ENTITY::associate(entities) )
    {
        ERRMSG << "\n + [INFO] could not register associations\n";
        iDE.clear();
        return false;
    }

    if( iDE.empty() )
        return true;

    int iEnt;
    int tDE;
    IGES_ENTITY* ep;
    std::list<int>::iterator sDE = iDE.begin();
    std::list<int>::iterator eDE = iDE.end();
    bool dup = false;

    while( sDE != eDE )
    {
        tDE = *sDE;

        if( tDE <= 0 || (tDE & 1) == 0 || tDE > 9999997 )
        {
            ERRMSG << "\n + [VIOLATION] invalid DE sequence number\n";
            iDE.clear();
            return false;
        }

        iEnt = tDE >> 1;

        if( iEnt < 0 || iEnt >= (int)(*entities).size() )
        {
            ERRMSG << "\n + [INFO] invalid entity (DE:" << tDE << ")\n";
            iDE.clear();
            return false;
        }

        ep = (*entities)[iEnt];

        if( !ep->addReference(this, dup) )
        {
            ERRMSG << "\n + [INFO] could not associate entity with DE " << tDE << "\n";
            iDE.clear();
            return false;
        }

        if( dup )
        {
            ERRMSG << "\n + [CORRUPT FILE]: adding duplicate entry\n";
            iDE.clear();
            return false;
        }

        DE.push_back( ep );
        ++sDE;
    }

    iDE.clear();
    return true;
}


bool IGES_ENTITY_308::format( int &index )
{
    pdout.clear();

    // ensure adherence with specification
    use = STAT_USE_DEFINITION;      // fixed

    if( index < 1 || index > 9999999 )
    {
        ERRMSG << "\n + [INFO] invalid Parameter Data Sequence Number\n";
        return false;
    }

    if( DE.empty() )
    {
        ERRMSG << "\n + [BUG] no associated entities\n";
        return false;
    }

    DEPTH = getDepthLevel();
    N = (int)DE.size();

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
    ostr << DEPTH << pd;
    string lstr = ostr.str();
    string tstr;

    if( !AddPDHStr( NAME, lstr, pdout, index, sequenceNumber, pd, rd, pd ) )
    {
        ERRMSG << "\n + [INFO] could not add Subfigure name\n";
        return false;
    }

    ostr.str("");
    ostr << N << pd;
    tstr = ostr.str();
    AddPDItem( tstr, lstr, pdout, index, sequenceNumber, pd, rd );

    int tEnt;

    std::list<IGES_ENTITY*>::iterator sDE = DE.begin();
    std::list<IGES_ENTITY*>::iterator eDE = DE.end();

    while( sDE != eDE )
    {
        tEnt = (*sDE)->getDESequence();

        ++sDE;
        ostr.str("");

        if( sDE == eDE && extras.empty() )
            ostr << tEnt << rd;
        else
            ostr << tEnt << pd;

        tstr = ostr.str();
        AddPDItem( tstr, lstr, pdout, index, sequenceNumber, pd, rd );
    }

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


bool IGES_ENTITY_308::rescale( double sf )
{
    // there is nothing to scale so this function always succeeds
    return true;
}


bool IGES_ENTITY_308::unlink(IGES_ENTITY *aChild)
{
    if(IGES_ENTITY::unlink(aChild) )
        return true;

    if( DE.empty() )
        return false;

    std::list<IGES_ENTITY*>::iterator sDE = DE.begin();
    std::list<IGES_ENTITY*>::iterator eDE = DE.end();

    while( sDE != eDE )
    {
        if( aChild == *sDE )
        {
            DE.erase( sDE );
            N = (int)DE.size();
            return true;
        }

        ++sDE;
    }

    return false;
}


bool IGES_ENTITY_308::isOrphaned( void )
{
    if( (refs.empty() && depends != STAT_INDEPENDENT)
        || DE.empty() )
        return true;

    return false;
}


bool IGES_ENTITY_308::addReference(IGES_ENTITY *aParentEntity, bool &isDuplicate)
{
    if( !aParentEntity )
    {
        ERRMSG << "\n + [BUG] NULL pointer passed for aParentEntity\n";
        return false;
    }

    if( !DE.empty() )
    {
        std::list<IGES_ENTITY*>::iterator sDE = DE.begin();
        std::list<IGES_ENTITY*>::iterator eDE = DE.end();

        while( sDE != eDE )
        {
            if( aParentEntity == *sDE )
            {
                ERRMSG << "\n + [BUG] circular reference requested\n";
                return false;
            }

            ++sDE;
        }
    }

    return IGES_ENTITY::addReference(aParentEntity, isDuplicate);
}


bool IGES_ENTITY_308::delReference(IGES_ENTITY *aParentEntity)
{
    return IGES_ENTITY::delReference(aParentEntity);
}


bool IGES_ENTITY_308::readDE(IGES_RECORD *aRecord, std::ifstream &aFile, int &aSequenceVar)
{
    if( !IGES_ENTITY::readDE(aRecord, aFile, aSequenceVar) )
    {
        ERRMSG << "\n + [INFO] failed to read Directory Entry\n";
        return false;
    }

    structure = 0;                  // N.A.
    use = STAT_USE_DEFINITION;      // fixed

    if( form != 0 )
    {
        ERRMSG << "\n + [CORRUPT FILE] non-zero Form Number in Subfigure Definition Entity\n";
        cerr << " + DE: " << aRecord->index << "\n";
        return false;
    }

    return true;
}


bool IGES_ENTITY_308::readPD(std::ifstream &aFile, int &aSequenceVar)
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

	idx = (int)pdout.find(pd);

    if( idx < 1 || idx > 8 )
    {
        ERRMSG << "\n + [BAD FILE] strange index for first parameter delimeter (";
        cerr << idx << ")\n";
        pdout.clear();
        return false;
    }

    ++idx;

    if( !ParseInt( pdout, idx, DEPTH, eor, pd, rd ) )
    {
        ERRMSG << "\n + [INFO] couldn't read DEPTH\n";
        pdout.clear();
        return false;
    }

    if( DEPTH < 0 )
    {
        ERRMSG << "\n + [INFO] invalid DEPTH (" << DEPTH;
        cerr << ") in entity DE (" << sequenceNumber << ")\n";
        pdout.clear();
        return false;
    }

    if( !ParseHString( pdout, idx, NAME, eor, pd, rd ) )
    {
        ERRMSG << "\n + [INFO] no name in entity DE (";
        cerr << sequenceNumber << ")\n";
        pdout.clear();
        return false;
    }

    if( !ParseInt( pdout, idx, N, eor, pd, rd ) )
    {
        ERRMSG << "\n + [INFO] couldn't read N parameter in DE ";
        cerr << sequenceNumber << "\n";
        pdout.clear();
        return false;
    }

    // note: N = 0 makes no sense but is not prohibited
    if( N < 0 )
    {
        ERRMSG << "\n + [INFO] invalid value for N (" << N;
        cerr << ") in DE " << sequenceNumber << "\n";
        pdout.clear();
        return false;
    }

    int tIdx;
    iDE.clear();

    for( int i = 0; i < N; ++ i )
    {
        if( !ParseInt( pdout, idx, tIdx, eor, pd, rd ) )
        {
            ERRMSG << "\n + [INFO] couldn't read associated entity #" << (iDE.size() + 1) << "\n";
            pdout.clear();
            return false;
        }

        if( tIdx < 0 || (tIdx & 1) == 0 || tIdx > 9999997 )
        {
            ERRMSG << "\n + [INFO] invalid DE pointer for associated entity #";
            cerr << (iDE.size() + 1) << " (" << tIdx << ")\n";
            pdout.clear();
            return false;
        }

        iDE.push_back( tIdx );
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


bool IGES_ENTITY_308::SetEntityForm( int aForm )
{
    if( aForm == 0 )
        return true;

    ERRMSG << "\n + [BUG] Subfigure Definition entity only supports Form 0 (requested form: ";
    cerr << aForm << ")\n";
    return false;
}


bool IGES_ENTITY_308::SetVisibility( bool isVisible )
{
    // the visibility parameter is ignored
    return true;
}


bool IGES_ENTITY_308::SetEntityUse( IGES_STAT_USE aUseCase )
{
    if( aUseCase == 2 )
        return true;

    ERRMSG << "\n + [BUG] Sunfigure Definition Entity only supports Use 2 (DEFINITION) (requested use: ";
    cerr << aUseCase << ")\n";
    return false;
}


bool IGES_ENTITY_308::SetHierarchy( IGES_STAT_HIER aHierarchy )
{
    hierarchy = aHierarchy;
    return true;
}


bool IGES_ENTITY_308::GetDEList( size_t& aDESize, IGES_ENTITY**& aDEList )
{
    if( DE.empty() )
    {
        aDESize = 0;
        aDEList = NULL;
        return false;
    }

    if( DE.size() != m_DE.size() )
    {
        m_DE.clear();
        std::list< IGES_ENTITY* >::iterator sL = DE.begin();
        std::list< IGES_ENTITY* >::iterator eL = DE.end();

        while( sL != eL )
        {
            m_DE.push_back( *sL );
            ++sL;
        }
    }

    aDESize = m_DE.size();
    aDEList = &m_DE[0];
    return true;
}


bool IGES_ENTITY_308::AddDE(IGES_ENTITY *aPtr)
{
    if( NULL == aPtr )
    {
        ERRMSG << "\n + [INFO] [BUG] NULL pointer passed\n";
        return false;
    }

    // ensure we have no references to this object
    if( aPtr == pStructure || aPtr == pLineFontPattern
        || aPtr == pLevel || aPtr == pView
        || aPtr == pTransform || aPtr == pLabelAssoc
        || aPtr == pColor )
    {
        ERRMSG << "\n + [BUG] invalid reference requested for DE list\n";
        return false;
    }

    std::list<IGES_ENTITY*>::iterator bref = refs.begin();
    std::list<IGES_ENTITY*>::iterator eref = refs.end();

    while( bref != eref )
    {
        if( aPtr == *bref )
        {
            ERRMSG << "\n + [BUG] circular reference requested for DE list\n";
            return false;
        }

        ++bref;
    }

    // check if the entity is a child in extras<>
    vector<IGES_ENTITY*>::iterator bExt = extras.begin();
    vector<IGES_ENTITY*>::iterator eExt = extras.end();

    while( bExt != eExt)
    {
        if( aPtr == *bExt )
        {
            ERRMSG << "\n + [BUG] invalid reference requested for DE list\n";
            return false;
        }

        ++bExt;
    }

    bref = DE.begin();
    eref = DE.end();

    while( bref != eref )
    {
        // while this is a bug, we can do the right thing and simply ignore the
        // additional reference
        if( aPtr == *bref )
        {
            m_DE.clear();
            return true;
        }

        ++bref;
    }

    bool dup = false;

    if( !aPtr->addReference(this, dup) )
    {
        ERRMSG << "\n + [INFO] [BUG] could not add child reference\n";
        return false;
    }

    if( dup )
    {
        ERRMSG << "\n + [BUG]: adding duplicate entry\n";
        return false;
    }

    aPtr->SetDependency( STAT_DEP_PHY );
    DE.push_back( aPtr );
    N = (int)DE.size();
    m_DE.clear();

    if( NULL != parent && parent != aPtr->GetParentIGES() )
        parent->AddEntity( aPtr );

    return true;
}


bool IGES_ENTITY_308::DelDE( IGES_ENTITY* aPtr )
{
    std::list<IGES_ENTITY*>::iterator bref = DE.begin();
    std::list<IGES_ENTITY*>::iterator eref = DE.end();

    while( bref != eref )
    {
        if( aPtr == *bref )
        {
            DE.erase( bref );
            N = (int)DE.size();
            return true;
        }

        ++bref;
    }

    return false;
}


int IGES_ENTITY_308::getDepthLevel( void )
{
    if( DE.empty() )
        return 0;

    int nd = 0; // minimum depth level
    int tm = 0;

    std::list<IGES_ENTITY*>::iterator bref = DE.begin();
    std::list<IGES_ENTITY*>::iterator eref = DE.end();

    while( bref != eref )
    {
        if( (*bref)->GetEntityType() == ENT_SUBFIGURE_DEFINITION )
        {
            IGES_ENTITY_308* ep308;
            ep308 = (IGES_ENTITY_308*)(*bref);
            tm = ep308->getDepthLevel();

            if( tm >= nd )
                nd = tm + 1;
        }
        else if( (*bref)->GetEntityType() == ENT_SINGULAR_SUBFIGURE_INSTANCE )
        {
            IGES_ENTITY_408* ep408;
            ep408 = (IGES_ENTITY_408*)(*bref);
            tm = ep408->getDepthLevel();

            if( tm >= nd )
                nd = tm + 1;
        }
        else if( (*bref)->GetEntityType() == ENT_NETWORK_SUBFIGURE_DEFINITION )
        {
            ERRMSG << "\n + [INFO] TO BE IMPLEMENTED: respond to ENT_NETWORK_SUBFIGURE_DEFINITION\n";
            return -100;
        }

        ++bref;
    }

    return nd;
}

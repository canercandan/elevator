#include <unistd.h>
#include <cmath>
#include <cstdlib>

#include <iostream>

#include "Move.h"

OrderedMove::OrderedMove( Elevator& elevator, OneMove& onemove ) : _elevator( elevator ), _onemove( onemove ) {}

void OrderedMove::operator()( ScheduleData::SubContainer& askedLevels )
{
    for ( ScheduleData::SubContainer::iterator it = askedLevels.begin(), end = askedLevels.end(); it != end; ++it )
	{
	    if ( !it->second ) continue;
	    std::cout << "ordered asked level: " << it->first << std::endl;
	    _onemove( _elevator, it->first );
	    it->second = false;
	}
}

UpDownMove::UpDownMove( Elevator& elevator, OneMove& onemove, bool direction /*= 1*/ ) : _elevator( elevator ), _onemove( onemove ), _direction( direction ) {}

void UpDownMove::operator()( ScheduleData::SubContainer& askedLevels )
{
    if ( _direction )
	{
	    upper( askedLevels );
	    lower( askedLevels );
	    return;
	}

    lower( askedLevels );
    upper( askedLevels );
}

void UpDownMove::upper( ScheduleData::SubContainer& askedLevels )
{
    std::cout << "upper asked levels: ";
    for ( ScheduleData::SubContainer::iterator
	      it = askedLevels.upper_bound(_elevator.position()),
	      end = askedLevels.end();
	  it != end; ++it )
	{
	    if ( !it->second ) continue;
	    _onemove( _elevator, it->first );
	    std::cout << " " << it->first << " ";
	    it->second = false;
	}
    std::cout << std::endl;
}

void UpDownMove::lower( ScheduleData::SubContainer& askedLevels )
{
    std::cout << "lower asked levels: ";
    ScheduleData::SubContainer::iterator lower = askedLevels.lower_bound(_elevator.position());
    for ( ScheduleData::SubContainer::reverse_iterator
	      it( lower ),
	      end = askedLevels.rend();
	  it != end; ++it )
	{
	    if ( !it->second ) continue;
	    _onemove( _elevator, it->first );
	    std::cout << " " << it->first << " ";
	    it->second = false;
	}
    std::cout << std::endl;
}

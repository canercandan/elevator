// -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 * Caner Candan <caner@candan.fr>, http://caner.candan.fr
 */

#ifndef _Scheduler_h
#define _Scheduler_h

#include <iostream>

#include "Move.h"
#include "ScheduleData.h"

class Scheduler
{
public:
    Scheduler( Move& move ) : _move( move ) {}

    virtual void operator()( ScheduleData data ) const
    {
	for ( size_t i = 0, size = data.size(); i < size; ++i )
	    {
		_move( data[i] );
	    }
    }

private:
    Move& _move;
};

class LoopScheduler : public Scheduler
{
public:
    LoopScheduler( Move& move ) : Scheduler( move ) {}

    virtual void operator()( ScheduleData data ) const
    {
	while ( 42 )
	    {
		Scheduler::operator()( data );
		std::cout << "Press CTRL+C to stop the loop..." << std::endl;
	    }
    }
};

#endif // !_Scheduler_h

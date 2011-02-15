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

#include <fstream>
#include <stdexcept>

#include "ScheduleSampler.h"

ScheduleSampler::ScheduleSampler( const std::string filename ) : _filename( filename ) {}

ScheduleData ScheduleSampler::operator()()
{
    std::ifstream ifs( _filename.c_str() );

    if (ifs.is_open() == false)
	{
	    throw std::runtime_error("Error: your file is incorrect, please choose another one");
	}

    ScheduleData schedule;

    while ( !ifs.eof() )
	{
	    int v = 0;
	    ifs >> v;
	    schedule[schedule.size()-1][v] = true;

	    if ( ifs.get() == '\n' )
		{
		    schedule.push_back( ScheduleData::SubContainer() );
		}
	}

    return schedule;
}

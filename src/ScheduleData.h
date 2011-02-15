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

#ifndef _ScheduleData_h
#define _ScheduleData_h

#include <vector>
#include <map>

#include "Printable.h"

class ScheduleData : private std::vector< std::map< int, bool > >, public Printable
{
public:
    typedef std::map< int, bool > SubContainer;
    typedef std::vector< SubContainer > Container;

    using Container::begin;
    using Container::end;
    using Container::iterator;
    using Container::const_iterator;
    using Container::size;
    using Container::push_back;
    using Container::operator[];

    ScheduleData();

    void printOn( std::ostream& os ) const;
};

#endif // !_ScheduleData_h

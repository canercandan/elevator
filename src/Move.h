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

#ifndef _Move_h
#define _Move_h

#include "Elevator.h"

class IMove
{
public:
    virtual ~IMove() {}
    virtual void operator()( int position ) = 0;
};

class MoveTemp : public IMove
{
public:
    MoveTemp( IElevator& elevator, int max, int min = 0, int timeout = 1 );

    void operator()( int position );

private:
    IElevator& _elevator;
    int _max;
    int _min;
    int _timeout;
};

#endif // !_Move_h
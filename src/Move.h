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
#include "OneMove.h"
#include "ScheduleData.h"

class Move
{
public:
    virtual ~Move() {}
    virtual void operator()( ScheduleData::SubContainer& ) = 0;
};

class OrderedMove : public Move
{
public:
    OrderedMove( Elevator& elevator, OneMove& onemove );

    void operator()( ScheduleData::SubContainer& );

private:
    Elevator& _elevator;
    OneMove& _onemove;
};

class UpDownMove : public Move
{
public:
    UpDownMove( Elevator& elevator, OneMove& onemove, bool direction = 1 );

    void operator()( ScheduleData::SubContainer& );

    void upper( ScheduleData::SubContainer& );
    void lower( ScheduleData::SubContainer& );

private:
    Elevator& _elevator;
    OneMove& _onemove;
    bool _direction;
};

#endif // !_Move_h

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

#ifndef _OneMove_h
#define _OneMove_h

#include "Elevator.h"

class OneMove
{
public:
    virtual ~OneMove() {}
    virtual void operator()( Elevator&, int position ) = 0;
};

class DummyOneMove : public OneMove
{
public:
    void operator()( Elevator&, int position );
};

class TemporizedOneMove : public OneMove
{
public:
    TemporizedOneMove( int timeout = 1 );

    void operator()( Elevator&, int position );

private:
    int _timeout;
};

#endif // !_OneMove_h

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

#ifndef _Elevator_h
#define _Elevator_h

class IElevator
{
public:
    virtual ~IElevator() {}
    virtual int& position() = 0;
};

class Elevator : public IElevator
{
public:
    Elevator( int initial_position, int max, int min = 0 ) : _position( initial_position ), _max( max), _min( min ) {}

    inline int& position() { return _position; }
    inline int max() const { return _max; }
    inline int min() const { return _min; }

private:
    int _position;
    int _max;
    int _min;
};

#endif // !_Elevator_h

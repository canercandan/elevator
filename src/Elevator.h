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

class Elevator
{
public:
    virtual ~Elevator() {}
    virtual int& position() = 0;
};

class EasyElevator : public Elevator
{
public:
    EasyElevator( int initial_position = 0 ) : _position( initial_position ) {}

    inline int& position() { return _position; }

private:
    int _position;
};

class OpenCloseElevator : public EasyElevator
{
public:
    OpenCloseElevator( int initial_position = 0 ) : EasyElevator( initial_position ), _open( false ) {}

    inline bool& open() { return _open; }

private:
    bool _open;
};

#endif // !_Elevator_h

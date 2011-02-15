#include <unistd.h>
#include <cmath>
#include <cstdlib>

#include <iostream>

#include "OneMove.h"

void DummyOneMove::operator()( Elevator& elevator, int position )
{
    elevator.position() = position;
}

TemporizedOneMove::TemporizedOneMove( int timeout /*= 1*/ ) : _timeout( timeout ) {}

void TemporizedOneMove::operator()( Elevator& elevator, int position )
{
    int distance = ::abs(elevator.position() - position);
    for (int i = 0; i < distance; ++i)
	{
	    std::cout << ".";
	    std::cout.flush();
	    ::sleep( _timeout );
	}
    elevator.position() = position;
}

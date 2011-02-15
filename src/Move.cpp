#include <unistd.h>
#include <cmath>
#include <cstdlib>

#include <iostream>

#include "Move.h"

MoveTemp::MoveTemp( IElevator& elevator, int max, int min /*= 0*/, int timeout /*= 1*/ ) : _elevator( elevator ), _max( max ), _min( min ), _timeout( timeout ) {}

void MoveTemp::operator()( int position )
{
    int distance = ::abs(_elevator.position() - position);
    std::cout << "distance: " << distance << std::endl;
    for (int i = 0; i < distance; ++i)
	{
	    ::sleep( _timeout );
	}
    _elevator.position() = position;
}

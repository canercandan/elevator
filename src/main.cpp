// -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * Authors: Caner Candan <caner@candan.fr>, http://caner.candan.fr
 */

#include <iostream>
#include <cstdlib>

#include "Elevator.h"
#include "Move.h"
#include "Scheduler.h"
#include "ScheduleSampler.h"
#include "ScheduleData.h"

int main(int ac, char **av)
{
    if (ac < 2)
	{
	    std::cout << "Usage: " << av[0] << " SAMPLE_FILE [INITIAL_POTISION]" << std::endl;
	    return -1;
	}

    int initial_position = ac > 2 ? ::atoi( av[2] ) : 0;

    /// used to read a filename containing the elevator calls scheduling
    ScheduleSampler sampler( av[1] );

    /// used to define a kind of elevator
    EasyElevator elevator( initial_position, 0 );

    /// used to control the behaviour during a motion between two levels
    /// here's the motion with anything else
    //DummyOneMove onemove;
    /// here's the temporized motion with 5 seconds of sleep
    TemporizedOneMove onemove( 1 );

    /// used to manage elevator motions when several levels are called at the same time
    /// here's an easy method listing and executing all motions in the list order
    //OrderedMove move( elevator, onemove );
    /// here's the behaviour checking first the higher levels and then the lower ones
    UpDownMove move( elevator, onemove );

    /// used to execute scheduling
    // here's the way without restarts
    Scheduler scheduler( move );
    // here's the scheduler into a infinity loop
    //LoopScheduler scheduler( move );

    /// just store the data related with scheduling
    ScheduleData data = sampler();

    /// print the scheduling
    std::cout << "///// Scheduling /////" << std::endl
	      << data
	      << "//////////////////////" << std::endl;
    std::cout << std::endl;

    /// and finally execute the program with all parameters defined above.
    scheduler( data );

    return (0);
}

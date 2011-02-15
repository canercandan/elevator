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
	    std::cout << "Usage: " << av[0] << " INITIAL_POTISION SAMPLE_FILE" << std::endl;
	    return -1;
	}

    Elevator elevator( ::atoi( av[1] ), 0 );
    MoveTemp move( elevator, 5 );
    Scheduler scheduler( move );
    ScheduleSampler sampler( av[2] );

    ScheduleData data = sampler();

    std::cout << data;

    // while (42)
    // 	{
    scheduler( data );
    //     std::cout << "Press CTRL+C to stop the loop..." << std::endl;
    // }

    return (0);
}

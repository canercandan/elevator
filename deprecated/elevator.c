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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "elevator.h"

static const int scheduling[][2] = {{3,5}, {0}, {5}, {2}, {6}};
static const int scheduling_size = sizeof(scheduling) / sizeof(*scheduling);

static t_level levels[] = {
    {0, 0, 0},
    {1, 1, 0},
    {2, 0, 0},
    {3, 1, 0},
    {4, 0, 0},
    {5, 1, 0},
};

static const int levels_size = sizeof(levels) / sizeof(*levels);

static int current_position = 0;

static void open_door(int position) { printf("[%d] opening door\n", position); sleep(1); }
static void close_door(int position) { printf("[%d] closing door\n", position); sleep(1); }

static void goto_level(int position)
{
    current_position = position;
    levels[position].state = 0;
    open_door(position);
    close_door(position);
}

static void ask_higher_levels()
{
    for (int i = current_position+1; i < levels_size; i++)
	{
	    if (levels[i].state == 0) { continue; }
	    goto_level(i);
	}
}

static void ask_lower_levels()
{
    for (int i = current_position-1; i >= 0; i--)
	{
	    if (levels[i].state == 0) { continue; }
	    goto_level(i);
	}
}

int main(int ac, char **av)
{
    if (ac < 2)
	{
	    printf("Usage: INITIAL_POTISION\n");
	    return (-1);
	}

    current_position = atoi(av[1]);

    printf("Intial level: %d\n", current_position);
    printf("Number of levels: %d\n", levels_size);

    printf("Asked levels: ");
    for (int i = 0; i < levels_size; i++)
	{
	    if (levels[i].state == 1)
		{
		    printf(" %d", i);
		}
	}
    printf("\n");

    while (42)
	{
	    ask_higher_levels();
	    ask_lower_levels();
	}

    return (0);
}

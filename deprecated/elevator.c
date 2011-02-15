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

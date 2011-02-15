#ifndef _elevator_h
#define _elevator_h

typedef struct	s_schedule
{
    int		time;
    int		level;
}		t_schedule;

typedef struct	s_level
{
    int		position;
    char	state;
    char	door_state;
}		t_level;

#endif // !_elevator_h

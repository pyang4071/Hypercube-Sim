#ifndef Globals_H
#define Globals_H

#define MAX_COUNT 10000
#define MAX_TURN 3000
//trial counts

typedef struct Trial
{
    int fd;             //number of visited vertices
    int visited[MAX_TURN];   //every unique visited vertex
    int move[MAX_TURN][2];   //number explorer called and Director selected distance
    //first digit is move num and second is resultant vertex
}Trial;

typedef struct Simulation
{
    int n;                  //$Q_n$
    int force_revisited;    //yes or no force the director to revisit
    Trial *trials[MAX_COUNT];   //trials are just Trials
    int min_fd;
    int occ;
}Simulation;


#endif /* Globals_H */
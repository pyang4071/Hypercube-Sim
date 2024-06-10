#ifndef Globals_H
#define Globals_H

#define MAX_COUNT 100
#define MAX_TURN 100
//trial counts

typedef struct Trial
{
    int fd;             //number of visited vertices
    int visited[100];   //every unique visited vertex
    int move[MAX_TURN][2];   //number explorer called and Director selected distance
    //first digit is move num and second is resultant vertex
}Trial;

typedef struct Simulation
{
    int n;                  //$Q_n$
    int force_revisited;    //yes or no force the director to revisit
    Trial *trials[MAX_COUNT];   //trials are just Trials
}Simulation;


#endif /* Globals_H */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <globals.h>
#include <simulate.c>

int main(){
    srand(time(NULL));
    Simulation *hypercube = malloc(sizeof(Simulation));
    if (hypercube == NULL){
        printf("it is over...\n");
        return 0;
    }
    char choice;
    do
    {
        printf("n = ");
        choice = getchar();
        while(getchar() != '\n');
    } while (choice < 1);
    
    hypercube->n = choice -'0'; //for now n = 5
    printf("%d\n", hypercube->n);

    
    do
    {
        printf("force revisit?\n");
        choice = getchar();
        getchar();
    } while (choice != 'y' && choice != 'n');
    if (choice == 'y'){
        hypercube->force_revisited = 1;
    } else {
        hypercube->force_revisited = 0;
    }
    Trial *trial1;
    int i = 0;
    while (i < MAX_TURN){
        trial1 = malloc(sizeof(Trial));
        hypercube->trials[i] = trial1;
        trial1->fd = 0;
        for (int j; j<100; j++){
            trial1->visited[j] = '\0';
            trial1->move[j][0] = 0;
            trial1->move[j][1] = 0;
        }
        simulate(hypercube, trial1);
        printf("Trial %d: fd = %d\n", i, trial1->fd);
        i++;
    }
    while(1){
        printf("which trial to check?\n");
        choice = getchar();
        while(getchar() != '\n');
        
        print(hypercube, choice);
        sleep(1);
    }
    return 0;
}

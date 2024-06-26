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
    int choice;
    do
    {
        printf("n = ");
        scanf("%d", &choice);
    } while (choice < 1);
    getchar();
    hypercube->n = choice; //for now n = 5
    char choice1;
    printf("%d\n", hypercube->n);    
    do
    {
        printf("force revisit?\n");
        choice1 = getchar();
        getchar();
    } while (choice1 != 'y' && choice1 != 'n');
    if (choice1 == 'y'){
        hypercube->force_revisited = 1;
    } else {
        hypercube->force_revisited = 0;
    }
    hypercube->min_fd = 0;
    hypercube->occ = 0;
    Trial *trial1;
    int i = 0;
    while (i < MAX_COUNT){
        trial1 = malloc(sizeof(Trial));
        hypercube->trials[i] = trial1;
        trial1->fd = 0;
        for (int j = 0; j<MAX_TURN; j++){
            trial1->visited[j] = '\0';
            trial1->move[j][0] = '\0';
            trial1->move[j][1] = '\0';
        }
        trial1->move[0][1] = 1;
        trial1->visited[0] = 0;
        simulate(hypercube, trial1);
        printf("Trial %d: fd = %d\n", i, trial1->fd);
        i++;
    }
    int num;
    print_sum(hypercube);
    while(1){
        printf("which trial to check?\n");
        scanf("%d", &num);
        while(getchar() != '\n');
        if(num == 4071){
            break;
        }
        print(hypercube, num);
    }
    for(int jj = 0; jj < MAX_COUNT; jj++){
        free(hypercube->trials[jj]);
    }
    free(hypercube);
    return 0;
}

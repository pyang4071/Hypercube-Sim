#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <globals.h>
#include <simulate.h>

void simulate(Simulation *hypercube, Trial *trial1){
    
    trial1->move[0][0] = 0;
    trial1->move[0][1] = 0;
    int turn = 1;
    while (turn < MAX_TURN){
        trial1->move[turn][0] = (rand() % hypercube->n) + 1;
        if(hypercube->force_revisited){
            check(hypercube, trial1, turn);
        } else {
            pick_rand(hypercube, trial1, turn);
        }
        turn++;
    }
}

void check(Simulation *hypercube, Trial *trial1, int turn){
    int valid[100];
    int index = 0;
    valid[index] = '\0';
    int index2 = 0;
    while(trial1->visited[index2] != '\0'){
        if (hamming_distance(trial1->visited[index2],trial1->move[turn-1][1]) == trial1->move[turn][0]){
            valid[index++] = index2;
            valid[index] = '\0';
        }
        index2++;
    }
    int choice;
    if(index == 0){
        pick_rand(hypercube, trial1, turn);
    } else {
        choice = rand() % index;
        trial1->move[turn][1] = trial1->visited[valid[choice]];
    }
}

void pick_rand(Simulation *hypercube, Trial *trial1, int turn){
    int choice;
    do
    {
        // printf("%d\n", hypercube->n);
        choice = rand() % exponent(2, hypercube->n);
    } while (hamming_distance(choice, trial1->move[turn-1][1]) != trial1->move[turn][0]);
    trial1->move[turn][1] = choice;
    int visit = 0;
    int index = 0;
    while(trial1->visited[index] != '\0'){
        if (choice == trial1->visited[index]){
            visit = 1;
        }
        index++;
    }
    if (visit == 0){
        trial1->visited[index++] = choice;
        trial1->visited[index] = '\0'; 
    }
}

int exponent(int a, int b){
    int result = 1;
    for (int i = 0; i < b; i++){
        result = result * a;
    }
    return result;
}

int hamming_distance(int a, int b){
    int count = 0;
    int xor_result = a ^ b;
    while (xor_result > 0) {
        count += xor_result & 1;
        xor_result >>= 1;
    }
    return count;
}

void print(Simulation *hypercube, int choice){
    printf("Trial: %d\n", choice);
    fflush(stdout);
    for(int i = 0; i < MAX_TURN; i++){
        printf("Explorer: %d, Vertex: %d\n", hypercube->trials[choice]->move[i][0], hypercube->trials[choice]->move[i][1]);
        fflush(stdout);
    }
    printf("Visited vertices\n");
    // fflush(stdout);
    int index = 0; 
    printf("egg: %d\n",hypercube->trials[choice]->visited[index]);
    // fflush(stdout);
    while (index < 100 && hypercube->trials[choice]->visited[index] != '\0') {
        printf("Visited %d\n", hypercube->trials[choice]->visited[index]);
        fflush(stdout);
        index++;
    }
}

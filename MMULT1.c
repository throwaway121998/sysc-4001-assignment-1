//
//  main.c
//  sysc-4001-assignment-1
//
//  Created by Kyle Horne on 2019-02-25.
//  Copyright © 2019 Kyle Horne. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/types.h>

#include "MMULT1.h"

void matrix_mul(struct shared_matrices *shared_matrices) {
    int row = shared_matrices->row_id;
    shared_matrices->row_id++;
    printf("Child Process: working with row: %d\n", row + 1);
    int sum = 0;
    /* Compute matrix mul of row id. */
    for (int k = 0 ; k < COLS; k++) {
        for (int j = 0; j < ROWS; j++) {
            sum += shared_matrices->m[row][j] * shared_matrices->n[j][k];
        }
        shared_matrices->q[row][k] = sum;
        sum = 0;
    }
    exit(0);
}

int main(int argc, const char * argv[]) {
    void *shared_memory = (void *)0;
    struct shared_matrices *shared_matrices;
    int shmid;
    
    srand((unsigned int)getpid());

    shmid = shmget((key_t)1234, sizeof(struct shared_matrices), 0666 | IPC_CREAT);
    if (shmid == -1) {
        fprintf(stderr, "shmget failed\n");
        exit(EXIT_FAILURE);
    }
    /* Make the shared memory accessible to the program. */
    shared_memory = shmat(shmid, (void *)0, 0);
    if (shared_memory == (void *)-1) {
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %X\n", (int)shared_memory);
    
    shared_matrices = (struct shared_matrices *)shared_memory;
    
    /* Init matrix m and n in shared mem. */
    matrix m = {{1, 2, 3, 4}, {5, 6, 7, 8}, {4, 3, 2, 1}, {8, 7, 6, 5}};
    for (int i = 0; i < ROWS; i++) {
        for (int k = 0 ; k < COLS; k++) {
            shared_matrices->m[i][k] = m[i][k];
        }
    }
    matrix n = {{1, 3, 5, 7}, {2, 4, 6, 8}, {7, 3, 5, 7}, {8, 6, 4, 2}};
    for (int i = 0; i < ROWS; i++) {
        for (int k = 0 ; k < COLS; k++) {
            shared_matrices->n[i][k] = n[i] [k];
        }
    }
    
    /* Fork n processes. */
    int n_processes = N_PROCESSES;
    for(int i = 0; i < n_processes; i++) {
        pid_t pid = fork();
        switch(pid) {
            case -1:
                perror("fork failed");
                exit(EXIT_FAILURE);
            case 0:
                matrix_mul(shared_matrices);
                break;
            default:
                break;
        }
    }
    
    /* Await child processes to exit. */
    int status;
    pid_t pid;
    while (n_processes > 0) {
        pid = wait(&status);
        --n_processes;
    }
    
    /* Print matrix q. */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0 ; j < COLS; j++) {
            printf("%d\t", shared_matrices->q[i][j]);
        }
        printf("\n");
    }

    /* Detach and delete shared memory. */
    if (shmdt(shared_memory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        fprintf(stderr, "shmctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

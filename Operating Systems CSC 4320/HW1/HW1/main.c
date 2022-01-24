//
//  main.c
//  HW1
//
//  Created by Isaiah Chennault on 1/19/22.
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    pid_t two = fork();
    
    if(two == -1){
    perror("uno");
    exit(EXIT_FAILURE);
    }
    
    if(two == 0)
    {
        printf("\n Child is " , getpid());
        exit(EXIT_SUCCESS);
    }else {
        printf("\n Parent is ", getppid());
        wait(NULL);
    }
    exit(EXIT_SUCCESS);
    
}

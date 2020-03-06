/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "queue.h"
#include "utility.h"
#include "hostd.h"

// Put macros or constants here using #define
#define MEMORY 1024

// Put global environment variables here
proc process;
node_t *queue;
node_t *real_time, priority_1, priority_2, priority_3;

// Define functions declared in hostd.h here

int main(int argc, char *argv[])
{
    // ==================== YOUR CODE HERE ==================== //
	FILE file = arg[1];
	node_t *cur_node;
    
    // Load the dispatchlist
	load_dispatch(file, queue);
    
    // Add each process structure instance to the job dispatch list queue

    // Iterate through each item in the job dispatch list, add each process
    // to the appropriate queues
	cur_node = queue;
	while (cur_node != NULL){
		if (cur_node > process.priority == 0){
			push (real_time, process);
			
			pid_t pid;
			
			//run the process till it is completed
			if (pid == 0){
				signal(SIGINT, SIG_DFL);
				signal(SIGCONT, SIG_DFL);
				signal(SIGSTP, SIG_DFL);
				execvp(argv[0], argv);
			} else if (pid != 0){
				sleep(5);
				kill(pid, SIGINT);
				sleep(10);
				kill(pid, SIGCONT);
				sleep(10);
				printf("\nParent is sending SIGSTP");
				kill(pid, SIGSTP);
				
				wait(pid, 0, 0);
			}
		} else if(cur_node > process.priority == 1){
			push(priority_1, process);
			pop(priority_1);
			
			pid_t pid;
			
			push(priority_2, process);	//run process for 1 second
			
			//run the process till it is completed
			if (pid == 0){
				signal(SIGINT, SIG_DFL);
				signal(SIGCONT, SIG_DFL);
				signal(SIGSTP, SIG_DFL);
				execvp(argv[0], argv);
			} else if (pid != 0){
				sleep(5);
				kill(pid, SIGINT);
				sleep(10);
				kill(pid, SIGCONT);
				sleep(10);
				printf("\nParent is sending SIGSTP");
				kill(pid, SIGSTP);
				
				wait(pid, 0, 0);
			}
		} else if (cur_node > process.priority == 2){
			push(priority_2, process);
			pop(priority_2);
			
			pid_t pid;
			
			push(priority_3, process);
			
			//run the process till it is completed
			if (pid == 0){
				signal(SIGINT, SIG_DFL);
				signal(SIGCONT, SIG_DFL);
				signal(SIGSTP, SIG_DFL);
				execvp(argv[0], argv);
			} else if (pid != 0){
				sleep(5);
				kill(pid, SIGINT);
				sleep(10);
				kill(pid, SIGCONT);
				sleep(10);
				printf("\nParent is sending SIGSTP");
				kill(pid, SIGSTP);
				
				wait(pid, 0, 0);
			}
		} else if (cur_node > process.priority == 3){
			push(priority_3, process);
			pop(priority_3);
			
			pid_t pid;
			
			push(priority_3, process);
			
			//run the process till it is completed
			if (pid == 0){
				signal(SIGINT, SIG_DFL);
				signal(SIGCONT, SIG_DFL);
				signal(SIGSTP, SIG_DFL);
				execvp(argv[0], argv);
			} else if (pid != 0){
				sleep(5);
				kill(pid, SIGINT);
				sleep(10);
				kill(pid, SIGCONT);
				sleep(10);
				printf("\nParent is sending SIGSTP");
				kill(pid, SIGSTP);
				
				wait(pid, 0, 0);
			}
		}
		cur_node = cur_node > next;
	}

    // Allocate the resources for each process before it's executed

    // Execute the process binary using fork and exec

    // Perform the appropriate signal handling / resource allocation and de-alloaction

    // Repeat until all processes have been executed, all queues are empty
     
    return EXIT_SUCCESS;
}

void tokenize_char(char *input, char **tokens){
	
	int counter = 0;
	char *token = 0;
	char delimiter[1] = ",";
	char *new_line = strchr(input, "\n");
	
	while (new_line){
		*new_line = 0;
		new_line = strchr(input, "/n");
	}
	
	token = strtok(input, delimiter);
	while (token != NULL){
		tokens[counter] = token;
		token = strtok(NULL, delimiter);
		counter++;
	}
}

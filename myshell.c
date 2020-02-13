#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"
#include <fnmatch.h>

#define BUFFER_LEN 256
 

int main(int argc, char *argv[]) {

    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
	char arg[BUFFER_LEN] = {0};
    
	// First get the current working directory to display on the shell at all times.

	char pwd[256];
	printf("shell = %s/%s$ ",getcwd(pwd,sizeof(pwd)),argv[0]);
    
	
	// Perform an infinite loop getting command from users.

	while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    	{
    
			// Perform string tokenization to get command and argument.

			buffer[strcspn(buffer, "\n")] = '\0';
			strcat(command, buffer);
			char* string_tokens = strtok(command, " ");

			// Run each commands and execute them.

			// First Command is cd --> change directory / display current working directory.

       		if (strcmp(string_tokens, "cd") == 0)
    			{
			
					string_tokens = strtok(NULL, " ");
					char *current_directory = string_tokens,pwd[256];
					DIR* new_directory;

				// If there are no arguments after cd, then just print the curerent working directory.

				if (string_tokens == NULL)
					{
		    			printf("%s\n", getcwd(pwd,sizeof(pwd)));
					}

				// Else change the directory to the appropriate directory.

				else
					{
						new_directory = opendir(string_tokens);
						chdir (current_directory);
			    		closedir(new_directory);
					}
        		}	

			// Second command is clr. This clears the console.
	
			else if (strcmp(string_tokens, "clr") == 0)
				{
					system("clear");
				}

			// Third command is dir which lists the current files in the directory.
	
			else if (strcmp(string_tokens, "dir") == 0)
				{
					system("ls");
				}

			// Fourth command is the environ command which lists out all the environmental variables.
		
					else if (strcmp(string_tokens, "environ") == 0)
				{
					system("env");
				}
	
			// Fifth command is echo which copies and pastes all the arguments.
			
			else if (strcmp(string_tokens, "echo") == 0)
				{
					while(string_tokens != NULL) 
						{
							string_tokens = strtok(NULL, " ");

							// Take all argumnets and copies and pastes them.

							if (string_tokens !=NULL) 
							{
								printf( "%s ", string_tokens );
							}
							else
							{
								break;
							}
  						}
					printf("\n");
				}
	
			// Sixth command is help which displays the user manuel.

			else if (strcmp(string_tokens, "help") == 0)
				{
					char c;
					FILE *file = fopen("readme.md", "r");
					if (file) 
						{
	    					while ((c = getc(file)) != EOF)
	       					putchar(c);
	    					fclose(file);
						}
				}

			// Seventh command is pause which pauses the terminal until enter is pressed.
		
			else if (strcmp(string_tokens, "pause") == 0)
				{
					char enter = 0;
					while (enter != '\n') 
						{ 
							enter = getchar(); 
						}	
				}

       		 // Eighth command is quit which terminates the shell.

       		else if (strcmp(string_tokens, "quit") == 0)
       			{
           			 return EXIT_SUCCESS;
        		}

       		 // Unsupported command.

     		else
     			{
            		fputs("Unsupported command, use help to display the manual\n", stderr);
        		}
	
			// Infinite loop for commands. 

			char pwd[256];
			printf("shell = %s/%s$ ",getcwd(pwd,sizeof(pwd)),argv[0]);
			memset(command, 0, sizeof command);
    	}
}
## Operating Systems Lab 2

#### Authors: Sohaib Mohiuddin, Umar Riaz, Matthew Bernard, Vidit Vyas

## Shell Help Guide

The following list of commands are supported on our shell.

1. cd - This command changes the current directory to another directory specified by the user. It should be used as: `cd /directory/to/go/to`.

2. clr - This command will clear the screen.

3. environ - List all the environment strings.

4. echo - This command will display user text input onto a new line.
	  It should be used as: `echo comment`.

5. help - Display the user manual with shell commands supported.

6. pause - Pause operation of the shell until 'Enter' is pressed.

7. quit - Quit the shell.


When running an external program such as a batch file with the appropriate commands, enter in the format `myshell file_name`. The shell will read through the content of the given file until end-of-file is reached, and display the results.

This shell supports input/output redirection in the form program_name arg1 arg2 < inputfile > outputfile. This will run the program_name with the 2 arguments. The input file in this command is replaced by inputfile, and the output file.

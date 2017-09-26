#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;

#define INPUT_SIZE 512
#define TOKEN_SIZE 32

char *readline()//to get line from the user
{
	static char usr_inpt_arry [INPUT_SIZE]; //creates an array for the input
	
	if(cin.eof())
	{
		exit(0);
	}

	cin.getline(usr_inpt_arry, INPUT_SIZE); //gets the input from the user
	
	string str(usr_inpt_arry);
	if (strcmp (str.c_str(), "exit") == 0)
	{
                    exit(0);
        }


	return usr_inpt_arry;//returns a pointer of the char array
}


char **parseline(char *usr_inpt_arry) //sperating lines
{
	int size = TOKEN_SIZE;
	char **tokens = (char **)malloc(sizeof(char*) * size);//allocating space for the array of tokens
	char *token;

	/*if (!token)//if there are no tokens it gives an error
	{
		cout << "ERROR: Allocation" << endl;
		return 0;
	}*/

	int i = 0;
	token = strtok(usr_inpt_arry, " ");//separating tokens
	while(token != NULL)
	{
		tokens[i] = token;
		i++;

	token = strtok(NULL, " ");
	}

	tokens[i] = NULL;
	
	return tokens;
}

int execute(char **args)
{
	pid_t pid;
	pid_t wait_pid;
	int status;

	pid = fork();

	if(args[0] == NULL)// No command
	{
		return 1;
	}

	if(pid == -1)//failed to fork
	{
		cout << "ERROR: failed to fork" << endl;
	}
	else if(pid > 0) //parent process
	{
	
			wait_pid = waitpid(pid, &status, 0);
	}
	else if(pid == 0)//child
	{
		if(execvp(*args, args) == -1)
		{
			cout << "ERROR: execution failed" << endl;
		}
		exit(EXIT_FAILURE);
	}
	else//error for a reason
	{
		cout << "ERROR: unknowned error" << endl;
	}
	return 1;
}
//for pipe doesnt work.
/*
int execute2(char **args,int status,int check, int final)
{
	int fd[2];
	int READ = 0;
	int WRITE = 1;
	pipe(fd);
	pid_t pid = fork();
	pid_t wait_pid;
	
	if(args[0] == NULL)// No command
	{
		return 1;
	}

	if(pid == -1)//failed to fork
	{
		cout << "ERROR: failed to fork" << endl;
	}
	else if(pid > 0) //parent process
	{

			wait_pid = waitpid(pid, &status, 0);
	}
	else if(pid == 0)//child
	{
		if(check == 0 && final == 0 && status != 0)
		{
			dup2(status, STDIN_FILENO);
			dup2(fd[WRITE], STDOUT_FILENO);
		}
		else if(check == 1 && final == 0 && status == 0)
		{
			dup2(fd[WRITE], STDOUT_FILENO);
		} 
 		else
 		{
 			dup2(status, STDIN_FILENO);
 		}
 		//executing
 		if(execvp(*args, args) == -1)
		{
			cout << "ERROR: execution failed" << endl;
		}
		exit(EXIT_FAILURE);
	}
	
	if(status != 0);
	{
		close(status);
	}
	
	close(fd[WRITE]);
	
	if(final == 1)
	{
		close(fd[READ]);
	}
	
	return fd[READ];
}
*/
int main(int argc, char *argv[])
{
	
	int status = 1;//while status is true

	while(status)
	{
		if(argv[1] != NULL)//checks if there is an argument 
		{
			if(strcmp(argv[1], "-n") == 0)
			{
			//no prompt line
			}
		}
		else
		{
		printf("my_shell: ");//prompt line
		} 
		//readline
		char *usr_inpt_arry = readline();
		//parsing the line
		char **args = parseline(usr_inpt_arry);
		
		/*if(strcmp (args[0], "cd") == 0)
		{
			if(args[1] == NULL)
			{
				cout<< "ERROR: No directory" << endl;
			}
			else
			{
				chdir(args[1]);
			}
		}*/
		
		//else{
		//execution
		status = execute(args);
		//}
	}

	return 0;
}

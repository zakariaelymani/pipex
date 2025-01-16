#include "pipex.h"

void executcommand(char *path, char *cmd)
{
	char **agrs;
	int	proc;

    proc = fork();
	if(proc == 0)
	{
		if (!path)
		{
			perror("command not found");
			exit(1);
		}
		agrs = ft_split(cmd,' ');
		execve(path ,agrs,NULL);
		perror("error in execve function");
		exit(1);
	}
	wait(NULL);
}

int main(int argc, char *argv[], char *env[])
{	
	int pid[argc - 3][2];
	if (argc >= 5)
	{
		
	}
    return (0);
}
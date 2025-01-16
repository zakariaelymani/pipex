/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:53:55 by zel-yama          #+#    #+#             */
/*   Updated: 2025/01/16 15:33:32 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void executcommand(char *path, char *cmd,int input, int output)
{
	char **agrs;

    if(input < 0 || output < 0)
    {
        perror("error in");
        exit(1);
    }
	dup2(input,0);
	close(input);
	dup2(output,1);
	close(output);
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

int main(int argc, char *argv[], char *env[])
{	
	int fd;
	int pid[2];
	int n;

	pipe(pid);
	if(argc != 5)  
		return (-1);
    n = fork(); 
    if (n == 0)
    {
        close(pid[0]);
		fd = open(argv[1],O_RDONLY);
        executcommand(findcmdpath(env,argv[2]),argv[2],fd,pid[1]);
    }
    else
    {
        close(pid[1]);
        fd = open(argv[4],O_WRONLY | O_CREAT | O_TRUNC,0644);
        executcommand(findcmdpath(env,argv[3]),argv[3],pid[0],fd);  
    }
    close(pid[0]);
    close(pid[1]);
    wait(NULL);
    wait(NULL);
    return (0);
}

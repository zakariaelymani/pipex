
#include "pipex.h"

char *findpath(char *str)
{
    char **args;
    char *cmd;
    int ex;
    int fok;
    int pid[2];
    char *retvaleu;
   
    pipe(pid);
    cmd = ft_strjoin("whereis ", str);
    args = ft_split(cmd, ' ');
    fok = fork();
    if (fok == 0)
    {
        close(pid[0]);
        close(1);
        dup(pid[1]);
       ex = access("/usr/bin/whereis",F_OK | X_OK);
        if (ex == -1)
        {
            perror("error in :");
            return NULL;
        } 
        execve("/usr/bin/whereis",args, NULL);
        
        close(pid[1]);
        exit(1);
    }
    else
    {
        close(pid[1]);
        wait(NULL);
        retvaleu = get_next_line(pid[0]);
    }
    return (ft_strnchr(retvaleu, '/'));
}

int main(int argc, char *argv[], char *env[]){
    
printf("{ %s ]",findpath("cat"));
}
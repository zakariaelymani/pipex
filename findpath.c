/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:25:18 by zel-yama          #+#    #+#             */
/*   Updated: 2025/01/10 19:25:29 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *findmepath(char *s)
{
    int pid[2];
    char *returvalue;
    char *joined;
    char **cmds;
    int pip;
    int fok;
    
    joined = ft_strjoin("which ",s);
    cmds = ft_split(joined, ' ');
    pip = pipe(pid);
    if (pip < 0)
    {
        perror("eror in pipe");
    }
    fok = fork();
    if (fok == -1)
    {
        perror("error in fork");
    }
    if(fok == 0)
    {
        close(pid[0]);
        close(1);
        dup(pid[1]);
        execve("/usr/bin/which",cmds,NULL);
        close(pid[1]);
        exit(0);
    }
    else
    {
        wait(NULL);
        close(pid[1]);
        returvalue = get_next_line(pid[0]);
        close(pid[0]);
    }
    return(returvalue);
}
int main()
{
    findmepath(" ls");
}
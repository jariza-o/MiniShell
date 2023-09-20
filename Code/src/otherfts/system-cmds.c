/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system-cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:41:41 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/20 18:31:17 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
void execArgs(char** parsed)
{
    // Forking a child
    pid_t pid = fork(); 
  
    if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {
        if (execvp(parsed[0], parsed) < 0) {
            printf("\nCould not execute command..");
        }
        exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL); 
        return;
    }
}

void	ft_system_cmds(char **command)
{
	pid_t pid;
	char *cmdpath;
	
	pid = fork();
	cmdpath = ft_strjoin("/bin/", command[0]);
	if(pid < 0)
	{
		printf("[ERROR] Could not create a child process \n");
		exit(1); //no sabemos si esto tiene que cerrar minishell
	}
	else if(pid == 0)
	{
		if (execve(cmdpath, command, g_data.env) < 0)
		{
			printf("[ERROR] Could not execute command %s \n", command[0]);
			exit(1); //no sabemos si esto tiene que cerrar minishell
		}
	}
	else
	{
		wait(NULL);
		free(cmdpath);
	}
}

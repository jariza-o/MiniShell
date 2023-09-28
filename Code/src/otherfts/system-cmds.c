/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system-cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:41:41 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/28 15:35:04 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char *ft_get_cmdpath(char *cmd, char **args)
{
	int cnt;
	int exists;
	struct stat *stats;
	char **path;

	cnt = 0;
	exists = 0;
	stats = NULL;
	path = ft_split(getenv("PATH"), ':');
	while(cmd[cnt])
	{
		if(cmd[cnt] == '/')
			exists = execve(cmd, args, g_data.env);
		cnt++;
	}
	if(exists > 0)
		return (cmd);
	cnt = 0;
	while(path[cnt])
	{
		if(execve(ft_strjoin(ft_strjoin(path[cnt], "/"), cmd), args, g_data.env) >= 0)
		 	return (cmd);
		cnt++;
	}
	return (NULL);
}

void	ft_system_cmds(char **command)
{
	//forks the child
	pid_t pid;
	char *cmdpath;
	
	pid = fork();
	cmdpath = NULL;
	if(pid < 0)
	{
		printf("[ERROR] Could not create a child process \n");
		exit(1); //no sabemos si esto tiene que cerrar minishell
	}
	else if(pid == 0)
	{
		cmdpath = ft_get_cmdpath(command[0], command);
		if(!cmdpath)
		{
			printf("[ERROR] Command not found: %s \n", command[0]);
			return ;
		}
		if (execve(cmdpath, command, g_data.env) < 0)
		{
			printf("[ERROR] Could not execute command %s \n", command[0]);
			exit(1); //no sabemos si esto tiene que cerrar minishell
		}
	}
	//waits for the child to end
	else
	{
		wait(NULL);
		free(cmdpath);
	}
}

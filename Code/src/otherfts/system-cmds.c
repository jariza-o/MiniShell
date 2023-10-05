/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system-cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:41:41 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/10/05 19:44:00 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_check_file(char *cmd)
{
	int	cnt;

	cnt = 0;
	while (cmd[cnt])
	{
		if (cmd[cnt] == '/')
		{
			if (access(cmd, F_OK) < 0)
			{
				printf("[ERROR] Not such file or directory \n");
				g_data.exit_status = 127;
				return (1);
			}
		}
		cnt++;
	}
	return (0);
}

char	*ft_get_cmdpath(char *cmd, char **args)
{
	int			cnt;
	int			exists;
	struct stat	*stats;
	char		**path;

	cnt = -1;
	exists = 0;
	stats = NULL;
	path = ft_split(getenv("PATH"), ':');
	while (cmd[++cnt])
	{
		if (cmd[cnt] == '/')
			exists = execve(cmd, args, g_data.env);
	}
	if (exists > 0)
		return (cmd);
	cnt = -1;
	while (path[++cnt])
	{
		if (execve(ft_strjoin(ft_strjoin(path[cnt], "/"), cmd), args,
				g_data.env) >= 0)
			return (cmd);
	}
	g_data.exit_status = 127;
	return (NULL);
}

void	ft_system_cmds(char **command)
{
	char	*cmdpath;

	if (ft_check_file(command[0]) == 1)
		return ;
	g_data.r_pid = fork();
	cmdpath = NULL;
	if (g_data.r_pid < 0)
		printf("[ERROR] Could not create a child process \n");
	else if (g_data.r_pid == 0)
	{
		if (ft_check_pipe(command) == 1)
		{
			ft_pipe(g_data.line);
			exit(0);
		}
		cmdpath = ft_get_cmdpath(command[0], command);
		if (!cmdpath)
			printf("[ERROR] Command not found: %s \n", command[0]);
		else if (execve(cmdpath, command, g_data.env) < 0)
		{
			printf("[ERROR] Could not execute command %s \n", command[0]);
		}
		exit(0);
	}
	free(cmdpath);
}

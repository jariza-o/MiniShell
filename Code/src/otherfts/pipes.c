/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:53:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/10/06 18:09:12 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void ft_first_pipe(char *cmd)
{
	char **args;
	char *path;

	dup2(g_data.spipe.fds[1], 1);
	close(g_data.spipe.fds[0]);
	args = ft_split(cmd, ' ');
	path = ft_get_cmdpath(args[0]);
	execve(path, args, g_data.env);
}

static void ft_second_pipe(char *cmd)
{
	char **args;
	char *path;

	dup2(g_data.spipe.fds[0], 0);
	close(g_data.spipe.fds[1]);
	args = ft_split(cmd, ' ');
	path = ft_get_cmdpath(args[0]);
	execve(path, args, g_data.env);
}

void	ft_check_pipe(char *command)
{
	if (ft_strchr(command, '|'))
		ft_pipe(command);
	else
		ft_cmds();
}

void	ft_pipe(char *line)
{
	int		cnt;
	char	**cmdp;

	cnt = 0;
	pipe(g_data.spipe.fds);
	cmdp = ft_split(line, '|');
	while (cmdp[cnt])
	{
		g_data.spipe.pid_c1 = fork();
		if (g_data.spipe.pid_c1 == 0)
			ft_first_pipe(cmdp[cnt]);
		cnt++;
		g_data.spipe.pid_c2 = fork();
		if (g_data.spipe.pid_c2 == 0)
			ft_second_pipe(cmdp[cnt]);
		waitpid(g_data.spipe.pid_c1, NULL, 0);
		waitpid(g_data.spipe.pid_c2, NULL, 0);
		cnt++;
	}
	close(g_data.spipe.fds[0]);
	close(g_data.spipe.fds[1]);
	// dup2(g_data.spipe.fds[0], 0);
	// dup2(g_data.spipe.fds[1], 1);
}

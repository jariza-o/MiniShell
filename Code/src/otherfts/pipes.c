/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:53:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/10/06 20:43:51 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int ft_count_pipes(char *line)
{
	int cnt;
	int pipes;

	pipes = 0;
	cnt = 0;
	while(line[cnt])
	{
		if (line[cnt] == '|')
			pipes++;
		cnt++;
	}
	return (pipes);
}

static void ft_first_pipe(char *cmd)
{
	char **args;
	char *path;

	dup2(g_data.spipe.fds[1], 1);
	close(g_data.spipe.fds[1]);
	args = ft_split(cmd, ' ');
	path = ft_get_cmdpath(args[0]);
	execve(path, args, g_data.env);
}

static void ft_middle_pipe(char *cmd)
{
	char **args;
	char *path;

	// dup(g_data.spipe.fds[0], );

}

static void ft_last_pipe(char *cmd)
{
	char **args;
	char *path;

	dup2(g_data.spipe.fds[0], 0);
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

//#TODO: *int[2] de pipes, ft_choose_pipe(chooses between first, middle and last pipe), ft_open_fds

void	ft_pipe(char *line)
{
	int		cnt;
	char	**cmdp;

	cnt = 0;
	cmdp = ft_split(line, '|');
	g_data.spipe.pipe_n = ft_count_pipes(line);
	while (g_data.spipe.pipe_n > 0 && cmdp[cnt + 1])
	{
		pipe(g_data.spipe.fds);
		g_data.spipe.pid_c1 = fork();
		if (g_data.spipe.pid_c1 == 0)
			ft_first_pipe(cmdp[cnt]);
		waitpid(g_data.spipe.pid_c1, NULL, 0);
		close(g_data.spipe.fds[1]);
		g_data.spipe.pid_c2 = fork();
		if (g_data.spipe.pid_c2 == 0)
			ft_last_pipe(cmdp[cnt + 1]);
		waitpid(g_data.spipe.pid_c2, NULL, 0);
		close(g_data.spipe.fds[0]);
		cnt++;
		g_data.spipe.pipe_n--;
	}
}

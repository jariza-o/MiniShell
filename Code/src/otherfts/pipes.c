/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:53:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/10/09 17:28:03 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void ft_close_pipes(void)
{
	int cnt;

	cnt = 0;
	while(cnt < g_data.spipe.pipe_n + 1)
	{
		close(g_data.spipe.fds[cnt][0]);
		close(g_data.spipe.fds[cnt][1]);
		cnt++;
	}
}

static int	ft_count_pipes(char *line)
{
	int	cnt;
	int	pipes;

	pipes = 0;
	cnt = 0;
	while (line[cnt])
	{
		if (line[cnt] == '|')
			pipes++;
		cnt++;
	}
	return (pipes);
}

static void	ft_first_pipe(char *cmd, int cnt)
{
	char	**args;
	char	*path;

	dup2(g_data.spipe.fds[cnt][1], 1);
	close(g_data.spipe.fds[cnt][0]);
	args = ft_split(cmd, ' ');
	path = ft_get_cmdpath(args[0]);
	execve(path, args, g_data.env);
}

static void ft_middle_pipe(char *cmd, int cnt)
{
	char **args;
	char *path;

	dup2(g_data.spipe.fds[cnt][0], g_data.spipe.fds[cnt + 1][1]);
	dup2(g_data.spipe.fds[cnt][1], 1);
	ft_close_pipes();
	args = ft_split(cmd, ' ');
	path = ft_get_cmdpath(args[0]);
	execve(path, args, g_data.env);
}

static void	ft_last_pipe(char *cmd, int cnt)
{
	char	**args;
	char	*path;

	dup2(g_data.spipe.fds[cnt][0], 0);
	close(g_data.spipe.fds[cnt][1]);
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

void	ft_init_pipes(void)
{
	int	cnt;

	cnt = 0;
	g_data.spipe.fds = ft_calloc(sizeof(int *), g_data.spipe.pipe_n + 1);
	while (cnt < g_data.spipe.pipe_n)
	{
		g_data.spipe.fds[cnt] = ft_calloc(sizeof(int), 2);
		cnt++;
	}
	cnt = 0;
	while(cnt < g_data.spipe.pipe_n)
	{
		pipe(g_data.spipe.fds[cnt]);
		cnt++;
	}
}

void ft_choose_pipe(char *cmd, int pipecnt, int cnt)
{
	if(cnt == 0)
		ft_first_pipe(cmd, pipecnt);
	else if (cnt == g_data.spipe.pipe_n)
		ft_last_pipe(cmd, pipecnt);
	else
		ft_middle_pipe(cmd, pipecnt);
}

// TODO: Try with only one pipe instead of **fds. Also see if pipe() need clean or not.

void	ft_pipe(char *line)
{
	int		cnt;
	int 	pipecnt;
	char	**cmdp;

	cnt = 0;
	pipecnt = 0;
	cmdp = ft_split(line, '|');
	g_data.spipe.pipe_n = ft_count_pipes(line);
	ft_init_pipes();
	while (cmdp[cnt] && pipecnt <= g_data.spipe.pipe_n)
	{
		g_data.spipe.pid_c1 = fork();
		if (g_data.spipe.pid_c1 == 0)
			ft_choose_pipe(cmdp[cnt], pipecnt, cnt);
		else
		{
			if(cnt == 0)
				close(g_data.spipe.fds[pipecnt][1]);
			else if(cnt == g_data.spipe.pipe_n)
				close(g_data.spipe.fds[pipecnt][0]);
			wait(&g_data.spipe.pid_c1);
		}
		cnt++;
		if(cnt % 2 == 0)
			pipecnt++;
	}
}

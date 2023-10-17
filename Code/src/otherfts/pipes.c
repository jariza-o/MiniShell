/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:53:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/10/17 20:48:12 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_child(char *cmd, int flag)
{
	char	**args;
	char	*path;

	close(g_data.spipe.fds[0]);
	dup2(g_data.spipe.prev_pipe, g_data.spipe.fd_in);
	if (flag)
		dup2(g_data.spipe.fds[1], g_data.spipe.fd_out);
	if(g_data.spipe.fd_out != 1)
	{
		dup2(g_data.spipe.fd_out, 1);
		g_data.spipe.fd_in = g_data.spipe.fd_out;
	}
	else
		g_data.spipe.fd_in = 0;
	close(g_data.spipe.fds[1]);
	args = ft_split(cmd, ' ');
	path = ft_get_cmdpath(args[0]);
	if (execve(path, args, g_data.env) < 0)
	{
		g_data.exit_status = 1;
		exit(1);
	}
}

static void	ft_parent(void)
{
	close(g_data.spipe.fds[1]);
	wait(NULL);
	g_data.spipe.prev_pipe = g_data.spipe.fds[0];
}

void	ft_check_pipe(char *command)
{
	if (ft_strchr(command, '|'))
		ft_pipe(command);
	else
		ft_cmds();
}

int	ft_exists(char *cmd)
{
	if (cmd)
		return (1);
	return (0);
}

void	ft_pipe(char *line)
{
	int		cnt;
	char	**cmdp;

	cnt = 0;
	cmdp = ft_split(line, '|');
	g_data.spipe.prev_pipe = 0;
	while (cmdp[cnt])
	{
		pipe(g_data.spipe.fds);
		cmdp[cnt] = ft_check_redir(cmdp[cnt]);
		g_data.r_pid = fork();
		if (g_data.r_pid == -1)
		{
			g_data.exit_status = 1;
			exit(1);
		}
		if (g_data.r_pid == 0)
			ft_child(cmdp[cnt], ft_exists(cmdp[cnt + 1]));
		else
			ft_parent();
		cnt++;
	}
	close(g_data.spipe.prev_pipe);
}

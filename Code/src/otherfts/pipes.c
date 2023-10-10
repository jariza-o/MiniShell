/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:53:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/10/10 19:03:45 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

static void	ft_child(char *cmd)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = ft_get_cmdpath(args[0]);
	execve(path, args, g_data.env);
}

// static void	ft_parent(void)
// {
// 	waitpid(g_data.spipe.pid_c1, NULL, 0);
// 	close(g_data.spipe.fds[1]);
// 	dup2(g_data.spipe.fds[0], 0);
// }

void	ft_check_pipe(char *command)
{
	if (ft_strchr(command, '|'))
		ft_pipe(command);
	else
		ft_cmds();
}

// TODO: Try with only one pipe instead of **fds. Also see if pipe() need clean or not.
//Rutas relativas execve
void	ft_pipe(char *line)
{
	int		cnt;
	int		pipecnt;
	char	**cmdp;

	cnt = 0;
	pipecnt = 0;
	cmdp = ft_split(line, '|');
	g_data.spipe.pipe_n = ft_count_pipes(line);
	while (cmdp[cnt])
	{
		pipe(g_data.spipe.fds);
		g_data.spipe.pid_c1 = fork();
		if (g_data.spipe.pid_c1 == 0)
		{
			close(g_data.spipe.fds[0]);
			dup2(g_data.spipe.fds[1], 1);
			ft_child(cmdp[cnt]);
		}
		else
		{
			close(g_data.spipe.fds[1]);
			dup2(g_data.spipe.fds[0], 0);
			waitpid(g_data.spipe.pid_c1, NULL, 0);
		}
		cnt++;
	}
}

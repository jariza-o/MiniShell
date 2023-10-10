/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:53:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/10/03 18:34:09 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_check_pipe(char **command)
{
	int	cnt;

	cnt = 0;
	while (command[cnt])
	{
		if (ft_strcmp(command[cnt], "|") == 0)
			return (1);
		cnt++;
	}
	return (0);
}

void	ft_pipe(char *line)
{
	int	cnt;
	char **cmdp;
	char **args;
	char *path;
	int	fds[2];

	cnt = 0;
	pipe(fds);
	cmdp = ft_split(line, '|');
	while (cmdp[cnt])
	{
		ft_printf("a");
		g_data.r_pid = fork();
		if(g_data.r_pid == 0)
		{
			close(fds[0]);
			dup2(fds[1], 1);
			close(fds[1]);
			path = ft_get_cmdpath(cmdp[0], cmdp);
			args = ft_split(cmdp[cnt], ' ');
			ft_printf("path: %s\n", path);
			execve(path,args,g_data.env);
		}
		else
		{
			close(fds[1]);
			wait(&g_data.r_pid);
			close(fds[0]);
		}
		cnt++;
	}
	ft_printf("hola");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system-cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:41:41 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/01 19:30:53 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_clean_matrix(char **matrix)
{
	int	cnt;

	cnt = 0;
	while (matrix[cnt])
	{
		free(matrix[cnt]);
		cnt++;
	}
	free(matrix);
	return (NULL);
}

char	*ft_get_env(char *str)
{
	int		cnt;
	char	*env;

	if (str[0] == '?') // AÑADIDO POR JARIZA PARA DEVOLVER $?
		return (ft_itoa(g_data.exit_status));
	cnt = 0;
	while (g_data.env[cnt])
	{
		if (ft_strncmp(g_data.env[cnt], str, ft_strlen(str)) == 0 \
		&& g_data.env[cnt][ft_strlen(str)] == '=')
		{
			env = ft_strdup(g_data.env[cnt] + (ft_strlen(str) + 1));
			return (env);
		}
		cnt++;
	}
	return (NULL);
}

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

char	*ft_get_cmdpath(char *cmd)
{
	int		cnt;
	int		exists;
	char	*cmdpath;
	char	**path;

	cnt = -1;
	exists = 1;
	path = ft_split(ft_get_env("PATH"), ':');
	exists = 1;
	path = ft_split(ft_get_env("PATH"), ':');
	while (cmd[++cnt])
	{
		if (cmd[cnt] == '/')
			exists = access(cmd, F_OK);
			exists = access(cmd, F_OK);
	}
	if (!exists)
	if (!exists)
		return (cmd);
	cnt = -1;
	while (path[++cnt])
	{
		cmdpath = ft_strjoin(ft_strjoin(path[cnt], "/"), cmd);
		if (access(cmdpath, F_OK) == 0)
			return (cmdpath);
	}
	ft_clean_matrix(path);
	free(cmdpath);
	return (NULL);
}

void	ft_system_cmds(char **command)
{
	char	*cmdpath;

	if (ft_check_file(command[0]) == 1)
		return ;
	cmdpath = NULL;
	cmdpath = ft_get_cmdpath(command[0]);
	if (!cmdpath)
	{
		printf("[ERROR] Command not found: %s \n", command[0]);
		g_data.exit_status = 127;
	}
	g_data.r_pid = fork();
	if (g_data.r_pid < 0)
		printf("[ERROR] Could not create a child process \n");
	else if (g_data.r_pid == 0)
	{
		if (execve(cmdpath, command, g_data.env) < 0
			&& g_data.exit_status != 127)
			printf("[ERROR] Could not execute command %s \n", command[0]);
		exit(1);
	}
	else
		wait(&g_data.r_pid);
	free(cmdpath);
}

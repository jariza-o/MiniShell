/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:41:56 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/04 18:24:20 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_path(char **path, char *cmd)
{
	int		cnt;
	char	*tmp;
	char	*cmdpath;

	cnt = 0;
	while (path[cnt])
	{
		tmp = ft_strjoin(path[cnt], "/");
		cmdpath = ft_strjoin(tmp, cmd);
		if (access(cmdpath, F_OK) == 0)
		{
			ft_clean_matrix(path);
			free(tmp);
			return (cmdpath);
		}
		free(cmdpath);
		free(tmp);
		cnt++;
	}
	return (NULL);
}

char	**ft_shell_lvl(char **env)
{
	char	*tmp;
	int		cnt;

	tmp = ft_get_env("SHLVL");
	tmp = ft_itoa(ft_atoi(tmp) + 1);
	cnt = 0;
	while (env[cnt])
	{
		if (ft_strncmp(env[cnt], "SHLVL", 5) == 0)
		{
			free(env[cnt]);
			env[cnt] = ft_strjoin("SHLVL=", tmp);
			free(tmp);
			return (env);
		}
		cnt++;
	}
	return (env);
}

void	ft_exec(char *cmdpath, char **command)
{
	g_data.r_pid = fork();
	if (g_data.r_pid < 0)
		printf("[ERROR] Could not create a child process \n");
	else if (g_data.r_pid == 0)
	{
		g_data.env = ft_shell_lvl(g_data.env);
		if (execve(cmdpath, command, g_data.env) < 0
			&& g_data.exit_status != 127)
			printf("[ERROR] Could not execute command %s \n", command[0]);
		exit(1);
	}
	else
		wait(&g_data.exit_status);
}

int	ft_strcmpup(char *str1, char *str2)
{
	char	*tmp1;
	char	*tmp2;
	int		ret;

	tmp1 = ft_strup(ft_strdup(str1));
	tmp2 = ft_strup(ft_strdup(str2));
	ret = ft_strcmp(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	return (ret);
}

char	*ft_strup(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		str[cnt] = ft_toupper(str[cnt]);
		cnt++;
	}
	return (str);
}

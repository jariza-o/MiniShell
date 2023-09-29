/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:44 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/29 19:45:47 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void ft_new_env(char *name, char *value)
{
	int cnt;
	int cnt2;
	char **env;

	cnt = 0;
	cnt2 = 0;
	while(g_data.env[cnt])
		cnt++;
	env = malloc(sizeof(char *) * (cnt + 2));
	while(g_data.env[cnt2])
	{
		env[cnt2] = ft_strdup(g_data.env[cnt2]);
		cnt2++;
	}
	env[cnt2] = ft_strjoin(ft_strjoin(name, "="), value);
	env[cnt2 + 1] = NULL;
	g_data.env = env;
}

void	ft_add_env(char **names, char **values)
{
	int		cnt;
	int		cnt2;
	int cnt3;
	int size;
	char	**env;

	cnt = 0;
	cnt2 = 0;
	while (g_data.env[cnt])
		cnt++;
	while (names[cnt2] && values[cnt2])
		cnt2++;
	size = cnt + cnt2;
	cnt3 = cnt;
	env = malloc(sizeof(char *) * size);
	while (cnt--)
		env[cnt] = ft_strdup(g_data.env[cnt]);
	cnt2 = -1;
	while (cnt3 < size && names[++cnt2])
	{
		env[cnt3] = ft_strjoin(ft_strjoin(names[cnt2], "="), values[cnt2]);
		cnt3++;
	}
	env[cnt3] = NULL;
	g_data.env = env;
}

static t_vars	*ft_realloc_vars(char *name, char *value)
{
	t_vars	*new;
	int		cnt;

	new = malloc(sizeof(t_vars *));
	cnt = 0;
	while (g_data.vars->names[cnt] && g_data.vars->values[cnt])
		cnt++;
	new->names = malloc(sizeof(char *) * (cnt + 2));
	new->values = malloc(sizeof(char *) * (cnt + 2));
	cnt = 0;
	while (g_data.vars->names[cnt] && g_data.vars->values[cnt])
	{
		new->names[cnt] = ft_strdup(g_data.vars->names[cnt]);
		new->values[cnt] = ft_strdup(g_data.vars->values[cnt]);
		cnt++;
	}
	new->names[cnt] = ft_strdup(name);
	new->names[cnt + 1] = NULL;
	new->values[cnt] = ft_strdup(value);
	new->values[cnt + 1] = NULL;
	g_data.vars = ft_clean_vars(g_data.vars);
	ft_new_env(new->names[cnt], new->values[cnt]);
	return (new);
}

static void	ft_init_vars(char *name, char *value)
{
	g_data.vars = malloc(sizeof(t_vars *));
	g_data.vars->names = malloc(sizeof(char *) * 2);
	g_data.vars->values = malloc(sizeof(char *) * 2);
	g_data.vars->names[0] = ft_strdup(name);
	g_data.vars->names[1] = NULL;
	g_data.vars->values[0] = ft_strdup(value);
	g_data.vars->values[1] = NULL;
	ft_add_env(g_data.vars->names, g_data.vars->values);
}

//ADD VARS TO ENV

void	ft_export(char **argv)
{
	char	**vars;

	g_data.r_pid = fork();
	if (g_data.r_pid < 0)
		printf("[ERROR] Could not create a child process \n");
	else if (g_data.r_pid == 0)
	{
		if (!argv[1])
			ft_print_matrix(g_data.env);
		else
		{
			vars = ft_split(argv[1], '=');
			if (!g_data.vars)
				ft_init_vars(vars[0], vars[1]);
			else
				g_data.vars = ft_realloc_vars(vars[0], vars[1]);
			free(vars[0]);
			free(vars[1]);
			free(vars);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:44 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/29 14:46:45 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void ft_print_env(t_vars *env)
{
	int cnt;

	cnt = 0;
	if(!env->values || !env->names)
		return;
	while(env->values[cnt] && env->names[cnt])
	{
		printf("%s = %s\n", env->names[cnt], env->values[cnt]);
		cnt++;
	}
}

static t_vars *ft_realloc_vars(char *name, char *value)
{
	t_vars *new;
	int cnt;

	new = malloc(sizeof(t_vars *));
	cnt = 0;
	while(g_data.vars->names[cnt] && g_data.vars->values[cnt])
		cnt++;
	new->names = malloc(sizeof(char *) * (cnt + 2));
	new->values = malloc(sizeof(char *) * (cnt + 2));
	cnt = 0;
	while(g_data.vars->names[cnt] && g_data.vars->values[cnt])
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
	return (new);
}

static void ft_init_vars(char *name, char *value)
{
	g_data.vars = malloc(sizeof(t_vars *));
	g_data.vars->names = malloc(sizeof(char *) * 2);
	g_data.vars->values = malloc(sizeof(char *) * 2);
	g_data.vars->names[0] = ft_strdup(name);
	g_data.vars->names[1] = NULL;
	g_data.vars->values[0] = ft_strdup(value);
	g_data.vars->values[1] = NULL;
}

//ADD VARS TO ENV

void ft_export(char **argv)
{
	char **vars;
	pid_t pid;

	pid = fork();
	if(pid < 0)
		printf("[ERROR] Could not create a child process \n");
	else if(pid == 0)
	{
		if(!argv[1])
			ft_print_env(g_data.vars);
		else
		{
			vars = ft_split(argv[1], '=');
			if(!g_data.vars)
				ft_init_vars(vars[0], vars[1]);
			else
				g_data.vars = ft_realloc_vars(vars[0], vars[1]);
			free(vars[0]);
			free(vars[1]);
			free(vars);
		}
	}
	else
		wait(&pid);
}

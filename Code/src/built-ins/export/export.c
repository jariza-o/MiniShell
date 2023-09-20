/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:44 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/20 18:03:51 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void ft_print_env(t_vars *env)
{
	int cnt;

	cnt = 0;
	if(!env)
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
		new->names[cnt] = malloc(sizeof(char)*ft_strlen(g_data.vars->names[cnt]));
		new->values[cnt] = malloc(sizeof(char)*ft_strlen(g_data.vars->values[cnt]));
		new->names[cnt] = ft_strdup(g_data.vars->names[cnt]);
		new->values[cnt] = ft_strdup(g_data.vars->values[cnt]);
		cnt++;
	}
	new->names[cnt] = malloc(sizeof(char)*ft_strlen(name) + 1);
	new->values[cnt] = malloc(sizeof(char)*ft_strlen(value) + 1);
	new->names[cnt] = ft_strdup(name);
	new->values[cnt] = ft_strdup(value);
	return (new);
}

static void ft_init_vars(char *name, char *value)
{
	g_data.vars = malloc(sizeof(t_vars *));
	g_data.vars->names = malloc(sizeof(char *) * 2);
	g_data.vars->values = malloc(sizeof(char *) * 2);
	g_data.vars->names[0] = malloc(sizeof(char)*ft_strlen(name) + 1);
	g_data.vars->values[0] = malloc(sizeof(char)*ft_strlen(value) + 1);
	g_data.vars->names[0] = ft_strdup(name);
	g_data.vars->values[0] = ft_strdup(value);
}

void ft_export(char **argv)
{
	char **vars;

	if(!argv[1])
		ft_print_env(g_data.vars);
	else
	{
		vars = ft_split(argv[1], '=');
		if(!g_data.vars)
			ft_init_vars(vars[0], vars[1]);
		else
			g_data.vars = ft_realloc_vars(vars[0], vars[1]);
	}
}
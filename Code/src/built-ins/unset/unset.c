/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:54 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/20 20:00:43 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static t_vars *ft_reasign_vars(int indx)
{
	t_vars *new;
	int cnt;
	int cnt2;

	cnt = 0;
	while(g_data.vars->names[cnt] && g_data.vars->values[cnt])
		cnt++;
	new = malloc(sizeof(t_vars *));
	new->names = malloc(sizeof(char *) * cnt - 1);	
	new->names = malloc(sizeof(char *) * cnt - 1);
	cnt = 0;
	cnt2 = 0;
	while(g_data.vars->names[cnt] && g_data.vars->values[cnt])
	{
		if(cnt != indx)
		{
			new->names[cnt2] = ft_strdup(g_data.vars->names[cnt]);
			new->values[cnt2] = ft_strdup(g_data.vars->values[cnt]);
			cnt2++;
		}
		cnt++;
	}
	g_data.vars = ft_clean_vars(g_data.vars);
	return (new);
}

void ft_unset(char **argv)
{
	int cnt;
	t_vars *new;

	cnt = 0;
	new = NULL;
	if(!argv[1])
	{
		printf("[ERROR] Not enough arguments\n");
		exit(1);
	}
	if(!g_data.vars)
		return;
	while(ft_strcmp(g_data.vars->names[cnt], argv[1]) != 0 && g_data.vars->names[cnt])
		cnt++;
	if(g_data.vars->names[cnt])
		g_data.vars = ft_reasign_vars(cnt);
}
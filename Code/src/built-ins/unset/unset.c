/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:54 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/29 14:55:23 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static t_vars *ft_reasign_vars(int indx)
{
	t_vars *new;
	int cnt;
	int cnt2;

	cnt = 0;
	printf("llega");
	while(g_data.vars->names[cnt] && g_data.vars->values[cnt])
		cnt++;
	new = malloc(sizeof(t_vars *));
	new->names = malloc(sizeof(char *) * cnt);	
	new->names = malloc(sizeof(char *) * cnt);
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
	printf("name: %s value %s\n", new->names[0], new->values[0]);
	g_data.vars = ft_clean_vars(g_data.vars);
	return (new);
}

void ft_unset(char **argv)
{
	int cnt;
	t_vars *new;
	pid_t pid;

	cnt = 0;
	pid = fork();
	new = NULL;
	if(pid < 0)
		printf("[ERROR] Could not create a child process \n");
	else if (pid == 0)
	{
		if(!argv[1])
		{
			printf("[ERROR] Not enough arguments\n");
			exit(1);
		}
		if(!g_data.vars)
			return;
		if(!g_data.vars->names[1] && !g_data.vars->values[1])
		{
			g_data.vars = ft_clean_vars(g_data.vars);
			return;
		}
		while(ft_strcmp(g_data.vars->names[cnt], argv[1]) != 0 && g_data.vars->names[cnt])
			cnt++;
		if(g_data.vars->names[cnt])
		{
			g_data.vars = ft_reasign_vars(cnt);
		}
	}
	else
		wait(&pid);
}

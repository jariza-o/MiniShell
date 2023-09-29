/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:41:56 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/29 14:33:13 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_vars *ft_clean_vars(t_vars *vars)
{
	int cnt;

	cnt = 0;
	if(!vars)
		return (NULL);
	while(vars->names[cnt] && vars->values[cnt])
	{
		free(vars->names[cnt]);
		free(vars->values[cnt]);
		cnt++;
	}
	free(vars->names[cnt]);
	free(vars->values[cnt]);
	free(vars->names);
	free(vars->values);
	free(vars);
	vars = NULL;
	return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:26 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/06 16:37:53 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_cd(char *path)
{
	if (!path || !ft_strcmp(path, ""))
	{
		if (chdir(getenv("HOME")) != 0)
		{
			ft_print_errors(CD);
			g_data.exit_status = 1;
			return ;
		}
	}
	else if ((chdir(path) != 0))
	{
		printf("cd: %s: No such file or directory\n", path);
		g_data.exit_status = 1;
	}
	else
		g_data.exit_status = 0;
}

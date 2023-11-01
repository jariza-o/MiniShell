/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:26 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/01 18:12:13 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_cd(char *path)
{
	char	oldpwd[255];

	getcwd(oldpwd, sizeof(oldpwd));
	if(path && !ft_strcmp(path, "-"))
		path = ft_get_env("OLDPWD");
	if (!path || !ft_strcmp(path, ""))
	{
		if (chdir(ft_get_env("HOME")) != 0)
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
	{
		ft_reasign("OLDPWD", oldpwd);
		getcwd(oldpwd, sizeof(oldpwd));
		ft_reasign("PWD", oldpwd);
		g_data.exit_status = 0;
	}
}

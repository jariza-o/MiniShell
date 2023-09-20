/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:26 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/20 13:36:51 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_cd(char *path)
{
	printf("path: %s\n", path);
	if (!path[1] || !ft_strcmp(path, ""))
	{
		if (chdir(g_data.user) != 0) // Cuando tenga hecho ENV poner aqui el home del user
		{
			ft_print_errors(CD);
			return ;
		}
	}
	if ((chdir(path) != 0))
		printf("cd: %s: No such file or directory\n", path); //en bash pone antes bash: deberíamos de poner el nombre de nuestra minishell??
	// crear funcion que mne actualice a donde está
}

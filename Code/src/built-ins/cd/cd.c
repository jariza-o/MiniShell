/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:26 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/29 14:24:27 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_cd(char *path)
{
	pid_t pid;

	pid = fork();
	if(pid < 0)
		printf("[ERROR] Could not create a child process \n");
	else if (pid == 0)
	{
		if (!path || !ft_strcmp(path, ""))
		{
			if (chdir(getenv("HOME")) != 0) // Cuando tenga hecho ENV poner aqui el home del user
			{
				ft_print_errors(CD);
				return ;
			}
		}
		else if ((chdir(path) != 0))
			printf("cd: %s: No such file or directory\n", path); //en bash pone antes bash: deberíamos de poner el nombre de nuestra minishell??
	}// crear funcion que mne actualice a donde está
	else
	{
		wait(&pid);
		free(path);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:26 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/18 18:03:27 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_cd(char **argv)
{
	if (!argv[1] || !ft_strcmp(argv[1], ""))
	{
		if (chdir("USER") != 0) // Cuando tenga hecho ENV poner aqui el home del user
		{
			ft_print_errors(CD);
			return ;
		}
	}
	if ((chdir(argv[1]) != 0))
		printf("cd: %s: No such file or directory\n", argv[1]); //en bash pone antes bash: deberíamos de poner el nombre de nuestra minishell??
	// crear funcion que mne actualice a donde está
}

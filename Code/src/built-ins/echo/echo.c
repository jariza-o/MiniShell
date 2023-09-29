/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:13:05 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/29 14:25:09 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
- tener en cuenta en el split que si es entre comillas el argv puede tener espacios y \t
- entre argumentos si hay varios espacio no hay que tenerlos en cuenta
- como se hace para que cuando empiece por " o por ' haga lo del salto y que se pueda escribir
*/

static int	ft_echo_flag(char **argv);

void	ft_echo(char **argv)
{
	int	i;
	pid_t pid;

	pid = fork();
	if(pid < 0)
		printf("[ERROR] Could not create a child process \n");
	else if (pid == 0)
	{
		i = ft_echo_flag(argv);
		if (!argv[1])
		{
			write(1, "\n", 1);
			return ;
		}
		if (i == 0)
			i++;
		while (argv[i])
		{
			ft_putstr(argv[i]);
			i++;
			if (argv[i])
				write(1, " ", 1);
		}
		if (ft_echo_flag(argv) <= 1)
			printf("\n");
	}
	else
		wait(&pid);
}

static int	ft_echo_flag(char **argv)
{
	int	i;
	int	n;

	i = 1;
	if (argv[1][0] != '-')
		return (0);
	while (argv[i])
	{
		n = 0;
		if (argv[i][n] == '-')
		{
			n++;
			while (argv[i][n])
			{
				if (argv[i][n] == 'n')
					i++;
				else
					return (i);
			}
		}
		else
			return (i);
		i++;
	}
	return (i);
}

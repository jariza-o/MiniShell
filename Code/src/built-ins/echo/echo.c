/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:13:05 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/04 18:27:05 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
- tener en cuenta en el split que si es entre comillas el argv 
puede tener espacios y \t
- entre argumentos si hay varios espacio no hay que tenerlos en cuenta
- como se hace para que cuando empiece por " o por ' haga lo del salto 
y que se pueda escribir
*/

static int	ft_echo_flag(char **argv);

static int	ft_status(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$')
	{
		i++;
		if (str[i] == '?')
			return (1);
	}
	return (0);
}

void	ft_echo(char **argv)
{
	int	i;

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
		if (ft_status(argv[i]) == 1)
			ft_printf("%i", g_data.exit_status);
		else
			ft_putstr(argv[i]);
		i++;
		if (argv[i])
			write(1, " ", 1);
	}
	if (ft_echo_flag(argv) <= 1)
		printf("\n");
	g_data.exit_status = 0;
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

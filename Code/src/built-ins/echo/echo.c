/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:13:05 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/15 17:21:03 by jjaen-mo         ###   ########.fr       */
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
	int	cnt;

	cnt = 1;
	if (ft_echo_flag(argv))
		cnt++;
	if (!argv[1])
	{
		write(1, "\n", 1);
		return ;
	}
	while (argv[cnt])
	{
		if (ft_status(argv[cnt]) == 1)
			ft_printf("%i", g_data.exit_status);
		else
			ft_putstr(argv[cnt]);
		cnt++;
		if (argv[cnt])
			write(1, " ", 1);
	}
	if (!ft_echo_flag(argv))
		printf("\n");
	g_data.exit_status = 0;
}

static int	ft_echo_flag(char **argv)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
	while (argv[cnt])
	{
		cnt2 = 0;
		if (argv[cnt][cnt2] == '-')
		{
			cnt2++;
			while (argv[cnt][cnt2] == 'n')
				cnt2++;
			if (argv[cnt][cnt2] == '\0')
				return (1);
		}
		cnt++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:37 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/02 18:03:26 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(void)
{
	ft_printf("exit\n");
	if(g_data.recieved[1])
	{
		if (!ft_is_number(g_data.recieved[1]))
		{
			ft_printf("exit: %s: numeric argument required\n", g_data.recieved[1]);
			g_data.exit_status = 255;
		}
		else
			g_data.exit_status = ft_atoi(g_data.recieved[1]);
	}
	ft_clean_double_pointer(g_data.recieved);
	free(g_data.prompt);
	// free(g_data.user);
	free(g_data.line);
	ft_clean_double_pointer(g_data.env);
	// ft_clear_tokens(&g_data.tokens);
	ft_printf("%i\n", g_data.exit_status);
	exit(g_data.exit_status);
}

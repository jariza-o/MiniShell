/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:37 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/04 19:16:11 by jjaen-mo         ###   ########.fr       */
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
	if (g_data.recieved[1])
	{
		if (!ft_is_number(g_data.recieved[1]))
		{
			ft_printf("exit: %s: numeric argument required\n",
				g_data.recieved[1]);
			g_data.exit_status = 255;
		}
		else
			g_data.exit_status = ft_atoi(g_data.recieved[1]);
	}
	if(g_data.recieved)
		ft_clean_double_pointer(g_data.recieved);
	if(g_data.prompt)
		free(g_data.prompt);
	if(g_data.prompt)
		free(g_data.line);
	if(g_data.env)
		g_data.env = ft_clean_matrix(g_data.env);
	exit(g_data.exit_status);
}

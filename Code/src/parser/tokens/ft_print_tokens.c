/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:51:12 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/04 17:52:43 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_print_tokens(void)
{
	t_token	*aux;

	aux = g_data.tokens;
	while (g_data.tokens)
	{
		ft_printf("Token STR:%s\n", g_data.tokens->str);
		// ft_printf("Token TYPE: %d\n", g_data.tokens->type);
		g_data.tokens = g_data.tokens->next;
	}
	g_data.tokens = aux;
}

void	ft_printf_recivied(void)
{
	int	i;

	i = 0;
	while (g_data.recieved[i])
	{
		ft_printf("RECEIVED: %s\n", g_data.recieved[i]);
		i++;
		ft_printf("-----------------------------------\n\n");
	}
}

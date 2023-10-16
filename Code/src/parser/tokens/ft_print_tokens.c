/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:51:12 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/16 16:56:33 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_print_tokens(void)
{
	t_token	*aux;

	aux = g_data.tokens;
	while (g_data.tokens)
	{
		ft_printf("Token STR: %s\n", g_data.tokens->str);
		ft_printf("Token TYPE: %d\n", g_data.tokens->type);
		g_data.tokens = g_data.tokens->next;
	}
	g_data.tokens = aux;
}
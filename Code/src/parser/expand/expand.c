/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:54:16 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/07 18:05:10 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_expand_data(void)
{
	t_token	*aux;
	int		i;

	aux = g_data.tokens;
	while (g_data.tokens)
	{
		i = -1;
		//ft_printf("INIT: %s\n", g_data.tokens->str);
		while (g_data.tokens->str[++i])
		{
			if (g_data.tokens->str[i] == '\'')
			{
				while (g_data.tokens->str[++i] != '\'')
					;
				i++;
			}
			if (g_data.tokens->str[i] == '$')
			{
				ft_expand_env(g_data.tokens);
				i = -1;
			}
		}
		g_data.tokens = g_data.tokens->next;
	}
	g_data.tokens = aux;
	while (g_data.tokens)
	{
		if (g_data.tokens)
			ft_printf("INITIAL: %s\n", g_data.tokens->str);
		ft_expand_quotes(g_data.tokens->str);
		if (g_data.tokens)
			ft_printf("FINAL: %s\n", g_data.tokens->str);
		g_data.tokens = g_data.tokens->next;
	}
	g_data.tokens = aux;
	// ft_print_tokens();
}

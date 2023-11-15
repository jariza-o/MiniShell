/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:54:16 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/15 19:36:15 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_expand_data(void)
{
	t_token	*aux;
	int		i;
	int		n;

	aux = g_data.tokens;
	while (g_data.tokens)
	{
		i = -1;
		while (g_data.tokens && g_data.tokens->str && g_data.tokens->str[++i])
		{
			n = i;
			if (g_data.tokens->str[i] == '\'')
			{
				while (g_data.tokens->str && g_data.tokens->str[++i] && g_data.tokens->str[i] != '\'')
					;
				if (!g_data.tokens->str[i])
					i = n;
			}
			else if (g_data.tokens->str && g_data.tokens->str[i] == '$')
			{
				ft_expand_env(g_data.tokens);
				i = -1;
			}
		}
		ft_expand_quotes(g_data.tokens->str);
		g_data.tokens = g_data.tokens->next;
	}
	g_data.tokens = aux;
}

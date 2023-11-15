/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:54:16 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/15 16:29:32 by jariza-o         ###   ########.fr       */
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
		while (g_data.tokens->str && g_data.tokens->str[++i])
		{
			if (g_data.tokens->str[i] == '\'')
			{
				while (g_data.tokens->str && g_data.tokens->str[++i] != '\'')
					;
			}
			else if (g_data.tokens->str[i] == '$')
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

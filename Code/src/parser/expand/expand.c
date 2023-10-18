/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:54:16 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/18 18:23:14 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// static void ft_del_single_quote(t_token *tokens);

void	ft_expand_data(void)
{
	t_token	*aux;
	int		i;

	aux = g_data.tokens;
	// ft_printf("EXPAND TOKEN: %s\n", g_data.tokens->str);
	// ft_printf("EXPAND AUX: %s\n", aux->str);
	while (g_data.tokens)
	{
		i = 0;
		if (g_data.tokens->type == ENVI_VAR)
			ft_expand_env(g_data.tokens);
		else if (g_data.tokens->type == SINGLE_QUOTE)
			ft_expand_quotes(g_data.tokens);
		else
		{
			while (g_data.tokens->str[i])
			{
				if (g_data.tokens->str[i] == '$')
				{
					ft_expand_env(g_data.tokens);
					i = -1; // ESTABA A 0
				}
				i++;
			}
			ft_expand_quotes(g_data.tokens);
			ft_printf("EXPAND QUOTES: %s\n", g_data.tokens->str);
		}
		g_data.tokens = g_data.tokens->next;
	}
	g_data.tokens = aux;
	//	ft_printf("EXPAND dsfsdf: %s\n", g_data.tokens->str);
	
	while (aux)
	{
		ft_printf("EXPAND AUX: %s\n", aux->str);
		aux = aux->next;
	}
}

// static void	ft_del_single_quote(t_token *tokens)
// {
// 	char	*str;
// 	int		i;
// 	int		n;

// 	i = 0;
// 	n = 0;
// 	while (tokens->str[i])
// 	{
// 		if (tokens->str[i] == '\'')
// 			n++;
// 		i++;
// 	}
// 	str = (char *)malloc(sizeof(char) * (i - n));
// 	if (!str)
// 		return ;
// 	i = 0;
// 	n = 0;
// 	while (tokens->str[i])
// 	{
// 		if (tokens->str[i] == '\'')
// 			i++;
// 		else
// 		{
// 			str[n] = tokens->str[i];
// 			i++;
// 			n++;
// 		}
// 	}
// 	tokens->str = str;
// 	free (str);
// }

// static void ft_del_double_quote(t_token *tokens)
// {
// 	char	*str;
// 	int		i;
// 	int		n;

// 	i = 0;
// 	n = 0;
// 	while (tokens->str[i])
// 	{
// 		if (tokens->str[i] == '\"')
// 			n++;
// 		i++;
// 	}
// 	str = (char *)malloc(sizeof(char) * (i - n));
// 	if (!str)
// 		return ;
// 	i = 0;
// 	n = 0;
// 	while (tokens->str[i])
// 	{
// 		if (tokens->str[i] == '\"')
// 			i++;
// 		else
// 		{
// 			str[n] = tokens->str[i];
// 			i++;
// 			n++;
// 		}
// 	}
// 	tokens->str = str;
// 	free (str);
// }

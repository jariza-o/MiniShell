/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:54:16 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/06 19:03:58 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// static void ft_del_single_quote(t_token *tokens);

void	ft_expand_data(void)
{
	t_token	*aux;
	int		i;

	aux = g_data.tokens;
	while (g_data.tokens)
	{
		i = 0;
		while (g_data.tokens->str[i] != '$' && g_data.tokens->str[i])
			i++;
		if (g_data.tokens->str[i] == '$')
		{
			ft_expand_env(g_data.tokens);
			ft_printf("TEST: %s\n", g_data.tokens->str);
		}
		else
		{
			ft_expand_quotes(g_data.tokens);
			ft_printf("hola: %s\n", g_data.tokens->str);
			ft_printf("I= %d\n", i);
			g_data.tokens = g_data.tokens->next;
		}
	}
	g_data.tokens = aux;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:40:43 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/07 19:21:52 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_check_redirections(void)
{
	t_token	*aux;

	aux = g_data.tokens;
	while (g_data.tokens)
	{
		if ((g_data.tokens->type == IN_RED || g_data.tokens->type == OUT_RED || \
		g_data.tokens->type == HERE_DOC_RED || \
		g_data.tokens->type == APPEND_RED || g_data.tokens->type == PIPE) && \
		(!g_data.tokens->prev || (!g_data.tokens->next || g_data.tokens->next == NULL)))
		{
			ft_printf("FJUDHJUDH\n");
			g_data.tokens = aux;
			return (0);
		}
		if ((g_data.tokens->type == IN_RED || g_data.tokens->type == OUT_RED || \
		g_data.tokens->type == HERE_DOC_RED || \
		g_data.tokens->type == APPEND_RED || g_data.tokens->type == PIPE) && \
		(g_data.tokens->next->type == IN_RED || g_data.tokens->next->type == OUT_RED || \
		g_data.tokens->next->type == HERE_DOC_RED || \
		g_data.tokens->next->type == APPEND_RED || g_data.tokens->next->type == PIPE))
		{
			ft_printf("sssssss\n");
			g_data.tokens = aux;
			return (0);
		}
			ft_printf("sswdsdsssss\n");
		g_data.tokens = g_data.tokens->next;
	}
	g_data.tokens = aux;
	return (1);
}

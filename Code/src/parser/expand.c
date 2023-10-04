/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:54:16 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/04 16:05:21 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_expand_data(void)
{
	t_token *aux;

	aux = g_data.tokens;
	while (g_data.tokens)
	{
		else if (g_data.tokens->type == NO_QUOTE)
		
		else if (g_data.tokens->type == SINGLE_QUOTE)

		else if (g_data.tokens->type == DOUBLE_QUOTE)

		else if (g_data.tokens->type == ENVI_VAR)
		
	}
}

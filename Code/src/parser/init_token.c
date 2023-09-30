/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:07:14 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/30 20:23:33 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	fit_init_token(void)
{
	// RSERVAR MEMORIA PARA LA LISTA??
	int	i;

	i = 0;
	while (g_data.recieved[i])
	{
		g_data.tokens->str = g_data.recieved[i];
		g_data.tokens->type = VOID;
		g_data.tokens = g_data.tokens->next;
		i++;
	}
}

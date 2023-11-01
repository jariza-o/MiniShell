/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:37 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/01 19:14:24 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_exit(void)
{
	ft_clean_double_pointer(g_data.recieved);
	free(g_data.prompt);
	free(g_data.user);
	free(g_data.line);
	ft_clean_double_pointer(g_data.env);
	// ft_clear_tokens(&g_data.tokens);
	exit(g_data.exit_status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:37 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/01 18:42:04 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/* He puesto 0, pero cuando salga tiene, te saca con un estado de salida,
	habrá que implemnetarlo,
	0 si está bien o otro si está mal. Este estado será segúnn el estado 
	del comando anteriror
*/

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

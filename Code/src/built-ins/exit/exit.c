/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:37 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/25 18:49:21 by jjaen-mo         ###   ########.fr       */
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
	g_data.recieved = ft_clean_matrix(g_data.recieved);
	if (g_data.line)
		free(g_data.line);
	if (g_data.vars_mod)
		g_data.env = ft_clean_matrix(g_data.env);
	exit(g_data.exit_status);
}

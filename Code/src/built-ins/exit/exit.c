/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:37 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/18 18:18:16 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_exit(void)
{
	// Funciones para liberar todo  lo necesario, que habrá que pasarselo a la función
	exit (0); // He puesto 0, pero cuando salga tiene, te saca con un estado de salida, habrá que implemnetarlo, 0 si está bien o otro si está mal. Este estado será segúnn el estado del comando anteriror
}

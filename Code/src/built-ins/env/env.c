/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:31 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/06 16:41:30 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_print_matrix(char **matrix)
{
	int	cnt;

	cnt = 0;
	if (!matrix)
		return ;
	while (matrix[cnt])
	{
		printf("%s\n", matrix[cnt]);
		cnt++;
	}
	g_data.exit_status = 0;
}

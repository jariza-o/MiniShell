/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:31 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/20 16:44:31 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void ft_print_matrix(char **matrix)
{
	int cnt;

	cnt = 0;
	if(!matrix)
		return;
	while(matrix[cnt])
	{
		printf("%s\n", matrix[cnt]);
		cnt++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:31 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/01 17:27:24 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_print_matrix(char **matrix)
{
	int	cnt;

	g_data.r_pid = fork();
	if (g_data.r_pid < 0)
		printf("[ERROR] Could not create a child process \n");
	else if (g_data.r_pid == 0)
	{
		cnt = 0;
		if (!matrix)
			return ;
		while (matrix[cnt])
		{
			printf("%s\n", matrix[cnt]);
			cnt++;
		}
	}
}

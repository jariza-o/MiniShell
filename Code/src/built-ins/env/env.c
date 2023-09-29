/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:31 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/29 14:26:07 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void ft_print_matrix(char **matrix)
{
	int cnt;
	pid_t pid;

	pid = fork();
	if(pid < 0)
		printf("[ERROR] Could not create a child process \n");
	else if (pid == 0)
	{
		cnt = 0;
		if(!matrix)
			return;
		while(matrix[cnt])
		{
			printf("%s\n", matrix[cnt]);
			cnt++;
		}
	}
	else
		wait(&pid);
}

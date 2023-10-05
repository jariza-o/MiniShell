/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:49 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/05 19:38:52 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_pwd(void)
{
	char	cwd[256];

	g_data.r_pid = fork();
	if (g_data.r_pid < 0)
		printf("[ERROR] Could not create a child process \n");
	else if (g_data.r_pid == 0)
	{
		cwd[255] = '\0';
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s\n", cwd);
		else
			ft_print_errors(PWD);
		exit(0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:49 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/29 14:28:01 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_pwd(void)
{
	pid_t	pid;
	char	cwd[256];

	pid = fork();
	if(pid < 0)
		printf("[ERROR] Could not create a child process \n");
	else if (pid == 0)
	{
		cwd[255] = '\0';
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s\n", cwd);
		else
			ft_print_errors(PWD);
	}
	else
		wait(&pid);
}

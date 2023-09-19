/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:55:00 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/19 19:41:07 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	char *str;
	int cnt;
	argc = 0;
	(void)env;

	argv[0] = "echo";
	argv[1] = "hola";
	str = 0;
	cnt = 0;
	while((str = readline("MiniSheh$> ")) != NULL)
	{
		g_data.recieved = ft_split(str, ' ');
		g_data.env = env;
		while(g_data.env[cnt])
		{
			printf("%s\n", g_data.env[cnt]);
			cnt++;
		}
		if(ft_strcmp(g_data.recieved[0], "echo") == 0)
			ft_echo(g_data.recieved);
		else if (ft_strcmp(g_data.recieved[0], "cd") == 0)
			ft_cd(g_data.recieved);
	}
	return (0);
}

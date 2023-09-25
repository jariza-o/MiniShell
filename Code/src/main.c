/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:55:00 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/25 17:02:54 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_shell(void)
{
	printf("\e[1;1H\e[2J");
	printf("\n******************"
			"************************");
	printf("\n\n\n\t****WELCOME TO****");
	printf("\n\n\t-MINIHSHEH-");
	printf("\n\n\n\n*******************"
			"***********************");
	printf("\nUSER is: @%s", g_data.user);
	printf("\n");
}

void	ft_cmds(void)
{
	if (ft_strcmp(g_data.recieved[0], "echo") == 0)
		ft_echo(g_data.recieved);
	else if (ft_strcmp(g_data.recieved[0], "cd") == 0)
		ft_cd(g_data.recieved[1]);
	else if (ft_strcmp(g_data.recieved[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(g_data.recieved[0], "export") == 0)
		ft_export(g_data.recieved);
	else if (ft_strcmp(g_data.recieved[0], "unset") == 0)
		ft_unset(g_data.recieved);
	else if (ft_strcmp(g_data.recieved[0], "env") == 0)
		ft_print_matrix(g_data.env);
	else if (ft_strcmp(g_data.recieved[0], "exit") == 0)
		ft_exit();
	else if (ft_strcmp(g_data.recieved[0], "clear") == 0)
		printf("\e[1;1H\e[2J");
	else
		ft_system_cmds(g_data.recieved);
}

int	main(int argc, char **argv, char **env)
{
	char	*str;

	(void)argc;
	(void)argv;
	str = 0;
	g_data.env = env;
	g_data.user = getenv("USER");
	ft_signals();
	init_shell();
	while ((str = readline("MiniSheh$> ")) != NULL)
	{
		add_history(str);
		g_data.recieved = ft_split(str, ' ');
		ft_parser();
		ft_cmds();
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:55:00 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/24 18:28:31 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void ft_leaks()
// {
// 	system("leaks -q Minishell");
// }

void	init_shell(void)
{
	printf("^^^~~~~~~!!!!!!!!!!!!!!!!!?PPGGGGGGP5J!~~~~~~~~!!!!!!!!!!!~~~~~\n");
	printf("::^^~~^^^^^^~^^~~~~!!!!7JY55P5PPPPPPGGPJ~~~~~~~!!~~~~!!!!!!!~~~\n");
	printf("^^^^~~^^^^^^^^^^^~~!!~~5G5YYYJ???777?5GJ~~~~~~~!!~~~~~!!!~!!!!!\n");
	printf("^^^^^^^^^^^^^^^^^^~~~~7PPY5555YJJ??77YP7~~~~~~~!!~^~~!!!~~~!!!!\n");
	printf("^^^^^^^^^::^^:^^^~~~!!?J?Y555PPYJ55JJ5Y!~~~~~~~~!~^~~!!!!~!!!!!\n");
	printf("^^^^^^^~^^^^^^^~~~~~!JY77YYYY55J?????J~~~~~!!~~~!~~~!!!~~!!!!!!\n");
	printf("::^:^^^^^^^^~~~~~~~~~7JJJYY555YJ??????~~~~~~~!!!!!!!!~~^~~~~~!!\n");
	printf(":::::^^^^~^~~~~~~^^^^^~!JYY5PP55Y???7~~~~^~~~~!!!!!!!~^^^^^^~~!\n");
	printf(":::::^^^^~~~~~~^^^^^^^^!JYYY5YJJ???~^^~~~^^~~~~!!!~~~~^^^^^^^^~\n");
	printf("^^^^^^^^~~~~~~~~~~~~~~~7Y5555YJJ???7~~~~~~~~~~~~!!!~~~~~~~~~~~~\n");
	printf("^^^^^^^~~~~~~~~~~~~~~~~7JJJY5YJJ??7PGY?!!!~~~~~~~~~~~~~~~~~~~~~\n");
	printf(":^::^^^~~~~~~^^^^~!77!7YYYYY5YYJJ?!P###GP5YJJ?77!~~~~~~~~^^^^^^\n");
	printf("^^::^^^~~~~~~!7J5GBB5!7Y55YY5P5J7~7B##&&&#BBB##BGGPY!~!!~~~~~~^\n");
	printf("::::^^^~~!?J5GB#&&#&G!7555YYYJ7!~7G##&&&&&###&&&&###P!~~!~~~~~~\n");
	printf("^^^^^^~~~Y#####&&&&&BJY5YJYYJ?77JB&#&&&&&&&&&&#######?~~!!!~~~~\n");
	printf("^^^^^^~~~P####&&&&&&#&#P?!YPPP5PG##&&&&&&&GP###&&####?~~~!!!!~~\n");
	printf("^^^^~~~~!G#&&#&&&&&&&&#P7!YPPPPGG##&&&&&&&P55&&#GB##Y~~~~!!!!!!\n");
	printf("^^^^^~~~~P#####&&&##&&#G?75PPPPGG##&&&&&&&#5YGPJ?YB#7~~~~~~!!!!\n");
	printf("^^~~~~!~~J#&&&&&#&&&&&&B55PPPPPGG#&&&&&&&&#555Y?YB#G!~~~~~~~~~!\n");
	printf("~~~~~~~!~Y#&&&&&&&&&&&&#5PGPPPPPGB&&&&&&&&#P5YJJJG##BJ~~~~~~~~~\n");
	printf("^~~~~~~~~Y##&&&&&&&&&&&#PPGGGGGGGB#&&&&&&&P5Y??JY#&&##5~~~~~~~~\n");
	printf("~~~~~~~~~?##&&&&&&&&&&&&PGGGGGGGBB##&&&&&&#G5YYY5B#####Y~~~~~~~\n");
	printf("~~~~~~~~~!B&&&&&&&&&&&&&PGGGGGGGGBBB#&&&&&@@&##B#&######J~~~~~~\n");
	printf("\n\t\t<--USER is: @%s-->", g_data.user);
	printf("\n\n");
}

// static char	**ft_dup_envs(char **env)
// {
// 	int		cnt;
// 	char	**new_env;

// 	cnt = 0;
// 	while (env[cnt])
// 		cnt++;
// 	new_env = (char **)malloc(sizeof(char *) * (cnt + 1));
// 	cnt = 0;
// 	while (env[cnt])
// 	{
// 		new_env[cnt] = ft_strdup(env[cnt]);
// 		cnt++;
// 	}
// 	new_env[cnt] = NULL;
// 	return (new_env);
// }

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
	// atexit(ft_leaks);
	(void)env; //
	(void)argc;
	(void)argv;
	// g_data.env = ft_dup_envs(env);
	g_data.env = NULL; //
	g_data.user = getenv("USER");
	ft_signals();
	// init_shell();
	while ((g_data.prompt = readline("MiniSheh$> ")) != NULL)
	{
		if (g_data.prompt[0] != '\0')
		{
			add_history(g_data.prompt);
			if ((g_data.recieved = ft_mini_split(g_data.prompt)) != NULL)
			{
				if (ft_initial_errors())
				{
					g_data.tokens = ft_init_token();
					ft_tokenizer();
					ft_print_tokens();
					if (ft_errors())
					{
						ft_expand_data();
						ft_tokens_to_str();
						ft_printf("LINE: %s\n", g_data.line);
						// g_data.tokens = NULL; // ESTO PORQUE?? LO METIO XEMA
						// ft_cmds();
						// if (g_data.recieved)
						// 	g_data.recieved = ft_clean_matrix(g_data.recieved);
						ft_clear();
					}
				}
			}
		}
		free (g_data.prompt);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:50:09 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/25 17:36:39 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_find_env(int i);

void	ft_simple_quote(void)
{
	int		i;
	int		n;
	int		j;
	char	*argv;

	i = 1;
	argv = malloc(100000); //cambiar
	while (g_data.recieved[i])
	{
		n = 0;
		j = 0;
		while (g_data.recieved[i][n])
		{
			if (g_data.recieved[i][n] == '\'')
				n++;
			argv[j] = g_data.recieved[i][n];
			j++;
			n++;
		}
		g_data.recieved[i] = argv;
		free(argv);
		i++;
	}
}

void	ft_double_quote(void)
{
	int		i;
	int		n;
	int		j;
	char	*argv;

	i = 1;
	argv = malloc(100000); //cambiar
	while (g_data.recieved[i])
	{
		n = 0;
		j = 0;
		while (g_data.recieved[i][n])
		{
			if (g_data.recieved[i][n] == '"')
				n++;
			argv[j] = g_data.recieved[i][n];
			j++;
			n++;
		}
		g_data.recieved[i] = argv;
		free(argv);
		i++;
	}
}

void	ft_parser(void)
{
	int		i;
	int		n;
	char	*argv;

	i = 1;
	argv = malloc(100000); //cambiar
	if (!ft_check_quotes(g_data.recieved))
	{
		ft_print_errors(BUILTINS);
		// termianrlo para poder seguir usando minishell, no se si con un return sirve
	}
	while (g_data.recieved[i])
	{
		n = 0;
		while (g_data.recieved[i][n])
		{
			if (g_data.recieved[i][n] == '\'')
			{
				while (g_data.recieved[i][++n] != '\'')
					n++;
			}
			else if (g_data.recieved[i][n] == '$')
			{
				printf("%s\n", g_data.recieved[i]);
				ft_find_env(i);
				n = 0;
			}
			n++;
		}
		i++;
	}
	ft_simple_quote();
	ft_double_quote();
}

static void	ft_find_env(int i)
{
	char	env[256];
	char	*cosa;
	char	*argv;
	int		n;
	int		j;
	int		k;

	n = 0;
	printf("FJ");
	argv = malloc(100000); //cambiar
	while (g_data.recieved[i][n] != '$')
	{
		argv[n] = g_data.recieved[i][n];
		n++;
	}
	j = n;
	n++;
	k = 0;
	while (g_data.recieved[i][n] != 32 && g_data.recieved[i][n] != '\t' && \
	g_data.recieved[i][n] != '\0' && g_data.recieved[i][n] != '$')
	{
		env[k] = g_data.recieved[i][n];
		k++;
		n++;
	}
	k = 0;
	cosa = getenv(env);
	while (cosa[k])
	{
		argv[j] = cosa[k];
		j++;
		k++;
	}
	while (g_data.recieved[i][n] != '\0')
	{
		argv[j] = g_data.recieved[i][n];
		j++;
		n++;
	}
	g_data.recieved[i] = argv;
	free(argv);
}

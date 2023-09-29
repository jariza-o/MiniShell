/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:50:09 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/29 17:47:12 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_find_env(int i);
static void	ft_simple_quote(void);
static void	ft_double_quote(void);

void	ft_parser(void)
{
	int		i;
	int		n;
	char	*argv;

	i = 1;
	argv = malloc(100000); //cambiar
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
				// printf("%s\n", g_data.recieved[i]);
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
	char	*env;
	char	*cosa;
	char	*argv;
	int		n;
	int		j;
	int		k;

	n = 0;
	argv = malloc(100000); //cambiar
	while (g_data.recieved[i][n] != '$')
	{
		argv[n] = g_data.recieved[i][n];
		n++;
	}
	j = n;
	n++;
	k = 0;
	env = malloc(100000); //cambiar
	while (g_data.recieved[i][n] != 32 && g_data.recieved[i][n] != '\t' && \
	g_data.recieved[i][n] != '\0' && g_data.recieved[i][n] != '$')
	{
		env[k] = g_data.recieved[i][n];
		k++;
		n++;
	}
	k = 0;
	cosa = malloc(100000); //cambiar
	cosa = getenv(env);
	// PONER QUE SI COSA == NULL PONER EL ESPACIO DE CUANDO NO EXISTE
	printf("%s %s\n", cosa, env);
	printf("TEST\n");
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
	printf("krorkffk\n");
	g_data.recieved[i] = argv;
	free(argv);
	// free(env); //
	// free(cosa); //
}

static void	ft_simple_quote(void)
{
	int		i;
	int		n;
	int		j;
	char	*argv;

	i = 1;
	while (g_data.recieved[i])
	{
		argv = malloc(100000); //cambiar
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
			ft_printf("TEST\n");
		i++;
	}
}

static void	ft_double_quote(void)
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
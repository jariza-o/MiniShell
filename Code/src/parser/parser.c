/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:50:09 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/21 18:16:59 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_find_env(int i);

void	ft_parser(t_data g_data)
{
	int	i;
	int	n;

	i = 1;
	ft_check_quotes(g_data.recieved);
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
				ft_find_env(i);
		}
	}
}

void	ft_find_env(int i)
{
	char	env[256];
	char	*cosa;
	char	argv[256];
	int		n;
	int		j;
	int		k;

	n = 0;
	(void)argv;
	while (g_data.recieved[i][n] != '$')
	{
		argv[n] = g_data.recieved[i][n];
		n++;
	}
	j = n;
	n++;
	k = 0;
	while (g_data.recieved[i][n] != ' ' || g_data.recieved[i][n] != '\t' || \
	g_data.recieved[i][n])
	{
	printf("HOLQ\n");
		env[k] = g_data.recieved[i][n];
		k++;
		n++;
	}
	k = 0;
	cosa = getenv(env);
	while (env[k])
	{
		argv[j] = cosa[k];
		j++;
		k++;
	}
	while (g_data.recieved[i][n])
	{
		argv[j] = g_data.recieved[i][n];
		j++;
		n++;
	}
	g_data.recieved[i] = argv;
}

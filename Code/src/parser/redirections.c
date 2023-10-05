/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:14:33 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/05 16:18:37 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_redirect_wordcounter(void);

char	**ft_split_redirections(void)
{
	int		i;
	int		i2;
	int		n;
	int		n2;
	char	**str;

	i = 0;
	i2 = 0;
	// str = malloc(sizeof(char *) * ft_redirect_wordcounter());
	(void)ft_redirect_wordcounter();
	str = malloc(sizeof(char *) * 2);
	while (g_data.recieved[i])
	{
		n = 0;
		n2 = 0;
		while (g_data.recieved[i][n])
		{
			str[i2] = malloc(sizeof(char) * 5);
			if (g_data.recieved[i][n] == '\'')
			{
				str[i2][n2] = g_data.recieved[i][n];
				n++;
				n2++;
				while (g_data.recieved[i][n] != '\'')
				{
					str[i2][n2] = g_data.recieved[i][n];
					n++;
					n2++;
				}
				str[i2][n2] = g_data.recieved[i][n];
				n++;
				n2++;
			}
			else if (g_data.recieved[i][n] == '"')
			{
				str[i2][n2] = g_data.recieved[i][n];
				n++;
				n2++;
				while (g_data.recieved[i][n] != '"')
				{
					str[i2][n2] = g_data.recieved[i][n];
					n++;
					n2++;
				}
				str[i2][n2] = g_data.recieved[i][n];
				n++;
				n2++;
			}
			if (g_data.recieved[i][n] == '<' || g_data.recieved[i][n] == '>' || g_data.recieved[i][n] == '|')
			{
				i2++;
				if ((g_data.recieved[i][n] == '<' || g_data.recieved[i][n] == '>') && (g_data.recieved[i][n + 1] == g_data.recieved[i][n]))
				{
					str[i2][0] = g_data.recieved[i][n];
					str[i2][1] = g_data.recieved[i][n + 1];
					n += 2;
				}
				else
					str[i2][0] = g_data.recieved[i][n];
				i2++;
			}
			else
			{
				str[i2][n2] = g_data.recieved[i][n];
				n++;
				n2++;
			}
		}
		i++;
		i2++;
	}
	return (str);
}

static int	ft_redirect_wordcounter(void)
{
	int	i;
	int	n;
	int	x;

	i = -1;
	x = 0;
	while(g_data.recieved[++i])
	{
		n = 0;
		while (g_data.recieved[i][n])
		{
			if (g_data.recieved[i][n] != '<' && g_data.recieved[i][n] != '>' && g_data.recieved[i][n] != '|')
				n++;
			else
			{
				if ((g_data.recieved[i][n] = '<' && g_data.recieved[i][n + 1] == '<') || \
				(g_data.recieved[i][n] = '>' && g_data.recieved[i][n + 1] == '>'))
					n+= 2;
				else
					n++;
				x+= 2;
			}
		}
		x++;
	}
	return (x);
}

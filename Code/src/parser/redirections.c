/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:14:33 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/01 16:58:23 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_redirect_wordcounter(void);

void	ft_split_redirections(void)
{
	int	i;
	int	n;
	char **str;

	i = 0;
	// str = malloc(sizeof((char *) * ft_redirect_wordcounter())); // VER ESTE MALLOC
	while (g_data.recieved[i])
	{
		n = 0;
		while (g_data.recieved[i][n])
		{
			if (g_data.recieved[i][n] != '\'')
			{
				n++;
				while (g_data.recieved[i][n] != '\'') 
					n++;
				n++;
			}
			else if (g_data.recieved[i][n] != '"')
			{
				n++;
				while (g_data.recieved[i][n] != '"') 
					n++;
				n++;
			}
		}
		
	}
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

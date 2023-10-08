/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:40:43 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/08 14:35:09 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_check_redirections(char **argv)
{
	int	i;
	int	n;

	i = 0;
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if (argv[i][n] == '<' || argv[i][n] == '>')
			{
				if ((argv[i][n] == '<' && argv[i][n + 1] == '>') || (argv[i][n] == '>' && argv[i][n + 1] == '<'))
					return (0);
				if (argv[i + 1][0] == '<' || argv[i + 1][0] == '>'|| argv[i + 1][0] == '|')
					return (0);
			}
			n++;
		}
		i++;
	}
	return (1);
}
int	ft_check_pipes(char **argv)
{
	int	i;
	int	n;

	i = 0;
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if (argv[i][n] == '|')
			{
				if (argv[i + 1][0] == '|')
					return (0);
			}
			n++;
		}
		i++;
	}
	return (1);
}
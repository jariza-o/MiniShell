/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:13:57 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/18 15:29:25 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_check_quotes(char **argv)
{
	int	i;
	int	n;

	i = 0;
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if (argv[i][n] == '"')
			{
				while (argv[i][n] != '"' && argv[i][n])
					n++;
				if (argv[i][n] != '"')
					return (0);
			}
			else if (argv[i][n] == '\'')
			{
				while (argv[i][n] != '\'' && argv[i][n])
					n++;
				if (argv[i][n] != '\'')
					return (0);
			}
			n++;
		}
		i++;
	}
	return (1);
}

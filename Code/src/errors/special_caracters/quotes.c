/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:13:57 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/05 16:19:32 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_check_quotes(char **argv)
{
	int	i;
	int	n;

	i = -1;
	while (argv[++i])
	{
		n = -1;
		while (argv[i][++n])
		{
			if (argv[i][n] == '"')
			{
				n++;
				while (argv[i][n] != '"' && argv[i][n])
					n++;
				if (argv[i][n] != '"')
					return (0);
			}
			else if (argv[i][n] == '\'')
			{
				n++;
				while (argv[i][n] != '\'' && argv[i][n])
					n++;
				if (argv[i][n] != '\'')
					return (0);
			}
		}
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:31:38 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/15 15:49:21 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_mini_isalpha(int c);

int	ft_check_env_errors(char **received)
{
	int	i;
	int	n;

	i = -1;
	while (received && received[++i])
	{
		n = 0;
		while (received[i][n])
		{
			if (received[i][n] == '\'')
			{
				n++;
				while (received[i][n] != '\'' && received[i][n])
					n++;
				if (received[i][n])
					n++;
			}
			if (received[i][n] && received[i][n] == '$' && ft_mini_isalpha(received[i][n + 1]))
				n += 2;
			else if (received[i][n] && received[i][n] == '$')
				return (0);
			while (received[i][n] && (received[i][n] != '$' || received[i][n] != '\''))
				n++;
		}
	}
	return (1);
}

static int	ft_mini_isalpha(int c)
{
	return ((c == '?') || (c == '_') || \
	(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

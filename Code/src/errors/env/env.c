/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:31:38 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/17 17:37:58 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_check_env_errors(char **received)
{
	int	i;
	int	n;

	i = 0;
	while (received[i])
	{
		n = 0;
		while (received[i][n])
		{
			if (received[i][n] == '\'')
			{
				n++;
				while (received[i][n] != '\'' && received[i][n])
					n++;
				n++;
			}
			// if (received[i][n] == '$' && received[i][n + 1] == '$')
			// 	return (0);
			if (received[i][n] == '$' && received[i][n + 1] != '?')
				n++;
			else if (received[i][n] == '$' && (received[i][n + 1] != '_' || received[i][n + 1] != '?'))
				return (0);
			else if (received[i][n] == '$' && ft_isalpha(received[i][n + 1]) != 1)
				return (0);
			n++;
			while ((received[i][n] != '$' || received[i][n] != '\'') && received[i][n])
				n++;
		}
		i++;
	}
	return (1);
}

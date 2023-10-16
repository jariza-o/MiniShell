/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:31:38 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/16 19:54:49 by jariza-o         ###   ########.fr       */
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
				while (received[i][n] != '\'')
					n++;
				n++;
			}
			if (received[i][n] == '$' && received[i][n + 1] == '$')
				return (0);
			if (received[i][n] == '$' && (received[i][n + 1] < 65 || received[i][n + 1] > 90) && (received[i][n + 1] < 97 || received[i][n + 1] > 122) && received[i][n + 1] != '_')
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:39:48 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/30 17:01:51 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_is_no_quote(char *argv);

void	ft_tokenizer(void)
{
	int	i;

	i = 0;
	while (g_data.recieved[i])
	{
		if (ft_is_no_quote(g_data.recieved[i]))
		{
			if (ft_is_builtin(g_data.recieved[i], i))
				// NOSE
			else if ()
		}
	}
}

static int	ft_is_no_quote(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '\'' || argv[i] == '\"')
			return (0);
		i++;
	}
	return (1);
}
static int	ft_is_builtin(char *argv, int i)
{
	if (i == 0)
	{
		
	}
}

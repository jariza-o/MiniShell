/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:39:48 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/30 20:46:56 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_is_no_quote(char *argv);

void	ft_tokenizer(void)
{
	int	i;

	i = 0;
	while (g_data.tokens->str)
	{
		if (ft_is_no_quote(g_data.tokens->str))
		{
			if (ft_is_builtin(g_data.tokens))
				g_data.tokens->type = BUILTINS;
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
static int	ft_is_builtin(t_token *token)
{
	if (!token->prev)
	{
		if (ft_check_builtin(token))
			return (1);
	}
	else if (token->prev->type == PIPE)
	{
		if (ft_check_builtin(token))
			return (1);
	}
	return (0);
}

static int	ft_check_builtin(t_token *token)
{
	if (!ft_strcmp(token->str, "echo") || !ft_strcmp(token->str, "cd") || \
	!ft_strcmp(token->str, "pwd") || !ft_strcmp(token->str, "export") || \
	!ft_strcmp(token->str, "unset") || !ft_strcmp(token->str, "env") || \
	!ft_strcmp(token->str, "exit"))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:16:25 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/14 20:09:49 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_restore_fds(int stdout, int stdin)
{
	dup2(stdout, 1);
	dup2(stdin, 0);
	close(stdout);
	close(stdin);
}

int	ft_is_comma(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->type == DOUBLE_QUOTE || tokens->type == SINGLE_QUOTE)
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

char	*ft_nl(char *line)
{
	char	*pos;

	pos = ft_strchr(line, '\n');
	if (pos != NULL)
		*pos = '\0';
	return (line);
}

char	*ft_eof(char *limiter)
{
	char	*test;

	if (ft_strcmp(limiter, "EOF") == 0)
		test = ft_strdup("\n");
	else
		test = limiter;
	return (test);
}

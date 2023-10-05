/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:18:10 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/05 23:46:05 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/* Revisar tema de los ++ porque ppor la norminette lo he reducido mucho */

static int ft_count_quotes(t_token *tokens);

void	ft_expand_quotes(t_token *tokens)
{
	char	*str;
	int		i;
	int		n;

	i = -1;
	n = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(tokens->str) - ft_count_quotes(tokens)));
	while (tokens->str[++i])
	{
		if (tokens->str[i] == '\'')
		{
			while (tokens->str[++i] != '\'')
				str[n++] = tokens->str[i];
		}
		else if (tokens->str[i] == '\"')
		{
			while (tokens->str[++i] != '\"')
				str[n++] = tokens->str[i];
		}
		else
			str[n++] = tokens->str[i];
	}
	tokens->str = str;
	free (str);
}

static int ft_count_quotes(t_token *tokens)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (tokens->str[++i])
	{
		if (tokens->str[i] == '\'')
		{
			len++;
			i++;
			while (tokens->str[i] != '\'')
				i++;
			len++;
		}
		else if (tokens->str[i] == '\"')
		{
			len++;
			i++;
			while (tokens->str[i] != '\"')
				i++;
			len++;
		}
	}
	return (len);
}

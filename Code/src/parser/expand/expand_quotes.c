/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:18:10 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/18 18:19:15 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/* Revisar tema de los ++ porque ppor la norminette lo he reducido mucho */

static int	ft_count_quotes(char *str);

void	ft_expand_quotes(t_token *tokens)
{
	char	*str;
	int		i;
	int		n;

	i = -1;
	n = 0;
	// ft_printf("EXPAND QUOTES: %s\n", tokens->str);
	str = (char *)ft_calloc((ft_strlen(tokens->str) - \
	ft_count_quotes(tokens->str)), sizeof(char));
	while (tokens->str[++i])
	{
		if (tokens->str[i] == '\'')
		{
			i++;
			while (tokens->str[i] != '\'')
			{
				str[n++] = tokens->str[i];
				i++;
			}
		}
		else if (tokens->str[i] == '\"')
		{
			i++;
			while (tokens->str[i] != '\"')
			{
				str[n++] = tokens->str[i];
				i++;
			}
		}
		else
			str[n++] = tokens->str[i];
	}
	tokens->str = str;
	// ft_printf("EXPAND QUOTES: %s\n", tokens->str);
	free (str);
}

static int	ft_count_quotes(char *str)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '\'')
		{
			len++;
			i++;
			while (str[i] != '\'')
				i++;
			len++;
		}
		else if (str[i] == '\"')
		{
			len++;
			i++;
			while (str[i] != '\"')
				i++;
			len++;
		}
	}
	return (len);
}

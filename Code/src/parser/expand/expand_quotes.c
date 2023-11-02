/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:18:10 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/02 12:56:48 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_count_quotes(char *str);
static void	ft_all_null(char *str);

void	ft_expand_quotes(char *quote)
{
	char	*str;
	int		i;
	int		n;

	i = -1;
	n = 0;
	str = ft_strdup(quote);
	ft_all_null(quote);
	free (quote);
	quote = (char *)ft_calloc((ft_strlen(str) - \
	ft_count_quotes(str)), sizeof(char));
	while (str[++i])
	{
		if (str[i] == '\'')
			while (str[++i] != '\'')
				quote[n++] = str[i];
		else if (str[i] == '\"')
			while (str[++i] != '\"')
				quote[n++] = str[i];
		else if (str[i])
			quote[n++] = str[i];
	}
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

static void	ft_all_null(char *str) //Comprobar guarrada
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
}

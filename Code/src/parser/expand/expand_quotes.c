/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:18:10 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/01 16:23:38 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/* Revisar tema de los ++ porque ppor la norminette lo he reducido mucho */

static int	ft_count_quotes(char *str);

void	ft_expand_quotes(char *quote)
{
	char	*str;
	int		i;
	int		n;

	i = -1;
	n = 0;
	str = ft_strdup(quote);
	free (quote);
	quote = (char *)ft_calloc((ft_strlen(quote) - \
	ft_count_quotes(quote)), sizeof(char));
	while (str[++i])
	{
		if (str[i] == '\'')
			while (str[++i] != '\'')
				quote[n++] = str[i];
		else if (str[i] == '\"')
			while (str[++i] != '\"')
				quote[n++] = str[i];
		else
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


// BACKUP
// char	*ft_expand_quotes(char *quote)
// {
// 	char	*str;
// 	int		i;
// 	int		n;

// 	i = -1;
// 	n = 0;
// 	str = (char *)ft_calloc((ft_strlen(quote) - \
// 	ft_count_quotes(quote)), sizeof(char));
// 	while (quote[++i])
// 	{
// 		if (quote[i] == '\'')
// 		{
// 			i++;
// 			while (quote[i] != '\'')
// 			{
// 				str[n++] = quote[i];
// 				i++;
// 			}
// 		}
// 		else if (quote[i] == '\"')
// 		{
// 			i++;
// 			while (quote[i] != '\"')
// 			{
// 				str[n++] = quote[i];
// 				i++;
// 			}
// 		}
// 		else
// 			str[n++] = quote[i];
// 	}
// 	free (quote);
// 	return (str);
// }


// char	*ft_expand_quotes(char *quote)
// {
// 	char	*str;
// 	int		i;
// 	int		n;

// 	i = -1;
// 	n = 0;
// 	str = (char *)ft_calloc((ft_strlen(quote) - \
// 	ft_count_quotes(quote)), sizeof(char));
// 	while (quote[++i])
// 	{
// 		if (quote[i] == '\'')
// 			while (quote[++i] != '\'')
// 				str[n++] = quote[i];
// 		else if (quote[i] == '\"')
// 			while (quote[++i] != '\"')
// 				str[n++] = quote[i];
// 		else
// 			str[n++] = quote[i];
// 	}
// 	free (quote); // AÑADIDO NUEVO
// 	return (str);
// }

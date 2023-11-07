/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:18:10 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/07 18:14:38 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_count_quotes(char *str);
// static void	ft_all_null(char *str);

void	ft_expand_quotes(char *quote) //POSIBLE LEAKS
{
	char	*str;
	int		i;
	int		n;

	i = -1;
	n = 0;
	str = ft_strdup(quote);
	// ft_all_null(quote); //me da doble free en valgrind pero si lo quito no me expande
	free (quote);
	quote = (char *)ft_calloc(ft_strlen(str), sizeof(char)); // Con la version de abajo da problema con casos super ramdoms
	// quote = (char *)ft_calloc((ft_strlen(str) - \
	// ft_count_quotes(str)), sizeof(char));
	ft_printf("STR: %s || Nº Quotes: %d\n", str, ft_count_quotes(str));
	if (!quote)
		return ;
	while (str && str[++i])
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
	// ft_printf("RESULT: %s\n\n", quote);
	free (str);
}

static int	ft_count_quotes(char *str)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (str && str[++i])
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

// static void	ft_all_null(char *str) //Comprobar guarrada
// {
// 	int	i;

// 	i = 0;
// 	while (str && str[i])
// 	{
// 		str[i] = '\0';
// 		i++;
// 	}
// }

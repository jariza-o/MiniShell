/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:03:57 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/05 12:15:59 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	ft_take_word(char *str, int *i, int *aux, size_t *len);
static void	ft_close_quotes(char *str, int *i, size_t *len);
static char	*ft_complete_word(char *s, int *i, int *aux, size_t len);

char	**ft_mini_split(char *s)
{
	char	**str;
	int		i;
	int		j;
	int		aux;
	size_t	len;

	str = (char **)ft_calloc((ft_words(s) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s && s[i] == ' ')
		i++;
	while (s && s[i])
	{
		aux = 0;
		len = 0;
		ft_take_word(s, &i, &aux, &len);
		str[j] = ft_complete_word(s, &i, &aux, len);
		while (s[i] == ' ')
			i++;
		j++;
	}
	return (str);
}

static void	ft_take_word(char *str, int *i, int *aux, size_t *len)
{
	*aux = *i;
	while (!ft_strchr(" |<>", str[*i]) && str[*i])
	{
		if (str[*i] == '\'' || str[*i] == '\"')
			ft_close_quotes(str, i, len);
		(*i)++;
		(*len)++;
	}
	if ((str[*i] == '<' || str[*i] == '>') && str[*i + 1] == str[*i])
	{
		(*i) += 2;
		(*len) += 2;
	}
	else if (str[*i] == '<' || str[*i] == '>' || str[*i] == '|')
	{
		(*i)++;
		(*len)++;
	}
}

static void	ft_close_quotes(char *str, int *i, size_t *len)
{
	char	quote;

	quote = str[*i];
	(*i)++;
	(*len)++;
	while (str[*i] != quote && str[*i])
	{
		(*i)++;
		(*len)++;
	}
}

static char	*ft_complete_word(char *s, int *i, int *aux, size_t len)
{
	char	*str;
	int		n;

	str = (char *)ft_calloc((len + 1), sizeof(char));
	n = 0;
	while (*aux != *i)
	{
		str[n] = s[*aux];
		n++;
		(*aux)++;
	}
	return (str);
}

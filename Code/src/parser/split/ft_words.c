/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:30:32 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/31 19:02:26 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	ft_close_quotes_words(char *str, int *i, size_t *len);
static void	ft_special_character(char *str, int *i, size_t *len);

size_t	ft_words(char *s)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			ft_close_quotes_words(s, &i, &len);
		else if (ft_strchr(" |<>", s[i]))
			ft_special_character(s, &i, &len);
		else
			i++;
	}
	if (!s[i] && !ft_strchr(" |<>", s[i - 1]))
		len++;
	return (len);
}

static void	ft_close_quotes_words(char *str, int *i, size_t *len)
{
	int	j;

	j = *i;
	(*i)++;
	while (str[*i] != str[j] && str[*i])
		(*i)++;
	(*i)++;
	if (ft_strchr(" |<>", str[*i]))
	{
		(*len)++;
		while (str[*i] == ' ' && str[*i])
			(*i)++;
	}
}

static void	ft_special_character(char *str, int *i, size_t *len)
{
	if ((!ft_strchr(" |<>", str[*i - 1])) && str[*i] != ' ')
		(*len)++;
	if ((str[*i] == '<' && str[*i + 1] == '<')
		|| (str[*i + 1] == '>' && str[*i + 1] == '>'))
		(*i) += 2;
	else
		(*i)++;
	(*len)++;
	while (str[*i] == ' ' && str[*i])
		(*i)++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:14:32 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/29 12:31:40 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	ft_mini_wordcounter(char *s, char c);
static int		ft_split_close_quote(char *argv, int i);

char	**ft_mini_split(char *s)
{
	char	**str;
	size_t	len;
	size_t	n;

	str = malloc(sizeof(char *) * (ft_mini_wordcounter(s, ' ') + 1));
	if (!str)
		return (0);
	n = 0;
	while (*s)
	{
		if (*s != ' ')
		{
			len = 0;
			while (*s && *s != ' ')
			{
				if (*s == '\'')
				{
					++len;
					++s;
					while (*s != '\'')
					{
						++len;
						++s;
					}
					++len;
					++s;
				}
				else if (*s == '"')
				{
					++len;
					++s;
					while (*s != '"')
					{
						++len;
						++s;
					}
					++len;
					++s;
				}
				else
				{
					++len;
					++s;
				}
			}
			str[n++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	str[n] = 0;
	return (str);
}

static size_t	ft_mini_wordcounter(char *s, char c)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
			i = ft_split_close_quote(s, i);
		else if (s[i] == '"')
			i = ft_split_close_quote(s, i);
		if (s[i++] != c && (s[i] == c || s[i] == '\0'))
			x++;
	}
	return (x);
}

static int	ft_split_close_quote(char *argv, int i)
{
	if (argv[i] == '\'')
	{
		i++;
		while (argv[i] != '\'' && argv[i])
			i++;
		i++;
		return (i);
	}
	else if (argv[i] == '"')
	{
		i++;
		while (argv[i] != '"' && argv[i])
			i++;
		i++;
		return (i);
	}
	return (i);
}

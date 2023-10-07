/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:14:32 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/07 18:05:57 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	ft_mini_wordcounter(char *s);
static int		ft_split_close_quote(char *argv, int i);

char	**ft_mini_split(char *s)
{
	char	**str;
	size_t	len;
	size_t	i;
	size_t	ii;
	size_t	n;
	size_t	j;

	str = (char **)malloc(sizeof(char *) * (ft_mini_wordcounter(s) + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		ii = i;
		if (s[i] != '<' && s[i] != '>' && s[i] != '|')
		{
			while (s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != '|' && s[i])
			{
				len++;
				++i;
			}
		}
		else
		{
			if (s[i] == '|' && s[i + 1] == '|')
			{
				ft_print_errors(PIPES);
				return (NULL);
			}
			if (s[i] == '<' && s[i + 1] == '<')
			{
				len++;
				++i;
			}
			else if (s[i] == '>' && s[i + 1] == '>')
			{
				len++;
				++i;
			}
			if (s[i] == '<' || s[i] == '>' || s[i] == '|')
			{
				len++;
				i++;
			}
		}
		str[j] = (char *)malloc(sizeof(char) * (len + 1));
		n = 0;
		while (s[ii] != s[i])
		{
			str[j][n] = s[ii];
			++n;
			++ii;
		}
		str[j][n] = '\0';
		while (s[i] == ' ')
			++i;
		j++;
	}
	return (str);
}

static size_t	ft_mini_wordcounter(char *s)
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
		if (s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != '|')
			i++;
		else
		{
			if ((s[i] == '>' || s[i] == '>') && ((s[i] == '>' && s[i + 1] == '>') || (s[i] == '>' && s[i + 1] == '>')))
			{
				x += 2;
				i += 2;
			}
			else if (s[i] == '>' || s[i] == '>' || s[i] == '|')
			{
				x += 2;
				i++;
			}
			if (!s[i])
				return (x);
			if (s[i] == ' ')
			{
				x++;
				i++;
			}
			if (s[i] == ' ')
				while (s[i] == ' ')
					i++;
		}
	}
	x++;
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

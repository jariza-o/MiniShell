/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:14:32 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/10 19:56:14 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	ft_mini_wordcounter(char *s);
static int		ft_split_close_quote(char *argv, int i);
static int		ft_len_close_quote(char *argv, int i, int len);

// char	**ft_mini_split(char *s)
// {
// 	char	**str;
// 	size_t	len;
// 	size_t	i;
// 	size_t	ii;
// 	size_t	n;
// 	size_t	j;

// 	str = (char **)ft_calloc((ft_mini_wordcounter(s) + 1), sizeof(char *));
// 	printf("Wordcounter: %ld\n", ft_mini_wordcounter(s));
// 	if (!str)
// 		return (0);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		len = 0;
// 		ii = i;
// 		if (s[i] != '<' && s[i] != '>' && s[i] != '|')
// 		{
// 			while ((s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != '|') && (s[i] != '\'' && s[i] != '\"') && s[i])
// 			{
// 				len++;
// 				++i;
// 			}
// 			if (s[i] == '\'' || s[i] == '\"')
// 			{
// 				i = ft_split_close_quote(s, i);
// 				len = ft_len_close_quote(s, i, len);
// 			}
// 		}
// 		else
// 		{
// 			if (s[i  + 1] != '\0' && ((s[i] == '<' && s[i + 1] == '<') || (s[i] == '>' && s[i + 1] == '>')))
// 			{
// 				len += 2;
// 				i += 2;
// 			}
// 			else
// 			{
// 				len++;
// 				i++;
// 			}
// 		}
// 		str[j] = (char *)ft_calloc((len + 1), sizeof(char));
// 		while (ii != i)
// 		{
// 			str[j][n] = s[ii];
// 			++n;
// 			++ii;
// 		}
// 		if (s[i] == ' ' || s[i] == '<' || s[i] == '>' || s[i] == '|')
// 		{
// 			j++;
// 			n = 0;
// 		}
// 		while (s[i] == ' ' && s[i])
// 			i++;
// 	}
// 	return (str);
// }

// static size_t	ft_mini_wordcounter(char *s)
// {
// 	size_t	i;
// 	size_t	x;

// 	i = 0;
// 	x = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == '\'')
// 			i = ft_split_close_quote(s, i);
// 		else if (s[i] == '"')
// 			i = ft_split_close_quote(s, i);
// 		if (s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != '|')
// 			i++;
// 		else
// 		{
// 			if (s[i + 1] && (s[i] == '>' || s[i] == '<') && ((s[i] == '>' && s[i + 1] == '>') || (s[i] == '<' && s[i + 1] == '<')))
// 			{
// 				x += 2;
// 				i += 2;
// 			}
// 			else if (s[i] == '>' || s[i] == '<' || s[i] == '|')
// 			{
// 				x++;
// 				i++;
// 			}
// 			if (!s[i])
// 				return (x);
// 			// if (s[i] == ' ')
// 			// {
// 			// 	x++;
// 			// 	i++;
// 			// }
// 			// if (s[i] == ' ')
// 			while (s[i] == ' ')
// 				i++;
// 			if (s[i])
// 				x++;
// 		}
// 	}
// 	x++;
// 	return (x);
// }

char	**ft_mini_split(char *s)
{
    char	**str;
    size_t	len;
    size_t	i;
    size_t	ii;
    size_t	n;
    size_t	j;

    str = (char **)ft_calloc((ft_mini_wordcounter(s) + 1), sizeof(char *));
	printf("Wordcounter: %ld\n", ft_mini_wordcounter(s));
    if (!str)
        return (0);
    i = 0;
    j = 0;
    while (s[i])
    {
        len = 0;
        ii = i;
        n = 0;
        if (s[i] != '<' && s[i] != '>' && s[i] != '|')
        {
            while ((s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != '|') && (s[i] != '\'' && s[i] != '\"') && s[i])
            {
                len++;
                i++;
            }
            if (s[i] == '\'' || s[i] == '\"')
            {
                i = ft_split_close_quote(s, i);
                len = ft_len_close_quote(s, i, len);
            }
        }
        else
        {
            if (s[i  + 1] != '\0' && ((s[i] == '<' && s[i + 1] == '<') || (s[i] == '>' && s[i + 1] == '>')))
            {
                len += 2;
                i += 2;
            }
            else
            {
                len++;
                i++;
            }
        }
        str[j] = (char *)ft_calloc((len + 1), sizeof(char));
        if (!str[j])
            return (0);
        while (ii != i)
        {
            str[j][n] = s[ii];
            n++;
            ii++;
        }
        if (s[i] == ' ' || s[i] == '<' || s[i] == '>' || s[i] == '|')
        {
            j++;
            n = 0;
        }
        while (s[i] == ' ' && s[i])
            i++;
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
        if (s[i] == '\'' || s[i] == '\"')
            i = ft_split_close_quote(s, i);
        else if (s[i] == '<' || s[i] == '>' || s[i] == '|')
        {
            if (s[i + 1] && s[i + 1] == s[i])
            {
                x += 2;
                i += 2;
            }
            else
            {
                x++;
                i++;
            }
        }
        else if (s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != '|')
        {
            x++;
            while (s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != '|' && s[i] != '\0')
            {
                if (s[i] == '\'' || s[i] == '\"')
                    i = ft_split_close_quote(s, i);
                i++;
            }
        }
        else
            i++;
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
		if (argv[i])
			i++;
		return (i);
	}
	else if (argv[i] == '"')
	{
		i++;
		while (argv[i] != '"' && argv[i])
			i++;
		if (argv[i])
			i++;
		return (i);
	}
	return (i);
}

static int	ft_len_close_quote(char *argv, int i, int len)
{
	if (argv[i] == '\'')
	{
		i++;
		len++;
		while (argv[i] != '\'' && argv[i])
		{
			i++;
			len++;
		}
		if (argv[i])
			i++;
	}
	else if (argv[i] == '"')
	{
		i++;
		len++;
		while (argv[i] != '"' && argv[i])
		{
			i++;
			len++;
		}
		if (argv[i])
			i++;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:14:32 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/27 13:12:31 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	ft_mini_wordcounter(char *s);
static int		is_special_char(char c);
static int		ft_split_close_quote(char *argv, int i);
// static int		ft_len_close_quote(char *argv, int i, int len);

char	**ft_mini_split(char *s)
{
	char	**str;
	size_t	len;
	size_t	i;
	size_t	ii;
	size_t	n;
	size_t	j;
	int		is_quote_encountred;

	str = (char **)ft_calloc((ft_mini_wordcounter(s) + 1), sizeof(char *));
	ft_printf("WORDCOUNTER: %d\n", ft_mini_wordcounter(s) + 1);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		ii = i;
		n = 0;
		is_quote_encountred = 0;
		if (s[i] != '<' && s[i] != '>' && s[i] != '|')
		{
			while (s[i] && (!is_special_char(s[i]) || is_quote_encountred))
			{
				if (s[i] == '\'' || s[i] == '\"')
				{
					if (is_quote_encountred == 0)
						is_quote_encountred = 1;
					else
						is_quote_encountred = 0;
				}
				len++;
				i++;
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

static int	is_special_char(char c)
{
	return (c == ' ' || c == '<' || c == '>' || c == '|');
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
				else
					i++;
			}
		}
		else
			i++;
	}
	if (s[i - 1] != '<' && s[i - 1] != '>' && s[i - 1] != '|' && s[i - 1] != ' ')
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
	else if (argv[i] == '\"')
	{
		i++;
		while (argv[i] != '\"' && argv[i])
			i++;
		if (argv[i])
			i++;
		return (i);
	}
	return (i);
}








// char	**ft_mini_split(char *s)
// {
// 	char	**str;
// 	size_t	len;
// 	size_t	i;
// 	size_t	ii;
// 	size_t	n;
// 	size_t	j;
// 	int		is_quote_encountred;

// 	str = (char **)ft_calloc((ft_mini_wordcounter(s) + 1), sizeof(char *));
// 	if (!str)
// 		return (0);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		len = 0;
// 		ii = i;
// 		n = 0;
// 		is_quote_encountred = 0;
// 		if (s[i] != '<' && s[i] != '>' && s[i] != '|')
// 		{
// 			while (s[i] && (!is_special_char(s[i]) || is_quote_encountred))
// 			{
// 				if (s[i] == '\'' || s[i] == '\"')
// 				{
// 					if (is_quote_encountred == 0)
// 						is_quote_encountred = 1;
// 					else
// 						is_quote_encountred = 0;
// 				}
// 				len++;
// 				i++;
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
// 		if (!str[j])
// 			return (0);
// 		while (ii != i)
// 		{
// 			str[j][n] = s[ii];
// 			n++;
// 			ii++;
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

// static int	is_special_char(char c)
// {
// 	return (c == ' ' || c == '<' || c == '>' || c == '|');
// }

// static size_t	ft_mini_wordcounter(char *s)
// {
// 	size_t	i;
// 	size_t	x;

// 	i = 0;
// 	x = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == '\'' || s[i] == '\"')
// 			i = ft_split_close_quote(s, i);
// 		else if (s[i] == '<' || s[i] == '>' || s[i] == '|')
// 		{
// 			if (s[i + 1] && s[i + 1] == s[i])
// 			{
// 				x += 2;
// 				i += 2;
// 			}
// 			else
// 			{
// 				x++;
// 				i++;
// 			}
// 		}
// 		else if (s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != '|')
// 		{
// 			x++;
// 			while (s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != '|' && s[i] != '\0')
// 			{
// 				if (s[i] == '\'' || s[i] == '\"')
// 					i = ft_split_close_quote(s, i);
// 				else
// 					i++;
// 			}
// 		}
// 		else
// 			i++;
// 	}
// 	if (s[i - 1] != '<' && s[i - 1] != '>' && s[i - 1] != '|' && s[i - 1] != ' ')
// 		x++;
// 	return (x);
// }
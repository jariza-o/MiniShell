/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:14:32 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/09 23:37:34 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	counter;

	counter = 0;
	while (n != 0 && counter++ <= (n - 1))
	{
		*(char *)s = '\0';
		s++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

static size_t	ft_mini_wordcounter(char *s);
static int		ft_split_close_quote(char *argv, int i);
static int		ft_len_close_quote(char *argv, int i, int len);

char	**ft_mini_split(char *s)
{
	char	**str;
	size_t	len;
	size_t	i;
	size_t	ii;
	size_t	n;
	size_t	j;

	// COMPROBAR SI ESTA VACIO
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
		if (s[i] != '<' && s[i] != '>' && s[i] != '|')
		{
			while ((s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != '|') && (s[i] != '\'' && s[i] != '\"') && s[i])
			{
				len++;
				++i;
			}
			if (s[i] == '\'' || s[i] == '\"')
			{
				i = ft_split_close_quote(s, i);
				len = ft_len_close_quote(s, i, len);
			}
		}
		else
		{
			if ((s[i] == '<' && s[i + 1] == '<') || (s[i] == '>' && s[i + 1] == '>'))
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
		n = 0;
		//ft_printf("ii: %d i: %d\n", ii, i);
		while (s[ii] != s[i])
		{
			str[j][n] = s[ii];
			++n;
			++ii;
		}
		if (s[i] == ' ' || s[i] == '<' || s[i] == '>' || s[i] == '|')
			j++;
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
		if (s[i] == '\'')
			i = ft_split_close_quote(s, i);
		else if (s[i] == '"')
			i = ft_split_close_quote(s, i);
		if (s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != '|')
			i++;
		else
		{
			if ((s[i] == '>' || s[i] == '<') && ((s[i] == '>' && s[i + 1] == '>') || (s[i] == '<' && s[i + 1] == '<')))
			{
				x += 2;
				i += 2;
			}
			else if (s[i] == '>' || s[i] == '<' || s[i] == '|')
			{
				x++;
				i++;
			}
			if (!s[i])
				return (x);
			// if (s[i] == ' ')
			// {
			// 	x++;
			// 	i++;
			// }
			// if (s[i] == ' ')
			while (s[i] == ' ')
				i++;
			if (s[i])
			x++;
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
int	main(void)
{
	char **str = ft_mini_split("echo >>>>>>><<<<>>>||||||||");
	for(int i = 0; str[i]; i++){
		printf("str[%d]: %s\n", i, str[i]);
	}
	return (0);
}
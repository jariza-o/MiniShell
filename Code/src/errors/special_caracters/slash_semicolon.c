/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slash_semicolon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:59:36 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/28 14:11:35 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_close_quote(char **argv, int i, int n);

int	ft_check_slash(char **argv)
{
	int	i;
	int	n;

	i = 0;
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if (argv[i][n] == '\'')
				n = ft_close_quote(argv, i, n);
			else if (argv[i][n] == '"')
				n = ft_close_quote(argv, i, n);
			if (argv[i][n] == '\\')
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}

int	ft_check_semicolon(char **argv)
{
	int	i;
	int	n;

	i = 0;
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if (argv[i][n] == '\'')
				n = ft_close_quote(argv, i, n);
			else if (argv[i][n] == '"')
				n = ft_close_quote(argv, i, n);
			if (argv[i][n] == ';')
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}

static int	ft_close_quote(char **argv, int i, int n)
{
	if (argv[i][n] == '\'')
	{
		n++;
		while (argv[i][n] != '\'')
			n++;
		n++;
		return (n);
	}
	else if (argv[i][n] == '"')
	{
		n++;
		while (argv[i][n] != '"')
			n++;
		n++;
		return (n);
	}
	return (n); // VER BIEN ESTE RETURN
}
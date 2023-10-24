/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:13:57 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/24 19:17:37 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// int	ft_check_quotes(char **argv)
// {
// 	(void)argv;
// 	// char	**aux;
// 	// int		quotes;

// 	// aux = argv;
// 	// while (*argv)
// 	// {
// 	// 	quotes = 0;
// 	// 	while (**argv)
// 	// 	{
// 	// 		if (**argv == '\"' || **argv == '\'')
// 	// 		{
// 	// 			if (!quotes)
// 	// 				quotes = **argv;
// 	// 			else if (**argv == quotes)
// 	// 				quotes = 0;
// 	// 		}
// 	// 		(*argv)++;
// 	// 	}
// 	// 	if (quotes)
// 	// 		return (argv = aux, 0);
// 	// 	argv++;
// 	// }
// 	// return (argv = aux, 1);
// 	return (1);
// }

// int	ft_check_quotes(char **argv)
// {
// 	char	c;
// 	int		i;
// 	int		n;
// 	int		q;

// 	q = 0;
// 	i = -1;
// 	while (argv[++i])
// 	{
// 		n = -1;
// 		while (argv[i][++n])
// 		{
// 			if (argv[i][n] == '\"' || argv[i][n] == '\'')
// 			{
// 				q++;
// 				c = argv[i][n++];
// 				while (argv[i][n] != c && argv[i][n])
// 					n++;
// 				q++;
// 			}
// 		}
// 	}
// 	if (q / 2 != 0)
// 		return (0);
// 	return (1);
// }

int	ft_check_quotes(char **argv)
{
	int	i;
	int	n;

	i = -1;
	while (argv[++i])
	{
		n = -1;
		while (argv[i][++n])
		{
			if (argv[i][n] == '\"')
			{
				n++;
				while (argv[i][n] != '\"' && argv[i][n])
					n++;
				if (argv[i][n] != '\"')
					return (0);
			}
			else if (argv[i][n] == '\'')
			{
				n++;
				while (argv[i][n] != '\'' && argv[i][n])
					n++;
				if (argv[i][n] != '\'')
					return (0);
			}
		}
	}
	return (1);
}

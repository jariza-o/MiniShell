/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:54:16 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/01 16:18:30 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// static void ft_del_single_quote(t_token *tokens);
// static char	*ft_expand_strdup(char *s1);

void	ft_expand_data(void)
{
	t_token	*aux;
	int		i;

	aux = g_data.tokens;
	while (g_data.tokens)
	{
		i = -1;
		while (g_data.tokens->str[++i])
		{
			if (g_data.tokens->str[i] == '\'')
			{
				while (g_data.tokens->str[++i] != '\'')
					;
				i++;
			}
			if (g_data.tokens->str[i] == '$')
			{
				ft_expand_env(g_data.tokens);
				i = -1;
			}
		}
		ft_expand_quotes(g_data.tokens->str);
		g_data.tokens = g_data.tokens->next;
	}
	g_data.tokens = aux;
}

// static char	*ft_expand_strdup(char *s1)
// {
// 	char	*ss1;
// 	char	*d;
// 	size_t	c;

// 	ss1 = (char *)s1;
// 	d = (char *)malloc((ft_strlen(ss1) + 1));
// 	if (d == NULL)
// 		return (NULL);
// 	c = 0;
// 	while (ss1[c] != '\0')
// 	{
// 		d[c] = ss1[c];
// 		c++;
// 	}
// 	d[c] = '\0';
// 	free (ss1);
// 	return (d);
// }

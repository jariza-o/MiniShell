/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:12:04 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/12 15:10:16 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_strlen_tokens(void);

void	ft_tokens_to_str(void)
{
	int		i;
	int		n;
	char	*str;
	t_token	*aux;

	n = 0;
	aux = g_data.tokens;
	str = (char *)ft_calloc(ft_strlen_tokens() + 1, sizeof(char *));
	while (g_data.tokens)
	{
		i = 0;
		while (g_data.tokens->str[i])
		{
			str[n] = g_data.tokens->str[i];
			n++;
			i++;
		}
		g_data.tokens = g_data.tokens->next;
		if (g_data.tokens)
		{
			str[n] = ' ';
			n++;
		}
	}
	g_data.tokens = aux;
	//g_data.line = str; // TENGO QUE LIBERAR MEMORIA O VOLVER A RESERVAR
}

static int	ft_strlen_tokens(void)
{
	int		len;
	t_token	*aux;

	len = 0;
	aux = g_data.tokens;
	while (g_data.tokens)
	{
		len += ft_strlen(g_data.tokens->str);
		g_data.tokens = g_data.tokens->next;
		if (g_data.tokens)
			len++;
	}
	g_data.tokens = aux;
	return (len);
}

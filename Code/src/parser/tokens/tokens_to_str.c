/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:12:04 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/18 16:06:17 by jariza-o         ###   ########.fr       */
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

		ft_printf("str: %s\n", g_data.tokens->str); // DONDE SEA ESTA STR ADELANTADO
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
		ft_printf("mitad: %s str: %s\n", str, g_data.tokens->str);
		g_data.tokens = g_data.tokens->next;
		if (g_data.tokens)
		{
			str[n] = 32;
			n++;
		}
	}
	ft_printf("tokenTOstr: %s\n", str);
	g_data.tokens = aux;
	free(g_data.line);
	g_data.line = str; // TENGO QUE LIBERAR MEMORIA O VOLVER A RESERVAR
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

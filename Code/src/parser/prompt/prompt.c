/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:36 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/15 15:55:26 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_all_spaces(char *str);

int	ft_check_prompt(void)
{
	if (!g_data.prompt || g_data.prompt[0] == '\0')
		return (0);
	if (ft_all_spaces(g_data.prompt))
		return (0);
	return (1);
}

static int	ft_all_spaces(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] == ' ' && str[i])
		i++;
	if (str && !str[i])
		return (1);
	return (0);
}

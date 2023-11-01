/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:41:56 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/10/25 18:48:50 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_strcmpup(char *str1, char *str2)
{
	char	*tmp1;
	char	*tmp2;
	int		ret;

	tmp1 = ft_strup(ft_strdup(str1));
	tmp2 = ft_strup(ft_strdup(str2));
	ret = ft_strcmp(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	return (ret);
}

char	*ft_strup(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		str[cnt] = ft_toupper(str[cnt]);
		cnt++;
	}
	return (str);
}

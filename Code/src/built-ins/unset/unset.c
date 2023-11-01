/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:54 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/01 19:14:51 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	**ft_remove_env(int indx, char **tmp)
{
	int		cnt;
	int		cnt2;
	char	**new;

	cnt = 0;
	cnt2 = 0;
	while (g_data.env[cnt])
		cnt++;
	new = malloc(sizeof(char *) * (cnt + 1));
	cnt = 0;
	while (g_data.env[cnt])
	{
		if (cnt != indx)
		{
			new[cnt2] = ft_strdup(g_data.env[cnt]);
			cnt2++;
		}
		cnt++;
	}
	new[cnt2] = NULL;
	g_data.env = ft_clean_matrix(g_data.env);
	g_data.env = new;
	g_data.vars_mod = 1;
	tmp = ft_clean_matrix(tmp);
	return (NULL);
}

void	ft_unset(char **argv)
{
	int		cnt;
	char	**tmp;

	cnt = 0;
	if (!argv[1])
	{
		printf("[ERROR] Not enough arguments\n");
		return ;
	}
	while (g_data.env[cnt])
	{
		tmp = ft_split(g_data.env[cnt], '=');
		if (ft_strncmp(tmp[0], argv[1], ft_strlen(argv[1])) == 0)
			tmp = ft_remove_env(cnt, tmp);
		else
			tmp = ft_clean_matrix(tmp);
		cnt++;
	}
}

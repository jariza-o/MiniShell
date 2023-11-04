/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:36 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/04 17:50:28 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_all_spaces(char *str);
// static int	ft_same_spaces(char *str);
// static void	ft_remove_spaces(void);
// static int	ft_spaces_len(char *str);

int	ft_check_prompt(void)
{
	if (g_data.prompt[0] == '\0')
		return (0);
	if (ft_all_spaces(g_data.prompt))
		return (0);
	// if (ft_same_spaces(g_data.prompt))
	// 	ft_remove_spaces();
	return (1);
}

static int	ft_all_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' && str[i])
		i++;
	if (!str[i])
		return (1);
	return (0);
}

// static int	ft_same_spaces(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str[0] == ' ')
// 		return (1);
// 	while (str[i])
// 	{
// 		if (str[i++] == '\'')
// 			while (str[i] != '\'')
// 				i++;
// 		else if (str[i++] == '\"')
// 			while (str[i] != '\"')
// 				i++;
// 		if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// static void	ft_remove_spaces(void)
// {
// 	char	*str;
// 	int		i;
// 	int		n;
// 	int		control;

// 	str = (char *)ft_calloc(ft_spaces_len(g_data.prompt), sizeof(char));
// 	i = 0;
// 	n = 0;
// 	control = 0;
// 	while (g_data.prompt[i])
// 	{
// 		if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
// 			i++;
// 		else if (str[i] == ' ' && (str[i + 1] != ' '
// 				|| str[i + 1] != '\0') && !control)
// 			i++;
// 		else
// 		{
// 			control = 1;
// 			str[n++] = str[i++];
// 		}
// 	}
// 	free (g_data.prompt);
// 	g_data.prompt = ft_strdup(str);
// 	free (str);
// }

// static int	ft_spaces_len(char *str)
// {
// 	int	len;
// 	int	i;
// 	int	control;

// 	len = 0;
// 	i = 0;
// 	control = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == 32)
// 			len++;
// 		else if (str[i] != 32 && control == 0)
// 			control = 1;
// 		else if (str[i] != 32 && control == 1)
// 			len--;
// 		if (str[i++] == '\'')
// 			while (str[i] != '\'')
// 				i++;
// 		else if (str[i++] == '\"')
// 			while (str[i] != '\"')
// 				i++;
// 		i++;
// 	}
// 	ft_printf("LEN: %d\n", len);
// 	return (ft_strlen(str) - len);
// }

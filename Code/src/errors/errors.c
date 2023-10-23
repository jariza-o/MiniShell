/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:33:09 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/23 17:04:44 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_initial_errors(void)
{
	if (!ft_check_slash(g_data.recieved))
		return (ft_print_errors(SLASH), g_data.exit_status = 1, 0);
	if (!ft_check_semicolon(g_data.recieved))
		return (ft_print_errors(SEMICOLON), g_data.exit_status = 1, 0);
	if (!ft_check_env_errors(g_data.recieved))
		return (ft_print_errors(ENVS), g_data.exit_status = 1, 0);
	return (1);
}

int	ft_errors(void)
{
	if (!ft_check_redirections())
		return (ft_print_errors(REDIRECTIONS), g_data.exit_status = 1, 0);
	if (!ft_check_quotes(g_data.recieved))
		return (ft_print_errors(QUOTES), g_data.exit_status = 1, 0);
	return (1);
}

void	ft_print_errors(int error)
{
	if (error == QUOTES)
		printf("Error: There is an unclosed quotation mark\n");
	else if (error == SLASH || error == SEMICOLON)
		printf("Error: You have entered a wrong character\n");
	else if (error == CD)
		printf("Error: The cd command failed when trying to access HOME\n");
	else if (error == PWD)
		printf("Error: The pwd command failed\n");
	else if (error == REDIRECTIONS)
		printf("Error: Syntax error\n");
	else if (error == ENVS)
		printf("Error: Env syntax error\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:33:09 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/28 15:34:19 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_errors(void)
{
	if (!ft_check_quotes(g_data.recieved))
		ft_print_errors(QUOTES);
	if (!ft_check_slash(g_data.recieved))
		ft_print_errors(SLASH);
	if (!ft_check_semicolon(g_data.recieved))
		ft_print_errors(SEMICOLON);
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
}

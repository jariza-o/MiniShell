/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:55:00 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/17 16:24:42 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv) //, char **env)
{
	argc = 0;

	if (!ft_strcmp(argv[1], "echo"))
		ft_echo(argv);
	return (0);
}

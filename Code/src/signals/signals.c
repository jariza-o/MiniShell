/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:03:11 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/04 19:14:40 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ctr_c(int signal);
static void	ctr_d(int signal);

void	ft_signals(void)
{
	signal(SIGINT, ctr_c);
	signal(SIGTSTP, ctr_d);
	signal(SIGQUIT, SIG_IGN);
}

static void	ctr_c(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
}

static void	ctr_d(int signal)
{
	(void)signal;
	ft_exit();
}

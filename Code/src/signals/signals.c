/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:03:11 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/25 18:32:31 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Ctr+D y Ctr+\ listos.  Creo que no es necesario hacer SIGACTION y esas cosas.
Terminar función de Ctr+C que ahora mismo no la entiendo */

static void	ctr_c(int signal);
static void	ctr_d(int signal);

void	ft_signals(void)
{
	signal(SIGINT, ctr_c); // CTR-C
	signal(SIGTSTP, ctr_d); // CTR-D
	signal(SIGQUIT, SIG_IGN); // CTR-\: SIG_IGN significa que ignore la señal
}
static void	ctr_c(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	//rl_on_new_line();
}

static void	ctr_d(int signal)
{
	(void)signal;
	ft_exit();
}

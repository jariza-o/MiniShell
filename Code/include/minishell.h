/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:55:37 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/18 18:59:07 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "stdio.h" // printf
# include "unistd.h" // chdir, getcwd

/* ERROR DEFINES */
# define BUILTINS	1
# define CD			2
# define PWD		3

/* ERRORS */
/* Print error message */
void	ft_print_errors(int error);
/* Quotes (" and ') */
int		ft_check_quotes(char **argv);

/* Built-ins */
/* Echo */
void	ft_echo(char **argv);
/* Cd */
void	ft_cd(char **argv);

#endif
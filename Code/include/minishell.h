/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:55:37 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/19 19:40:13 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h> // printf
# include <unistd.h> // chdir, getcwd
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>

/* ERROR DEFINES */
# define BUILTINS	1
# define CD			2
# define PWD		3

typedef struct s_data
{
	char	**recieved;
	char 	**env;
}				t_data;

t_data g_data;

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
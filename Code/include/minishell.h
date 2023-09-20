/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:55:37 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/20 18:15:26 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h> // printf
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h> // chdir, getcwd
# include <unistd.h>

/* ERROR DEFINES */
# define BUILTINS 1
# define CD 2
# define PWD 3

typedef struct s_vars
{
	char	**names;
	char	**values;
}			t_vars;

typedef struct s_data
{
	char	**recieved;
	char	**env;
	char	*user;
	t_vars	*vars;
}			t_data;

t_data		g_data;

/* ERRORS */
/* Print error message */
void		ft_print_errors(int error);
/* Quotes (" and ') */
int			ft_check_quotes(char **argv);

/* Built-ins */
/* Echo */
void		ft_echo(char **argv);
/* Cd */
void		ft_cd(char *path);

void		ft_pwd(void);

void		ft_print_matrix(char **matrix);

void		ft_export(char **argv);

void		ft_unset(char **argv);

void		ft_exit(void);

void		ft_system_cmds(char **command);

#endif
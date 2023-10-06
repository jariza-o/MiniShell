/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:55:37 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/06 17:16:05 by jjaen-mo         ###   ########.fr       */
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
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h> // chdir, getcwd
# include <unistd.h>

/* ERRORS */
enum				e_errors
{
	QUOTES,
	SLASH,
	SEMICOLON,
	CD,
	PWD,
	// BUILTINS,
};

/* Token List */
enum				e_datatype
{
	VOID,
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	PIPE,
	BUILTINS,
	COMMAND,
	ENVI_VAR,
	IN_RED,
	OUT_RED,
	HERE_DOC_RED,
	APPEND_RED,
};

typedef struct s_pipe
{
	int				fds[2];
	pid_t			pid_c1;
	pid_t			pid_c2;
}					t_pipe;

typedef struct s_token
{
	char			*str;
	enum e_datatype	type;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_data
{
	char			**recieved;
	char			*line;
	t_token			*tokens;
	char			**env;
	char			*user;
	int				exit_status;
	pid_t			r_pid;
	t_pipe			spipe;
	int				vars_mod;
}					t_data;

t_data				g_data;

/* ERRORS */
void				ft_errors(void);
/* Print error message */
void				ft_print_errors(int error);
/* Quotes (" and ') */
int					ft_check_quotes(char **argv);
/* Semicolon */
int					ft_check_semicolon(char **argv);
/* Slashs */
int					ft_check_slash(char **argv);

void				ft_cmds(void);
/* Built-ins */
/* Echo */
void				ft_echo(char **argv);
/* Cd */
void				ft_cd(char *path);

void				ft_pwd(void);

void				ft_print_matrix(char **matrix);

void				ft_export(char **argv);

void				ft_unset(char **argv);

void				ft_exit(void);

void				ft_system_cmds(char **command);

void				ft_parser(void);

void				ft_signals(void);

char				**ft_clean_matrix(char **matrix);
void				ft_check_pipe(char *command);

char				*ft_get_cmdpath(char *cmd);

void				ft_pipe(char *line);
void				ft_signals(void);

char				**ft_mini_split(char *s);
char				**ft_split_redirections(void);
void				ft_tokenizer(void);

/* Tokens */
t_token				*ft_init_token(void);

#endif
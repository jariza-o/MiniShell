/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:45:26 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/10/18 21:02:39 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void ft_heredoc(char *limiter)
{
	char *line;
	int fd;

	fd = open("tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		line = readline("Input> ");
		if (!ft_strcmp(line, limiter))
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	g_data.spipe.fd_in = open("tmp", O_RDONLY);
	unlink("tmp");
}

static int	ft_double_redir_ck(char *line, char red)
{
	int	cnt;
	int	flag;

	flag = 0;
	cnt = 0;
	while (line[cnt])
	{
		if (line[cnt] == red && line[cnt + 1] == red)
			flag = 1;
		cnt++;
	}
	return (flag);
}

static char	*ft_in_redir(char *line)
{
	char **cmd;
	int cnt;

	cnt = 0;
	cmd = ft_split(line, '<');
	while (cmd[cnt])
		cnt++;
	if (cnt > 2)
	{
		printf("[ERROR] Infile redirection error\n");
		g_data.exit_status = 1;
		return(cmd[0]);
	}
	cmd[0] = ft_strtrim(cmd[0], " ");
	cmd[1] = ft_strtrim(cmd[1], " ");
	if(ft_double_redir_ck(line, '<'))
		ft_heredoc(cmd[1]);
	else
		g_data.spipe.fd_in = open(cmd[1], O_RDONLY);
	return (cmd[0]);
}

static char	*ft_out_redir(char *line)
{
	char	**cmd;
	int		cnt;

	cnt = 0;
	cmd = ft_split(line, '>');
	while (cmd[cnt])
		cnt++;
	if (cnt > 2)
	{
		printf("[ERROR] Outfile redirection error\n");
		g_data.exit_status = 1;
		exit(1);
	}
	else
	{
		cmd[0] = ft_strtrim(cmd[0], " ");
		cmd[1] = ft_strtrim(cmd[1], " ");
		if (ft_double_redir_ck(line, '>'))
			g_data.spipe.fd_out = open(cmd[1], O_CREAT | O_WRONLY | O_APPEND,
					0644);
		else
			g_data.spipe.fd_out = open(cmd[1], O_CREAT | O_WRONLY | O_TRUNC,
					0644);
	}
	return (cmd[0]);
}

char	*ft_check_redir(char *line)
{
	g_data.spipe.fd_in = 0;
	g_data.spipe.fd_out = 1;
	if (ft_strchr(line, '>'))
		line = ft_out_redir(line);
	if (ft_strchr(line, '<'))
		line = ft_in_redir(line);
	return (line);
}
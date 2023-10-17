/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:45:26 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/10/17 19:59:34 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char *ft_out_redir(char *line)
{
	char **cmd;
	int cnt;
	
	cnt = 0;
	cmd = ft_split(line, '>');
	while(cmd[cnt])
		cnt++;
	if(cnt > 2)
	{
		printf("[ERROR] Outfile redirection error\n");
		g_data.exit_status = 1;
		exit(1);
	}
	else
	{
		cmd[0] = ft_strtrim(cmd[0], " ");
		cmd[1] = ft_strtrim(cmd[1], " ");
		g_data.spipe.fd_out = open(cmd[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	return (cmd[0]);
}

char *ft_check_redir(char *line)
{
	g_data.spipe.fd_in = 0;
	g_data.spipe.fd_out = 1;
	if(ft_strchr(line, '>'))
		line = ft_out_redir(line);
	// else if(ft_strchr(line, '<'))
	// 	ft_in_redir();
	return (line);
}
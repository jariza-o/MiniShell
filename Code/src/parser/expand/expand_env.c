/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:06:03 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/05 23:49:12 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/* HACER CUANDO NO EXISTA VARIABLE $ENV */

static char	*ft_obtain_env(t_token *tokens, int i);
static char	*ft_obtain_env_content(char *env);
static char	*ft_change_env_str(t_token *tokens, char *content);

void	ft_expand_env(t_token *tokens)
{
	char	*env;
	char	*content;
	int		i;

	i = -1;
	while (tokens->str[++i])
	{	
		if (tokens->str[i] == '\'')
		{
			i++;
			while (tokens->str[i] != '\'')
				i++;
		}
		else if (tokens->str[i] == '$')
		{
			env = ft_obtain_env(tokens, i);
			break ;
		}
	}
	content = ft_obtain_env_content(env);
	tokens->str = ft_change_env_str(tokens, content);
	if (tokens->str[i])
		ft_expand_env(tokens);
	free(env);
	free(content);
}

static char	*ft_obtain_env(t_token *tokens, int i)
{
	int		n;
	int		len;
	char	*env;

	i += 1;
	n = i;
	len = 0;
	while (tokens->str[n] && (tokens->str[n] != ' ' && tokens->str[n] != '\"' && tokens->str[n] != '$'))
	{
		len++;
		n++;
	}
	env = (char *)malloc(sizeof(char) * len); //Haria falta el +1?
	if (!env)
		return (NULL);
	n = 0;
	while (tokens->str[i] && (tokens->str[i] != ' ' && tokens->str[i] != '\"' && tokens->str[i] != '$'))
	{
		env[n] = tokens->str[i];
		n++;
		i++;
	}
	return (env);
}

static char	*ft_obtain_env_content(char *env)
{
	int		i;
	int		n;
	int		j;
	char	*content;

	i = 0;
	while (g_data.env[i])
	{
		n = -1;
		while (g_data.env[i][++n] && env[n])
		{
			if (g_data.env[i][n] != env[n])
				break ;
		}
		if (g_data.env[i][n] == '=' && env[n] == '\0')
			break ;
	}
	content = (char *)malloc(sizeof(char) * (ft_strlen(g_data.env[i]) - n));
	j = 0;
	while (g_data.env[i][++n])
	{
		content[j] = g_data.env[i][n];
		j++;
	}
	return (content);
}

static char	*ft_change_env_str(t_token *tokens, char *content)
{
	char	*str;
	int		i;
	int		len;
	int		len_env;
	int		len_content;

	i = 0;
	len = ft_strlen(tokens->str);
	len_content = ft_strlen(content);
	while (tokens->str[i] != '$')
		i++;
	len_env = 0;
	while (tokens->str[i] && (tokens->str[i] != ' ' && tokens->str[i] != '\"' && tokens->str[i] != '$'))
	{
		len_env++;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (len - len_env + len_content));
	i = -1;
	len = -1;
	while (tokens->str[++i] != '$')
		str[++len] = tokens->str[i];
	while (tokens->str[i] != ' ' && tokens->str[i] != '\"' && tokens->str[i] != '$')
		i++;
	len_env = -1;
	while (content[++len_env])
		str[++len] = content[len_env];
	while (tokens->str[i])
	{
		str[++len] = tokens->str[i];
		i++;
	}
	return (str);
}

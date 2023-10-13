/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:06:03 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/13 12:37:18 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/* HACER CUANDO NO EXISTA VARIABLE $ENV */

static char	*ft_obtain_env(t_token *tokens, int i);
// static char	*ft_obtain_env_content(char *env);
static char	*ft_change_env_str(t_token *tokens, char *content, char *env);

void	ft_expand_env(t_token *tokens)
{
	char	*env = NULL;
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
	if (!env)
		return ;
	content = ft_get_env(env);
	ft_printf("content: %s\n", content); // Borrar
	tokens->str = ft_change_env_str(tokens, content, env);
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
	env = (char *)malloc(sizeof(char) * (len + 1));
	if (!env)
		return (NULL);
	n = 0;
	while (tokens->str[i] && (tokens->str[i] != ' ' && tokens->str[i] != '\"' && tokens->str[i] != '$'))
	{
		env[n] = tokens->str[i];
		n++;
		i++;
	}
	env[n] = '\0';
	return (env);
}

// static char	*ft_obtain_env_content(char *env)
// {
// 	int		i;
// 	int		n;
// 	int		j;
// 	int		len;
// 	char	*content;

// 	i = 0;
// 	while (g_data.env[i])
// 	{
// 		len = ft_strlen(env);
// 		if ((ft_strncmp(g_data.env[i], env, len) == 0) && g_data.env[i][len] == '=')
// 			break ;
// 		i++;
// 	}
// 	if (!g_data.env[i])
// 		return (NULL);
// 	content = (char *)malloc(sizeof(char) * (ft_strlen(env) + 1));
// 	n = 0;
// 	while (g_data.env[i][n] != '=')
// 		n++;
// 	j = 0;
// 	while (g_data.env[i][++n])
// 	{
// 		content[j] = g_data.env[i][n];
// 		j++;
// 	}
// 	return (content);
// }

static char	*ft_change_env_str(t_token *tokens, char *content, char *env)
{
	char	*str;
	int		i;
	int		len;
	int		len_env;

	len = ft_strlen(tokens->str);
	len_env = ft_strlen(env);
	str = (char *)malloc(sizeof(char) * (len - len_env + ft_strlen(content)));
	i = -1;
	len = -1;
	while (tokens->str[++i] != '$')
		str[++len] = tokens->str[i];
	++i;
	while (tokens->str[i] != ' ' && tokens->str[i] != '\"' && tokens->str[i] != '$' && tokens->str[i])
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

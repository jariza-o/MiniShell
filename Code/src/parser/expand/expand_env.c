/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:06:03 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/27 08:28:41 by jariza-o         ###   ########.fr       */
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
			while (tokens->str[++i] != '\'')
				;
		else if (tokens->str[i] == '$')
		{
			env = ft_obtain_env(tokens, ++i);
			break ;
		}
	}
	if (!env)
		return ;
	content = ft_get_env(env);
	if (content == NULL)
		content = ft_calloc(1, 1);
	tokens->str = ft_change_env_str(tokens, content, env);
	free(env);
	free(content);
}

static char	*ft_obtain_env(t_token *tokens, int i)
{
	int		n;
	int		len;
	char	*env;

	if (tokens->str[i] == '?')
		return (env = (char *)ft_calloc(2, sizeof(char)), env[0] = '?', env);
	n = i;
	len = 0;
	while (tokens->str[n] && (tokens->str[n] == '_' || \
	ft_isalnum(tokens->str[n]) == 1))
	{
		len++;
		n++;
	}
	env = (char *)ft_calloc((len + 1), sizeof(char));
	if (!env)
		return (NULL);
	n = 0;
	while (tokens->str[i] && (tokens->str[i] == '_' || \
	ft_isalnum(tokens->str[i]) == 1))
		env[n++] = tokens->str[i++];
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
	if (!ft_strcmp(env, "?"))
		len_env = ft_strlen(ft_itoa(g_data.exit_status));
	str = (char *)ft_calloc((len - len_env + ft_strlen(content)), sizeof(char));
	i = -1;
	len = -1;
	while (tokens->str[++i] != '$')
		str[++len] = tokens->str[i];
	while ((tokens->str[++i] == '_' || ft_isalnum(tokens->str[i])) \
	&& tokens->str[i])
		i++;
	if (tokens->str[i - 1] == '$' && tokens->str[i] == '?')
		i++;
	len_env = -1;
	while (content[++len_env])
		str[++len] = content[len_env];
	while (tokens->str[i])
		str[++len] = tokens->str[i++];
	return (free(tokens->str), str);
}

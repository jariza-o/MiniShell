/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:06:03 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/26 19:03:28 by jariza-o         ###   ########.fr       */
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
			env = ft_obtain_env(tokens, ++i);
			break ;
		}
	}
	if (!env)
		return ;
	content = ft_get_env(env);
	if (content == NULL)
		content = ft_calloc(1,1);
	free(tokens->str); // PUESTO DESPUES 
	tokens->str = ft_change_env_str(tokens, content, env);
	ft_printf("FT_EXPAND_ENV_YTEST\n");
	free(env);
	free(content);
}

static char	*ft_obtain_env(t_token *tokens, int i)
{
	int		n;
	int		len;
	char	*env;

	// i += 1;
	if (tokens->str[i] == '?')
		return (env = (char *)ft_calloc(2, sizeof(char)), env[0] = '?', env);
	n = i;
	len = 0;
	while (tokens->str[n] && (tokens->str[n] == '_' || ft_isalnum(tokens->str[n]) == 1))
	{
		len++;
		n++;
	}
	env = (char *)ft_calloc((len + 1), sizeof(char));
	if (!env)
		return (NULL);
	n = 0;
	while (tokens->str[i] && (tokens->str[i] == '_' || ft_isalnum(tokens->str[i]) == 1))
	{
		env[n] = tokens->str[i];
		n++;
		i++;
	}
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

	// if (!ft_strcmp(env, "?"))
	// 	return(ft_itoa(g_data.exit_status));
	len = ft_strlen(tokens->str);
	if (!ft_strcmp(env, "?"))
		len_env = ft_strlen(ft_itoa(g_data.exit_status));
	else
		len_env = ft_strlen(env);
	str = (char *)ft_calloc((len - len_env + ft_strlen(content)), sizeof(char));
	i = -1;
	len = -1;
	while (tokens->str[++i] != '$')
		str[++len] = tokens->str[i];
	++i;
	while ((tokens->str[i] == '_' || ft_isalnum(tokens->str[i]) == 1) && tokens->str[i])
		i++;
	if (tokens->str[i - 1] == '$' && tokens->str[i] == '?')
		i++;
	len_env = -1;
	while (content[++len_env])
	{
		str[++len] = content[len_env];
	}
	ft_printf("%c %c\n", str[len], tokens->str[i]); //A VECES LLEGA A VECES NO
	ft_printf("ttgrgrtg: %s\n", tokens->str);
	while (tokens->str[i])
	{
		str[++len] = tokens->str[i];
		i++;
	}
ft_printf("FT_CHANGE_ENV_STR_TEST\n");
	return (str);
}

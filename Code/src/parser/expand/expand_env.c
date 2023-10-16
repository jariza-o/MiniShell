/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:06:03 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/16 18:48:08 by jariza-o         ###   ########.fr       */
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
	content = ft_get_env(env); // ESTA FUNCION ESTa MAL, HASTA QUE XEMA NO ME LA ARREGLE NO PUEDO CONTINUAR
	if (content == NULL)
	{
		content = ""; //ESTO SE PUEDE HACER SIN MALLOC?? CREO QUE NO
	}
	ft_printf("content: %s\n", content); // Borrar
	tokens->str = ft_change_env_str(tokens, content, env);
	ft_printf("VARIABLE: %s\n\n", tokens->str);
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
		if ((tokens->str[n] < 48 || tokens->str[n] > 57) && (tokens->str[n] < 65 || tokens->str[n] > 90) && (tokens->str[n] < 97 || tokens->str[n] > 122) && tokens->str[n] != '_')
			break; // REVISAR SI ESTO ESTA BIEN QUE NO LO SE
		len++;
		n++;
	}
	env = (char *)ft_calloc((len + 1), sizeof(char));
	if (!env)
		return (NULL);
	n = 0;
	while (tokens->str[i] && (tokens->str[i] != ' ' && tokens->str[i] != '\"' && tokens->str[i] != '$'))
	{
		if ((tokens->str[n] < 48 || tokens->str[n] > 57) && (tokens->str[n] < 65 || tokens->str[n] > 90) && (tokens->str[n] < 97 || tokens->str[n] > 122) && tokens->str[n] != '_')
			break; // REVISAR SI ESTO ESTA BIEN QUE NO LO SE
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

	if (!ft_strcmp(env, "?"))
		return(ft_itoa(g_data.exit_status));
	len = ft_strlen(tokens->str);
	len_env = ft_strlen(env);
	str = (char *)ft_calloc((len - len_env + ft_strlen(content)), sizeof(char));
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

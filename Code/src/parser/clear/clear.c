/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:52:42 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/14 19:58:01 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_clear(void)
{
	if (g_data.recieved)
		ft_clean_double_pointer(g_data.recieved);
	if(g_data.vars_mod == 10)
		unlink("tmp");
	if (g_data.line)
		free(g_data.line);
  ft_clear_tokens();
	g_data.line = NULL;
}

void	ft_clear_parser(int i)
{
	if (i == 0)
	{
		if (g_data.recieved)
			ft_clean_matrix(g_data.recieved);
	}
	else if (i == 1)
	{
		if (g_data.recieved)
			ft_clean_matrix(g_data.recieved);
		if (g_data.tokens)
			ft_clear_tokens();
	}
}

void	ft_clean_double_pointer(char **matrix)
{
	int		cnt;

	cnt = 0;
	while (matrix[cnt + 1])
	{
		free(matrix[cnt]);
		cnt++;
	}
	free(matrix);
	matrix = NULL;
}

void	ft_clear_tokens(void)
{
	// t_token	*aux = g_data.tokens;
	t_token	*next;
	
	while (g_data.tokens)
	{
		ft_printf("CLEAR TOKENS: %s\n", g_data.tokens->str);
		// aux = g_data.tokens;
		next = g_data.tokens->next;
		free (g_data.tokens->str);
		free (g_data.tokens);
		// ft_printf("CLEANED TOKENS: %s\n", g_data.tokens->str);
		g_data.tokens = next;
	}
	// g_data.tokens = aux;
	// if (g_data.tokens)
	// 	ft_printf("JHGBJHB: %s\n", g_data.tokens->str);
	// g_data.tokens = g_data.tokens->next;
	// if (g_data.tokens)
	// 	ft_printf("JHGBJHB: %s\n", g_data.tokens->str);
	g_data.tokens = NULL; //NOSE SI ESTO ESTA GUAY
	// free (aux);
}

// void	ft_clear_tokens(t_token **tokens)
// {
// 	t_token	*current;
// 	t_token	*next;

// 	if (!tokens || !*tokens)
// 		return ;
// 	current = *tokens;
// 	while (current)
// 	{
// 		next = current->next;
// 		free(current->str);
// 		free (current);
// 		current = next;
// 	}
// 	free(current); // AÑADIDO DESPUES
// 	*tokens = NULL;
// }

// void	ft_clear_tokens(t_token *tokens)
// {
// 	t_token	*aux;

// 	aux = tokens;
// 	while (tokens)
// 	{
// 		free(tokens->str);
// 		tokens = tokens->next;
// 	}
// 	free (aux);
// }

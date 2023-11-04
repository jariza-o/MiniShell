/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:52:42 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/04 20:25:04 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_clear(void)
{
	// if (g_data.recieved)
		ft_clean_double_pointer(g_data.recieved);
		//ft_clear_tokens(&g_data.tokens);
	// if (g_data.line)
		free(g_data.line);
}

void	ft_clear_parser(int i)
{
	if (i == 0)
		ft_clean_double_pointer(g_data.recieved);
	else if (i == 1)
	{
		ft_clean_double_pointer(g_data.recieved);
		ft_clear_tokens();
	}
}

void	ft_clean_double_pointer(char **matrix)
{
	int		cnt;

	cnt = 0;
	while (matrix[cnt])
	{
		free(matrix[cnt]);
		cnt++;
	}
	free(matrix);
	matrix = NULL;
}

void	ft_clear_tokens(void)
{
	t_token	*aux;
	t_token	*next;

	while (g_data.tokens)
	{
		aux = g_data.tokens;
		next = g_data.tokens->next;
		free (g_data.tokens->str);
		free (aux);
		g_data.tokens = next;
	}
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

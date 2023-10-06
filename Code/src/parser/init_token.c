/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:07:14 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/06 13:02:34 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_token	*ft_lstnew_mini(char *argv);
static t_token	*ft_lstlast_mini(t_token *lst);
static void		ft_lstadd_back_mini(t_token **lst, t_token *new);


t_token	*ft_init_token(void)
{
	t_token	*list;
	int		i;

	i = 0;
	list = ft_lstnew_mini(g_data.recieved[i]);
	i++;
	while (g_data.recieved[i])
	{
		ft_lstadd_back_mini(&list, ft_lstnew_mini(g_data.recieved[i]));
		i++;
	}
	return (list);
}

static t_token	*ft_lstnew_mini(char *argv)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (node == NULL)
		return (NULL);
	node->str = argv;
	node->type = VOID;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static t_token	*ft_lstlast_mini(t_token *lst)
{
	if (!lst)
		return (NULL);
	// ft_printf("test\n");
	while (lst)
	{
		if (lst->next == NULL)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (lst);
}

static void	ft_lstadd_back_mini(t_token **lst, t_token *new)
{
	if (*lst)
	{
		// ft_printf("PIRULETA\n");
		new->prev = ft_lstlast_mini(*lst);
		ft_lstlast_mini(*lst)->next = new;
		// ft_printf("%s", ft_lstlast_mini(*lst)->str);
	}
	// else
	// {
	// 	ft_printf("PIRULETA2\n");
	// 	*lst = new;
	// ft_printf("test2\n");
	// }
	//ft_printf("%s", new->str);
}

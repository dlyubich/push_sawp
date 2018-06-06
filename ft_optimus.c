/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:20:03 by dlyubich          #+#    #+#             */
/*   Updated: 2018/01/30 15:20:04 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_opti_check(t_list *node)
{
	if ((!ft_strcmp(node->content, "ra") &&
		!ft_strcmp(node->next->content, "rra"))
		|| (!ft_strcmp(node->content, "pa") &&
		!ft_strcmp(node->next->content, "pb")) ||
		(!ft_strcmp(node->content, "rb") &&
		!ft_strcmp(node->next->content, "rrb")) ||
		(!ft_strcmp(node->content, "rra") &&
		!ft_strcmp(node->next->content, "ra")) ||
		(!ft_strcmp(node->content, "rrb") &&
		!ft_strcmp(node->next->content, "rb")) ||
		(!ft_strcmp(node->content, "pb") &&
		!ft_strcmp(node->next->content, "pa")))
		return (1);
	return (0);
}

int			opti_help4(t_list **list, t_list *prev, t_list **main)
{
	t_list	*node;

	node = *list;
	if (ft_opti_check(node))
	{
		if (prev)
			prev->next = node->next->next;
		else
			*main = node->next->next;
		free(node->content);
		free(node->next->content);
		free(node->next);
		free(node);
		return (1);
	}
	return (0);
}

int			ft_optimus(t_list **list)
{
	t_list	*node;
	t_list	*prev;

	node = *list;
	if (!node || !node->next)
		return (0);
	prev = NULL;
	while (node->next)
	{
		if (opti_main(&node))
		{
			node = *list;
			continue ;
		}
		else if (opti_help4(&node, prev, list))
		{
			node = *list;
			prev = NULL;
			continue ;
		}
		prev = node;
		node = node->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimus_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:07:33 by dlyubich          #+#    #+#             */
/*   Updated: 2018/02/04 13:11:45 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			opti_help1(t_list **list)
{
	t_list	*node;
	t_list	*tmp;

	node = *list;
	if (((!ft_strcmp(node->content, "sa") &&
	!ft_strcmp(node->next->content, "sb")) || (!ft_strcmp(node->content, "sb")
	&& !ft_strcmp(node->next->content, "sa"))))
	{
		free(node->content);
		node->content = ft_strdup("ss");
		tmp = node->next;
		node->next = node->next->next;
		free(tmp->content);
		free(tmp);
		return (1);
	}
	return (0);
}

int			opti_help2(t_list **list)
{
	t_list	*node;
	t_list	*tmp;

	node = *list;
	if (((!ft_strcmp(node->content, "ra") &&
	!ft_strcmp(node->next->content, "rb")) || (!ft_strcmp(node->content, "rb")
	&& !ft_strcmp(node->next->content, "ra"))))
	{
		free(node->content);
		node->content = "rr";
		tmp = node->next;
		node->next = node->next->next;
		free(tmp->content);
		free(tmp);
		return (1);
	}
	return (0);
}

int			opti_help3(t_list **list)
{
	t_list	*node;
	t_list	*tmp;

	node = *list;
	if (((!ft_strcmp(node->content, "rra") &&
	!ft_strcmp(node->next->content, "rrb")) || (!ft_strcmp(node->content, "rrb")
	&& !ft_strcmp(node->next->content, "rra"))))
	{
		free(node->content);
		node->content = "rrr";
		tmp = node->next;
		node->next = node->next->next;
		free(tmp->content);
		free(tmp);
		return (1);
	}
	return (0);
}

int			opti_main(t_list **list)
{
	t_list *node;

	node = *list;
	if (opti_help1(&node) || opti_help2(&node) || opti_help3(&node))
		return (1);
	return (0);
}

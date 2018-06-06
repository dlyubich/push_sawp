/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:56:16 by dlyubich          #+#    #+#             */
/*   Updated: 2018/01/13 15:56:17 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_ra(t_stack **s_a, t_list **com)
{
	t_stack	*tmp;
	t_stack	*node;

	tmp = *s_a;
	if (!tmp || !tmp->next)
		return ;
	ft_lstpushback(com, "ra", 3);
	*s_a = (*s_a)->next;
	node = *s_a;
	node->prev = NULL;
	while (node->next)
	{
		node = node->next;
	}
	node->next = tmp;
	tmp->prev = node;
	tmp->next = NULL;
}

void		ft_rb(t_stack **s_b, t_list **com)
{
	t_stack	*tmp;
	t_stack	*node;

	tmp = *s_b;
	if (!tmp || !tmp->next)
		return ;
	tmp = *s_b;
	ft_lstpushback(com, "rb", 3);
	*s_b = (*s_b)->next;
	node = *s_b;
	node->prev = NULL;
	while (node->next)
	{
		node = node->next;
	}
	node->next = tmp;
	tmp->prev = node;
	tmp->next = NULL;
}

void		ft_rra(t_stack **s_a, t_list **com)
{
	t_stack	*prev;
	t_stack	*node;

	if (*s_a && count_stack(*s_a) > 1)
	{
		prev = NULL;
		ft_lstpushback(com, "rra", 4);
		node = *s_a;
		while (node->next)
		{
			prev = node;
			node = node->next;
		}
		if (prev)
			prev->next = NULL;
		ft_stackadd(s_a, node);
	}
}

void		ft_rrb(t_stack **s_b, t_list **com)
{
	t_stack	*prev;
	t_stack	*node;

	if (*s_b && count_stack(*s_b) > 1)
	{
		prev = NULL;
		ft_lstpushback(com, "rrb", 4);
		node = *s_b;
		while (node->next)
		{
			prev = node;
			node = node->next;
		}
		if (prev)
			prev->next = NULL;
		ft_stackadd(s_b, node);
	}
}

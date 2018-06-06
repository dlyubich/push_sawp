/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:25:06 by dlyubich          #+#    #+#             */
/*   Updated: 2018/01/13 16:25:06 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_a_sorted(t_stack **s_a, int num)
{
	t_stack	*node;
	int		i;

	node = *s_a;
	i = 0;
	if (!node)
		return (0);
	while (node->next && i < num - 1)
	{
		if (node->nb > node->next->nb)
			return (0);
		i++;
		node = node->next;
	}
	return (1);
}

int			ft_b_sorted(t_stack **s_b, int num)
{
	t_stack	*node;
	int		i;

	node = *s_b;
	if (!node)
		return (0);
	i = 0;
	while (node->next && i < num - 1)
	{
		if (node->nb < node->next->nb)
			return (0);
		i++;
		node = node->next;
	}
	return (1);
}

void		ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int			count_stack(t_stack *s_a)
{
	t_stack	*node;
	int		i;

	i = 0;
	node = s_a;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void		ft_stackadd(t_stack **alst, t_stack *new)
{
	new->next = *alst;
	new->prev = NULL;
	if (*alst)
		(*alst)->prev = new;
	*alst = new;
}

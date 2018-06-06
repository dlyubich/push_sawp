/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:07:15 by dlyubich          #+#    #+#             */
/*   Updated: 2018/01/31 15:07:17 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_bigger_a(t_stack **s_a, int pivot)
{
	t_stack	*node;

	node = *s_a;
	while (node)
	{
		if (node->nb < pivot)
			return (1);
		else
			node = node->next;
	}
	return (0);
}

int			check_bigger_b(t_stack **s_a, int pivot)
{
	t_stack *node;

	node = *s_a;
	while (node)
	{
		if (node->nb > pivot)
			return (1);
		else
			node = node->next;
	}
	return (0);
}

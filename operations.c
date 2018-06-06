/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:12:17 by dlyubich          #+#    #+#             */
/*   Updated: 2018/01/30 16:12:17 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_divide(t_stack **s_a, t_stack **s_b, int num, t_list **com)
{
	int	count;
	int	a;
	int	pivot;
	int	tmp;

	count = 0;
	a = 0;
	tmp = count_stack(*s_a);
	pivot = ft_median(*s_a, num, 1);
	while (check_bigger_a(s_a, pivot))
	{
		if ((*s_a)->nb < pivot)
		{
			ft_pb(s_a, s_b, com);
			count++;
		}
		else if (++a)
			ft_ra(s_a, com);
	}
	if (tmp != num)
		while (a-- > 0)
			ft_rra(s_a, com);
	return (count);
}

int		ft_divide_b(t_stack **s_b, t_stack **s_a, int num, t_list **com)
{
	int	count;
	int	a;
	int	pivot;
	int	tmp;

	count = 0;
	a = 0;
	tmp = count_stack(*s_b);
	pivot = ft_median(*s_b, num, 0);
	while (check_bigger_b(s_b, pivot))
	{
		if ((*s_b)->nb > pivot)
		{
			ft_pa(s_a, s_b, com);
			count++;
		}
		else if (++a)
			ft_rb(s_b, com);
	}
	if (tmp != num)
		while (a-- > 0)
			ft_rrb(s_b, com);
	return (count);
}

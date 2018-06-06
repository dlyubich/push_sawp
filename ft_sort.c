/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:16:29 by dlyubich          #+#    #+#             */
/*   Updated: 2018/01/25 12:16:29 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_papapa(t_stack **s_a, t_stack **s_b, t_list **com)
{
	ft_pa(s_a, s_b, com);
	ft_pa(s_a, s_b, com);
	ft_pa(s_a, s_b, com);
}

void		ft_rb_sb_pa_pa_rrb_pa(t_stack **s_a, t_stack **s_b, t_list **com)
{
	ft_rb(s_b, com);
	ft_sb(*s_b, com);
	ft_pa(s_a, s_b, com);
	ft_pa(s_a, s_b, com);
	ft_rrb(s_b, com);
	ft_pa(s_a, s_b, com);
}

void		ft_rb_sb_pa_rrb_pa_pa(t_stack **s_a, t_stack **s_b, t_list **com)
{
	ft_rb(s_b, com);
	ft_sb(*s_b, com);
	ft_pa(s_a, s_b, com);
	ft_rrb(s_b, com);
	ft_pa(s_a, s_b, com);
	ft_pa(s_a, s_b, com);
}

void		ft_sort_a(t_stack **s_a, t_stack **s_b, int num, t_list **com)
{
	int		tob;

	if (ft_a_sorted(s_a, num))
		return ;
	if (num > 3)
	{
		tob = ft_divide(s_a, s_b, num, com);
		ft_sort_a(s_a, s_b, num - tob, com);
		ft_sort_b(s_a, s_b, tob, com);
	}
	else
	{
		ft_sort_trio_a(s_a, s_b, num, com);
	}
}

void		ft_sort_b(t_stack **s_a, t_stack **s_b, int num, t_list **com)
{
	int		toa;
	int		i;

	if (ft_b_sorted(s_b, num))
	{
		i = 0;
		while (i < num)
		{
			ft_pa(s_a, s_b, com);
			i++;
		}
		return ;
	}
	if (num > 3)
	{
		toa = ft_divide_b(s_b, s_a, num, com);
		ft_sort_a(s_a, s_b, toa, com);
		ft_sort_b(s_a, s_b, num - toa, com);
	}
	else
	{
		ft_sort_trio_b(s_a, s_b, num, com);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_trio_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:25:00 by dlyubich          #+#    #+#             */
/*   Updated: 2018/01/25 12:25:01 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sb_pa_sb_pa_pa(t_stack **s_a, t_stack **s_b, t_list **com)
{
	ft_sb(*s_b, com);
	ft_pa(s_a, s_b, com);
	ft_sb(*s_b, com);
	ft_pa(s_a, s_b, com);
	ft_pa(s_a, s_b, com);
}

void		ft_pa_sb_pa_pa(t_stack **s_a, t_stack **s_b, t_list **com)
{
	ft_pa(s_a, s_b, com);
	ft_sb(*s_b, com);
	ft_pa(s_a, s_b, com);
	ft_pa(s_a, s_b, com);
}

void		ft_only_trio_b(t_stack **s_a, t_stack **s_b, t_list **com)
{
	t_stack	*t_b;

	t_b = *s_b;
	if (t_b && t_b->next && t_b->next->next &&
	t_b->nb < t_b->next->nb && t_b->next->nb < t_b->next->next->nb)
	{
		ft_sb(*s_b, com);
		ft_rrb(s_b, com);
	}
	else if (t_b && t_b->next && t_b->next->next &&
	t_b->nb > t_b->next->nb && t_b->next->next->nb > t_b->nb)
		ft_rrb(s_b, com);
	else if (t_b && t_b->next && t_b->next->next &&
	t_b->nb < t_b->next->next->nb && t_b->next->nb > t_b->next->next->nb)
		ft_rb(s_b, com);
	else if (t_b && t_b->next && t_b->next->next &&
	t_b->nb < t_b->next->nb && t_b->nb > t_b->next->next->nb)
		ft_sb(*s_b, com);
	else if (t_b && t_b->next && t_b->next->next &&
	t_b->nb > t_b->next->next->nb && t_b->next->nb < t_b->next->next->nb)
	{
		ft_rrb(s_b, com);
		ft_sb(*s_b, com);
	}
	ft_papapa(s_a, s_b, com);
}

void		ft_sort_other_b(t_stack **s_a, t_stack **s_b, t_list **com)
{
	t_stack	*t_b;

	t_b = *s_b;
	if (t_b && t_b->next && t_b->next->next &&
	t_b->nb < t_b->next->nb && t_b->next->nb < t_b->next->next->nb)
		ft_rb_sb_pa_pa_rrb_pa(s_a, s_b, com);
	else if (t_b && t_b->next && t_b->next->next &&
	t_b->nb > t_b->next->nb && t_b->nb < t_b->next->next->nb)
		ft_rb_sb_pa_rrb_pa_pa(s_a, s_b, com);
	else if (t_b && t_b->next && t_b->next->next &&
	t_b->nb < t_b->next->next->nb && t_b->next->nb > t_b->next->next->nb)
		ft_sb_pa_sb_pa_pa(s_a, s_b, com);
	else if (t_b && t_b->next && t_b->next->next &&
	t_b->nb > t_b->next->next->nb && t_b->next->nb > t_b->nb)
	{
		ft_sb(*s_b, com);
		ft_papapa(s_a, s_b, com);
	}
	else if (t_b && t_b->next && t_b->next->next &&
	t_b->nb > t_b->next->next->nb && t_b->next->nb < t_b->next->next->nb)
		ft_pa_sb_pa_pa(s_a, s_b, com);
}

void		ft_sort_trio_b(t_stack **s_a, t_stack **s_b, int num, t_list **com)
{
	t_stack	*t_b;

	t_b = *s_b;
	if (num < 2)
	{
		ft_pa(s_a, s_b, com);
		return ;
	}
	if (num == 2)
	{
		if (t_b && t_b->next && t_b->nb < t_b->next->nb)
			ft_sb(*s_b, com);
		ft_pa(s_a, s_b, com);
		ft_pa(s_a, s_b, com);
		return ;
	}
	if (t_b && t_b->next && t_b->next->next &&
	t_b->nb > t_b->next->nb && t_b->next->nb > t_b->next->next->nb)
		ft_papapa(s_a, s_b, com);
	else if (num == 3 && count_stack(t_b) == 3)
		ft_only_trio_b(s_a, s_b, com);
	else
		ft_sort_other_b(s_a, s_b, com);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_trio_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:24:42 by dlyubich          #+#    #+#             */
/*   Updated: 2018/01/25 12:24:43 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_ra_sa_rra(t_stack **s_a, t_list **com)
{
	ft_ra(s_a, com);
	ft_sa(*s_a, com);
	ft_rra(s_a, com);
}

void		ft_sa_ra_sa_rra_sa(t_stack **s_a, t_list **com)
{
	ft_sa(*s_a, com);
	ft_ra_sa_rra(s_a, com);
	ft_sa(*s_a, com);
}

void		ft_only_trio_a(t_stack **s_a, t_list **com)
{
	t_stack	*t_a;

	t_a = *s_a;
	if (t_a && t_a->next && t_a->next->next && t_a->nb > t_a->next->nb &&
	t_a->next->nb > t_a->next->next->nb)
	{
		ft_sa(*s_a, com);
		ft_rra(s_a, com);
	}
	else if (t_a && t_a->next && t_a->next->next &&
	t_a->nb < t_a->next->next->nb && t_a->next->nb > t_a->next->next->nb)
	{
		ft_rra(s_a, com);
		ft_sa(*s_a, com);
	}
	else if (t_a && t_a->next && t_a->next->next && t_a->nb > t_a->next->nb &&
	t_a->nb < t_a->next->next->nb)
		ft_sa(*s_a, com);
	else if (t_a && t_a->next && t_a->next->next &&
	t_a->nb > t_a->next->next->nb && t_a->next->nb > t_a->nb)
		ft_rra(s_a, com);
	else if (t_a && t_a->next && t_a->next->next &&
	t_a->nb > t_a->next->next->nb && t_a->next->nb < t_a->next->next->nb)
		ft_ra(s_a, com);
}

void		ft_sort_other_a(t_stack **s_a, t_list **com)
{
	t_stack	*t_a;

	t_a = *s_a;
	if (t_a && t_a->next && t_a->next->next &&
	t_a->nb > t_a->next->nb && t_a->next->nb > t_a->next->next->nb)
		ft_sa_ra_sa_rra_sa(s_a, com);
	else if (t_a && t_a->next && t_a->next->next
	&& t_a->nb > t_a->next->next->nb && t_a->next->nb > t_a->nb)
	{
		ft_ra_sa_rra(s_a, com);
		ft_sa(*s_a, com);
	}
	else if (t_a && t_a->next && t_a->next->next &&
	t_a->nb > t_a->next->next->nb && t_a->next->nb < t_a->next->next->nb)
	{
		ft_sa(*s_a, com);
		ft_ra_sa_rra(s_a, com);
	}
	else if (t_a && t_a->next && t_a->next->next &&
	t_a->next->nb < t_a->nb && t_a->nb < t_a->next->next->nb)
		ft_sa(*s_a, com);
	else if (t_a && t_a->next && t_a->next->next &&
	t_a->nb < t_a->next->next->nb && t_a->next->next->nb < t_a->next->nb)
		ft_ra_sa_rra(s_a, com);
}

void		ft_sort_trio_a(t_stack **s_a, t_stack **s_b, int num, t_list **com)
{
	t_stack	*t_a;

	t_a = *s_a;
	if (s_b)
		;
	if (num < 2)
		return ;
	if (num == 2)
	{
		if (t_a && t_a->next && t_a->nb > t_a->next->nb)
			ft_sa(*s_a, com);
		else
			return ;
	}
	if (t_a && t_a->next && t_a->next->next)
		if (t_a->nb < t_a->next->nb && t_a->next->nb < t_a->next->next->nb)
			return ;
	if (num == 3 && count_stack(t_a) == 3)
		ft_only_trio_a(s_a, com);
	else
		ft_sort_other_a(s_a, com);
}

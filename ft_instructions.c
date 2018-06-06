/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:50:49 by dlyubich          #+#    #+#             */
/*   Updated: 2018/01/13 14:50:50 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sa(t_stack *s_a, t_list **com)
{
	int		tmp;

	if (!s_a || (!s_a->next))
		return ;
	else
	{
		ft_lstpushback(com, "sa", 3);
		tmp = s_a->nb;
		s_a->nb = s_a->next->nb;
		s_a->next->nb = tmp;
	}
}

void		ft_sb(t_stack *s_b, t_list **com)
{
	int		tmp;

	if (!s_b || !s_b->next)
		return ;
	else
	{
		ft_lstpushback(com, "sb", 3);
		tmp = s_b->nb;
		s_b->nb = s_b->next->nb;
		s_b->next->nb = tmp;
	}
}

void		ft_pa(t_stack **s_a, t_stack **s_b, t_list **com)
{
	t_stack	*tmp;

	if (!*s_b)
		return ;
	else
	{
		ft_lstpushback(com, "pa", 3);
		tmp = *s_b;
		*s_b = (*s_b)->next;
		if (*s_b)
			(*s_b)->prev = NULL;
		ft_stackadd(s_a, tmp);
	}
}

void		ft_pb(t_stack **s_a, t_stack **s_b, t_list **com)
{
	t_stack	*tmp;

	if (!*s_a)
		return ;
	else
	{
		ft_lstpushback(com, "pb", 3);
		tmp = *s_a;
		*s_a = (*s_a)->next;
		if (*s_a)
			(*s_a)->prev = NULL;
		ft_stackadd(s_b, tmp);
	}
}

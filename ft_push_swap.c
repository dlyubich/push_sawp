/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:29:08 by dlyubich          #+#    #+#             */
/*   Updated: 2018/02/04 13:12:54 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_print_commands(t_list **com)
{
	t_list	*node;

	node = *com;
	ft_optimus(&node);
	while (node)
	{
		write(1, node->content, node->content_size - 1);
		write(1, "\n", 1);
		node = node->next;
	}
}

int			ft_median(t_stack *tmp_a, int n, int fl)
{
	int		*mas;
	int		i;
	int		ret;
	t_stack	*node;

	if (!(node = tmp_a))
		return (0);
	mas = (int*)malloc(sizeof(int) * n);
	ft_bzero(mas, n);
	i = 0;
	ret = 0;
	while (i < n && node)
	{
		mas[i++] = node->nb;
		node = node->next;
	}
	ft_max(mas, n);
	ret = mas[n / 2];
	if (fl == 0 && !(n % 2))
		ret = mas[n / 2 - 1];
	mas ? free(mas) : NULL;
	return (ret);
}

void		ft_small_bubbles(t_stack **s_a, t_list **com)
{
	t_stack *t_a;

	t_a = *s_a;
	if (t_a->nb > t_a->next->nb && t_a->next->nb > t_a->next->next->nb)
	{
		ft_sa(*s_a, com);
		ft_rra(s_a, com);
	}
}

void		ft_bubbles(t_stack **s_a, t_stack **s_b, t_list **com, int i)
{
	t_stack	*t_b;
	t_stack	*t_a;
	int		tmp;

	tmp = i;
	t_a = *s_a;
	t_b = *s_b;
	if (count_stack(*s_a) == 3)
		ft_small_bubbles(s_a, com);
	else
	{
		while (tmp >= 1)
		{
			ft_rra(s_a, com);
			ft_pb(s_a, s_b, com);
			tmp--;
		}
		tmp = i;
		while (tmp >= 1)
		{
			ft_pa(s_a, s_b, com);
			tmp--;
		}
	}
}

int			main(int ac, char **av)
{
	int		i;
	int		nb;
	t_stack	*s_a;
	t_stack	*s_b;
	t_list	*com;

	if (ac == 1)
		ft_error_usage();
	i = 0;
	s_a = NULL;
	s_b = NULL;
	com = NULL;
	while (av[++i])
	{
		if (check_integer(av[i]) && check_doubles(s_a, (nb = ft_atoi(av[i]))))
			ft_stackpushback(&s_a, nb);
		else
			ft_error();
	}
	ft_b_sorted(&s_a, ac - 1) ? ft_bubbles(&s_a, &s_b, &com, ac - 1)
		: ft_sort_a(&s_a, &s_b, ac - 1, &com);
	i != 2 ? ft_print_commands(&com) : NULL;
	return (0);
}

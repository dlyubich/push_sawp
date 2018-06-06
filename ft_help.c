/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:48:12 by dlyubich          #+#    #+#             */
/*   Updated: 2018/01/15 14:48:14 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_integer(char *av)
{
	int i;
	int	tmp;

	i = 0;
	tmp = ft_strlen(av);
	if (tmp > 11 || (tmp == 10 && av[0] != '-'
	&& ft_strcmp(av, "2147483647") > 0)
	|| (tmp == 11 && av[0] == '-' && ft_strcmp(av, "-2147483648") > 0))
		return (0);
	if (av[0] == '-')
		i = 1;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int			ft_check_stack(t_stack *s_a)
{
	t_stack	*node;
	int		tmp;
	int		nb;

	node = s_a;
	nb = -2147483648;
	while (node)
	{
		tmp = node->nb;
		if (tmp < nb)
			return (0);
		nb = tmp;
		node = node->next;
	}
	return (1);
}

int			check_doubles(t_stack *s_a, int n)
{
	int		i;
	int		tmp;
	t_stack	*node;

	i = 0;
	node = s_a;
	while (node)
	{
		tmp = node->nb;
		if (tmp == n)
			ft_error();
		node = node->next;
	}
	return (1);
}

t_stack		*ft_stacknew(int nb, t_stack *prev)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->next = NULL;
	new->prev = prev;
	new->nb = nb;
	return (new);
}

void		ft_stackpushback(t_stack **list, int nb)
{
	t_stack	*listbegin;

	listbegin = *list;
	if (listbegin)
	{
		while (listbegin->next)
			listbegin = listbegin->next;
		listbegin->next = ft_stacknew(nb, listbegin);
	}
	else
		*list = ft_stacknew(nb, NULL);
}

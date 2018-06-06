/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:45:43 by dlyubich          #+#    #+#             */
/*   Updated: 2018/02/04 13:17:15 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_r_intrs(t_stack **s_a, t_stack **s_b, t_list **com, char *str)
{
	if (!ft_strcmp(str, "ra"))
		ft_ra(s_a, com);
	else if (!ft_strcmp(str, "rb"))
		ft_rb(s_b, com);
	else if (!ft_strcmp(str, "rr"))
		ft_rr(s_a, s_b, com);
	else if (!ft_strcmp(str, "rra"))
		ft_rra(s_a, com);
	else if (!ft_strcmp(str, "rrb"))
		ft_rrb(s_b, com);
	else if (!ft_strcmp(str, "rrr"))
		ft_rrr(s_a, s_b, com);
	else
		ft_error();
}

void		ft_instructions(t_stack **s_a, t_stack **s_b, t_list **com)
{
	char	*str;

	while (get_next_line(0, &str) > 0)
	{
		if (!ft_strcmp(str, "sa"))
			ft_sa(*s_a, com);
		else if (!ft_strcmp(str, "sb"))
			ft_sb(*s_b, com);
		else if (!ft_strcmp(str, "ss"))
			ft_ss(s_a, s_b, com);
		else if (!ft_strcmp(str, "pa"))
			ft_pa(s_a, s_b, com);
		else if (!ft_strcmp(str, "pb"))
			ft_pb(s_a, s_b, com);
		else if (str[0] == 'r')
			ft_r_intrs(s_a, s_b, com, str);
		else
			ft_error();
		free(str);
	}
}

void		ft_del_list(t_list **com)
{
	t_list	*node;
	t_list	*next;

	node = *com;
	while (node)
	{
		next = node->next;
		free(node->content);
		free(node);
		node = next;
	}
	*com = NULL;
}

void		ft_result(t_stack *s_a, t_stack *s_b)
{
	if (ft_check_stack(s_a) && s_b == NULL)
	{
		ft_putstr("\x1b[32m");
		write(1, "OK\n", 3);
		ft_putstr("\x1b[0m");
	}
	else
	{
		ft_putstr("\x1b[31m");
		write(1, "KO\n", 3);
		ft_putstr("\x1b[0m");
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
		ft_error_usage_checker();
	i = 0;
	s_a = NULL;
	s_b = NULL;
	com = NULL;
	while (av[++i])
	{
		nb = ft_atoi(av[i]);
		if (check_integer(av[i]) && check_doubles(s_a, nb))
			ft_stackpushback(&s_a, nb);
		else
			ft_error();
	}
	ft_instructions(&s_a, &s_b, &com);
	ft_del_list(&com);
	ft_result(s_a, s_b);
	return (0);
}

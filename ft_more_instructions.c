/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:52:14 by dlyubich          #+#    #+#             */
/*   Updated: 2018/01/31 18:52:14 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack **s_a, t_stack **s_b, t_list **com)
{
	ft_sa(*s_a, com);
	ft_sb(*s_b, com);
}

void	ft_rr(t_stack **s_a, t_stack **s_b, t_list **com)
{
	ft_ra(s_a, com);
	ft_rb(s_b, com);
}

void	ft_rrr(t_stack **s_a, t_stack **s_b, t_list **com)
{
	ft_rra(s_a, com);
	ft_rrb(s_b, com);
}

void	ft_error_usage(void)
{
	write(1, "Usage ./push_swap [args]\n", 25);
	exit(0);
}

void	ft_error_usage_checker(void)
{
	write(1, "Usage ./checker [args]\n", 23);
	exit(0);
}

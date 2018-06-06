/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:01:03 by dlyubich          #+#    #+#             */
/*   Updated: 2018/01/31 19:01:05 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct		s_stack
{
	int				nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				ft_sa(t_stack *s_a, t_list **com);
void				ft_sb(t_stack *s_b, t_list **com);
void				ft_pa(t_stack **s_a, t_stack **s_b, t_list **com);
void				ft_pb(t_stack **s_a, t_stack **s_b, t_list **com);
void				ft_ra(t_stack **s_a, t_list **com);
void				ft_rb(t_stack **s_b, t_list **com);
void				ft_rra(t_stack **s_a, t_list **com);
void				ft_rrb(t_stack **s_b, t_list **com);
int					check_integer(char *av);
int					ft_check_stack(t_stack *s_a);
int					check_doubles(t_stack *s_a, int nb);
void				ft_error();
t_stack				*ft_stacknew(int nb, t_stack *prev);
void				ft_stackpushback(t_stack **list, int nb);
void				ft_stackadd(t_stack **alst, t_stack *new);
void				ft_sort_b(t_stack **s_a, t_stack **s_b, int num,
					t_list **com);
void				ft_sort_a(t_stack **s_a, t_stack **s_b, int num,
					t_list **com);
void				ft_sort_trio_a(t_stack **s_a, t_stack **s_b, int num,
					t_list **com);
void				ft_sort_trio_b(t_stack **s_a, t_stack **s_b, int num,
					t_list **com);
int					ft_median(t_stack *tmp_a, int n, int fl);
int					count_stack(t_stack *s_a);
int					ft_divide(t_stack **s_a, t_stack **s_b, int pivot,
					t_list **com);
int					ft_divide_b(t_stack **s_b, t_stack **s_a, int pivot,
					t_list **com);
int					opti_main(t_list **list);
int					ft_optimus(t_list **list);
int					ft_a_sorted(t_stack **s_a, int num);
int					ft_b_sorted(t_stack **s_b, int num);
int					check_bigger_a(t_stack **s_a, int pivot);
int					check_bigger_b(t_stack **s_a, int pivot);
void				ft_rb_sb_pa_rrb_pa_pa(t_stack **s_a, t_stack **s_b,
					t_list **com);
void				ft_rb_sb_pa_pa_rrb_pa(t_stack **s_a, t_stack **s_b,
					t_list **com);
void				ft_papapa(t_stack **s_a, t_stack **s_b, t_list **com);
void				ft_ss(t_stack **s_a, t_stack **s_b, t_list **com);
void				ft_rr(t_stack **s_a, t_stack **s_b, t_list **com);
void				ft_rrr(t_stack **s_a, t_stack **s_b, t_list **com);
void				ft_error_usage(void);
void				ft_error_usage_checker(void);
#endif

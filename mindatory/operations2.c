/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:35:39 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/13 22:56:30 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*a1;
	t_stack	*a2;

	if (ft_lstsize(*a) < 2)
		return ;
	a1 = *a;
	a2 = *a;
	while (a2->next->next)
		a2 = a2->next;
	a2->next->next = a1;
	*a = a2->next;
	a2->next = NULL;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	t_stack	*b1;
	t_stack	*b2;

	if (ft_lstsize(*b) < 2)
		return ;
	b1 = *b;
	b2 = *b;
	while (b2->next->next)
		b2 = b2->next;
	b2->next->next = b1;
	*b = b2->next;
	b2->next = NULL;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_putstr_fd("rrr\n", 1);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*a1;
	t_stack	*b1;

	if (*b == NULL)
		return ;
	a1 = *a;
	b1 = *b;
	*b = b1->next;
	b1->next = a1;
	*a = b1;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*a1;
	t_stack	*b1;

	if (*a == NULL)
		return ;
	a1 = *a;
	b1 = *b;
	*a = a1->next;
	a1->next = b1;
	*b = a1;
	ft_putstr_fd("pb\n", 1);
}

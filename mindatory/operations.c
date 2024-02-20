/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:19:40 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/11 23:57:12 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*a1;
	t_stack	*a2;

	if (ft_lstsize(*a) < 2)
		return ;
	a1 = *a;
	a2 = (*a)->next;
	a1->next = a2->next;
	a2->next = a1;
	*a = a2;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	t_stack	*b1;
	t_stack	*b2;

	if (ft_lstsize(*b) < 2)
		return ;
	b1 = *b;
	b2 = (*b)->next;
	b1->next = b2->next;
	b2->next = b1;
	*b = b2;
	ft_putstr_fd("sb\n", 1);
}

void	ra(t_stack **a)
{
	t_stack	*a1;
	t_stack	*a2;

	if (ft_lstsize(*a) < 2)
		return ;
	a1 = *a;
	a2 = *a;
	while (a2->next)
		a2 = a2->next;
	*a = a1->next;
	a1->next = NULL;
	a2->next = a1;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	t_stack	*b1;
	t_stack	*b2;

	if (ft_lstsize(*b) < 2)
		return ;
	b1 = *b;
	b2 = *b;
	while (b2->next)
		b2 = b2->next;
	*b = b1->next;
	b1->next = NULL;
	b2->next = b1;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*a1;
	t_stack	*a2;

	if (ft_lstsize(*a) >= 2)
	{
		a1 = *a;
		a2 = *a;
		while (a2->next)
			a2 = a2->next;
		*a = a1->next;
		a1->next = NULL;
		a2->next = a1;
	}
	if (ft_lstsize(*b) >= 2)
	{
		a1 = *b;
		a2 = *b;
		while (a2->next)
			a2 = a2->next;
		*b = a1->next;
		a1->next = NULL;
		a2->next = a1;
	}
	ft_putstr_fd("rr\n", 1);
}

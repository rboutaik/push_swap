/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:33:08 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/12 00:28:37 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bring_to_top(t_stack **b, t_stack **elem, int pos)
{
	if (pos < ft_lstsize(*b) / 2)
	{
		while ((*b) != *elem)
			rb(b);
	}
	else
	{
		while (*b != *elem)
			rrb(b);
	}
}

void	ft_sort_all(t_stack **a, t_stack **b)
{
	t_vars	vars;
	t_stack	*max;
	t_stack	*bmax;

	max = NULL;
	bmax = NULL;
	(ft_vars_init(&vars, a), ft_push_a_to_b(a, b, vars));
	while (*b)
	{
		max = ft_get_max(b);
		bmax = ft_get_b_max(b);
		vars.maxpos = ft_getpos(b, max->index);
		vars.bmaxpos = ft_getpos(b, bmax->index);
		if (ft_abs((ft_lstsize(*b) / 2) - vars.maxpos)
			< ft_abs((ft_lstsize(*b) / 2) - vars.bmaxpos))
		{
			(ft_bring_to_top(b, &bmax, vars.bmaxpos), pa(a, b));
			if (*b == NULL)
				break ;
		}
		vars.maxpos = ft_getpos(b, max->index);
		(ft_bring_to_top(b, &max, vars.maxpos), pa(a, b));
		if ((*a)->next && (*a)->next->index < (*a)->index)
			sa(a);
	}
}

void	ft_sort_three(t_stack **a)
{
	t_stack	*max;

	max = ft_get_max(a);
	if (max == *a)
		ra(a);
	else if (max == (*a)->next)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	ft_sort_for(t_stack **a, t_stack **b, int size)
{
	int		maxpos;
	t_stack	*max;

	max = ft_get_max(a);
	maxpos = ft_getpos(a, max->index);
	while (*a != max)
	{
		if (maxpos <= size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(b, a);
	ft_sort_three(a);
	pa(a, b);
	ra(a);
}

void	ft_sort_five(t_stack **a, t_stack **b, int size)
{
	int		maxpos;
	t_stack	*max;

	max = ft_get_max(a);
	maxpos = ft_getpos(a, max->index);
	while (*a != max)
	{
		if (maxpos <= size / 2)
			ra(a);
		else
			rra(a);
	}
	(pb(b, a), max = ft_get_max(a));
	maxpos = ft_getpos(a, max->index);
	while (*a != max)
	{
		if (maxpos <= size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(b, a);
	ft_sort_three(a);
	(pa(a, b), ra(a));
	(pa(a, b), ra(a));
}

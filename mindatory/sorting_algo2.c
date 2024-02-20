/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:06:21 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/12 00:10:52 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *a)
{
	t_stack	*tmp;
	int		v;

	if (a == NULL)
		return (1);
	v = a->value;
	tmp = a->next;
	while (tmp)
	{
		if (tmp->value < v)
			return (0);
		v = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

t_stack	*ft_get_max(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*max;

	if (!*a)
		return (NULL);
	tmp = *a;
	max = *a;
	while (tmp)
	{
		if (tmp->index > max->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_check_more(t_stack **a, int chunksize)
{
	t_stack	*a1;

	a1 = *a;
	while (a1)
	{
		if (a1->index < chunksize)
			return (1);
		a1 = a1->next;
	}
	return (0);
}

t_stack	*ft_get_b_max(t_stack **b)
{
	t_stack	*max;
	t_stack	*bmax;
	t_stack	*b1;

	max = ft_get_max(b);
	bmax = NULL;
	b1 = (*b);
	while (b1)
	{
		if (b1->index < max->index)
		{
			if (bmax == NULL || b1->index > bmax->index)
				bmax = b1;
		}
		b1 = b1->next;
	}
	if (bmax == NULL)
		return (*b);
	else
		return (bmax);
}

int	ft_getpos(t_stack **b, int index)
{
	int		pos;
	t_stack	*b1;

	pos = 0;
	b1 = *b;
	while (b1 && b1->index != index)
	{
		pos++;
		b1 = b1->next;
	}
	return (pos);
}

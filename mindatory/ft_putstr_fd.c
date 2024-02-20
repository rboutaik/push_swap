/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:47:16 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/13 22:39:01 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	size;

	size = 0;
	if (s == NULL || fd < 0 || fd > 1023)
		return ;
	while (s[size])
		size++;
	write(fd, s, size);
}

void	ft_sorting(t_stack **a, t_stack **b)
{
	int		size;

	size = ft_lstsize(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		ft_sort_three(a);
	else if (size == 4)
		ft_sort_for(a, b, size);
	else if (size == 5)
		ft_sort_five(a, b, size);
	else
		ft_sort_all(a, b);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	ft_vars_init(t_vars *vars, t_stack **a)
{
	vars->size = ft_lstsize(*a);
	if (vars->size >= 200)
		vars->diviser = 9;
	else
		vars->diviser = 5;
	vars->chunksize = vars->size / vars->diviser;
}

void	ft_push_a_to_b(t_stack **a, t_stack **b, t_vars vars)
{
	while (*a)
	{
		if ((*a)->index < vars.chunksize)
		{
			pb(b, a);
			if ((*a) == NULL)
				break ;
			if ((*b)->index >= vars.chunksize
				- ((vars.size / vars.diviser) / 2))
			{
				if (ft_check_more(a, vars.chunksize)
					&& (*a)->index >= vars.chunksize)
					rr(a, b);
				else
					rb(b);
			}
		}
		else
			ra(a);
		if (!ft_check_more(a, vars.chunksize))
			vars.chunksize += vars.size / vars.diviser;
	}
}

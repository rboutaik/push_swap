/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:30:18 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/12 00:02:46 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}

void	ft_error(t_stack *a)
{
	ft_free_stack(a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_check_dup(t_stack *a, int nb)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->value == nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_stack	*ft_parsing(char **av, int ac)
{
	int		i;
	int		nb;
	char	**s;
	t_stack	*a;

	a = NULL;
	while (ac > 1)
	{
		s = ft_split(av[ac - 1], ' ');
		if (*av[ac - 1] == '\0' || *s == NULL)
			ft_error(a);
		i = 0;
		while (s[i])
			i++;
		while (--i >= 0)
		{
			nb = ft_atoi(s[i]);
			if (ft_check_dup(a, nb))
				ft_error(a);
			(free(s[i]), ft_lstadd_front(&a, ft_lstnew(nb, 0)));
		}
		free(s);
		ac--;
	}
	return (a);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	if (ac == 1)
		return (0);
	a = ft_parsing(av, ac);
	if (ft_is_sorted(a))
		return (ft_free_stack(a), 0);
	ft_sorting(&a, &b);
	ft_free_stack(a);
	return (0);
}

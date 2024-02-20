/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:44:22 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/11 23:55:09 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	ft_putstr_fd("ss\n", 1);
}

long	ft_atoi(const char *str)
{
	int				i;
	int				signe;
	long			nb;

	i = 0;
	signe = 1;
	nb = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			signe *= -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + str[i++] - 48;
		if ((nb > 2147483647 && signe == 1) || (nb > 2147483648 && signe == -1))
			(ft_putstr_fd("Error\n", 2), exit(1));
	}
	if (((str[i] && (!(str[i] >= 48 && str[i] <= 57))) && str[i] != ' ')
		|| (!(str[i - 1] >= 48 && str[i - 1] <= 57) && str[i - 1] != ' '))
		(ft_putstr_fd("Error\n", 2), exit(1));
	return (nb * signe);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:47:16 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/12 00:49:59 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

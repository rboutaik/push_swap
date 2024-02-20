/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:44:33 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/13 22:27:46 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	ft_in_op(char **op, char *str)
{
	int	pos;

	pos = 0;
	while (*op)
	{
		if (!ft_strncmp(*op, str, ft_strlen(*op) + 1))
			return (pos);
		op++;
		pos++;
	}
	return (-1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_init_func(t_func_array *func)
{
	func[0] = sa;
	func[1] = sb;
	func[2] = ss;
	func[3] = pa;
	func[4] = pb;
	func[5] = ra;
	func[6] = rb;
	func[7] = rr;
	func[8] = rra;
	func[9] = rrb;
	func[10] = rrr;
}

void	ft_call_checker(t_stack **a, t_stack **b)
{
	char			*str;
	char			**op;
	t_func_array	func[11];
	int				pos;

	str = NULL;
	op = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	ft_init_func(func);
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		pos = ft_in_op(op, str);
		free(str);
		if (pos == -1)
		{
			ft_free(op);
			ft_error(*a, *b);
		}
		func[pos](a, b);
	}
	ft_free(op);
}

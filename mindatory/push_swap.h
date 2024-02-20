/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:30:22 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/12 00:35:29 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_vars
{
	int	size;
	int	bmaxpos;
	int	maxpos;
	int	chunksize;
	int	diviser;
}	t_vars;
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int value, int index);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_parsing(char **av, int ac);
int		ft_check_dup(t_stack *a, int nb);
void	ft_error(t_stack *a);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
int		ft_is_sorted(t_stack *a);
void	ft_sorting(t_stack **a, t_stack **b);
t_stack	*ft_get_max(t_stack **a);
void	ft_sort_all(t_stack **a, t_stack **b);
t_stack	*ft_get_b_max(t_stack **b);
int		ft_getpos(t_stack **b, int index);
void	ft_sort_for(t_stack **a, t_stack **b, int size);
void	ft_sort_three(t_stack **a);
void	ft_putstr_fd(char *s, int fd);
int		ft_abs(int a);
void	ft_vars_init(t_vars *vars, t_stack **a);
int		ft_check_more(t_stack **a, int chunksize);
void	ft_sort_five(t_stack **a, t_stack **b, int size);
void	ft_push_a_to_b(t_stack **a, t_stack **b, t_vars vars);

#endif
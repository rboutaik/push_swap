/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:35:01 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/13 22:29:25 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 24

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef void	(*t_func_array)(t_stack **a, t_stack **b);

size_t	ft_strlen(const char *c);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_getstr(char *s);
char	*ft_getsecond(char *s);
char	*ft_allocat2(int size, char **s1, char **s2);
char	*ft_allocat(char **str, int s);
int		f(char **str, char **buffer, int size);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int value, int index);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_parsing(char **av, int ac);
int		ft_check_dup(t_stack *a, int nb);
void	ft_error(t_stack *a, t_stack *b);
void	sa(t_stack **a, t_stack **b);
void	sb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a, t_stack **b);
void	rb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, t_stack **b);
void	rrb(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
int		ft_is_sorted(t_stack *a);
void	ft_putstr_fd(char *s, int fd);
void	ft_call_checker(t_stack **a, t_stack **b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_in_op(char **op, char *str);

#endif
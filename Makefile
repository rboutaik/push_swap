# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 13:30:24 by rboutaik          #+#    #+#              #
#    Updated: 2024/02/12 00:47:12 by rboutaik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap


BNAME = checker

PATH = ./mindatory/

BPATH = ./bonus/

HEADER = $(PATH)push_swap.h

BHEADER = $(HPATH)checker.h

CFILES = $(PATH)push_swap.c $(PATH)ft_split.c $(PATH)ft_atoi.c $(PATH)ft_lstadd_front.c $(PATH)ft_lstnew.c $(PATH)ft_lstsize.c \
	$(PATH)operations.c $(PATH)sorting_algo.c $(PATH)operations2.c $(PATH)ft_putstr_fd.c $(PATH)sorting_algo2.c

BCFILES = $(BPATH)checker.c $(BPATH)ft_split.c $(BPATH)ft_atoi.c $(BPATH)ft_lstadd_front.c $(BPATH)ft_lstnew.c $(BPATH)ft_lstsize.c \
	$(BPATH)operations.c $(BPATH)operations2.c $(BPATH)ft_putstr_fd.c $(BPATH)ft_checker_utils.c $(BPATH)get_next_line.c $(BPATH)get_next_line_utils.c

OFILES = $(CFILES:.c=.o)

BOFILES = $(BCFILES:.c=.o)

all : $(NAME)

$(NAME) : $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

$(BNAME) : $(BOFILES)
	$(CC) $(CFLAGS) $(BOFILES) -o $(BNAME)

$(PATH)%.o : $(PATH)%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(BNAME)

clean :
	rm -f $(OFILES) $(BOFILES)

fclean : clean
	rm -f $(NAME) $(BNAME)

re : fclean all
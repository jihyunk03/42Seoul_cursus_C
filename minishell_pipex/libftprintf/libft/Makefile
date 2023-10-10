# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 15:14:18 by jiyunlee          #+#    #+#              #
#    Updated: 2023/08/11 15:14:43 by jiyunlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= \
		  ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	\
		  ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c		\
		  ft_memcpy.c	ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	\
		  ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c	\
		  ft_strncmp.c	ft_memchr.c		ft_memcmp.c		ft_strnstr.c	\
		  ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c		\
		  ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c		\
		  ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	\
		  ft_putendl_fd.c	ft_putnbr_fd.c								\
		  ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c \
		  ft_lstadd_back.c	ft_lstdelone.c		ft_lstclear.c	ft_lstiter.c \
		  ft_lstmap.c

NAME	= libft.a
OBJS	= ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
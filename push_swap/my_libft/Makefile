NAME	= lib_jihykim2.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar -rcs

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strcmp.c ft_strncmp.c \
		  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		  ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		  ft_calloc.c ft_strdup.c ft_strmapi.c ft_striteri.c\
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		  ft_printf.c ft_printf_utils.c \
		  get_next_line.c get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	@$(AR) $@ $^
	@echo $(YELLOW) "✭  [ my_libft ]	Ready to use lib_jihykim2.a" $(RESET)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@$(RM) $(OBJS)

fclean	:
	@$(MAKE) clean
	@$(RM) $(NAME)

re		:
	@$(MAKE) fclean
	@$(MAKE) all

RESET	=	"\x1b[0m"
GREY	=	"\x1b[30m"
RED		=	"\x1b[31m"
GREEN	=	"\x1b[32m"
YELLOW	=	"\x1b[33m"
BLUE	=	"\x1b[34m"
PURPLE	=	"\x1b[35m"
CYAN	=	"\x1b[36m"
WHITE	=	"\x1b[37m"

.PHONY	: all clean fclean re

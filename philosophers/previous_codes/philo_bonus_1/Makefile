NAME		= philo_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=thread -g3
RM			= rm -f

SRCS_DIR	= ./srcs/
SRCS		= philo_0_bonus.c
OBJS		= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

all		: $(NAME)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo $(GREEN) "⚡︎	[ philo_bonus ]	Ready to use philo_bonus" $(RESET)

clean	:
	@$(RM) $(OBJS)
	@echo $(GREEN) "⚡︎	[ philo_bonus ]	Removed Object files" $(RESET)

fclean	: clean
	@$(RM) $(NAME)
	@echo $(GREEN) "⚡︎	[ philo_bonus ]	Removed philo_bonus" $(RESET)

re		:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY	: all clean fclean re

RESET	= "\x1b[0m"
GREY	= "\x1b[30m"
RED		= "\x1b[31m"
GREEN	= "\x1b[32m"
YELLOW	= "\x1b[33m"
BLUE	= "\x1b[34m"
PURPLE	= "\x1b[35m"
CYAN	= "\x1b[36m"
WHITE	= "\x1b[37m"

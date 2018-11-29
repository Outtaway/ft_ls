# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:46:20 by kpshenyc          #+#    #+#              #
#    Updated: 2018/11/21 14:16:13 by kpshenyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

OK_COLOR = \x1b[32;01m
WARN_COLOR  = \033[0;33m
ERROR_COLOR = \x1b[31;01m
NO_COLOR  = \033[m

NAME = libftprintf.a

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

SRC = libft/*.c srcs/*.c

SRO = obj/*.o

I = libft/libft.h includes/ft_printf.h libft/includes/type_limits.h

all: $(NAME)

$(NAME):
	@echo "$(WARN_COLOR)-----------------------------------------------------------"
	@gcc -c $(FLAGS) $(SRC) -I $(I)
	@mv *.o obj/
	@echo "$(NO_COLOR)\tCompiling srcs-files $(OK_COLOR)                [done]"
	@ar rc $(NAME) $(SRO)
	@echo "$(NO_COLOR)\tCreating libftprintf static library $(OK_COLOR) [done]"
	@echo "$(WARN_COLOR)-----------------------------------------------------------"
clean:
	@echo "$(ERROR_COLOR)-----------------------------------------------------------"
	@rm -f obj/*.o libft/*.o
	@echo "$(NO_COLOR)\tDeleting all object-files $(OK_COLOR)           [done]"
	@echo "$(ERROR_COLOR)-----------------------------------------------------------"

fclean: clean
	@echo "$(ERROR_COLOR)-----------------------------------------------------------"
	@rm -f $(NAME) $(LIBFT)
	@echo "$(NO_COLOR)\tDeleting libftprintf static library $(OK_COLOR) [done]"
	@echo "$(ERROR_COLOR)-----------------------------------------------------------"

re: fclean all

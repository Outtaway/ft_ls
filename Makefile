.PHONY: all clean fclean re

NAME = ft_ls

LIBFTPRINTF = libftprintf/libftprintf.a

I = includes/

I2 = libftprintf/includes/

SRCS = srcs/ft_ls.c\
		srcs/main_loop.c\
		srcs/list.c\
		srcs/sorts.c\
		srcs/process_files.c\
		srcs/process_dirs.c\
		obj/handlers.o\

OBJ = obj/ft_ls.o\
		obj/main_loop.o\
		obj/list.o\
		obj/sorts.o\
		obj/process_files.o\
		obj/process_dirs.o\
		obj/handlers.o\

all: $(NAME)

$(NAME): ft_ls_obj main_loop_obj list_obj sorts_obj process_files_obj process_dirs_obj handlers_obj
	gcc -o $(NAME) $(OBJ) $(LIBFTPRINTF)

ft_ls_obj:
	gcc -c $(FLAGS) srcs/ft_ls.c -I $(I) -I $(I2)
	mv ft_ls.o obj/

main_loop_obj:
	gcc -c $(FLAGS) srcs/main_loop.c -I $(I) -I $(I2)
	mv main_loop.o obj/

list_obj:
	gcc -c $(FLAGS) srcs/list.c -I $(I) -I $(I2)
	mv list.o obj/

sorts_obj:
	gcc -c $(FLAGS) srcs/sorts.c -I $(I) -I $(I2)
	mv sorts.o obj/

process_files_obj:
	gcc -c $(FLAGS) srcs/process_files.c -I $(I) -I $(I2)
	mv process_files.o obj/

process_dirs_obj:
	gcc -c $(FLAGS) srcs/process_dirs.c -I $(I) -I $(I2)
	mv process_dirs.o obj/

handlers_obj:
	gcc -c $(FLAGS) srcs/handlers.c -I $(I) -I $(I2)
	mv handlers.o obj/

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

lre:
	@make -C libftprintf re

lclean:
	@make -C libftprintf clean

lfclean:
	@make -C libftprintf fclean

re: fclean all
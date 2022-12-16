CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SOURCES =	ft_char.c				\
			ft_hex.c				\
			ft_int.c				\
			ft_new_list.c			\
			ft_percentage.c			\
			ft_pointer_edgecase.c	\
			ft_pointer.c			\
			ft_print_hex.c			\
			ft_print_int.c			\
			ft_print_uns_int.c		\
			ft_printf.c				\
			ft_read_spec.c			\
			ft_string.c				\
			ft_uns_int_null.c		\
			ft_uns_int.c		\
			ft_util.c
OBJECTS = $(SOURCES:.c=.o)
MAKE = make
LIBFT_PATH = ./libft/

all : subsystem $(NAME)

subsystem :
	$(MAKE) -C libft

$(NAME) : $(OBJECTS)
	ar cr $@ $(OBJECTS) $(LIBFT_PATH)*.o

bonus : all

.PHONY : clean fclean re

clean :
	rm -f $(OBJECTS) $(LIBFT_PATH)*.o

fclean : clean
	rm -f $(NAME) $(LIBFT_PATH)libft.a

re : fclean all

SRCS	:=	main.c				\
			ft_split.c			\
			map_checker.c		\
			map_parser.c		\
			map_solve_check.c	\
			so_long_utils.c		\
			map_gen.c			\
			move_wasd.c

SRCS_D	:=	srcs/

OBJS_D	:=	objs/

OBJS	:=	$(SRCS:%.c=$(OBJS_D)%.o)

HEAD_D	:=	.

CFLAGS	:=	-Wall -Wextra -Werror

AR	:=	ar rcs

NAME	:=	so_long

all	:	$(NAME)

$(NAME)	:	$(OBJS_D) $(OBJS) mlx Makefile
			$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS)	:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD)
			$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(OBJS_D)	:
			@mkdir -p $(OBJS_D)

mlx			:
			make -C mlx_linux

clean	:
			$(RM) -r $(OBJS) $(OBJS_D) $(OBJS_B)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY: all bonus clean fclean re
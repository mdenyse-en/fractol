NAME	= fractol

SORCES	= ft_utils.c ft_threads.c ft_hints.c fractol.c ft_parc_param.c ft_get_fact.c ft_colors.c ft_interface.c ft_keyboard.c ft_minimap.c ft_mouse.c ft_get_fact_other.c

DIRS	= ./src

DIRL	= ./libft

DIRM	= ./mlx

SRC		= $(addprefix $(DIRS)/,$(SORCES))

OBJ		= $(SRC:.c=.o)

HEAD	= $(DIRS)/fractol.h

LIB		= $(DIRL)/libft.a

MLX		= $(DIRM)/libmlx.a

CC		= gcc

CFLAG	= -Wall -Wextra -Werror

RM		= rm -f

%.o:	%.c $(HEAD)
	$(CC) $(CFLAG) -c -o $@ $<

$(NAME):	$(OBJ) $(HEAD)
	$(MAKE) -C $(DIRL)
	$(CC) $(CFLAG) $(LIB) $(MLX) $(SRC) -L. -Lmlx -lmlx -framework OpenGL -framework AppKit -o fractol

	@echo $(NAME) is compiled!

all: $(NAME)

clean:
	$(MAKE) clean -C $(DIRL)	
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(DIRL)
	$(RM) $(NAME)

re: fclean all

################### Product NAME ############################
NAME = cube3d

################ Compiler and FLAGS #########################

CC = gcc -v

#CFLAGS = -Wall -Werror -Wextra

# first init should have this command --> sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev

####################### FILE ################################

MAIN_SRC = ./src/main.c

UTILL_FILE = init_data.c put_error.c

RENDER_FILE = render_main.c map_render.c draw_func.c

PARSER_FILE = parser_main.c map_reader.c

CONTROL_FILE = control_main.c key_hook.c

LIBFT_FILE = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
ft_isprint.c ft_itoa.c ft_lstadd_back.c	ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
ft_substr.c ft_tolower.c ft_toupper.c

####################### DIR ################################
RENDER_DIR = ./src/render/
PARSER_DIR = ./src/parser/
CONTROL_DIR = ./src/control/
UTILL_DIR = ./src/utill/
LIBFT_DIR = ./src/utill/libft/

###################### DIR and PATH #########################
RENDER_SRC = $(addprefix $(RENDER_DIR), $(RENDER_FILE))
PARSER_SRC = $(addprefix $(PARSER_DIR), $(PARSER_FILE))
CONTROL_SRC = $(addprefix $(CONTROL_DIR), $(CONTROL_FILE))
UTILL_SRC = $(addprefix $(UTILL_DIR), $(UTILL_FILE))
LIBFT_SRC = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

###################### to compile mlx library system condition #########################

UNAME = $(shell uname)
ifeq ($(UNAME), Darwin)
MLX_DIR = ./minilibx/mlx-mac/
MLXFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@
else
MLXFLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz
MLX_DIR = ./minilibx/mlx-linux/
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I$(MLX_DIR) -O3 -c $< -o $@
endif

########################################################################################

RM = rm -rf

SRC =  $(RENDER_SRC) $(CONTROL_SRC) $(UTILL_SRC) $(LIBFT_SRC) $(MAIN_SRC)

#$(PARSER_SRC)

OBJ = $(SRC:.c=.o)

all : $(NAME)

MLX_LIB = $(MLX_DIR)libmlx.a

$(NAME) : $(OBJ) 
ifeq ($(shell test -r $(MLX_LIB) && echo yes), yes)
		@echo "mlx library exists"
else
		@echo "mlx library does not exist"
		make mlx_init
endif
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o ${NAME}

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

mlx_init :
	make -C $(MLX_DIR)

mlx_clean :
	make clean -C $(MLX_DIR)

re : fclean all

.PHONY: all clean fclean re bonus

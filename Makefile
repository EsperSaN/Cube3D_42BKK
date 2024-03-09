NAME = cub3d

CC = clang

CLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/

LIB_DIR = ./lib/
LIB_MLX_DIR = $(LIB_DIR)MLX42_codam/
LIB_FT_DIR = $(LIB_DIR)libft/
LIB_FILE = $(LIB_FT_DIR)libft.a $(LIB_MLX_DIR)build/libmlx42.a

LIB_LINK = -L$(LIB_FT_DIR) -L$(LIB_MLX_DIR)
INCLUDE_FLAG = -I$(LIB_FT_DIR) -I$(LIB_MLX_DIR)/include

UNAME = $(shell uname)
ifeq ($(UNAME), Linux)
MLXLINK_FLAG = -ldl -lglfw3 -pthread -lm
else ifeq ($(UNAME), Darwin)
MLXLINK_FLAG = -framework Cocoa -framework OpenGL -framework IOKit -L/opt/homebrew/opt/glfw/lib -lglfw
else
MLXLINK_FLAG = -lglfw3 -lopengl32 -lgdi32
endif

SRCS = ./src/main.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $@

all : libft libmlx $(NAME)

libft :
	make -C $(LIB_FT_DIR)

libmlx :
	@cmake $(LIB_MLX_DIR) -B $(LIB_MLX_DIR)build
	make -C $(LIB_MLX_DIR)/build -j4

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LIB_FILE) $(LIB_LINK) $(MLXLINK_FLAG) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	make -C $(LIB_FT_DIR) fclean
	make -C $(LIB_MLX_DIR)build/ clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re libmlx
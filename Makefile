
# >=> >=> >=> >=> INITIAL CONFIG <=< <=< <=< <=<
CC = cc
FLAGS = -Wall -Wextra -Werror -g3
NAME = so_long
MKDIR = mkdir -p

# >=> >=> >=> CONFIG PATH AND FILES <=< <=< <=<
SRCS_PATH = ./srcs
LIBS = ./libs
HEADERS_PATH = ./includes
HEADERS_FILES = so_long.h
SRCS_FILES = main.c init_map.c start_matrix_validation.c message_sucess_or_error.c validate_game.c clean_matrix.c \
ft_flood_fill.c

OBJS_PATH = ./objs
INCLUDES = $(addprefix $(HEADERS_PATH)/, $(HEADERS_FILES))
SOURCES = $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))
OBJS_FILES = $(patsubst %.c, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_FILES))

# >=> >=> >=> >=> >=> LIBFT <=< <=< <=< <=< <=<
LIBFT_NAME = libft.a
LIBFT_PATH = $(LIBS)/libft
LIBFT_HEADER_PATH = $(LIBFT_PATH)/includes
LIBFT_LIB = $(LIBFT_PATH)/$(LIBFT_NAME)
LIBFT_CC = -I $(LIBFT_HEADER_PATH) -L$(LIBFT_PATH) -lft

# >=> >=> >=> >=> >=> MLX42 <=< <=< <=< <=< <=<
MLX42_REPO = https://github.com/codam-coding-college/MLX42.git
MLX42_LIB_NAME = libmlx42.a
MLX42_PATH = $(LIBS)/MLX42
MLX42_HEADER_PATH = $(MLX42_PATH)/include
MLX42_BUILD_PATH = $(MLX42_PATH)/build
MLX42_LIB = $(MLX42_BUILD_PATH)/$(MLX42_LIB_NAME)
MLX42_LIBS = -lmlx42 -ldl -lglfw -pthread -lm
MLX42_CC = -I $(MLX42_HEADER_PATH) -L $(MLX42_BUILD_PATH) $(MLX42_LIBS)

# >=> >=> >=> >=> >=> COLORS <=< <=< <=< <=< <=<
BLUE				=	\033[0;	34m
MAGENTA				=	\033[0;35m
GREEN				=	\033[0;32m
DEFAULT 			=	\033[0:0m

# >=> >=> >=> >=> >=> RULES <=< <=< <=< <=< <=<
.PHONY: all bonus clean fclean re clean_mlx

all: prep $(NAME)

prep:
	@$(MKDIR) $(SRCS_PATH) $(OBJS_PATH)

$(NAME): $(MLX42_LIB) $(LIBFT_LIB) $(OBJS) $(INCLUDES)
	@ $(CC) -o $(NAME) $(OBJS) -I $(HEADERS_PATH) \
	$(MLX42_CC) $(LIBFT_CC) $(FLAGS) -L$(LIBFT_PATH) -lft
	@ printf "$(GREEN) $(NAME) $(DEFAULT) successfully generated\n"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c $(INCLUDES)
	@ printf "$(MAGENTA)$< $(BLUE)->$(GREEN) $@$(DEFAULT)\n"
	@ $(CC) -c $<                                            \
	-I $(HEADERS_PATH)                                       \
	-I $(MLX42_HEADER_PATH)                                  \
	-I $(LIBFT_HEADER_PATH)                                  \
	-o $@ $(FLAGS)
clean:
	@ make -s -C $(LIBFT_PATH) clean
	@ rm -rf $(OBJS)

fclean: clean clean_mlx
	@ make -s -C $(LIBFT_PATH) fclean
	@ rm -rf $(NAME)

re: fclean all

$(LIBFT_LIB): $(LIBFT_PATH)
	@ make -s -C $(LIBFT_PATH)

$(MLX42_LIB): $(MLX42_PATH)
	@ cd $(MLX42_PATH) &&       \
	  cmake -B build &&         \
	  cmake --build build -j4

$(MLX42_PATH):
	@ git clone $(MLX42_REPO) $(MLX42_PATH)
	@ cd $@ &&                                 \
	sed -i "s/(VERSION 3.18.0)/(VERSION 3.16.0)/" CMakeLists.txt

# >=> >=> >=> >=> >=> clean MLX42 <=< <=< <=< <=< <=<
clean_mlx:
	@ rm -rf $(MLX42_PATH)
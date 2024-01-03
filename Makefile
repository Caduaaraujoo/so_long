HEADERS_PATH = ./includes/
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
LIBS_PATH = ./libs/
BINS_PATH = ./bin/
MLX42_DIR = MLX42
MLX42_REPO = https://github.com/codam-coding-college/MLX42.git

CC = gcc
FLAGS = -Wall -Wextra -Werror -I $(HEADERS_PATH)

RM = rm -rf
MKDIR = mkdir -p

NAME = $(BINS_PATH)so_long
LIBFT_A = $(LIBS_PATH)libft.a
SRC_FILES = main.c
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

all: make_dir $(NAME)

$(LIBFT_A):
	@make -C $(LIBS_PATH)libft

make_dir:
	@$(MKDIR) $(BINS_PATH)

$(NAME): $(LIBFT_A) $(OBJECTS) $(MLX42_DIR)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -L $(LIBS_PATH) -lft

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(FLAGS) -c $< -o $@

$(MLX42_DIR):
	@if [ ! -d $(LIBS_PATH)$(MLX42_DIR) ]; then \
		echo "Cloning MLX42 repository..."; \
		git clone $(MLX42_REPO) $(LIBS_PATH)$(MLX42_DIR); \
		cd $(LIBS_PATH)$(MLX42_DIR) && sed -i "s/(VERSION 3.18.0)/(VERSION 3.16.0)/" CMakeLists.txt; \
	else \
		echo "$(MLX42_DIR) already exists. Skipping cloning."; \
	fi

clean:
	@$(RM) $(OBJECTS)
	@cd $(LIBS_PATH)libft/ && $(MAKE) $@


fclean: clean
	@$(RM) $(NAME)
	@cd $(LIBS_PATH)libft/ && $(MAKE) $@


re: fclean all

.PHONY: all run clean fclean re make_dir

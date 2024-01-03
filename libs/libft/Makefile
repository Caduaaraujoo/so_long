
HEADERS_PATH = ../../includes/
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
LIBS_PATH = ../

CC = gcc
FLAGS = -Wall -Wextra -Werror

RM = rm -rf
MKDIR = mkdir -p


NAME = libft.a
SRC_FILES = \
    ft_bzero.c  ft_isalnum.c  ft_isalpha.c  ft_isascii.c  ft_isdigit.c  ft_isprint.c  ft_memset.c  ft_strlen.c  \
    ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
    ft_memchr.c ft_memcmp.c ft_strnstr.c  ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
    ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c\
    ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))


all: prep $(NAME)

prep:
	@$(MKDIR) $(SRCS_PATH) $(OBJS_PATH)

$(NAME): $(OBJECTS)
	@ar -rcs $(LIBS_PATH)$(NAME) $(OBJECTS)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@$(CC) $(FLAGS) -I $(HEADERS_PATH) -c $< -o $@

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(LIBS_PATH)$(NAME)

re: fclean all

.PHONY:	all clean fclean re

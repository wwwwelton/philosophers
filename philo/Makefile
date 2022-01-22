SOURCES_FILES	=	actions.c exit.c ft_atoi.c ft_atol.c ft_isdigit.c
SOURCES_FILES	+=	init.c main.c thread_utils.c time_utils.c utils.c
SOURCES_FILES	+=	philo_utils.c

SOURCES_DIR		=	sources

OBJ_DIR			=	objects

HEADER			=	$(SOURCES_DIR)/philosophers.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	philo

CC				=	gcc
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror
LDFLAGS			=	-pthread

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				all

$(NAME):			$(OBJ_DIR) $(OBJECTS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re bonus

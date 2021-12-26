SOURCES_FILES	=	main.c init_philo.c utils.c ft_atoi.c debug.c
SOURCES_FILES	+=	exit.c actions.c

SOURCES_BONUS	=

SOURCES_DIR		=	sources
BONUS_DIR		=

OBJ_DIR			=	objects

HEADER			=	$(SOURCES_DIR)/philosophers.h
HEADER_BONUS	=	$(BONUS_DIR)/philosophers.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTS_BONUS	=	$(BONUS_FILES:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	philo
NAME_BONUS		=	philo_bonus

CC				=	gcc
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror -g3
LDFLAGS			=	-pthread

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o:		$(BONUS_DIR)/%.c $(HEADER_BONUS)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJECTS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(LDFLAGS) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(OBJ_DIR) $(OBJECTS_BONUS) $(HEADER_BONUS)
					$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) $(LDFLAGS) -o $(NAME_BONUS)

$(LIBFT):
					$(MAKE) -C $(LIBFT_PATH) bonus

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re bonus

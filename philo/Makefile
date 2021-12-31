SOURCES_FILES	=	actions.c exit.c ft_atoi.c ft_atol.c ft_isdigit.c
SOURCES_FILES	+=	init.c main.c thread_utils.c time_utils.c utils.c

SOURCES_BONUS	=	actions_bonus.c exit_bonus.c ft_atoi_bonus.c
SOURCES_BONUS	+=	ft_atol_bonus.c ft_isdigit_bonus.c init_bonus.c
SOURCES_BONUS	+=	main_bonus.c philosophers_bonus.h thread_utils_bonus.c
SOURCES_BONUS	+=	time_utils_bonus.c utils_bonus.c process_utils_bonus.c

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus

OBJ_DIR			=	objects

HEADER			=	$(SOURCES_DIR)/philosophers.h
HEADER_BONUS	=	$(BONUS_DIR)/philosophers_bonus.h

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

bonus:				fclean $(NAME_BONUS)

$(NAME):			$(OBJ_DIR) $(OBJECTS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME)

$(NAME_BONUS):		$(OBJ_DIR) $(OBJECTS_BONUS) $(HEADER_BONUS)
					$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LDFLAGS) -o $(NAME_BONUS)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re bonus

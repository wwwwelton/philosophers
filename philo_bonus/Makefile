SOURCES_BONUS	=	actions_bonus.c exit_bonus.c ft_atoi_bonus.c
SOURCES_BONUS	+=	ft_atol_bonus.c ft_isdigit_bonus.c init_bonus.c
SOURCES_BONUS	+=	main_bonus.c time_utils_bonus.c utils_bonus.c
SOURCES_BONUS	+=	process_utils_bonus.c

BONUS_DIR		=	sources_bonus

OBJ_DIR			=	objects

HEADER_BONUS	=	$(BONUS_DIR)/philosophers_bonus.h

BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS_BONUS	=	$(BONUS_FILES:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME_BONUS		=	philo_bonus

CC				=	gcc
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror
LDFLAGS			=	-pthread

$(OBJ_DIR)/%.o:		$(BONUS_DIR)/%.c $(HEADER_BONUS)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME_BONUS)

bonus:				all

$(NAME_BONUS):		$(OBJ_DIR) $(OBJECTS_BONUS) $(HEADER_BONUS)
					$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LDFLAGS) -o $(NAME_BONUS)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:02:29 by ale-tron          #+#    #+#              #
#    Updated: 2024/09/02 16:08:39 by cle-tron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# ═══ COLORS ══════════════════════════════════════════════════════════════════#
GREEN = \033[0;32m
RED =\033[0;31m
WHITE =\033[0;37m

# ═══ COMPILATE ═══════════════════════════════════════════════════════════════#
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR		= ar -rcs
MKDIR	= mkdir -p

# ═══ DIRECTORIES ═════════════════════════════════════════════════════════════#
INC_DIR	= inc/
SRC_DIR	= src/
OBJ_DIR	= obj/

IS_DIR	= is/
STR_DIR	= str/
MEM_DIR	= mem/
PUT_DIR	= put/
TO_DIR	= to/
GNL_DIR	= gnl/

# ═══ SOURCES ═════════════════════════════════════════════════════════════════#
IS_FILES	= ft_isalpha ft_isalnum ft_isascii ft_isdigit ft_isprint ft_isspace
STR_FILES	= ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strncmp ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_strlen ft_strnstr ft_strmapi ft_striteri
MEM_FILES	= ft_bzero ft_memset ft_memcpy ft_memmove ft_memchr ft_memcmp ft_calloc
PUT_FILES	= ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
TO_FILES	= ft_tolower ft_toupper ft_atoi ft_itoa
GNL_FILES	= get_next_line get_next_line_utils

SRC_FILES+=$(addprefix $(IS_DIR),$(IS_FILES))
SRC_FILES+=$(addprefix $(STR_DIR),$(STR_FILES))
SRC_FILES+=$(addprefix $(MEM_DIR),$(MEM_FILES))
SRC_FILES+=$(addprefix $(PUT_DIR),$(PUT_FILES))
SRC_FILES+=$(addprefix $(TO_DIR),$(TO_FILES))
SRC_FILES+=$(addprefix $(GNL_DIR),$(GNL_FILES))

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
INCLUDES = inc/libft.h inc/get_next_line.h Makefile

# ═══ RULES ═══════════════════════════════════════════════════════════════════#

all:	$(NAME)

$(NAME):	$(OBJS) $(INCLUDES)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) created$(WHITE)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)objects deleted $(WHITE)"

fclean:	clean 
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) deleted $(WHITE)"

re: fclean all

.PHONY:			all clean fclean re

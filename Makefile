NAME		= miniRT

CC			= gcc
CFLAGS		= -Werror -Wall -Wextra #-g fsanitize=address
LIB_FLAG	= -L${LIBFT_DIR} -lft
DEP_FLAG	= -MMD -MP
INCLUDE		= -I${INC_DIR} -I${LIBFT_DIR}inc/
RMF			= rm -f
RMD			= rm -rf
MKDIR		= mkdir -p


LIBFT_DIR	= lib/libft/
INC_DIR		= inc/
SRC_DIR		= src/
OBJ_DIR		= obj/
PARSE_DIR	= parser/

MAIN_FILES	= miniRT
PARSE_FILES	=

MAIN_SRCS	= $(MAIN_FILES)
PARSE_SRCS	= $(addprefix $(PARSE_DIR), $(PARSE_FILES))

SRCS		:= $(MAIN_SRCS) $(PARSE_SRCS)
OBJS		:= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS)))
DEPS		:= $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRCS)))
SRCS		:= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCS)))

all: libft	$(NAME)

libft:	
		make -C $(LIBFT_DIR)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIB_FLAG) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile $(LIBFT_DIR)libft.a
			$(MKDIR) $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) $(DEP_FLAG) -o $@ -c $<

clean:	
		$(RMD) $(OBJ_DIR)
		make clean -C $(LIBFT_DIR)

fclean:	clean
		$(RMF) $(NAME)
		$(RMF) $(LIBFT_DIR)libft.a

re:		fclean all

-include $(DEPS)
.PHONY: all clean fclean re libft

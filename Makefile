NAME		= miniRT

CC			= gcc
CFLAGS		= -Werror -Wall -Wextra -g -fsanitize=address
LIB_FLAG	= -L${LIBFT_DIR} -lft -L${MLX_DIR} -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
DEP_FLAG	= -MMD -MP
INCLUDE		= -I${INC_DIR} -I${LIBFT_DIR}inc/ -I${MLX_DIR} -I/usr/include
A_FILES		= $(LIBFT_DIR)libft.a $(MLX_DIR)libmlx.a $(MLX_DIR)libmlx_Linux.a
RMF			= rm -f
RMD			= rm -rf
MKDIR		= mkdir -p


LIBFT_DIR	= lib/libft/
MLX_DIR		= lib/mlx/
INC_DIR		= inc/
SRC_DIR		= src/
OBJ_DIR		= obj/
PARSE_DIR	= parser/
UTILS_DIR	= utils/
RAY_DIR		= ray/
LIGHT_DIR	= light/

MAIN_FILES	= miniRT
PARSE_FILES	= init fill_data parser_utils init_objects check_errors id_error\
			  specific_data_error syntax_range_error check_syntax print_error\
			  object_error
UTILS_FILES	= print free_utils system_error
RAY_FILES	= generate_ray vec_math intersect ray_utils hit_cylinder\
			  hit_cylinder_caps hit_plane
LIGHT_FILES	= lightning shadows

MAIN_SRCS	= $(MAIN_FILES)
PARSE_SRCS	= $(addprefix $(PARSE_DIR), $(PARSE_FILES))
UTILS_SRCS	= $(addprefix $(UTILS_DIR), $(UTILS_FILES))
RAY_SRCS	= $(addprefix $(RAY_DIR), $(RAY_FILES))
LIGHT_SRCS	= $(addprefix $(LIGHT_DIR), $(LIGHT_FILES))

SRCS		:= $(MAIN_SRCS) $(PARSE_SRCS) $(UTILS_SRCS) $(RAY_SRCS) \
			   $(LIGHT_SRCS)
OBJS		:= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS)))
DEPS		:= $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRCS)))
SRCS		:= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCS)))

all: libft mlx $(NAME)

mlx:	
		make -C $(MLX_DIR)

libft:	
		@make -C $(LIBFT_DIR) --silent

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIB_FLAG) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile $(A_FILES)
			$(MKDIR) $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) $(DEP_FLAG) -o $@ -c $<

clean:	
		$(RMD) $(OBJ_DIR)
		make clean -C $(LIBFT_DIR)
		make clean -C $(MLX_DIR)

fclean:	clean
		$(RMF) $(NAME)
		$(RMF) $(LIBFT_DIR)libft.a

re:		fclean all

-include $(DEPS)
.PHONY: all clean fclean re libft

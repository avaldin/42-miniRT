# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 10:53:51 by tmouche           #+#    #+#              #
#    Updated: 2024/10/23 00:00:13 by thibaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRS	:= structure.h parsing.h displaying.h calcul.h memory.h\

SRCS	:=	main.c\
			parsing/extract_check_args.c\
			parsing/extract_check_line.c\
			parsing/extract_check_env.c\
			parsing/extract_check_obj.c\
			parsing/extract_env_init.c\
			parsing/extract_gnl.c\
			parsing/extract_obj_init.c\
			parsing/extract_obj_table.c\
			parsing/extract.c\
			parsing/menu_change.c\
			parsing/menu_cylinder.c\
			parsing/menu_plane.c\
			parsing/menu_selection.c\
			parsing/menu_sphere.c\
			parsing/utils_nums.c\
			parsing/utils_strings.c\
			calcul/calcul.c\
			calcul/color.c\
			calcul/cylinder_normal.c\
			calcul/generation.c\
			calcul/intersect_utils.c\
			calcul/intersection.c\
			calcul/nearest_object.c\
			calcul/pixel.c\
			calcul/rebase_objects.c\
			calcul/rotation_matrix.c\
			displaying/displaying.c\
			displaying/hook_keyboard.c\
			displaying/hook_mouse.c\
			displaying/loop_frame.c\
			displaying/moove_cam.c\
			memory/alloc_utils.c\
			memory/free_axis.c\
			memory/free_env.c\
			memory/free_mvt.c\
			memory/free_obj.c\
			memory/free_utils.c\
			memory/free_disp.c\

TEST_S	:=	main.c\
			parsing.c\
			calcul.c\
			test_parsing.c\

SRCS_D	:= SRCS/
TEST_D	:= TEST/
HDRS_D	:= HDRS/
OBJS_D	:= OBJS/
INC_D	:= include/

CFLAGS	:= -Wall -Wextra -Werror -g -O3
CC		:= cc
AR		:= ar rcs
RM		:= rm -rf

NAME	:= miniRT
OBJS	:= $(SRCS:%.c=$(OBJS_D)%.o)


TEST_EXE	:= test
TEST_OBJS	:= $(TEST_S:%.c=$(OBJS_D)test_%.o)

all: libft minilibx-linux $(NAME)

$(NAME): $(OBJS_D) $(OBJS)  include/libft/libft.a  include/minilibx-linux/libmlx.a include/minilibx-linux/libmlx_Linux.a
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_D)libft/HDRS -L$(INC_D)libft  -I$(INC_D)minilibx-linux -L$(INC_D)minilibx-linux -lmlx -I$(HDRS_D) -L/usr/lib -lXext -lX11 -lz -lft -lm -o $(NAME)
	@echo "\033[1;32m[$(NAME)] compiled. !!!\033[0m."

$(OBJS_D)%.o: $(SRCS_D)%.c $(HDRS:%=$(HDRS_D)%) Makefile HDRS/calcul.h HDRS/displaying.h HDRS/memory.h HDRS/parsing.h HDRS/structure.h include/minilibx-linux/mlx.h include/minilibx-linux/mlx_int.h
	$(CC) $(CFLAGS) -I$(INC_D)libft -I$(HDRS_D)  -c $< -o $@

$(OBJS_D):
	@mkdir -p $(OBJS_D)
	@mkdir -p $(OBJS_D)memory
	@mkdir -p $(OBJS_D)parsing
	@mkdir -p $(OBJS_D)calcul
	@mkdir -p $(OBJS_D)displaying
	@mkdir -p $(OBJS_D)moovement

$(TEST_D):
	@mkdir -p $(TEST_D)

libft:
	@echo "Libft ...."
	@make --no-print-directory -C $(INC_D)libft
	@echo "\033[1;32m[Libft Make] !!!\033[0m."
minilibx-linux:
	@echo "minilibx ...."
	@$(MAKE) -C $(INC_D)minilibx-linux
	@echo "\033[1;32m[minilibx Make] !!!\033[0m."

clean:
	@make --no-print-directory -C $(INC_D)libft clean
	@echo "[Libft deleted] !!!."
	@make --no-print-directory -C $(INC_D)minilibx-linux clean
	@echo "[minilibx deleted] !!!."
	@rm -rf ${OBJ_D}
	@echo "[all deleted] !!!."
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(TEST_EXE)
	@$(RM) $(OBJS_D)
	@echo "[$(NAME)] deleted!!!."
	@echo "[$(TEST_EXE)] deleted!!!."

re: fclean all

.PHONY: all clean fclean re libft

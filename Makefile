# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 10:53:51 by tmouche           #+#    #+#              #
#    Updated: 2024/08/18 15:21:04 by tmouche          ###   ########.fr        #
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
			calcul/generation.c\
			calcul/rebase_objects.c\
			calcul/calcul.c\
			calcul/intersection.c\
			calcul/color.c\
			calcul/rotation_matrix.c\
			displaying/displaying.c\
			displaying/hook_keyboard.c\
			displaying/hook_mouse.c\
			displaying/loop_frame.c\
			displaying/moove_cam.c\
			displaying/pixel.c\
			memory/alloc_utils.c\
			memory/alloc_axis.c\
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

CFLAGS	:= -Wall -Wextra -Werror -g
CC		:= cc
AR		:= ar rcs
RM		:= rm -rf

NAME	:= miniRT
OBJS	:= $(SRCS:%.c=$(OBJS_D)%.o)


TEST_EXE	:= test
TEST_OBJS	:= $(TEST_S:%.c=$(OBJS_D)test_%.o)

all: libft minilibx-linux $(NAME)

$(NAME): $(OBJS_D) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_D)libft/HDRS -L$(INC_D)libft  -I$(INC_D)minilibx-linux -L$(INC_D)minilibx-linux -lmlx -I$(HDRS_D) -L/usr/lib -lXext -lX11 -lz -lft -lm -o $(NAME)


$(OBJS_D)%.o: $(SRCS_D)%.c $(HDRS:%=$(HDRS_D)%) $(INC_D)libft $(INC_D)minilibx-linux Makefile
	$(CC) $(CFLAGS) -I$(INC_D)libft -I$(HDRS_D)  -c $< -o $@


$(OBJS_D)test_%.o: $(TEST_D)%.c $(HDRS:%=$(HDRS_D)%) $(INC_D)libft Makefile TEST/test.h
	$(CC) $(CFLAGS) -I$(INC_D)libft -I$(INC_D)minilibx-linux -I$(HDRS_D) -c $< -o $@

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
	$(MAKE) -C $(INC_D)libft
	$(MAKE) bonus -C $(INC_D)libft

minilibx-linux:
	$(MAKE) -C $(INC_D)minilibx-linux

clean:
	$(RM) -r $(OBJS_D)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_EXE)
	$(MAKE) -C $(INC_D)libft fclean
	$(MAKE) -C $(INC_D)minilibx-linux clean

t : $(TEST_D) $(TEST_OBJS) TEST/test.h
	$(MAKE)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(filter-out OBJS/main.o, $(OBJS)) -I$(INC_D)libft -L$(INC_D)libft -lm -lft -o $(TEST_EXE)

re: fclean all

.PHONY: all clean fclean re libft

test : all t
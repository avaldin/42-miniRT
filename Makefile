# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 10:53:51 by tmouche           #+#    #+#              #
#    Updated: 2024/07/06 23:07:28 by thibaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRS	:= structure.h\

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
			parsing/utils_nums.c\
			parsing/utils_strings.c\
			parsing/free_obj.c\
			parsing/free_env.c\
			calcul/generation.c\
			calcul/calcul.c\
			calcul/intersection.c\
			calcul/tools_pixel.c\

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
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_D)libft -L$(INC_D)libft  -I$(INC_D)minilibx-linux -L$(INC_D)minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lz -lft -lm -o $(NAME)


$(OBJS_D)%.o: $(SRCS_D)%.c $(HDRS:%=$(HDRS_D)%) $(INC_D)libft $(INC_D)minilibx-linux Makefile
	$(CC) $(CFLAGS) -I$(INC_D)libft -c $< -o $@


$(OBJS_D)test_%.o: $(TEST_D)%.c $(HDRS:%=$(HDRS_D)%) $(INC_D)libft Makefile TEST/test.h
	$(CC) $(CFLAGS) -I$(INC_D)libft -I$(INC_D)minilibx-linux -c $< -o $@

$(OBJS_D):
	@mkdir -p $(OBJS_D)

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
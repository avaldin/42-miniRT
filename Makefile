# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 10:53:51 by tmouche           #+#    #+#              #
#    Updated: 2024/06/24 18:54:49 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRS	:= objects.h parsing.h structure.h

SRCS	:=	main.c\
			parsing/parsing_check_args.c\
			parsing/parsing_extract.c\
			parsing/parsing_extract_env.c\
			parsing/parsing_extract_gnl.c\
			parsing/utils_nums.c\
			parsing/utils_strings.c\

TEST_S	:=	main.c\
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

all: libft $(NAME)

$(NAME): $(OBJS_D) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_D)libft -I$(HDRS_D) -L$(INC_D)libft -lft -o $(NAME)


$(OBJS_D)%.o: $(SRCS_D)%.c $(HDRS:%=$(HDRS_D)%) $(INC_D)libft Makefile
	$(CC) $(CFLAGS) -I$(INC_D)libft -I$(HDRS_D) -c $< -o $@


$(OBJS_D)test_%.o: $(TEST_D)%.c $(HDRS:%=$(HDRS_D)%) $(INC_D)libft Makefile TEST/test.h TEST/colors.h
	$(CC) $(CFLAGS) -I$(INC_D)libft -I$(HDRS_D) -c $< -o $@

$(OBJS_D):
	@mkdir -p $(OBJS_D)
	@mkdir -p $(OBJS_D)parsing

$(TEST_D):
	@mkdir -p $(TEST_D)

libft:
	$(MAKE) -C $(INC_D)libft
	$(MAKE) bonus -C $(INC_D)libft

clean:
	$(RM) -r $(OBJS_D)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_EXE)
	$(MAKE) -C $(INC_D)libft fclean

t : $(TEST_D) $(TEST_OBJS) TEST/test.h TEST/colors.h
	$(MAKE)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(filter-out OBJS/main.o, $(OBJS)) -I$(INC_D)libft -L$(INC_D)libft -lft -o $(TEST_EXE)

re: fclean all

.PHONY: all clean fclean re libft

test : all t
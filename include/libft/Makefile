# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avaldin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 13:32:16 by tmouche           #+#    #+#              #
#    Updated: 2024/10/09 14:33:23 by avaldin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRS    := libft.h

SRCS    := ft_atof.c\
           ft_atoi.c\
           ft_atol.c\
           ft_bzero.c\
           ft_calloc.c\
		   ft_float_abs.c\
		   ft_int_abs.c\
           ft_isalnum.c\
           ft_isalpha.c\
           ft_isascii.c\
           ft_isdigit.c\
           ft_isprint.c\
           ft_itoa.c\
           ft_memchr.c\
           ft_memcmp.c\
           ft_memcpy.c\
           ft_memmove.c\
           ft_memset.c\
           ft_putchar_fd.c\
           ft_putendl_fd.c\
           ft_putnbr_fd.c\
           ft_putstr_fd.c\
           ft_split.c\
           ft_stradd.c\
           ft_strchr.c\
           ft_strdup.c\
           ft_strfull.c\
           ft_striteri.c\
           ft_strjoin.c\
           ft_strlcat.c\
           ft_strlcpy.c\
           ft_strlen.c\
           ft_strncmp.c\
           ft_strnstr.c\
           ft_strrchr.c\
           ft_strtrim.c\
           ft_strmapi.c\
           ft_substr.c\
           ft_tolower.c\
           ft_toupper.c

BONUS   := ft_lstnew.c\
           ft_lstadd_front.c\
           ft_lstsize.c\
           ft_lstlast.c\
           ft_lstadd_back.c\
           ft_lstdelone.c\
           ft_lstclear.c\
           ft_lstiter.c\
           ft_lstmap.c

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g

SRCS_D  := SRCS/
OBJS_D  := OBJS/
HDRS_D  := .

OBJS    := $(SRCS:%.c=$(OBJS_D)%.o)
B_OBJS  := $(BONUS:%.c=$(OBJS_D)%.o)

AR      := ar rcs
NAME    := libft.a

all: $(NAME)

$(NAME): $(OBJS_D) $(OBJS)
	@$(AR) $(NAME) $(OBJS)


$(OBJS_D)%.o: $(SRCS_D)%.c $(HDRS_D)/$(HDRS)
	$(CC) $(CFLAGS) -I$(HDRS_D) -c $< -o $@

$(OBJS_D):
	@mkdir -p $(OBJS_D)

bonus: $(OBJS) $(B_OBJS)
	@$(AR) $(NAME) $(OBJS) $(B_OBJS)

clean:
	@$(RM) -r $(OBJS_D)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
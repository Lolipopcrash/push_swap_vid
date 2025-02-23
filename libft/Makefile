# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 17:16:24 by kelevequ          #+#    #+#              #
#    Updated: 2024/10/28 17:36:31 by kelevequ         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_isnum.c ft_free.c

BONUS_SRCS = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

PRINTF_SRCS = \
	ft_printf.c ft_printf_base.c ft_printf_ch.c ft_printf_hex.c ft_printf_ptr.c \
	ft_printf_putnbr.c ft_printf_str.c ft_printf_unsigned.c

GNL_SRCS = \
	get_next_line_bonus.c

OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJS_DIR)/, $(BONUS_SRCS:.c=.o))
PRINTF_OBJS = $(addprefix $(OBJS_DIR)/, $(PRINTF_SRCS:.c=.o))
GNL_OBJS = $(addprefix $(OBJS_DIR)/, $(GNL_SRCS:.c=.o))

HDRS = libft.h ft_printf.h get_next_line_bonus.h
NAME = libft.a
RM = rm -rf
CC = cc
AR = ar rcs
FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)/%.o: %.c $(HDRS)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -I includes -c $< -o $@

$(NAME): $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

all: $(NAME)

prime: $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

printf: $(PRINTF_OBJS)
	$(AR) $(NAME) $(PRINTF_OBJS)

gnl: $(GNL_OBJS)
	$(AR) $(NAME) $(GNL_OBJS)

re: fclean all

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re bonus


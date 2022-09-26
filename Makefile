# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwichoi <hwichoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 15:26:21 by hwichoi           #+#    #+#              #
#    Updated: 2022/09/26 16:03:28 by hwichoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =
SERVER = server
CLIENT = client

LIBFT = libft
LIBFT_LIB = libft.a

SRC_C = client.c
SRC_S = server.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):  $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_S) $(LIBFT_LIB) -o $(SERVER)

$(CLIENT):  $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_C) $(LIBFT_LIB) -o $(CLIENT)

$(LIBFT):
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB)

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(SERVER) $(CLIENT)

fclean: clean
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

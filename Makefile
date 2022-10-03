# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 03:44:48 by hwichoi           #+#    #+#              #
#    Updated: 2022/09/29 04:46:31 by hwichoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

LIBFT = libft/libft.a
LIBFT_DIR = libft

SRCS_S = server.c
SRCS_C = client.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(SERVER): $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_S) $(LIBFT) -o $(SERVER)

$(CLIENT): $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_C) $(LIBFT) -o $(CLIENT)

clean:
	$(RM) *.o
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

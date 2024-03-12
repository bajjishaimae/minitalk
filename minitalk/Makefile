# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 17:40:05 by cbajji            #+#    #+#              #
#    Updated: 2024/03/09 17:40:06 by cbajji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SERVER	= server

CLIENT	= client

LIBFT	= libft/libft.a

FTPRINTF	= ft_printf/libftprintf.a

CSRC	= client.c

COBJ	= $(CSRC:%c=%o)

SSRC	= server.c

SOBJ	= $(SSRC:%c=%o)

CC		= cc

CFLAGS	= -Wall -Werror -Wextra

INCLUDE	= minitalk.h

all:	$(SERVER) $(CLIENT)

%o	: %c $(INCLUDE)
		$(CC) $(FLAGS) -c $<

$(SERVER): $(SOBJ)
			make -C libft
			make -C ft_printf
			$(CC) $(FLAGS) $< $(LIBFT) $(FTPRINTF) -o $(SERVER)

$(CLIENT): $(COBJ)
			$(CC) $(FLAGS) $< $(LIBFT) $(FTPRINTF) -o $(CLIENT)

clean:
		make -C libft clean
		make -C ft_printf clean
		@rm -f $(COBJ) $(SOBJ)

fclean:	clean
	make -C libft fclean
	make -C ft_printf fclean
	$(RM) -rf $(CLIENT) $(SERVER)

re: 	fclean all

.PHONY:	clean

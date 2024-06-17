# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 14:31:33 by tcohen            #+#    #+#              #
#    Updated: 2024/06/17 16:26:29 by tcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft
SRC_DIR = src
LIBFT = $(LIBFT_DIR)/libft.a
FLAGS = -Wall -Wextra -Werror
CC = cc
SRC = $(addprefix src/ft_, $(addsuffix .c, pnbr pstr printf))
OBJ = $(SRC:.c=.o)
INCLUDE = -I$(LIBFT_DIR) -I$(SRC_DIR)

all : $(LIBFT) $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(AR) rcs $@ $^
	$(AR) x $(LIBFT)
	$(AR) rcs $@ *.o
	rm -f *.o

%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

ft_printf.o: $(LIBFT)
ft_pstr.o: $(LIBFT)
ft_pnbr.o: $(LIBFT)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)
	
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re 
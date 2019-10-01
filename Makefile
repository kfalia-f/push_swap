# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/27 18:48:23 by kfalia-f          #+#    #+#              #
#    Updated: 2019/10/01 19:37:42 by kfalia-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_NAME = push_swap

CH_NAME = checker

LIB_FOLDER = libft

FLAGS = -Wall -Wextra -Werror

GEN_FOLD = srcs/general

PS_FOLD = srcs/push_swap

CH_FOLD = srcs/checker

GEN_SRC = $(GEN_FOLD)/test.c $(GEN_FOLD)/g_valid.c $(GEN_FOLD)/g_lists.c $(GEN_FOLD)/g_cast.c

PS_SRC = $(PS_FOLD)/p_main.c

CH_SRC = $(CH_FOLD)/c_main.c

LIBFT = -L $(LIB_FOLDER) -lft

PS_OBJ = $(PS_SRC:.c=.o)

CH_OBJ = $(CH_SRC:.c=.o)

GEN_OBJ = $(GEN_SRC:.c=.o)

HEADERS = -I includes -I $(LIB_FOLDER)/includes

%.o: %.c $(INCLUDES)
	@gcc $(FLAGS) $(HEADERS) -c $< -o $@

all: $(PS_NAME) $(CH_NAME)

$(PS_NAME): $(PS_OBJ) $(GEN_OBJ)
	@make -C $(LIB_FOLDER)
	@make -C $(LIB_FOLDER) clean
	@gcc $(FLAGS) -o $(PS_NAME) $(HEADERS) $(PS_OBJ) $(GEN_OBJ) $(LIBFT)

$(CH_NAME): $(CH_OBJ)
	@gcc $(FLAGS) -o $(CH_NAME) $(HEADERS) $(CH_OBJ) $(GEN_OBJ) $(LIBFT)

clean:
	@rm -f $(PS_OBJ) $(GEN_OBJ) $(CH_OBJ)

fclean: clean
	@rm -f $(PS_NAME) $(CH_NAME)
	@make -C $(LIB_FOLDER) fclean

re: fclean all

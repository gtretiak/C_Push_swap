# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 14:02:12 by gtretiak          #+#    #+#              #
#    Updated: 2025/06/19 13:14:06 by gtretiak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker
PUSH_LIB = push_swap.a
CHECKER_LIB = checker.a
HEADER = push_swap.h
HEADER_B = push_swap_bonus.h
LIBFT = libft.a
LIBFT_DIR = C_libft/
SRCS = main.c freeing.c ft_create_and_validate.c push.c reverse_rotate.c \
       rotate.c sorting.c sort_many.c swap.c utils.c upgrade.c
SRCS_B = main_bonus.c freeing_bonus.c push_bonus.c reverse_rotate_bonus.c \
	 ft_create_and_validate_bonus.c rotate_bonus.c swap_bonus.c
SRCS_DIR = Sources/
SRCS_B_DIR = Sources_bonus/
OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))
OBJS_B = $(addprefix $(SRCS_B_DIR), $(SRCS_B:.c=.o))
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(PUSH_LIB) $(NAME)

$(LIBFT):
	@if [ -d $(LIBFT_DIR) ]; then \
		echo "C-libft is already cloned."; \
	else \
		git clone git@github.com:gtretiak/C_libft.git $(LIBFT_DIR); \
	fi
	@if [ -f $(LIBFT_DIR)$(LIBFT) ]; then \
		echo "libft.a is already compiled."; \
	else \
		$(MAKE) -C $(LIBFT_DIR); \
	fi

$(PUSH_LIB): $(OBJS) $(HEADER) $(LIBFT_DIR)$(LIBFT)
	ar -rc $(PUSH_LIB) $^

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER) $(LIBFT_DIR)$(LIBFT)
	cc $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

$(NAME): $(PUSH_LIB) $(LIBFT) $(OBJS)
	@if [ $(PUSH_LIB) -nt $(NAME) ] || [ $(LIBFT) -nt $(NAME) ] \
		|| [ ! -f $(NAME) ]; then \
		cc $(PUSH_LIB) -L$(LIBFT_DIR) -lft -o $(NAME); fi

.PHONY: clean fclean re bonus clean_bonus fclean_bonus re_bonus

clean:
	rm -f $(OBJS)
	@if [ -d $(LIBFT_DIR) ]; then make clean -C $(LIBFT_DIR); fi

fclean: clean
	@if [ -f $(PUSH_LIB) ]; then rm -f $(PUSH_LIB); fi
	@if [ -f $(NAME) ]; then rm -f $(NAME); fi
	@if [ -d $(LIBFT_DIR) ]; then make fclean -C $(LIBFT_DIR); fi
	@if [ -d $(LIBFT_DIR) ]; then rm -rf $(LIBFT_DIR); fi

re: fclean all

bonus: $(LIBFT) $(CHECKER_LIB) $(NAME_B)

$(CHECKER_LIB): $(OBJS_B) $(HEADER_B) $(LIBFT_DIR)$(LIBFT)
	ar -rc $(CHECKER_LIB) $^

$(SRCS_B_DIR)%.o: $(SRCS_B_DIR)%.c $(HEADER_B) $(LIBFT_DIR)$(LIBFT)
	cc $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

$(NAME_B): $(CHECKER_LIB) $(LIBFT) $(OBJS_B)
	@if [ ! -f $(NAME_B) ] || [ $(CHECKER_LIB) -nt $(NAME_B) ] \
		|| [ $(LIBFT) -nt $(NAME_B) ]; then \
		cc $(CHECKER_LIB) -lft -L$(LIBFT_DIR) -o $(NAME_B); fi

clean_bonus:
	rm -f $(OBJS_B)
	@if [ -d $(LIBFT_DIR) ]; then make clean -C $(LIBFT_DIR); fi

fclean_bonus: clean_bonus
	@if [ -f $(CHECKER_LIB) ]; then rm -f $(CHECKER_LIB); fi
	@if [ -f $(NAME_B) ]; then rm -f $(NAME_B); fi
	@if [ -d $(LIBFT_DIR) ]; then make fclean -C $(LIBFT_DIR); fi
	@if [ -d $(LIBFT_DIR) ]; then rm -rf $(LIBFT_DIR); fi

re_bonus: fclean_bonus bonus

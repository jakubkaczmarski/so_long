all: push_swap

push_swap:
	gcc -Wall -Wextra -Werror -o so_long check_map.c helper_func_thingy.c ft_itoa.c get_next_line.c get_next_line_utils.c so_long.c helper_functions.c libftprintf.a libmlx42.a libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit
clean:
	@rm -f push_swap
fclean:
	@rm -f push_swap
re: fclean all

.PHONY: all clean fclean re

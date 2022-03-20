all: so_long

so_long:
	gcc -Wall -Wextra -Werror -o so_long movement_op.c error_manag.c key_managment.c check_map.c movement_manag.c helper_func_thingy.c ft_itoa.c get_next_line.c get_next_line_utils.c so_long.c helper_functions.c libftprintf.a libmlx42.a libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit
clean:
	@rm -f so_long
fclean:
	@rm -f so_long
re: fclean all

.PHONY: all clean fclean re

NAME		=	cub3D

SRCS		=	cub3d.c create_bmp.c game_setup_1.c game_setup_2.c \
				get_map_matrix.c get_parameters_from_file.c map_validation_1.c \
				map_validation_2.c raycast_1.c raycast_2.c render_1.c \
				render_2.c render_3.c setup_variables.c sprites.c update.c \
				utils_general.c utils_strings.c utils_get_next_line.c \
				utils_events.c utils_raycasting.c utils_render.c

OBJS        =   ${SRCS:.c=.o}

CC          =   gcc

CFLAGS      =   -Wall -Wextra -Werror -g

LIBS		=	-lmlx -framework OpenGL -framework AppKit

RM			=	rm -f

all:		$(NAME)

$(NAME):	${OBJS}
	${CC} ${CFLAGS} ${LIBS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

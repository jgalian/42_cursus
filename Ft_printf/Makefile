# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 06:44:26 by jgalian-          #+#    #+#              #
#    Updated: 2020/02/10 06:44:32 by jgalian-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
				ft_num_len.c get_data_type.c get_flags.c \
				get_precision.c get_width.c int_to_hex_long_un.c int_to_hex.c \
				percentage_found.c print_caracter.c print_decimal.c \
				print_hexadecimal.c print_padding.c print_percentage.c \
				print_pointer.c print_string.c print_unsigned.c \
				put_functions.c reset_temp_values.c \
				set_initial_values.c str_functions.c\

OBJS        =   ${SRCS:.c=.o}

CC          =   gcc

CFLAGS      =   -c -Wall -Wextra -Werror -g

RM			=	rm -f

all:		$(NAME)

$(NAME):	${SRCS}
	${CC} ${CFLAGS} ${SRCS}
	ar -rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:	
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

NAME		=	libasm.a

EXEC		=	test

SRC_ASM 	=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s \
				ft_read.s ft_strdup.s

MAIN_SRC	=	main.c

OBJ_ASM		=	$(SRC_ASM:.s=.o)

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

CC_FLAGS	=	-g -Wall -Werror -Wextra -fno-builtin

CC_ASM		=	nasm

CC			=	gcc

ASM_FLAGS	=	-f macho64

DIR_HEADER	=	./include/

all :		$(NAME)

$(NAME) :	$(OBJ_ASM)
	ar rcs $(NAME) $(OBJ_ASM)

test :	$(NAME)
	$(CC) $(CC_FLAGS) -L. -lasm -o $(EXEC) $(MAIN_SRC)

%.o : %.s
	$(CC_ASM) $(ASM_FLAGS) $< -o $@

%.o : %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_ASM) $(MAIN_OBJ)

fclean : clean
	rm -f $(NAME) $(EXEC)

re : fclean all

re_test : fclean test

.PHONY: clean fclean re

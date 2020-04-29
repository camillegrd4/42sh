##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

BUILTIN =			src/builtin/call_function_recode.c 	\
					src/builtin/cd_function.c 			\
					src/builtin/unsetenv_function.c 	\
					src/builtin/change_env.c 			\
					src/builtin/change_line.c 			\
					src/builtin/env_function.c 			\
					src/builtin/recode_function.c 		\
					src/builtin/setenv_function.c 		\

PIPE_COMMA =		src/pipe_comma/comma_function.c 	 \
					src/pipe_comma/comma_or_pipe.c 		 \
					src/pipe_comma/exec_first_pipe.c 	 \

EXECVE_FUNCTION =	src/execve_function/exec_binary.c 		\
					src/execve_function/check_function.c 	\
					src/execve_function/find_path.c 		\
					src/execve_function/exec_function.c 	\

LIB =				lib/my_putchar.c 					\
					lib/my_putstr.c 					\
					lib/my_strlen.c 					\
					lib/my_str_to_world_array.c 		\
					lib/my_strcat.c 					\
					lib/my_strncmp.c 					\
					lib/my_str_to_world_array_pipe.c 	\
					lib/my_strncmp_next.c 				\
					lib/my_strdup.c						\
					lib/my_strcat_two.c 				\
					lib/my_str_to_world_array_comma.c 	\

SRCS	=		src/main.c 						\
				src/minishell.c 				\
				src/init_struct.c 				\
				$(BUILTIN)						\
				$(PIPE_COMMA)					\
				$(EXECVE_FUNCTION)				\
				$(LIB)							\

CFLAGS	=	-I ./include -g

LDFLAGS =	-L./lib

OBJ	=	$(SRCS:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

debug:	$(OBJ)
	gcc -o debug $(OBJ) $(CFLAGS)

re:	fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

tests_run:
	make -C tests
	./tests/unit_tests

test:
	make -C tests_shell/tests
	./test_shell/tests/my_tests_sh

.PHONY:	fclean clean all re tests_run
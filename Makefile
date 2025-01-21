FILE =  pipex.c utils.c
NAME = pipex
CC = cc 
<<<<<<< HEAD
bonfile = utils_bonus.c pipex_bonus.c here_doc.c
FLAGS = -Wall -Werror -Wextra 
FILES=$(FILE:.c=.o)
OBJbo = $(bonfile:.c=.o)
lib=libft/libft.a
 %.o: %.c pipex.h
	@$(CC) $(FLAGS)  -c $< -o $@
%.o: %.c pipex_bonus.h
	@$(CC) $(FLAGS)  -c $< -o $@
all: $(NAME)

$(NAME): $(FILES) pipex.h
	@make -C libft
	@$(CC) $(FLAGS) $(FILES) $(lib) -o $(NAME) 
bonus: ${OBJbo} fclean pipex_bonus.h
	@make -C libft
	@$(CC) $(FLAGS) $(bonfile) $(lib) -o $(NAME)  $(lib)
clean:
	@make clean -C libft
	@rm -rf $(FILES)
	@rm -rf $(OBJbo)
=======
FLAGS = -Wall -Werror -Wextra 
FILES=$(FILE:.c=.o)
lib=libft/libft.a
%.o: %.c pipex.h
	@make -C libft
	@$(CC) $(FLAGS)  -c $< -o $@

all: $(NAME)

$(NAME): $(FILES)
	@make -C libft
	@$(CC)  $(FILES) $(lib) -o $(NAME)

clean:
	@make clean -C libft
	@rm -rf $(FILES)
>>>>>>> 3d8b75dcfcae9d858d4d982d2152eace5308e3fe
fclean:clean
	@make clean -C libft
	@rm -rf $(NAME)
re: fclean all

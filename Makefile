FILE =  pipex.c utils.c
NAME = pipex
CC = cc 
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
fclean:clean
	@make clean -C libft
	@rm -rf $(NAME)
re: fclean all

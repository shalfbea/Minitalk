HEADER := include/minitalk.h

SERVER = server
CLIENT = client
LIBFT = libft/libft.a
CC := clang

TestingFlags := -fsanitize=address -g3

FLAGS := -Wall -Wextra -Werror -I./include -g3 -I./libft/include

SRC_FILES_CLIENT = src/client.c
SRC_FILES_SERVER= src/server.c

OBJ_CLIENT = $(patsubst %.c, %.o, $(SRC_FILES_CLIENT))
OBJ_SERVER = $(patsubst %.c, %.o, $(SRC_FILES_SERVER))

RM := rm -rf

all: $(HEADER) $(SERVER) $(CLIENT) $(OBJ)

$(SERVER): $(OBJ_SERVER) $(HEADER) $(LIBFT)
	$(CC) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(HEADER) $(LIBFT)
	$(CC) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

$(LIBFT) :
	git submodule update --init --recursive
	make -C ./libft


bonus : $(all)

%.o: %.c $(HEADER) $(LIBFT)
	$(CC) $(FLAGS) -c $< -o $@

testing : test


clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	make clean -C ./libft

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	make fclean -C ./libft

re: fclean all

norm: $(SRC_FILES)
	norminette $<

.PHONY: all clean fclean re norm bonus

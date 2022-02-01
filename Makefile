HEADER := include/minitalk.h

SERVER = server
CLIENT = client

CC := clang

TestingFlags := -fsanitize=address -g3

FLAGS := -Wall -Wextra -Werror -Imlx -I./include -g3

SRC_FILES_CLIENT = src/client.c
SRC_FILES_SERVER= src/server.c

OBJ_CLIENT = $(patsubst %.c, %.o, $(SRC_FILES_CLIENT))
OBJ_SERVER = $(patsubst %.c, %.o, $(SRC_FILES_SERVER))

RM := rm -rf

all: $(HEADER) $(SERVER) $(CLIENT) $(OBJ)

$(SERVER): $(OBJ_SERVER) $(HEADER)
	$(CC) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(HEADER)
	$(CC) $(OBJ_CLIENT) -o $(CLIENT)

bonus : $(all)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

testing : test


clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

norm: $(SRC_FILES)
	norminette $<

.PHONY: all clean fclean re norm bonus

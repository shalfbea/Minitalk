HEADER := include/minitalk.h

SERVER = server
CLIENT = client
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
CC := clang

TestingFlags := -fsanitize=address -g3

FLAGS := -Wall -Wextra -Werror -Imlx -I./include -g3 -I./libft

SRC_FILES_CLIENT = src/client.c
SRC_FILES_SERVER= src/server.c

OBJ_CLIENT = $(patsubst %.c, %.o, $(SRC_FILES_CLIENT))
OBJ_SERVER = $(patsubst %.c, %.o, $(SRC_FILES_SERVER))

RM := rm -rf

all: $(HEADER) $(SERVER) $(CLIENT) $(OBJ)

$(SERVER): $(OBJ_SERVER) $(HEADER) $(LIBFT) $(FT_PRINTF)
	$(CC) $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(HEADER) $(LIBFT) $(FT_PRINTF)
	$(CC) $(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF) -o $(CLIENT)

$(LIBFT) :
	make -C ./libft

$(FT_PRINTF) :
	make -C ./ft_printf

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

S = server
C = client

S_BONUS = server_bonus
C_BONUS = client_bonus

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
RM = rm -f 

SRC_S = server.c
SRC_B = client.c 
SRC_S_B = server_bonus.c 
SRC_C_B = client_bonus.c 

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_B:.c=.o)
OBJ_S_B = $(SRC_S_B:.c=.o)
OBJ_C_B = $(SRC_C_B:.c=.o)

%.o : %.c
	@$(CC) $(CC_FLAGS) -c -o $@ $^

libft:
	@ make -C libft/

server: libft $(OBJ_S)
	@ $(CC) $(CC_FLAGS) -o $(S) $(OBJ_S) libft/*.o

client: libft $(OBJ_C)
	@ $(CC) $(CC_FLAGS) -o $(C) $(OBJ_C) libft/*.o

all : server client

server_bonus: libft $(OBJ_S_B)
	@ $(CC) $(CC_FLAGS) -o $(S_BONUS) $(OBJ_S_B) libft/*.o

client_bonus: libft $(OBJ_C_B)
	@ $(CC) $(CC_FLAGS) -o $(C_BONUS) $(OBJ_C_B) libft/*.o

bonus: all server_bonus client_bonus

clean:
	@ $(RM) $(OBJ_S) $(OBJ_C) $(OBJ_S_B) $(OBJ_C_B)
	@ make -C libft/ clean

fclean: clean
	@ $(RM) $(S) $(C) $(S_BONUS) $(C_BONUS)
	@ make -C libft/ clean

re: fclean all
	s

NAME_CLIENT = client
NAME_SERVER = server

HEAD = src/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC_FILES_CLIENT = client printf printf2
SRC_FILES_SERVER = server printf printf2


SRC_DIR = src/
OBJ_DIR = obj/


OBJ_CLIENT = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_CLIENT)))
SRC_CLIENT = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_CLIENT)))

OBJ_SERVER = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_SERVER)))
SRC_SERVER = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_SERVER)))

all : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT)   : $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER)   : $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(OBJ_DIR)%.o   :   $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME_CLIENT)
	$(RM) $(NAME_SERVER)

re : fclean all
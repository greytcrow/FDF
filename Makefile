.PHONY: all, re, clean, fclean, lib, mlx

NAME = fdf

UNAME := $(shell uname)

FRAME = -framework
OGL = OpenGl
APPK = AppKit
FLAG_OS = $(FRAME) $(APPK) $(FRAME) $(OGL)

export CC = gcc
export CC_FLAGS = -Wall -Werror -Wextra
OPTI_FLAG = -O2

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

LIBMLX_PATH = mlx
LIBMLX = $(LIBMLX_PATH)/libmlx.a

SRC_NAME =	main.c \
	   bresenhamdraw.c \
	   projection.c \
	   parsing.c \
	   spacerotation.c \
	   xrotation.c \
	   yrotation.c \
	   zrotation.c \
	   init_matrix.c \
	   mult_matrix.c \
	   xvectorrotation.c \
	   yvectorrotation.c \
	   zvectorrotation.c \
	   mult_vector.c \
	   init_vector.c \
	   key_pos.c

SRC_PATH = src

INC_NAME =	fdf.h	

INC_PATH = includes
INCLUDES = -I$(LIBFT_PATH)

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	@ printf "\033[1mCompilation du projet \033[34m$@\033[0m \033[1men \033[31m$@\033[0m ✅\n"
	@ $(CC) $(CC_FLAGS) $(OPTI_FLAG) -o $@ $^ $(FLAG_OS)

libft: $(LIBFT)

$(LIBFT):
	@ make -C $(LIBFT_PATH)

mlx : $(LIBMLX)

$(LIBMLX):
	@ make -C $(LIBMLX_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@ mkdir $(OBJ_PATH) 2> /dev/null || true
	@ printf "\033[1mCompilation de \033[36m%-20s\033[37m\ten \033[32m%-20s\033[0m ✅\n" $< $@
	@ $(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@ /bin/rm -rf $(OBJ_PATH)
	@ make -C $(LIBFT_PATH) clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ make -C $(LIBMLX_PATH) clean
	@ make -C $(LIBFT_PATH) fclean

re: fclean all
NAME := minishell

CC		:= cc
#CFLAGS	:= -v -Wall -Wextra -Werror

LIBFT_DIR	:= ./lib/libft
LIBFT 	:= $(LIBFT_DIR)/libft.a
HEADERS	:=  -I $(LIBFT_DIR)/inc

SRC_DIR = build-ins
SRC = main-test.c \
	  pwd.c \
	  cd.c \
	  exit.c \
	  echo.c 
LIBS := -L$(LIBFT_DIR) -lft -lreadline
SRCS	:= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR	:= obj
OBJ		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)


$(LIBFT): $(LIBFT_DIR)
	make -C$(LIBFT_DIR);

$(LIBFT_DIR):
	git clone https://github.com/YukiHalf/42_libft.git $@;

$(OBJ_DIR):
	mkdir obj

$(NAME):  $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(LIBS) $(HEADERS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c minishell.h | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@ $(HEADERS)

clean:
	rm -rf $(OBJ)
	make clean -C$(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rmdir $(OBJ_DIR)
	rm -rf $(LIBFT_DIR)
re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all, clean, fclean, re

# <==== Meta Data =====>
NAME	:= minishell-test
CC		:= cc
CFLAGS	:= -Wall -Wextra

# Paths relative to src/execution/
INC_DIR		:= execution_inc
ROOT_INC	:= ../../inc
LIBFT_DIR	:= ../../lib/libft
LIBFT		:= $(LIBFT_DIR)/libft.a
OBJS_DIR	:= ./objs/

# <==== Files & Folders =====>
MAIN_FILE	:= main-test.c

# Subdirectories that exist
BUILTIN_DIR	:= build-ins/
CHECKS_DIR	:= checks/
EXEC_DIR	:= exec/
UTILS_DIR  := utils/

# Source files by directory
BUILTIN_FILES := echo.c pwd.c cd.c exit.c env.c export.c unset.c helper_buildins.c
CHECKS_FILES  := check_cmd.c
EXEC_FILES    := exec_cmd.c and_root.c or_root.c pipe_root.c execution_main.c
UTILS_FILES := helper_functions.c
# Combine all sources
SRCS		:= $(MAIN_FILE) \
               $(addprefix $(BUILTIN_DIR), $(BUILTIN_FILES)) \
               $(addprefix $(CHECKS_DIR), $(CHECKS_FILES)) \
               $(addprefix $(EXEC_DIR), $(EXEC_FILES)) \
				$(addprefix $(UTILS_DIR), $(UTILS_FILES))

# Object files
OBJS		:= $(addprefix $(OBJS_DIR), $(SRCS:%.c=%.o))

# Readline library flags
LDFLAGS		:= -lreadline

# <===== Rules =====>

all: $(LIBFT) $(NAME)

# Build libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compile executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Compile main-test.c
$(OBJS_DIR)main-test.o: main-test.c | $(OBJS_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(ROOT_INC) -I$(LIBFT_DIR) -c $< -o $@

# Compile builtin files
$(OBJS_DIR)$(BUILTIN_DIR)%.o: $(BUILTIN_DIR)%.c | $(OBJS_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(ROOT_INC) -I$(LIBFT_DIR) -c $< -o $@

# Compile checks files
$(OBJS_DIR)$(CHECKS_DIR)%.o: $(CHECKS_DIR)%.c | $(OBJS_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(ROOT_INC) -I$(LIBFT_DIR) -c $< -o $@

# Compile exec files
$(OBJS_DIR)$(EXEC_DIR)%.o: $(EXEC_DIR)%.c | $(OBJS_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(ROOT_INC) -I$(LIBFT_DIR) -c $< -o $@

$(OBJS_DIR)$(UTILS_DIR)%.o: $(UTILS_DIR)%.c | $(OBJS_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(ROOT_INC) -I$(LIBFT_DIR) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)$(BUILTIN_DIR)
	@mkdir -p $(OBJS_DIR)$(CHECKS_DIR)
	@mkdir -p $(OBJS_DIR)$(EXEC_DIR)
	@mkdir -p $(OBJS_DIR)$(UTILS_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

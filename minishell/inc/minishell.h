#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "token.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
// Malloc , pwd , cd, terminal information
# include <stdlib.h>
# include <unistd.h>
// Dir manipulation like read , close ,open
# include <dirent.h>
# include <sys/types.h>
// Strerror
# include <string.h>
# include <termios.h>

typedef struct s_meta
{
	t_token	*head;
	int		last_exit_code;
}			t_meta;

#endif

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include <fcntl.h>

int	 	b_pwd(void);
int		b_cd(t_token *cmd);
int	b_exit(t_token *cmd);
int	b_echo(t_token *cmd);

int		check_node(t_token *node, char **env);
int		check_build_in(t_token *cmd);
void	execute(t_token *node, char **env);


int		exec_cmd(t_token *cmd, char **env);
int		pipe_root(t_token *exec, char **env);
int     and_root(t_token *exec, char **env);
int     or_root(t_token *exec, char **env);


int	execute_simple_cmd(t_token *cmd, char **env);
int	get_exit_code(int status);
#endif

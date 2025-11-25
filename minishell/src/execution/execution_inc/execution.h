#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include <fcntl.h>

int		b_pwd(void);
int		b_cd(t_token *cmd);
int		b_exit(t_token *cmd);
int		b_echo(t_token *cmd);
int		b_env(t_meta *meta);

int		check_node(t_token *node, t_meta *meta);
int		check_build_in(t_token *cmd,t_meta *meta);
void	execute(t_token *node, t_meta *meta);

int		exec_cmd(t_token *cmd, t_meta *meta);
int		pipe_root(t_token *exec,t_meta *meta);
int		and_root(t_token *exec, t_meta *meta);
int		or_root(t_token *exec, t_meta *meta);

int		execute_simple_cmd(t_token *cmd, t_meta *meta);
int		get_exit_code(int status);
#endif

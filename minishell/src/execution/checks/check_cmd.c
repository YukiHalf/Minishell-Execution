#include "../execution_inc/execution.h"

int	check_build_in(t_token *cmd, t_meta *meta)
{
	if (ft_strcmp(cmd->s_cmd[0], "pwd") == 0)
		return (printf("merge"), b_pwd());
	else if (ft_strcmp(cmd->s_cmd[0], "cd") == 0)
		return (b_cd(cmd));
	else if (ft_strcmp(cmd->s_cmd[0], "exit") == 0)
		return (b_exit(cmd));
	else if (ft_strcmp(cmd->s_cmd[0], "echo") == 0)
		return (b_echo(cmd));
	else if (ft_strcmp(cmd->s_cmd[0], "env") == 0)
		return (b_env(meta));
	else if (ft_strcmp(cmd->s_cmd[0], "export") == 0)
		return (b_export(cmd, meta));
	return (-1);
}

int	check_node(t_token *node, t_meta *meta)
{
	int	exit_code;

	if (node->type == T_TEXT)
		exit_code = execute_simple_cmd(node, meta);
	else if (node->type == T_PIPE)
		exit_code = pipe_root(node, meta);
	else if (node->type == T_AND)
		exit_code = and_root(node, meta);
	else if (node->type == T_OR)
		exit_code = or_root(node, meta);
	else
	{
		display_error("Unknown command type\n", 0);
		exit_code = 1;
	}
	return (exit_code);
}

#include "../execution_inc/execution.h"

int	and_root(t_token *exec, t_meta *meta)
{
	int	exit_code;

	if (exec->left->type == T_PIPE)
		exit_code = pipe_root(exec->left, meta);
	else
		exit_code = execute_simple_cmd(exec->left, meta);
	if (exit_code == 0)
	{
		if (exec->right->type == T_PIPE)
			exit_code = pipe_root(exec->right, meta);
		else
			exit_code = execute_simple_cmd(exec->right, meta);
	}
	return (exit_code);
}

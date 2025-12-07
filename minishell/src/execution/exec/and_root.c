#include "../execution_inc/execution.h"

int	and_root(t_token *exec, t_meta *meta)
{
	int	exit_code;

	exit_code = check_node(exec->left, meta);
	if (exit_code == 0)
		exit_code = check_node(exec->right, meta);
	return (exit_code);
}

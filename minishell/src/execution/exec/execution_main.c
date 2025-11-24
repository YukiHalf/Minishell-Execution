#include "execution.h"

void	execute(t_token *node, char **env)
{
	while (node->left)
	{
		execute(node->left, env);
		check_node(node, env);
	}
	while (node->right)
	{
		execute(node->right, env);
		check_node(node, env);
	}
}

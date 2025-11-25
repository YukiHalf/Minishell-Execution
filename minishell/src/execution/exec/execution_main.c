#include "execution.h"

void	execute(t_token *node, t_meta *meta)
{
	while (node->left)
	{
		execute(node->left, meta->env);
		check_node(node, meta->env);
	}
	while (node->right)
	{
		execute(node->right, meta->env);
		check_node(node, meta);
	}
}

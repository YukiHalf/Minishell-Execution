#include "execution_inc/execution.h"

// char **filter_cmd(char *cmd)
//{
//	char **s_cmd;
//	s_cmd = ft_split(cmd,' ');

void	debug_data(t_meta *meta)
{
	t_token	*echo_cmd;
	t_token	*echo_arg;
	t_token	*pipe_node;
	t_token	*grep_cmd;
	t_token	*grep_arg;

	// Allocate all nodes
	echo_cmd = malloc(sizeof(t_token));
	echo_arg = malloc(sizeof(t_token));
	pipe_node = malloc(sizeof(t_token));
	grep_cmd = malloc(sizeof(t_token));
	grep_arg = malloc(sizeof(t_token));
	// Echo command node
	echo_cmd->type = T_TEXT;
	echo_cmd->value = ft_strdup("echo");
	echo_cmd->left = echo_arg;
	echo_cmd->right = NULL; // Next argument
	echo_cmd->back = NULL;
	// Echo argument node ("hello world")
	echo_arg->type = T_TEXT;
	echo_arg->value = ft_strdup("hello world");
	echo_arg->left = NULL;
	echo_arg->right = NULL;
	echo_arg->back = echo_cmd; // Previous node
	// Pipe node (connects left and right commands)
	pipe_node->type = T_PIPE;
	pipe_node->value = NULL;
	pipe_node->left = echo_cmd;  // Left side: echo command chain
	pipe_node->right = grep_cmd; // Right side: grep command chain
	pipe_node->back = NULL;
	// Grep command node
	grep_cmd->type = T_TEXT;
	grep_cmd->value = ft_strdup("grep");
	grep_cmd->left = grep_arg;
	grep_cmd->right = NULL; // Next argument
	grep_cmd->back = NULL;
	// Grep argument node ("a")
	grep_arg->type = T_TEXT;
	grep_arg->value = ft_strdup("a");
	grep_arg->left = NULL;
	grep_arg->right = NULL;
	grep_arg->back = grep_cmd; // Previous node
	// Update back pointers for command chains
	echo_cmd->back = pipe_node;
	grep_cmd->back = pipe_node;
	// Set meta head to the root (pipe)
	meta->head = pipe_node;
}

void	debug_print(t_token *node, char **s_cmd, int *index)
{
	char	*tmp;

	if (!node)
		return ;
	if (node->left)
		debug_print(node->left, s_cmd, index);
	if (node->right)
		debug_print(node->right, s_cmd, index);
	if (!node->left && !node->right)
	{
		if (node->type == T_TEXT)
		{
			s_cmd[*index] = ft_strdup(node->value);
			(*index)++;
		}
	}
}

// void	debug_buildin(t_meta *meta)
//{

//	if (strcmp(meta->head->value, "pwd") == 0)
//		printf("%s\n",b_pwd());
//	else if(strcmp(meta->head->value,"cd") == 0)
//		b_cd(meta);
//	//else if (strcmp(meta->head->value,"exit") == 0)
//	//	b_exit(meta);
//	//else if(strcmp(meta->head->value,"echo") == 0)
//		//b_echo(meta);
//}

int	main(int argc, char **argv, char **env)
{
	t_meta	meta;
	char	**s_cmd;
	int		i;
	int		j;
	int		index;

	i = 0;
	s_cmd = malloc(sizeof(char *) * 10);
	// while (i < 10)
	//{
	//	s_cmd[i] = malloc(sizeof(char) * 100);
	//	j = 0;
	//	while (j <= 100)
	//	{
	//		s_cmd[i][j] = 0;
	//		j++;
	//	}
	//	i++;
	// }
	i = 0;
	// const char	*prompt = "test > ";
	//	char *line;
	// while (1)
	//{
	// line = readline(prompt);
	// if (!line)
	//{
	//	printf("exit\n");
	//	break ;
	// }
	// if (*line == '\0')
	//{
	//	free(line);
	//	continue ;
	// }
	debug_data(&meta);
	index = 0;
	debug_print(meta.head, s_cmd, &index);
	i = 0;
	while (i < 10)
	{
		printf("%s\n", s_cmd[i]);
		i++;
	}
	// load_data(&meta,line);
	// add_history(line);
	// debug_buildin(&meta);
	// free(line);
	//}
	// clear_history();
	return (0);
}

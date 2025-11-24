#include "execution_inc/execution.h"

// Command: echo hello | grep h && ls -la || pwd
void	debug_data_complex(t_meta *meta)
{
	t_token	*echo_cmd;
	t_token	*grep_cmd;
	t_token	*ls_cmd;
	t_token	*pwd_cmd;
	t_token	*pipe_node;
	t_token	*and_node;
	t_token	*or_node;

	// Allocate all nodes
	echo_cmd = malloc(sizeof(t_token));
	grep_cmd = malloc(sizeof(t_token));
	ls_cmd = malloc(sizeof(t_token));
	pwd_cmd = malloc(sizeof(t_token));
	pipe_node = malloc(sizeof(t_token));
	and_node = malloc(sizeof(t_token));
	or_node = malloc(sizeof(t_token));
	// Echo command: echo hello
	echo_cmd->type = T_TEXT;
	echo_cmd->value = ft_strdup("echo");
	echo_cmd->s_cmd = malloc(sizeof(char *) * 3);
	echo_cmd->s_cmd[0] = ft_strdup("echo");
	echo_cmd->s_cmd[1] = ft_strdup("hello");
	echo_cmd->s_cmd[2] = NULL;
	echo_cmd->left = NULL;
	echo_cmd->right = NULL;
	echo_cmd->back = NULL;
	echo_cmd->redirections = NULL;
	// Grep command: grep h
	grep_cmd->type = T_TEXT;
	grep_cmd->value = ft_strdup("grep");
	grep_cmd->s_cmd = malloc(sizeof(char *) * 3);
	grep_cmd->s_cmd[0] = ft_strdup("grep");
	grep_cmd->s_cmd[1] = ft_strdup("h");
	grep_cmd->s_cmd[2] = NULL;
	grep_cmd->left = NULL;
	grep_cmd->right = NULL;
	grep_cmd->back = NULL;
	grep_cmd->redirections = NULL;
	// Pipe node: echo hello | grep h
	pipe_node->type = T_PIPE;
	pipe_node->value = NULL;
	pipe_node->s_cmd = NULL;
	pipe_node->left = echo_cmd;
	pipe_node->right = grep_cmd;
	pipe_node->back = NULL;
	pipe_node->redirections = NULL;
	echo_cmd->back = pipe_node;
	grep_cmd->back = pipe_node;
	// Ls command: ls -la
	ls_cmd->type = T_TEXT;
	ls_cmd->value = ft_strdup("ls");
	ls_cmd->s_cmd = malloc(sizeof(char *) * 3);
	ls_cmd->s_cmd[0] = ft_strdup("ls");
	ls_cmd->s_cmd[1] = ft_strdup("-la");
	ls_cmd->s_cmd[2] = NULL;
	ls_cmd->left = NULL;
	ls_cmd->right = NULL;
	ls_cmd->back = NULL;
	ls_cmd->redirections = NULL;
	// AND node: (echo hello | grep h) && ls -la
	and_node->type = T_AND;
	and_node->value = NULL;
	and_node->s_cmd = NULL;
	and_node->left = pipe_node;
	and_node->right = ls_cmd;
	and_node->back = NULL;
	and_node->redirections = NULL;
	pipe_node->back = and_node;
	ls_cmd->back = and_node;
	// Pwd command
	pwd_cmd->type = T_TEXT;
	pwd_cmd->value = ft_strdup("pwd");
	pwd_cmd->s_cmd = malloc(sizeof(char *) * 2);
	pwd_cmd->s_cmd[0] = ft_strdup("pwd");
	pwd_cmd->s_cmd[1] = NULL;
	pwd_cmd->left = NULL;
	pwd_cmd->right = NULL;
	pwd_cmd->back = NULL;
	pwd_cmd->redirections = NULL;
	// OR node: ((echo hello | grep h) && ls -la) || pwd
	or_node->type = T_OR;
	or_node->value = NULL;
	or_node->s_cmd = NULL;
	or_node->left = and_node;
	or_node->right = pwd_cmd;
	or_node->back = NULL;
	or_node->redirections = NULL;
	and_node->back = or_node;
	pwd_cmd->back = or_node;
	// Set meta head to the root (OR node)
	meta->head = or_node;
}

// Another complex example: cat file.txt | grep error | wc -l && echo done
	//|| echo failed
void	debug_data_complex2(t_meta *meta)
{
	t_token	*cat_cmd;
	t_token	*grep_cmd;
	t_token	*wc_cmd;
	t_token	*echo_done;
	t_token	*echo_failed;
	t_token	*pipe1;
	t_token	*pipe2;
	t_token	*and_node;
	t_token	*or_node;

	// Allocate all nodes
	cat_cmd = malloc(sizeof(t_token));
	grep_cmd = malloc(sizeof(t_token));
	wc_cmd = malloc(sizeof(t_token));
	echo_done = malloc(sizeof(t_token));
	echo_failed = malloc(sizeof(t_token));
	pipe1 = malloc(sizeof(t_token));
	pipe2 = malloc(sizeof(t_token));
	and_node = malloc(sizeof(t_token));
	or_node = malloc(sizeof(t_token));
	// Cat command: cat file.txt
	cat_cmd->type = T_TEXT;
	cat_cmd->value = ft_strdup("cat");
	cat_cmd->s_cmd = malloc(sizeof(char *) * 3);
	cat_cmd->s_cmd[0] = ft_strdup("cat");
	cat_cmd->s_cmd[1] = ft_strdup("file.txt");
	cat_cmd->s_cmd[2] = NULL;
	cat_cmd->left = NULL;
	cat_cmd->right = NULL;
	cat_cmd->back = NULL;
	cat_cmd->redirections = NULL;
	// Grep command: grep error
	grep_cmd->type = T_TEXT;
	grep_cmd->value = ft_strdup("grep");
	grep_cmd->s_cmd = malloc(sizeof(char *) * 3);
	grep_cmd->s_cmd[0] = ft_strdup("grep");
	grep_cmd->s_cmd[1] = ft_strdup("error");
	grep_cmd->s_cmd[2] = NULL;
	grep_cmd->left = NULL;
	grep_cmd->right = NULL;
	grep_cmd->back = NULL;
	grep_cmd->redirections = NULL;
	// First pipe: cat file.txt | grep error
	pipe1->type = T_PIPE;
	pipe1->value = NULL;
	pipe1->s_cmd = NULL;
	pipe1->left = cat_cmd;
	pipe1->right = grep_cmd;
	pipe1->back = NULL;
	pipe1->redirections = NULL;
	cat_cmd->back = pipe1;
	grep_cmd->back = pipe1;
	// Wc command: wc -l
	wc_cmd->type = T_TEXT;
	wc_cmd->value = ft_strdup("wc");
	wc_cmd->s_cmd = malloc(sizeof(char *) * 3);
	wc_cmd->s_cmd[0] = ft_strdup("wc");
	wc_cmd->s_cmd[1] = ft_strdup("-l");
	wc_cmd->s_cmd[2] = NULL;
	wc_cmd->left = NULL;
	wc_cmd->right = NULL;
	wc_cmd->back = NULL;
	wc_cmd->redirections = NULL;
	// Second pipe: (cat file.txt | grep error) | wc -l
	pipe2->type = T_PIPE;
	pipe2->value = NULL;
	pipe2->s_cmd = NULL;
	pipe2->left = pipe1;
	pipe2->right = wc_cmd;
	pipe2->back = NULL;
	pipe2->redirections = NULL;
	pipe1->back = pipe2;
	wc_cmd->back = pipe2;
	// Echo done command
	echo_done->type = T_TEXT;
	echo_done->value = ft_strdup("echo");
	echo_done->s_cmd = malloc(sizeof(char *) * 3);
	echo_done->s_cmd[0] = ft_strdup("echo");
	echo_done->s_cmd[1] = ft_strdup("done");
	echo_done->s_cmd[2] = NULL;
	echo_done->left = NULL;
	echo_done->right = NULL;
	echo_done->back = NULL;
	echo_done->redirections = NULL;
	// AND node: (cat file.txt | grep error | wc -l) && echo done
	and_node->type = T_AND;
	and_node->value = NULL;
	and_node->s_cmd = NULL;
	and_node->left = pipe2;
	and_node->right = echo_done;
	and_node->back = NULL;
	and_node->redirections = NULL;
	pipe2->back = and_node;
	echo_done->back = and_node;
	// Echo failed command
	echo_failed->type = T_TEXT;
	echo_failed->value = ft_strdup("echo");
	echo_failed->s_cmd = malloc(sizeof(char *) * 3);
	echo_failed->s_cmd[0] = ft_strdup("echo");
	echo_failed->s_cmd[1] = ft_strdup("failed");
	echo_failed->s_cmd[2] = NULL;
	echo_failed->left = NULL;
	echo_failed->right = NULL;
	echo_failed->back = NULL;
	echo_failed->redirections = NULL;
	// OR node: ((cat file.txt | grep error | wc -l) && echo done)
	//	|| echo failed
	or_node->type = T_OR;
	or_node->value = NULL;
	or_node->s_cmd = NULL;
	or_node->left = and_node;
	or_node->right = echo_failed;
	or_node->back = NULL;
	or_node->redirections = NULL;
	and_node->back = or_node;
	echo_failed->back = or_node;
	// Set meta head to the root (OR node)
	meta->head = or_node;
}

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
	echo_cmd->value = ft_strdup("cd");
	echo_cmd->s_cmd = malloc(sizeof(char *) * 3); // ✅ ADD THIS
	echo_cmd->s_cmd[0] = ft_strdup("cd");         // ✅ ADD THIS
	echo_cmd->s_cmd[1] = ft_strdup("checks");   // ✅ ADD THIS
	echo_cmd->s_cmd[2] = NULL;                    // ✅ ADD THIS
	echo_cmd->left = echo_arg;
	echo_cmd->right = NULL;
	echo_cmd->back = NULL;
	echo_cmd->redirections = NULL; // ✅ ADD THIS
	// Echo argument node ("hello world")
	echo_arg->type = T_TEXT;
	echo_arg->value = ft_strdup("checks");
	echo_arg->s_cmd = NULL; // ✅ ADD THIS (args don't need s_cmd)
	echo_arg->left = NULL;
	echo_arg->right = NULL;
	echo_arg->back = echo_cmd;
	echo_arg->redirections = NULL; // ✅ ADD THIS
	// Pipe node (connects left and right commands)
	pipe_node->type = T_PIPE;
	pipe_node->value = NULL;
	pipe_node->s_cmd = NULL; // ✅ ADD THIS (pipes don't have s_cmd)
	pipe_node->left = echo_cmd;
	pipe_node->right = grep_cmd;
	pipe_node->back = NULL;
	pipe_node->redirections = NULL; // ✅ ADD THIS
	// Grep command node
	grep_cmd->type = T_TEXT;
	grep_cmd->value = ft_strdup("pwd");
	grep_cmd->s_cmd = malloc(sizeof(char *) * 3); // ✅ ADD THIS
	grep_cmd->s_cmd[0] = ft_strdup("pwd");       // ✅ ADD THIS
	grep_cmd->s_cmd[1] = NULL;          // ✅ ADD THIS
	grep_cmd->s_cmd[2] = NULL;                    // ✅ ADD THIS
	grep_cmd->left = NULL;
	grep_cmd->right = NULL;
	grep_cmd->back = NULL;
	grep_cmd->redirections = NULL; // ✅ ADD THIS
	// Grep argument node ("a")
	grep_arg->type = T_TEXT;
	grep_arg->value = ft_strdup("a");
	grep_arg->s_cmd = NULL; // ✅ ADD THIS
	grep_arg->left = NULL;
	grep_arg->right = NULL;
	grep_arg->back = grep_cmd;
	grep_arg->redirections = NULL; // ✅ ADD THIS
	// Update back pointers for command chains
	echo_cmd->back = pipe_node;
	grep_cmd->back = pipe_node;
	// Set meta head to the root (pipe)
	meta->head = pipe_node;
}

int	main(int argc, char **argv, char **env)
{
	t_meta	meta;

	meta.last_exit_code = 0;
	debug_data(&meta);
	// execute(&meta.head,env);
	meta.last_exit_code = check_node(meta.head, env);
	printf("\n EXIT CODE: %d \n", meta.last_exit_code);
	return (0);
}

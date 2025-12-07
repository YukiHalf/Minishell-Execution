#include "execution_inc/execution.h"

// Command: ls -la | grep .c > output.txt && cat output.txt | wc -l
//	|| echo "No C files"
void	debug_data_complex3(t_meta *meta)
{
	t_token	*ls_cmd;
	t_token	*grep_cmd;
	t_token	*cat_cmd;
	t_token	*wc_cmd;
	t_token	*echo_cmd;
	t_token	*pipe1;
	t_token	*pipe2;
	t_token	*and_node;
	t_token	*or_node;
	t_redir	*out_redir;

	// Allocate all nodes
	ls_cmd = malloc(sizeof(t_token));
	grep_cmd = malloc(sizeof(t_token));
	cat_cmd = malloc(sizeof(t_token));
	wc_cmd = malloc(sizeof(t_token));
	echo_cmd = malloc(sizeof(t_token));
	pipe1 = malloc(sizeof(t_token));
	pipe2 = malloc(sizeof(t_token));
	and_node = malloc(sizeof(t_token));
	or_node = malloc(sizeof(t_token));
	out_redir = malloc(sizeof(t_redir));
	// ls -la
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
	// grep .c (with output redirection)
	grep_cmd->type = T_TEXT;
	grep_cmd->value = ft_strdup("grep");
	grep_cmd->s_cmd = malloc(sizeof(char *) * 3);
	grep_cmd->s_cmd[0] = ft_strdup("grep");
	grep_cmd->s_cmd[1] = ft_strdup(".c");
	grep_cmd->s_cmd[2] = NULL;
	grep_cmd->left = NULL;
	grep_cmd->right = NULL;
	grep_cmd->back = NULL;
	// Setup output redirection > output.txt
	out_redir->type = OUT_FD;
	out_redir->path = ft_strdup("output.txt");
	out_redir->next = NULL;
	grep_cmd->redirections = out_redir;
	// First pipe: ls -la | grep .c > output.txt
	pipe1->type = T_PIPE;
	pipe1->value = NULL;
	pipe1->s_cmd = NULL;
	pipe1->left = ls_cmd;
	pipe1->right = grep_cmd;
	pipe1->back = NULL;
	pipe1->redirections = NULL;
	ls_cmd->back = pipe1;
	grep_cmd->back = pipe1;
	// cat output.txt
	cat_cmd->type = T_TEXT;
	cat_cmd->value = ft_strdup("cat");
	cat_cmd->s_cmd = malloc(sizeof(char *) * 3);
	cat_cmd->s_cmd[0] = ft_strdup("cat");
	cat_cmd->s_cmd[1] = ft_strdup("output.txt");
	cat_cmd->s_cmd[2] = NULL;
	cat_cmd->left = NULL;
	cat_cmd->right = NULL;
	cat_cmd->back = NULL;
	cat_cmd->redirections = NULL;
	// wc -l
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
	// Second pipe: cat output.txt | wc -l
	pipe2->type = T_PIPE;
	pipe2->value = NULL;
	pipe2->s_cmd = NULL;
	pipe2->left = cat_cmd;
	pipe2->right = wc_cmd;
	pipe2->back = NULL;
	pipe2->redirections = NULL;
	cat_cmd->back = pipe2;
	wc_cmd->back = pipe2;
	// AND node: (ls -la | grep .c > output.txt) && (cat output.txt | wc -l)
	and_node->type = T_AND;
	and_node->value = NULL;
	and_node->s_cmd = NULL;
	and_node->left = pipe1;
	and_node->right = pipe2;
	and_node->back = NULL;
	and_node->redirections = NULL;
	pipe1->back = and_node;
	pipe2->back = and_node;
	// echo "No C files"
	echo_cmd->type = T_TEXT;
	echo_cmd->value = ft_strdup("echo");
	echo_cmd->s_cmd = malloc(sizeof(char *) * 3);
	echo_cmd->s_cmd[0] = ft_strdup("echo");
	echo_cmd->s_cmd[1] = ft_strdup("No C files");
	echo_cmd->s_cmd[2] = NULL;
	echo_cmd->left = NULL;
	echo_cmd->right = NULL;
	echo_cmd->back = NULL;
	echo_cmd->redirections = NULL;
	// OR node: ((ls -la | grep .c > output.txt) && (cat output.txt | wc -l))
	//	|| echo "No C files"
	or_node->type = T_OR;
	or_node->value = NULL;
	or_node->s_cmd = NULL;
	or_node->left = and_node;
	or_node->right = echo_cmd;
	or_node->back = NULL;
	or_node->redirections = NULL;
	and_node->back = or_node;
	echo_cmd->back = or_node;
	meta->head = or_node;
}

// Command: cd /tmp && pwd && export TEST=hello && env | grep TEST
//	|| echo "Failed"
void	debug_data_complex4(t_meta *meta)
{
	t_token	*cd_cmd;
	t_token	*pwd_cmd;
	t_token	*export_cmd;
	t_token	*env_cmd;
	t_token	*grep_cmd;
	t_token	*echo_cmd;
	t_token	*pipe_node;
	t_token	*and1;
	t_token	*and2;
	t_token	*and3;
	t_token	*or_node;

	// Allocate nodes
	cd_cmd = malloc(sizeof(t_token));
	pwd_cmd = malloc(sizeof(t_token));
	export_cmd = malloc(sizeof(t_token));
	env_cmd = malloc(sizeof(t_token));
	grep_cmd = malloc(sizeof(t_token));
	echo_cmd = malloc(sizeof(t_token));
	pipe_node = malloc(sizeof(t_token));
	and1 = malloc(sizeof(t_token));
	and2 = malloc(sizeof(t_token));
	and3 = malloc(sizeof(t_token));
	or_node = malloc(sizeof(t_token));
	// cd /tmp
	cd_cmd->type = T_TEXT;
	cd_cmd->value = ft_strdup("cd");
	cd_cmd->s_cmd = malloc(sizeof(char *) * 3);
	cd_cmd->s_cmd[0] = ft_strdup("cd");
	cd_cmd->s_cmd[1] = ft_strdup("/tmp");
	cd_cmd->s_cmd[2] = NULL;
	cd_cmd->left = NULL;
	cd_cmd->right = NULL;
	cd_cmd->back = NULL;
	cd_cmd->redirections = NULL;
	// pwd
	pwd_cmd->type = T_TEXT;
	pwd_cmd->value = ft_strdup("pwd");
	pwd_cmd->s_cmd = malloc(sizeof(char *) * 2);
	pwd_cmd->s_cmd[0] = ft_strdup("pwd");
	pwd_cmd->s_cmd[1] = NULL;
	pwd_cmd->left = NULL;
	pwd_cmd->right = NULL;
	pwd_cmd->back = NULL;
	pwd_cmd->redirections = NULL;
	// AND1: cd /tmp && pwd
	and1->type = T_AND;
	and1->value = NULL;
	and1->s_cmd = NULL;
	and1->left = cd_cmd;
	and1->right = pwd_cmd;
	and1->back = NULL;
	and1->redirections = NULL;
	cd_cmd->back = and1;
	pwd_cmd->back = and1;
	// export TEST=hello
	export_cmd->type = T_TEXT;
	export_cmd->value = ft_strdup("export");
	export_cmd->s_cmd = malloc(sizeof(char *) * 3);
	export_cmd->s_cmd[0] = ft_strdup("export");
	export_cmd->s_cmd[1] = ft_strdup("TEST=hello");
	export_cmd->s_cmd[2] = NULL;
	export_cmd->left = NULL;
	export_cmd->right = NULL;
	export_cmd->back = NULL;
	export_cmd->redirections = NULL;
	// AND2: (cd /tmp && pwd) && export TEST=hello
	and2->type = T_AND;
	and2->value = NULL;
	and2->s_cmd = NULL;
	and2->left = and1;
	and2->right = export_cmd;
	and2->back = NULL;
	and2->redirections = NULL;
	and1->back = and2;
	export_cmd->back = and2;
	// env
	env_cmd->type = T_TEXT;
	env_cmd->value = ft_strdup("env");
	env_cmd->s_cmd = malloc(sizeof(char *) * 2);
	env_cmd->s_cmd[0] = ft_strdup("env");
	env_cmd->s_cmd[1] = NULL;
	env_cmd->left = NULL;
	env_cmd->right = NULL;
	env_cmd->back = NULL;
	env_cmd->redirections = NULL;
	// grep TEST
	grep_cmd->type = T_TEXT;
	grep_cmd->value = ft_strdup("grep");
	grep_cmd->s_cmd = malloc(sizeof(char *) * 3);
	grep_cmd->s_cmd[0] = ft_strdup("grep");
	grep_cmd->s_cmd[1] = ft_strdup("TEST");
	grep_cmd->s_cmd[2] = NULL;
	grep_cmd->left = NULL;
	grep_cmd->right = NULL;
	grep_cmd->back = NULL;
	grep_cmd->redirections = NULL;
	// PIPE: env | grep TEST
	pipe_node->type = T_PIPE;
	pipe_node->value = NULL;
	pipe_node->s_cmd = NULL;
	pipe_node->left = env_cmd;
	pipe_node->right = grep_cmd;
	pipe_node->back = NULL;
	pipe_node->redirections = NULL;
	env_cmd->back = pipe_node;
	grep_cmd->back = pipe_node;
	// AND3: ((cd /tmp && pwd) && export TEST=hello) && (env | grep TEST)
	and3->type = T_AND;
	and3->value = NULL;
	and3->s_cmd = NULL;
	and3->left = and2;
	and3->right = pipe_node;
	and3->back = NULL;
	and3->redirections = NULL;
	and2->back = and3;
	pipe_node->back = and3;
	// echo "Failed"
	echo_cmd->type = T_TEXT;
	echo_cmd->value = ft_strdup("echo");
	echo_cmd->s_cmd = malloc(sizeof(char *) * 3);
	echo_cmd->s_cmd[0] = ft_strdup("echo");
	echo_cmd->s_cmd[1] = ft_strdup("Failed");
	echo_cmd->s_cmd[2] = NULL;
	echo_cmd->left = NULL;
	echo_cmd->right = NULL;
	echo_cmd->back = NULL;
	echo_cmd->redirections = NULL;
	// OR: (((cd /tmp && pwd) && export TEST=hello) && (env | grep TEST))
	//	|| echo "Failed"
	or_node->type = T_OR;
	or_node->value = NULL;
	or_node->s_cmd = NULL;
	or_node->left = and3;
	or_node->right = echo_cmd;
	or_node->back = NULL;
	or_node->redirections = NULL;
	and3->back = or_node;
	echo_cmd->back = or_node;
	meta->head = or_node;
}

// Command: echo a | cat | cat | cat && echo b | cat | cat || pwd
void	debug_data_complex5(t_meta *meta)
{
	t_token	*pwd_cmd;

	t_token *echo_a, *cat1, *cat2, *cat3;
	t_token *echo_b, *cat4, *cat5;
	t_token *pipe1, *pipe2, *pipe3, *pipe4, *pipe5;
	t_token *and_node, *or_node;
	// Allocate all
	echo_a = malloc(sizeof(t_token));
	cat1 = malloc(sizeof(t_token));
	cat2 = malloc(sizeof(t_token));
	cat3 = malloc(sizeof(t_token));
	echo_b = malloc(sizeof(t_token));
	cat4 = malloc(sizeof(t_token));
	cat5 = malloc(sizeof(t_token));
	pwd_cmd = malloc(sizeof(t_token));
	pipe1 = malloc(sizeof(t_token));
	pipe2 = malloc(sizeof(t_token));
	pipe3 = malloc(sizeof(t_token));
	pipe4 = malloc(sizeof(t_token));
	pipe5 = malloc(sizeof(t_token));
	and_node = malloc(sizeof(t_token));
	or_node = malloc(sizeof(t_token));
	// echo a
	echo_a->type = T_TEXT;
	echo_a->value = ft_strdup("echo");
	echo_a->s_cmd = malloc(sizeof(char *) * 3);
	echo_a->s_cmd[0] = ft_strdup("echo");
	echo_a->s_cmd[1] = ft_strdup("a");
	echo_a->s_cmd[2] = NULL;
	echo_a->left = NULL;
	echo_a->right = NULL;
	echo_a->back = NULL;
	echo_a->redirections = NULL;
	// cat (1st)
	cat1->type = T_TEXT;
	cat1->value = ft_strdup("cat");
	cat1->s_cmd = malloc(sizeof(char *) * 2);
	cat1->s_cmd[0] = ft_strdup("cat");
	cat1->s_cmd[1] = NULL;
	cat1->left = NULL;
	cat1->right = NULL;
	cat1->back = NULL;
	cat1->redirections = NULL;
	// pipe1: echo a | cat
	pipe1->type = T_PIPE;
	pipe1->value = NULL;
	pipe1->s_cmd = NULL;
	pipe1->left = echo_a;
	pipe1->right = cat1;
	pipe1->back = NULL;
	pipe1->redirections = NULL;
	echo_a->back = pipe1;
	cat1->back = pipe1;
	// cat (2nd)
	cat2->type = T_TEXT;
	cat2->value = ft_strdup("cat");
	cat2->s_cmd = malloc(sizeof(char *) * 2);
	cat2->s_cmd[0] = ft_strdup("cat");
	cat2->s_cmd[1] = NULL;
	cat2->left = NULL;
	cat2->right = NULL;
	cat2->back = NULL;
	cat2->redirections = NULL;
	// pipe2: (echo a | cat) | cat
	pipe2->type = T_PIPE;
	pipe2->value = NULL;
	pipe2->s_cmd = NULL;
	pipe2->left = pipe1;
	pipe2->right = cat2;
	pipe2->back = NULL;
	pipe2->redirections = NULL;
	pipe1->back = pipe2;
	cat2->back = pipe2;
	// cat (3rd)
	cat3->type = T_TEXT;
	cat3->value = ft_strdup("cat");
	cat3->s_cmd = malloc(sizeof(char *) * 2);
	cat3->s_cmd[0] = ft_strdup("cat");
	cat3->s_cmd[1] = NULL;
	cat3->left = NULL;
	cat3->right = NULL;
	cat3->back = NULL;
	cat3->redirections = NULL;
	// pipe3: ((echo a | cat) | cat) | cat
	pipe3->type = T_PIPE;
	pipe3->value = NULL;
	pipe3->s_cmd = NULL;
	pipe3->left = pipe2;
	pipe3->right = cat3;
	pipe3->back = NULL;
	pipe3->redirections = NULL;
	pipe2->back = pipe3;
	cat3->back = pipe3;
	// echo b
	echo_b->type = T_TEXT;
	echo_b->value = ft_strdup("echo");
	echo_b->s_cmd = malloc(sizeof(char *) * 3);
	echo_b->s_cmd[0] = ft_strdup("echo");
	echo_b->s_cmd[1] = ft_strdup("b");
	echo_b->s_cmd[2] = NULL;
	echo_b->left = NULL;
	echo_b->right = NULL;
	echo_b->back = NULL;
	echo_b->redirections = NULL;
	// cat (4th)
	cat4->type = T_TEXT;
	cat4->value = ft_strdup("cat");
	cat4->s_cmd = malloc(sizeof(char *) * 2);
	cat4->s_cmd[0] = ft_strdup("cat");
	cat4->s_cmd[1] = NULL;
	cat4->left = NULL;
	cat4->right = NULL;
	cat4->back = NULL;
	cat4->redirections = NULL;
	// pipe4: echo b | cat
	pipe4->type = T_PIPE;
	pipe4->value = NULL;
	pipe4->s_cmd = NULL;
	pipe4->left = echo_b;
	pipe4->right = cat4;
	pipe4->back = NULL;
	pipe4->redirections = NULL;
	echo_b->back = pipe4;
	cat4->back = pipe4;
	// cat (5th)
	cat5->type = T_TEXT;
	cat5->value = ft_strdup("cat");
	cat5->s_cmd = malloc(sizeof(char *) * 2);
	cat5->s_cmd[0] = ft_strdup("cat");
	cat5->s_cmd[1] = NULL;
	cat5->left = NULL;
	cat5->right = NULL;
	cat5->back = NULL;
	cat5->redirections = NULL;
	// pipe5: (echo b | cat) | cat
	pipe5->type = T_PIPE;
	pipe5->value = NULL;
	pipe5->s_cmd = NULL;
	pipe5->left = pipe4;
	pipe5->right = cat5;
	pipe5->back = NULL;
	pipe5->redirections = NULL;
	pipe4->back = pipe5;
	cat5->back = pipe5;
	// AND: (echo a | cat | cat | cat) && (echo b | cat | cat)
	and_node->type = T_AND;
	and_node->value = NULL;
	and_node->s_cmd = NULL;
	and_node->left = pipe3;
	and_node->right = pipe5;
	and_node->back = NULL;
	and_node->redirections = NULL;
	pipe3->back = and_node;
	pipe5->back = and_node;
	// pwd
	pwd_cmd->type = T_TEXT;
	pwd_cmd->value = ft_strdup("pwd");
	pwd_cmd->s_cmd = malloc(sizeof(char *) * 2);
	pwd_cmd->s_cmd[0] = ft_strdup("pwd");
	pwd_cmd->s_cmd[1] = NULL;
	pwd_cmd->left = NULL;
	pwd_cmd->right = NULL;
	pwd_cmd->back = NULL;
	pwd_cmd->redirections = NULL;
	// OR: ((echo a | cat | cat | cat) && (echo b | cat | cat)) || pwd
	or_node->type = T_OR;
	or_node->value = NULL;
	or_node->s_cmd = NULL;
	or_node->left = and_node;
	or_node->right = pwd_cmd;
	or_node->back = NULL;
	or_node->redirections = NULL;
	and_node->back = or_node;
	pwd_cmd->back = or_node;
	meta->head = or_node;
}

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
	echo_cmd->value = ft_strdup("export");
	echo_cmd->s_cmd = malloc(sizeof(char *) * 3); // ✅ ADD THIS
	echo_cmd->s_cmd[0] = ft_strdup("export");     // ✅ ADD THIS
	echo_cmd->s_cmd[1] = ft_strdup("var=35");     // ✅ ADD THIS
	echo_cmd->s_cmd[2] = NULL;                    // ✅ ADD THIS
	echo_cmd->left = echo_arg;
	echo_cmd->right = NULL;
	echo_cmd->back = NULL;
	echo_cmd->redirections = NULL; // ✅ ADD THIS
	// Echo argument node ("hello world")
	echo_arg->type = T_TEXT;
	echo_arg->value = ft_strdup("var=35");
	echo_arg->s_cmd = NULL; // ✅ ADD THIS (args don't need s_cmd)
	echo_arg->left = NULL;
	echo_arg->right = NULL;
	echo_arg->back = echo_cmd;
	echo_arg->redirections = NULL; // ✅ ADD THIS
	// Pipe node (connects left and right commands)
	pipe_node->type = T_AND;
	pipe_node->value = NULL;
	pipe_node->s_cmd = NULL; // ✅ ADD THIS (pipes don't have s_cmd)
	pipe_node->left = echo_cmd;
	pipe_node->right = grep_cmd;
	pipe_node->back = NULL;
	pipe_node->redirections = NULL; // ✅ ADD THIS
	// Grep command node
	grep_cmd->type = T_TEXT;
	grep_cmd->value = ft_strdup("export");
	grep_cmd->s_cmd = malloc(sizeof(char *) * 3); // ✅ ADD THIS
	grep_cmd->s_cmd[0] = ft_strdup("export");     // ✅ ADD THIS
	grep_cmd->s_cmd[1] = NULL;                    // ✅ ADD THIS
	grep_cmd->s_cmd[2] = NULL;                    // ✅ ADD THIS
	grep_cmd->left = NULL;
	grep_cmd->right = NULL;
	grep_cmd->back = NULL;
	grep_cmd->redirections = NULL; // ✅ ADD THIS
	// Grep argument node ("a")
	grep_arg->type = T_TEXT;
	grep_arg->value = ft_strdup("");
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

void	load_env(t_meta *meta, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = count_env(env);
	meta->env = malloc((sizeof(char *) * len) + 1);
	if (!meta->env)
		return ;
	while (env[i])
	{
		meta->env[i] = ft_strdup(env[i]);
		i++;
	}
	meta->env[i] = NULL;
}

int	main(int argc, char **argv, char **env)
{
	t_meta	meta;
	char	cwd[PATH_MAX];

	meta.last_exit_code = 0;
	load_env(&meta, env);

	if (getcwd(cwd, PATH_MAX))
		meta.pwd = ft_strdup(cwd);
	else
		meta.pwd = ft_strdup("/");
		debug_data_complex4(&meta);

	meta.last_exit_code = check_node(meta.head, &meta);
	printf("\n EXIT CODE: %d \n", meta.last_exit_code);
	return (0);
}

#include "../execution_inc/execution.h"

void	child_right(t_token *cmd, int *fd_main, char **env)
{
	int	fd;

	close(fd_main[1]);
	dup2(fd_main[0], STDIN_FILENO);
	close(fd_main[0]);
	if (cmd->redirections && cmd->redirections->type == OUT_FD)
	{
		fd = open(cmd->redirections->path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
		{
			perror(cmd->redirections->path);
			exit(1);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	exec_cmd(cmd, env);
	exit(1);
}

void	child_left(t_token *cmd, int *fd_main, char **env)
{
	int	fd;

	close(fd_main[0]);
	if (cmd->redirections && cmd->redirections->type == IN_FD)
	{
		fd = open(cmd->redirections->path, O_RDONLY);
		if (fd < 0)
		{
			perror(cmd->redirections->path);
			exit(1);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	dup2(fd_main[1], STDOUT_FILENO);
	close(fd_main[1]);
	exec_cmd(cmd, env);
	exit(1);
}

int	pipe_root(t_token *exec, char **env)
{
	int	fd_main[2];
	int	status;

	pid_t pid1, pid2;
	if (pipe(fd_main) == -1)
		return (perror("pipe"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork"), 1);
	if (pid1 == 0)
		child_left(exec->left, fd_main, env);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork"), 1);
	if (pid2 == 0)
		child_right(exec->right, fd_main, env);
	close(fd_main[0]);
	close(fd_main[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	return (get_exit_code(status));
}

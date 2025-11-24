#include "../execution_inc/execution.h"

char	*filter_env(char **env)
{
	int		i;
	int		j;
	char	*env_box;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		env_box = ft_substr(env[i], 0, j);
		if (ft_strcmp("PATH", env_box) == 0)
		{
			free(env_box);
			return (env[i] + j + 1);
		}
		free(env_box);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**path;
	char	*check_path;
	char	*exec;

	path = ft_split(filter_env(env), ':');
	i = -1;
	while (path[++i])
	{
		check_path = ft_strjoin(path[i], "/");
		exec = ft_strjoin(check_path, cmd);
		free(check_path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free2d(path);
			return (exec);
		}
		free(exec);
	}
	free2d(path);
	return (cmd);
}

int	exec_cmd(t_token *cmd, char **env)
{
	char	*path;

	path = get_path(cmd->s_cmd[0], env);
	if (execve(path, cmd->s_cmd, env) == -1)
	{
		// free;
		perror(cmd->s_cmd[0]);
		exit(127);
	}
	return (1);
}

int	execute_simple_cmd(t_token *cmd, char **env)
{
	pid_t	pid;
	int		status;
	int		buildin_exit;

	buildin_exit = check_build_in(cmd);
	if (buildin_exit >= 0)
		return (buildin_exit);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);
	if (pid == 0)
	{
		exec_cmd(cmd, env);
		exit(1);
	}
	waitpid(pid, &status, 0);
	return (get_exit_code(status));
}

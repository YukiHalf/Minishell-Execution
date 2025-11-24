#include "execution.h"

int	b_cd(t_token *cmd)
{
	char	*path;

	if (!cmd->s_cmd[1])
		path = getenv("HOME");
	else
		path = cmd->s_cmd[1];
	if (!path)
		return (printf("cd: HOME not set\n"), 1);
	if (chdir(path) == -1)
		return (perror("cd"), 1);
	return (0);
}

#include "execution.h"

bool	is_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	b_exit(t_token *cmd)
{
	int	exit_code;

	exit_code = 0;
	if (cmd->s_cmd[1] && is_num(cmd->s_cmd[1]))
	{
		exit_code = atoi(cmd->s_cmd[1]);
		exit(exit_code);
	}
	else if (!cmd->s_cmd[1])
	{
		exit(exit_code);
	}
	else
		perror("exit");
	return (0);
	// free everything , make sure all the processes finish corect?
	// maybe i need to use kill
}

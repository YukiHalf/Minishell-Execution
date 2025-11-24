#include "execution.h"

bool	flag_n(char *flag)
{
	int	i;

	i = 1;
	if (flag[0] == '-')
	{
		while (flag[i])
		{
			if (flag[i] != 'n')
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int	b_echo(t_token *cmd)
{
	int	i;

	i = 1;
	if (flag_n(cmd->s_cmd[1]))
		i = 2;
	while (cmd->s_cmd[i])
	{
		printf("%s", cmd->s_cmd[i]);
		if (cmd->s_cmd[i + 1])
			printf(" ");
		i++;
	}
	if (!flag_n(cmd->s_cmd[1]))
		printf("\n");
	return (0);
}

#include "execution.h"

int	b_env(char **env)
{
	int	i;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

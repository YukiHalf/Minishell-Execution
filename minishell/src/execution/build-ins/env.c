#include "execution.h"

int	b_env(t_meta *meta)
{
	int	i;

	i = 0;
	while (meta->env[i])
	{
		printf("%s\n", meta->env[i]);
		i++;
	}
	return (0);
}

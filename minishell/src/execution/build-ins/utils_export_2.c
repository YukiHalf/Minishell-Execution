#include "execution.h"

int	find_env_index(char **env, char *var)
{
	int	i;
	int	len;

	len = 0;
	while (var[len] && var[len] != '=')
		len++;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, len) == 0 && env[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

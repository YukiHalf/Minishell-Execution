#include "execution.h"

int	is_valid_identifier(char *cmd)
{
	int	i;

	if (!cmd || !cmd[0])
		return (0);
	if (!ft_isalpha(cmd[0]) && cmd[0] != '_')
		return (0);
	i = 1;
	while (cmd[i] && cmd[i] != '=')
	{
		if (!ft_isalnum(cmd[i]) && cmd[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	count_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	*get_name(char *var)
{
	int		len;
	char	*name;

	len = 0;
	while (var[len] && var[len] != '=')
		len++;
	name = ft_substr(var, 0, len);
	if (!name)
		return (NULL);
	return (name);
}

char	**copy_env(char **env, char *var, int count, int index)
{
	int		i;
	int		j;
	char	**new_env;

	i = -1;
	j = 0;
	new_env = malloc(sizeof(char *) * (count + 2));
	if (!new_env)
		return (NULL);
	while (++i < index)
	{
		new_env[j] = env[i];
		j++;
	}
	j++;
	while (i < count)
	{
		new_env[j] = env[i];
		i++;
		j++;
	}
	new_env[j] = NULL;
	return (new_env);
}

int	find_insert_index(char **env, char *var)
{
	int		i;
	char	*var_name;
	char	*env_name;
	int		cmp;

	var_name = get_name(var);
	i = 0;
	while (env[i])
	{
		env_name = get_name(env[i]);
		if (!env_name)
		{
			free(var_name);
			return (i);
		}
		cmp = ft_strcmp(var_name, env_name);
		free(env_name);
		if (cmp < 0)
		{
			free(var_name);
			return (i);
		}
		i++;
	}
	free(var_name);
	return (i);
}

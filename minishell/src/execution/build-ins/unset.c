#include "execution.h"

static int	find_var_index(char **env, char *var)
{
	int	i;
	int	len;

	len = ft_strlen(var);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, len) == 0 && env[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

static void remove_env_var(t_meta *meta, int index)
{
	int i;

	free(meta->env[index]);
	i = index;
	while(meta->env[i])
	{
		meta->env[i] = meta->env[i+1];
		i++;
	}
}


int	b_unset(t_token *cmd, t_meta *meta)
{
	int	i;
	int	index;

	if (!cmd->s_cmd[1])
		return (0);
	i = 1;
	while (cmd->s_cmd[i])
	{
		index = find_var_index(meta->env, cmd->s_cmd[i]);
		if (index >= 0)
			remove_env_var(meta, index);
		i++;
	}
}

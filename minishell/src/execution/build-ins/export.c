#include "execution.h"

static int	update_env_var(t_meta *meta, char *var, int index)
{
	free(meta->env[index]);
	meta->env[index] = ft_strdup(var);
	if (!meta->env[index])
		return (1);
	return (0);
}

static int	add_env_var(t_meta *meta, char *new_var)
{
	int		count;
	char	**new_env;
	int		i;

	count = count_env(meta->env);
	new_env = malloc(sizeof(char *) * (count + 2));
	while (!new_env)
		return (1);
	i = 0;
	while (i < count)
	{
		new_env[i] = meta->env[i];
		i++;
	}
	new_env[i] = ft_strdup(new_var);
	if (!new_env[i])
	{
		free(new_env);
		return (1);
	}
	new_env[i + 1] = NULL;
	free(meta->env);
	meta->env = new_env;
	return (0);
}

static void	print_export(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("declare -x %s\n", env[i]);
		i++;
	}
}

static void	process_env(t_meta *meta, t_token *cmd, int i)
{
	int	index;

	if (ft_strchr(cmd->s_cmd[i], '='))
	{
		index = find_env_index(meta->env, cmd->s_cmd[i]);
		if (index >= 0)
			update_env_var(meta, cmd->s_cmd[i], index);
		else
			add_env_var(meta, cmd->s_cmd[i]);
	}
}
int	b_export(t_token *cmd, t_meta *meta)
{
	int	exit_code;
	int	i;

	if (!cmd->s_cmd[1])
	{
		print_export(meta->env);
		return (0);
	}
	exit_code = 0;
	i = 1;
	while (cmd->s_cmd[i])
	{
		if (!is_valid_identifier(cmd->s_cmd[i]))
		{
			printf("export: `%s': not a valid identifier\n", cmd->s_cmd[i]);
			exit_code = 1;
			i++;
			continue ;
		}
		process_env(meta, cmd, i);
		i++;
	}
	return (exit_code);
}

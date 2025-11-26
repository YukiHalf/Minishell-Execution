#include "execution.h"

static int	update_env_var(t_meta *meta, char *var, int index)
{
	free(meta->env[index]);
	meta->env[index] = ft_strdup(var);
	if (!meta->env[index])
		return (1);
	return (0);
}

static int	add_env_var(t_meta *meta, char *new_var, int index)
{
	int		count;
	char	**new_env;

	count = count_env(meta->env);
	new_env = copy_env(meta->env, new_var, count, index);
	new_env[index] = ft_strdup(new_var);
	free(meta->env);
	meta->env = new_env;
	return (0);
}

static void	print_export(char **env)
{
	int		i;
	int		j;
	char	*name;
	char	*value;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		if (env[i][j] == '=')
		{
			name = ft_substr(env[i], 0, j);
			value = ft_strdup(env[i] + j + 1);
			printf("declare -x %s=\"%s\"\n", name, value);
			free(name);
			free(value);
		}
		else
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
		{
			index = find_insert_index(meta->env, cmd->s_cmd[i]);
			add_env_var(meta, cmd->s_cmd[i], index);
		}
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

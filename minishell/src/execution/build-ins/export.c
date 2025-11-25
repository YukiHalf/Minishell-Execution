#include "execution.h"

static int find_env_index(char **env,char *var)
{
	int i;
	int len;

	len = 0;
	while(var[len] != '=' && var[len])
	len++;
}

static int	is_valid_identifier(char *cmd)
{
	int	i;

	if (!cmd || !cmd[0])
		return (0);
	if (!ft_isalpha(cmd[0]) && cmd[0] != '_')
		return (1);
	i = 1;
	while (cmd[i] && cmd[i] != '=')
	{
		if (!ft_isalnum(cmd[i]) && cmd[i] != '_')
			return (1);
		i++;
	}
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

int	b_export(t_token *cmd, t_meta *meta)
{
	int	exit_code;
	int	index;
	int	i;

	if (!cmd->s_cmd[1])
	{
		print_export(meta);
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
		if(ft_strchr(cmd->s_cmd[i],'='))
		{
			index = find_env_index(meta->env,cmd->s_cmd[i]);

		}
	}
}

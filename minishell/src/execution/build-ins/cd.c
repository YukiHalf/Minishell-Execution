#include "execution.h"

static void new_path(char *path, t_meta *meta)
{
	char *new_pwd = malloc(ft_strlen(meta->pwd) + ft_strlen(path) + 2);
	if(new_pwd)
	{
		new_pwd = ft_strlcpy(new_pwd,meta->pwd,ft_strlen(meta->pwd));
		if(meta->pwd[ft_strlen(meta->pwd) - 1] != '/')
			new_pwd[ft_strlen(new_pwd) - 1] = '/';
		ft_strlcat(new_pwd,path,ft_strlen(path));
		meta->pwd = new_pwd;
	}
}

static void	normal_nav(char *path, t_meta *meta, int case_nb)
{
	char	cwd[PATH_MAX];
	char	*last_dir;

	if (case_nb == 1)
	{
		if (getcwd(cwd, PATH_MAX))
			meta->pwd = ft_strdup(cwd);
		else
			meta->pwd = ft_strdup("/");
	}
	if (case_nb == 2)
	{
		last_dir = ft_strrchr(meta->pwd, "/");
		if (last_dir && last_dir != meta->pwd)
			meta->pwd = ft_substr(meta->pwd, 0, last_dir - meta->pwd);
		else
			meta->pwd = ft_strdup("/");
	}
	if (case_nb == 3)
		meta->pwd = ft_strdup(path);
}

static void	get_case(char *path, t_meta *meta)
{
	if (ft_strcmp(path, ".") == 0)
		normal_nav(path, meta, 1);
	else if (ft_strcmp(path, "..") == 0)
		normal_nav(path, meta, 2);
	else if (path[0] == '/')
		normal_nav(path, meta, 3);
	else
		new_path(path,meta);
}

static void	update_meta(char *path, t_meta *meta)
{
	get_case(path,meta);

}

int	b_cd(t_token *cmd, t_meta *meta)
{
	char	*path;
	char	*home;

	if (!cmd->s_cmd[1])
	{
		home = getenv("HOME");
		if (!home)
		{
			perror("cd: Home not set\n");
			return (1);
		}
		path = home;
	}
	else
		path = cmd->s_cmd[1];
	if (chdir(path) != 0)
		return (perror("cd"), 1);
	update_meta(path, meta);
	return (0);
}

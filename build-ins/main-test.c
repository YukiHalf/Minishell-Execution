/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:26:04 by sdarius-          #+#    #+#             */
/*   Updated: 2025/10/15 19:44:36 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//char **filter_cmd(char *cmd)
//{
//	char **s_cmd;
//	s_cmd = ft_split(cmd,' ');

//}


void	debug_buildin(char *cmd)
{
	char **s_cmd;
	s_cmd = ft_split(cmd,' ');
	if (strcmp(s_cmd[0], "pwd") == 0)
		printf("%s\n",b_pwd());
	else if(strcmp(s_cmd[0],"cd") == 0)
		b_cd(s_cmd[1]);
	else if (strcmp(s_cmd[0],"exit") == 0)
		b_exit(s_cmd);
	else if(strcmp(s_cmd[0],"echo") == 0)
		b_echo(s_cmd);
	free(s_cmd);
}

int	main(int argc, char **argv, char **env)
{
	const char	*prompt = "test > ";
		char *line;

	while (1)
	{
		line = readline(prompt);
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		if (*line == '\0')
		{
			free(line);
			continue ;
		}
		add_history(line);
		debug_buildin(line);
		free(line);
	}
	clear_history();
	return (0);
}

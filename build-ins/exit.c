/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:31:14 by sdarius-          #+#    #+#             */
/*   Updated: 2025/10/15 19:54:38 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

void	b_exit(char **s_cmd)
{
	int	exit_code;

	exit_code = 0;
	if (s_cmd[1] && is_num(s_cmd[1]))
	{
		exit_code = atoi(s_cmd[1]);
		exit(exit_code);
	}
	else if(!s_cmd[1])
	{
		exit(exit_code);
	}
	else
		perror("exit");
	// free everything , make sure all the processes finish corect?
	// maybe i need to use kill
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:30:17 by sdarius-          #+#    #+#             */
/*   Updated: 2025/10/15 20:04:18 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	flag_n(char *flag)
{
	int	i;

	i = 1;
	if (flag[0] == '-')
	{
		while (flag[i])
		{
			if (flag[i] != 'n')
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

void	b_echo(char **s_cmd)
{
	int	i;

	i = 1;
	if (flag_n(s_cmd[1]))
		i = 2;
	while (s_cmd[i])
	{
		printf("%s", s_cmd[i]);
		if(s_cmd[i+1])
		printf(" ");
		i++;
	}
	if (!flag_n(s_cmd[1]))
	{
		printf("\n");
	}
}

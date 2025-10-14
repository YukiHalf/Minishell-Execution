/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:25:42 by sdarius-          #+#    #+#             */
/*   Updated: 2025/10/14 19:12:32 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*b_pwd(void)
{
	long	size;
	char	*buf;

	size = pathconf(".", _PC_PATH_MAX);
	if (size == -1)
		size = 4096;

	if ((buf = malloc((size_t)size)) == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	if (getcwd(buf, (size_t)size) == NULL)
	{
		perror("getcwd");
		free(buf);
		return (NULL);
	}
	return (buf);
}

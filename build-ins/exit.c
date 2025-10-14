/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:31:14 by sdarius-          #+#    #+#             */
/*   Updated: 2025/10/14 19:43:40 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void b_exit()
{
	// free everything , make sure all the processes finish corect?
	// maybe i need to use kill
	exit(EXIT_SUCCESS);
}

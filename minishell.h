/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:58:17 by sdarius-          #+#    #+#             */
/*   Updated: 2025/10/15 19:46:32 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "lib/libft/libft.h"

//printf, perror
#include <stdio.h>

//For readline and history for bash
#include <readline/readline.h>
#include <readline/history.h>


//Malloc , pwd , cd, terminal information
#include <stdlib.h>
#include <unistd.h>

// Dir manipulation like read , close ,open
#include <sys/types.h>
#include <dirent.h>

// Strerror
#include <string.h>


#include <termios.h>

char	*b_pwd(void);
int b_cd(const char *path);
void b_exit(char **s_cmd);
void	b_echo(char **s_cmd);
#endif

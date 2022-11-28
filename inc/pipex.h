/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:49:54 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/28 04:18:54 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Header files
# include "pipex.h"
# include "libs.h"
# include "define.h"
# include "structures.h"

//Libft
# include "../libft/inc/libft.h"

//Check commands
char	**only_path(char **env);
int		try_comands(char **matrix, char *cmd);

//Pipex
int		pipex(int argc, char **argv, char **env);

//Errors
void	ft_print_error(int error_code, char *error_message);
#endif

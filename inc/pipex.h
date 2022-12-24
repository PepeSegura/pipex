/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:49:54 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/24 14:24:36 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Header files
# include "pipex.h"
# include "libs.h"

//Libft
# include "../libft/inc/libft.h"

//Constantes
# define SPACE	' '
# define CHILD	0
# define TRUE	1
# define FALSE	0

# ifndef BONUS
#  define BONUS 0
# endif

//New pipex
void	pipex(char **argv, char **env);
char	*only_path(char *cmd, char **env);
void	ft_exec(char *argv, char **env);
void	child_1(int *pipa, char **argv, char *cmd, char **env);
void	child_2(int *pipa, char **argv, char *cmd, char **env);

void	ft_perror(char *str);
void	ft_print_error(char *str);
#endif

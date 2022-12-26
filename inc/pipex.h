/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:49:54 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/26 18:11:52 by psegura-         ###   ########.fr       */
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
# define ANY	-1
# define CHILD	0

# define TRUE	1
# define FALSE	0
# define LEFT	0
# define RIGHT	1

# ifndef BONUS
#  define BONUS 0
# endif

//New pipex
void	pipex(char **argv, char **env);
void	ft_exec(char *argv, char **env);
void	child_input(int *pipa, char **argv, char **env);
void	child_output(int *pipa, char **argv, char **env, int cmd_pos);
//BONUS
void	pipex_bonus(int argc, char **argv, char **env);
void	child_middle(int pipa[2][2], char **argv, char **env);

void	ft_perror(char *str);
void	ft_print_error(char *str);
int		check_path(char **env);
#endif

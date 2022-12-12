/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:49:54 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/12 23:34:31 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Header files
# include "pipex.h"
# include "libs.h"

//Libft
# include "../libft/inc/libft.h"

//struct
typedef struct s_fd {
	int	input;
	int	output;
}	t_fd;

//Constantes
# define SPACE	' '
# define CHILD	0
# define TRUE	1
# define FALSE	0

# ifndef BONUS
#  define BONUS 0
# endif

//PIPEX
void	pipex(int argc, char **argv, char **env);
void	pipex_bonus(int argc, char **argv, char **env);

//Functions
char	*only_path(char *cmd, char **env);
void	child(char *argv, char **env);
void	ft_exec(char *argv, char **env);

void	ft_print_error(void);
#endif

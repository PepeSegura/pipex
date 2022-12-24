/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:08:57 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/20 22:30:31 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//fd[0] -> read
//fd[1] -> write
//pid_t -> id del proceso
void	child(char *argv, char **env)
{
	int		fd[2];
	pid_t	id;

	if (pipe(fd) == -1)
		ft_perror();
	id = fork();
	if (id == CHILD)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_exec(argv, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

		// waitpid(id, NULL, 0);
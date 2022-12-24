/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:08:57 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/24 14:25:12 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//fd[0] -> read
//fd[1] -> write
//pid_t -> id del proceso

void	child_1(int *pipa, char **argv, char *cmd, char **env)
{
	pid_t	child1;
	int		fd_input;

	child1 = fork();
	if (child1 < 0)
		ft_perror("fork ");
	if (child1 == CHILD)
	{
		fd_input = open(argv[1], O_RDONLY);
		if (fd_input < 0)
			ft_perror(argv[1]);
		close(pipa[0]);
		dup2(fd_input, STDIN_FILENO);
		dup2(pipa[1], STDOUT_FILENO);
		ft_exec(cmd, env);
	}
}

void	child_2(int *pipa, char **argv, char *cmd, char **env)
{
	pid_t	child2;
	int		fd_output;

	child2 = fork();
	if (child2 < 0)
		ft_perror("fork ");
	if (child2 == CHILD)
	{
		fd_output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd_output < 0)
			ft_perror(argv[4]);
		close(pipa[1]);
		dup2(fd_output, STDOUT_FILENO);
		dup2(pipa[0], STDIN_FILENO);
		ft_exec(cmd, env);
	}
}

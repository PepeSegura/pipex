/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:08:57 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/26 17:57:57 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_input(int *pipa, char **argv, char **env)
{
	pid_t	child;
	int		fd_input;

	child = fork();
	if (child < 0)
		ft_perror("fork ");
	if (child == CHILD)
	{
		fd_input = open(argv[1], O_RDONLY);
		if (fd_input < 0)
			ft_perror(argv[1]);
		close(pipa[0]);
		dup2(fd_input, STDIN_FILENO);
		dup2(pipa[1], STDOUT_FILENO);
		ft_exec(argv[2], env);
	}
}

void	child_output(int *pipa, char **argv, char **env, int cmd_pos)
{
	pid_t	child;
	int		fd_output;

	child = fork();
	if (child < 0)
		ft_perror("fork ");
	if (child == CHILD)
	{
		fd_output = open(argv[cmd_pos + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd_output < 0)
			ft_perror(argv[cmd_pos + 1]);
		close(pipa[1]);
		dup2(fd_output, STDOUT_FILENO);
		dup2(pipa[0], STDIN_FILENO);
		ft_exec(argv[cmd_pos], env);
	}
}

void	child_middle(int pipa[2][2], char **argv, char **env)
{
	pid_t	child;

	child = fork();
	if (child < 0)
		ft_perror("fork ");
	if (child == CHILD)
	{
		close(pipa[0][0]);
		dup2(pipa[0][1], STDIN_FILENO);
		dup2(pipa[1][0], STDOUT_FILENO);
		ft_exec(argv[3], env);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:53:49 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/24 14:29:16 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	pipex(char **argv, char **env)
// {
// 	t_fd	fd;
// 	int		end[2];
// 	int		status;
// 	pid_t	child1;
// 	pid_t	child2;

// 	fd.input = open(argv[1], O_RDONLY, 0666);
// 	fd.output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
// 	if (fd.input == -1 || fd.output == -1)
// 		return (perror(""));
// 	pipe(end);
// 	child1 = fork();
// 	if (child1 < 0)
// 		return (perror("Fork: "));
// 	if (child1 == 0)
// 		child(fd.input, argv[2], env, end);
// 	child2 = fork();
// 	if (child2 < 0)
// 		return (perror("Fork: "));
// 	if (child2 == 0)
// 		child(fd.output, argv[3], env, end);
// 	close(end[0]);               // this is the parent
// 	close(end[1]);               // doing nothing
// 	waitpid(child1, &status, 0); // supervising the children
// 	waitpid(child2, &status, 0); // while they finish their tasks
// }

void	pipex(char **argv, char **env)
{
	int	pipa[2];
	int	status;

	if (pipe(pipa) < 0)
		ft_perror(NULL);
	child_1(pipa, argv, argv[2], env);
	child_2(pipa, argv, argv[3], env);
	close(pipa[0]);
	close(pipa[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}

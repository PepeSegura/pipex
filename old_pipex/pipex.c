/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 04:01:25 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/20 22:28:47 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int argc, char **argv, char **env)
{
	int		first_cmd;
	t_fd	fd;

	first_cmd = 2;
	fd.output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (access(argv[first_cmd - 1], F_OK | R_OK) != 0)
	{
		ft_putchar_fd('0', fd.output);
		return (perror(argv[first_cmd - 1]));
	}
	fd.input = open(argv[first_cmd - 1], O_RDONLY, 0666);
	if (fd.output == -1)
		ft_perror();
	dup2(fd.input, STDIN_FILENO);
	child(argv[first_cmd], env);
	dup2(fd.output, STDOUT_FILENO);
	ft_exec(argv[argc - 2], env);
}

void	pipex_bonus(int argc, char **argv, char **env)
{
	int		first_cmd;
	t_fd	fd;

	first_cmd = 2;
	fd.input = open(argv[first_cmd - 1], O_RDONLY, 0666);
	fd.output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd.output == -1)
		ft_perror();
	dup2(fd.input, STDIN_FILENO);
	while (first_cmd < argc - 2)
		child(argv[first_cmd++], env);
	dup2(fd.output, STDOUT_FILENO);
	ft_exec(argv[argc - 2], env);
}
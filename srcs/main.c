/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:48:00 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/09 01:48:50 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		first_cmd;
	t_fd	fd;

	if (!env)
		ft_print_error();
	if (argc < 5)
		ft_print_error();
	first_cmd = 2;
	fd.input = open(argv[first_cmd - 1], O_RDONLY, 0666);
	fd.output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd.output == -1)
		ft_print_error();
	dup2(fd.input, STDIN_FILENO);
	while (first_cmd < argc - 2)
		child(argv[first_cmd++], env);
	dup2(fd.output, STDOUT_FILENO);
	ft_exec(argv[argc - 2], env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 04:15:05 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/02 18:59:16 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_3d(char ***matrix)
{
	int	i;
	
	i = 0;
	while (matrix[i])
		i++;
	i--;
	while (i >= 0)
		ft_free_matrix(matrix[i--]);
	free(matrix);
}

void	ft_core(char *command, t_argument args, char **env, t_fd *fd)
{
	printf("%d", fd->output);
	int	pid[2];
	int	i;
	
	i = 1;
	pipe(pid);
	// fork();
	dup2(fd->output, STDOUT);
	execve(command, args.matrix[i], env);
}

void	ft_exec(t_argument args ,char **env)
{
	char	**cmd;
	int		i;
	char	*path;

	i = 0;
	cmd = &args.matrix[i][0];
	path = only_path(args.matrix[i], env);
	if (!path)
	{
		ft_free_matrix(*args.matrix);
		ft_print_error(-10, "No hay un comando valido");
	}
	if (execve(path, args.matrix[i], env) == -1)
		ft_print_error(-10, "No hay un comando valido");	
}

int	pipex(int argc, char **argv, char **env)
{
	t_argument	args;
	t_fd		fd;
	int			i;
	char		*command;

	ft_memset(&args, 0, sizeof(t_argument));
	ft_memset(&fd, 0, sizeof(t_fd));
	fd.output = open(argv[argc - 1], O_WRONLY | O_CREAT, 0666);
	args.cmd_count = argc - 3;
	ft_printf("Comands count: %d\n\n", args.cmd_count);
	args.matrix = malloc(sizeof(char *) * (argc));
	if (!args.matrix)
		return (0);
	i = -1;
	while (++i <= argc - 2)
		args.matrix[i] = ft_split(argv[i + 1], SPACE);
	args.matrix[i] = NULL;
	i = 1;
	//Only_path returns the path where the command is working.
	// while (args.cmd_count)
	// {
	// 	command = only_path(args.matrix[i++], env);
	// 	printf("%s\n", command);
	// 	free(command);
	// 	args.cmd_count--;
	// }
	
	//Comando
	command = only_path(args.matrix[i++], env);
	// printf("%d", fd.output);
	//Fork para ejecutar execve
	ft_core(command, args, env, &fd);
	//Ejecucion comando
	// execve(command, args.matrix[i], env);
	
	ft_free_3d(args.matrix);
	return (0);
}

// ft_printf("Comands count: %d\n\n", args.cmd_count);
// ft_printf("Parametro %d -> %s\n", i, args.matrix[i]);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 04:15:05 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/28 04:32:04 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char **argv, char **env)
{
	t_argument	args;
	char		**matrix;
	int			i;

	ft_memset(&args, 0, sizeof(t_argument));
	if (argc <= 4)
		return (ft_printf("Mete más argumentos"));
	args.cmd_count = argc - 3;
	args.matrix = malloc(sizeof(char *) * (argc - 1));
	if (!args.matrix)
		return (ft_printf("Malloc falla"));
	i = 0;
	ft_printf("Comands count: %d\n\n", args.cmd_count);
	while (i <= argc - 2)
	{
		args.matrix[i] = ft_strdup(argv[i + 1]);
		// ft_printf("Parametro %d -> %s\n", i, args.matrix[i]);
		i++;
	}
	i = 1;
	matrix = only_path(env);
	while (i <= args.cmd_count)
	{
		if (try_comands(matrix, args.matrix[i]) == FALSE)
			ft_print_error(INVALID_CMD , "Commands not found\n");
		i++;
	}
	return (0);
}
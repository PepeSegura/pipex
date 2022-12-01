/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 04:15:05 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/01 17:02:22 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char **argv, char **env)
{
	t_argument	args;
	int			i;

	ft_memset(&args, 0, sizeof(t_argument));
	args.cmd_count = argc - 3;
	ft_printf("Comands count: %d\n\n", args.cmd_count);
	args.matrix = malloc(sizeof(char *) * (argc));
	if (!args.matrix)
		return (ft_printf("Malloc falla"));
	i = -1;
	while (++i <= argc - 2)
		args.matrix[i] = ft_split(argv[i + 1], ' ');
		// args.matrix[i] = ft_strdup(argv[i + 1]);
	args.matrix[i] = NULL;
	i = 1;
	env = only_path(env);
	while (i <= args.cmd_count)
	{
		if (try_comands(env, args.matrix[i]) == FALSE)
			perror("");
			// ft_print_error(INVALID_CMD, "Commands not found\n");
		i++;
	}
	ft_free_matrix(env);
	ft_free_matrix(*args.matrix);
	return (0);
}

// ft_printf("Comands count: %d\n\n", args.cmd_count);
// ft_printf("Parametro %d -> %s\n", i, args.matrix[i]);
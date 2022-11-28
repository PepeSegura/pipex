/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:48:00 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/19 21:09:22 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_argument	args;
	int			i;

	ft_memset(&args, 0, sizeof(t_argument));
	if (argc == 5)
	{
		args.matrix = malloc(sizeof(char *) * (argc - 3));
		if (!args.matrix)
			return (ft_printf("Malloc falla"));
		i = 1;
		while (i < argc - 2)
		{
			args.matrix[i] = ft_strdup(argv[i + 1]);
			ft_printf("Comando %d -> %s\n", i, args.matrix[i]);
			i++;
		}
		args.input = ft_strdup(argv[1]);
		args.output = ft_strdup(argv[argc - 1]);
	}
	ft_printf("Input: %s\n", args.input);
	ft_printf("Output: %s\n", args.output);
	if (argc != 5)
		return (ft_printf("Mete más argumentos"));
	return (0);
}

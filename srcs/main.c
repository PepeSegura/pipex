/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:48:00 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/01 17:22:29 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (!env)
		ft_print_error(INVALID_ENV, "Invalid enviroment variables\n");
	if (argc >= 5)
		pipex(argc, argv, env);
	else
		ft_print_error(INVALID_INPUT, "Wrong number of parameters\n");
	// system("leaks -q pipex");
	return (0);
}

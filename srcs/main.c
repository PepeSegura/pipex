/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:32:40 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/24 14:29:32 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (BONUS == FALSE && argc == 5)
		pipex(argv, env);
	else
		ft_print_error("Incorrect number of arguments");
	return (0);
}

	// else if (BONUS == TRUE && argc >= 5)
	// 	pipex_bonus(argc, argv, env);
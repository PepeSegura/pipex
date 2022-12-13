/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:48:00 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/13 17:14:22 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (!env)
		ft_print_error("There is no enviroment");
	if (BONUS == FALSE)
	{
		if (argc == 5)
			pipex(argc, argv, env);
		else
			ft_print_error("Incorrect number of arguments");
	}
	if (BONUS == TRUE)
	{
		if (argc >= 5)
			pipex_bonus(argc, argv, env);
		else
			ft_print_error("To few arguments");
	}
	return (0);
}

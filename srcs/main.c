/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:48:00 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/13 00:35:28 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (!env)
		ft_print_error();
	if (BONUS == FALSE)
	{
		if (argc == 5)
		{
			ft_printf("PARTE COMUN");
			pipex(argc, argv, env);
		}
		else
			ft_print_error();
	}
	if (BONUS == TRUE)
	{
		if (argc >= 5)
		{
			ft_printf("PIPEX BONUS");
			pipex_bonus(argc, argv, env);
		}
		else
			ft_print_error();
	}
	return (0);
}

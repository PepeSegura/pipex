/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:53:49 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/26 18:02:38 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **argv, char **env)
{
	int	pipa[2];
	int	status;

	if (pipe(pipa) < 0)
		ft_perror(NULL);
	child_input(pipa, argv, env);
	child_output(pipa, argv, env, 3);
	close(pipa[0]);
	close(pipa[1]);
	waitpid(ANY, &status, 0);
	waitpid(ANY, &status, 0);
}

void	pipex_bonus(int argc, char **argv, char **env)
{
	int	pipa[2][2];
	int	status;
	int	cmd_count;

	cmd_count = argc - 3;
	if (pipe(pipa[LEFT]) < 0 || pipe(pipa[RIGHT]) < 0)
		ft_perror(NULL);
	child_input(pipa[LEFT], argv, env);
	child_output(pipa[LEFT], argv, env, argc - 2);
	close(pipa[0][0]);
	close(pipa[0][1]);
	while (cmd_count-- > 0)
		waitpid(ANY, &status, 0);
}

	// child_middle(pipa, argv, env);
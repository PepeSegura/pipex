/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:48:00 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/28 04:37:04 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**only_path(char **env)
{
	int		i;
	char	*path;
	char	**matrix;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_substr(env[i], 5, ft_strlen(env[i]));
			matrix = ft_split(path, ':');
		}
		i++;
	}
	free(path);
	// system("leaks pipex");
	return (matrix);
}

int	try_comands(char **matrix, char *cmd)
{
	int		i;
	int		found = FALSE;
	char	*path = "HOLA";
	char	*path_cmd = "PEPE";

	i = 0;
	while (matrix[i])
	{
		path = ft_strjoin(matrix[i], "/");
		path_cmd = ft_strjoin(path, cmd);
		if (access(path_cmd, X_OK)== 0)
		{
			ft_printf("Command: [%s] found in -> %s\n", cmd, path_cmd);
			found = TRUE;
		}
		free(path);
		free(path_cmd);
		i++;
	}
	return (found);
}

int	main(int argc, char **argv, char **env)
{
	if (!env)
		ft_print_error(INVALID_ENV , "Invalid enviroment variables\n");
	if (argc >= 5)
		pipex(argc, argv, env);
	else
		ft_print_error(INVALID_INPUT , "Wrong number of parameters\n");
	system("leaks pipex");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:45:32 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/26 18:11:38 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	ft_print_error("There is no PATH defined in the enviroment");
	return (i);
}

static char	*only_path(char *cmd, char **env)
{
	int		i;
	char	**env_paths;
	char	*path;
	char	*path_cmd;

	i = check_path(env);
	env_paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (env_paths[i])
	{
		path = ft_strjoin(env_paths[i], "/");
		path_cmd = ft_strjoin(path, cmd);
		free(path);
		if (access(path_cmd, X_OK) == 0)
		{
			ft_free_matrix(env_paths);
			return (path_cmd);
		}
		free(path_cmd);
		i++;
	}
	ft_free_matrix(env_paths);
	ft_print_error("command not found");
	return (EXIT_SUCCESS);
}

void	ft_exec(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, SPACE);
	path = only_path(cmd[0], env);
	if (execve(path, cmd, env) == -1)
		ft_perror("");
}

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

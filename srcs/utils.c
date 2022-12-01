/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:45:32 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/01 18:08:47 by psegura-         ###   ########.fr       */
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
	return (matrix);
}

int	try_comands(char **env, char **cmd)
{
	int		i;
	int		found;
	char	*path;
	char	*path_cmd;
	t_fd	fd;

	fd.input = open("input", O_RDONLY);
	fd.output = open("output", O_WRONLY);
	i = 0;
	found = FALSE;
	path = "/path";
	path_cmd = "/path/command";
	while (env[i])
	{
		path = ft_strjoin(env[i], "/");
		path_cmd = ft_strjoin(path, cmd[0]);
		if (access(path_cmd, X_OK) == 0)
		{
			ft_printf("Command: [%s] found in -> %s\n", cmd[0], path_cmd);
			dup2(fd.output, STDOUT);
			printf("FD Out: %d\n", fd.output);
			// execve(path_cmd, cmd, env);
			found = TRUE;
		}
		free(path);
		free(path_cmd);
		i++;
	}
	return (found);
}

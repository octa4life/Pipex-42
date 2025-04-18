/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 08:54:18 by octavie           #+#    #+#             */
/*   Updated: 2025/04/17 11:16:43 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*create_check_path(t_pipex *pipex, char *cmd)
{
	pipex->cmd = ft_split(cmd, ' ');
	if (!pipex->cmd)
		return (NULL);
	if (pipex->cmd[0] == NULL)
	{
		free_split(pipex->cmd);
		pipex->path = NULL;
		return (NULL);
	}
	pipex->path = find_cmd_in_path(pipex->cmd[0], pipex->env);
	if (!pipex->path)
	{
		free_split(pipex->cmd);
		return (NULL);
	}
	return (pipex->path);
}

void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
// free tab in tab

char	*get_path_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}
//search path in env

char	*cmd_is_possible(char **paths, char *cmd)
{
	int		i;
	char	*res;
	char	*resfinal;

	i = 0;
	while (paths[i])
	{
		res = ft_strjoin(paths[i], "/");
		if (!res)
			return (NULL);
		resfinal = ft_strjoin(res, cmd);
		free(res);
		if (!resfinal)
			return (NULL);
		if (access(resfinal, X_OK) != -1)
		{
			free_split(paths);
			return (resfinal);
		}
		free(resfinal);
		i++;
	}
	free_split(paths);
	ft_putstr_fd("Error: command not found\n", 2);
	return (NULL);
}

char	*find_cmd_in_path(char *cmd, char **env)
{
	char	*path_env;
	char	**paths;
	char	*cmd_path;

	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) != -1)
			return (cmd);
		else
		{
			ft_putstr_fd("Error: command not found\n", 2);
			return (NULL);
		}
	}
	path_env = get_path_env(env);
	if (!path_env)
		return (ft_putstr_fd("Error: command not found\n", 2), NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	cmd_path = cmd_is_possible(paths, cmd);
	if (!cmd_path)
		return (NULL);
	return (cmd_path);
}

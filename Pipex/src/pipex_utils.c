/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octavie <octavie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 08:54:16 by octavie           #+#    #+#             */
/*   Updated: 2025/04/12 09:12:26 by octavie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_pipex *pipex)
{
	if (pipex->cmd[0] != pipex->path)
		free(pipex->path);
	if (pipex->cmd)
		free_split(pipex->cmd);
}

void	fork1(t_pipex *pipex, int pid)
{
	if (pid == 1)
	{
		if (pipex->infile == -1)
		{
			free_all(pipex);
			return ;
		}
		pipex->pid_1 = fork();
		if (pipex->pid_1 == -1)
			(close_all(pipex), free(pipex));
		if (pipex->pid_1 == 0)
			exec_fork1(pipex);
		free_all(pipex);
	}
}

void	fork2(t_pipex *pipex, int pid)
{
	if (pid == 2)
	{
		if (pipex->outfile == -1)
		{
			free_all(pipex);
			return ;
		}
		pipex->pid_2 = fork();
		if (pipex->pid_2 == -1)
			(close_all(pipex), free(pipex));
		if (pipex->pid_2 == 0)
			exec_fork2(pipex);
		free_all(pipex);
	}
}

t_pipex	*init_struct(char **av, char **env)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(1);
	pipex->infile = open(av[1], O_RDONLY, 0644);
	if (pipex->infile == -1)
		(ft_putstr_fd("fail to open infile\n", 2));
	pipex->outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
		(ft_putstr_fd("fail to open outfile\n", 2));
	pipex->env = env;
	return (pipex);
}

void	close_all(t_pipex *pipex)
{
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
}
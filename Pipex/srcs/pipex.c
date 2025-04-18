/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 08:53:42 by octavie           #+#    #+#             */
/*   Updated: 2025/04/18 14:03:47 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_fork1(t_pipex *pipex)
{
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close_all(pipex);
	execve(pipex->path, pipex->cmd, pipex->env);
	if (pipex->path != pipex->cmd[0])
		free(pipex->path);
	free_split(pipex->cmd);
	free(pipex);
	ft_putstr_fd("Error: execve fail\n", 2);
	exit(1);
}

void	exec_fork2(t_pipex *pipex)
{
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close_all(pipex);
	execve(pipex->path, pipex->cmd, pipex->env);
	if (pipex->path != pipex->cmd[0])
		free(pipex->path);
	free_split(pipex->cmd);
	free(pipex);
	ft_putstr_fd("Error: execve fail\n", 2);
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	if (ac != 5)
		(ft_putstr_fd("usage : <infile > <cm1> <cm2> <outfile>\n", 2), exit(1));
	pipex = init_struct(av, env);
	if (pipe(pipex->pipe_fd) == -1)
		(close(pipex->infile), close(pipex->outfile), free(pipex));
	create_check_path(pipex, av[2]);
	if (pipex->path)
		fork1(pipex, 1);
	create_check_path(pipex, av[3]);
	if (pipex->path)
		fork2(pipex, 2);
	return (close_all(pipex), wait(NULL), wait(NULL),
		free(pipex), 0);
}

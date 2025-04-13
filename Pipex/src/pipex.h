/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octavie <octavie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 08:54:21 by octavie           #+#    #+#             */
/*   Updated: 2025/04/13 16:58:30 by octavie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	char	*path;
	char	**cmd;
	char	**env;
}	t_pipex;

void	free_split(char **tab);
char	*cmd_is_possible(char **paths, char *cmd);
char	*create_check_path(t_pipex *pipex, char *cmd);
void	fork1(t_pipex *pipex, int pid);
void	fork2(t_pipex *pipex, int pid);
void	close_all(t_pipex *pipex);
void	exec_fork1(t_pipex *pipex);
void	exec_fork2(t_pipex *pipex);
t_pipex	*init_struct(char **av, char **env);
char	*find_cmd_in_path(char *cmd, char **env);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 01:15:50 by tharodon          #+#    #+#             */
/*   Updated: 2021/08/08 01:15:51 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	err_exit(char *error)
{
	perror(error);
	exit(0);
}

static void	ul_parent(t_pipe *pip, char **argv, char **envirion)
{
	pip->open_fd2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (pip->open_fd2 == -1)
		err_exit("file");
	pip->comand = ft_split(argv[3], ' ');
	path_to_comand(envirion, pip);
	pip->path_comand = to_find(pip);
}

static void	parent_proccess(t_pipe *pip, char **argv, char **envirion, int *fd)
{
	wait(NULL);
	close(fd[1]);
	pip->pid = fork();
	if (!pip->pid)
	{
		ul_parent(pip, argv, envirion);
		dup2(fd[0], 0);
		close(fd[0]);
		dup2(pip->open_fd2, 1);
		if (pip->path_comand == NULL)
		{
			unlink(argv[4]);
			err_exit("You should try another command");
		}
		else
		{
			if (execve(pip->path_comand, pip->comand, NULL) == -1)
				err_exit("comand");
		}
	}
	wait(NULL);
	exit(0);
}

static void	child_proccess(t_pipe *pip, char **argv, char **envirion, int *fd)
{
	close(fd[0]);
	pip->open_fd = open(argv[1], O_RDONLY);
	if (pip->open_fd == -1)
		err_exit("No such file or directory");
	pip->comand = ft_split(argv[2], ' ');
	path_to_comand(envirion, pip);
	pip->path_comand = to_find(pip);
	dup2(pip->open_fd, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	if (pip->path_comand == NULL)
		err_exit("You should try another command");
	else
	{
		if (execve(pip->path_comand, pip->comand, NULL) == -1)
			err_exit("command");
	}
}

int	main(int argc, char **argv, char **envirion)
{
	t_pipe	pip;
	int		fd[2];

	if (argc < 5)
	{
		ft_putstr("too few arguments!\n");
		return (0);
	}
	if (pipe(fd) == -1)
		err_exit("./pipex");
	pip.pid = fork();
	if (pip.pid == -1)
		err_exit("fork");
	if (pip.pid == 0)
		child_proccess(&pip, argv, envirion, fd);
	else
		parent_proccess(&pip, argv, envirion, fd);
}

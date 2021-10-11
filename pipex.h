/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 01:16:05 by tharodon          #+#    #+#             */
/*   Updated: 2021/08/08 01:16:06 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_pipe
{
	char	**way;
	char	**comand;
	char	*path_comand;
	int		open_fd;
	int		open_fd2;
	pid_t	pid;
}				t_pipe;

void	path_to_comand(char **env, t_pipe *pipe);
char	*to_find_way(char *way, char *commands);
char	*to_find(t_pipe *pipe);
#endif

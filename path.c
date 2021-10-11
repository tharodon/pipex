/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 01:15:55 by tharodon          #+#    #+#             */
/*   Updated: 2021/08/08 01:15:57 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path_to_comand(char **env, t_pipe *pipe)
{
	int		str;
	char	*r;

	str = 0;
	while (env[str])
	{
		if (ft_strncmp(env[str], "PATH=", 5) == 0)
		{
			r = env[str];
			pipe->way = ft_split(r, ':');
		}
		str++;
	}
}

char	*to_find_way(char *way, char *commands)
{
	char	*result;

	commands = ft_strjoin("/", commands);
	result = ft_strjoin(way, commands);
	return (result);
}

char	*to_find(t_pipe *pipe)
{
	int		i;
	int		o;
	char	*result;

	i = -1;
	while (pipe->way[++i])
	{
		result = to_find_way(pipe->way[i], pipe->comand[0]);
		o = open(result, O_RDONLY);
		if (o != -1)
			break ;
	}
	if (o == -1)
		return (NULL);
	else
		return (result);
}

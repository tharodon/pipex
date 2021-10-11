/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:04:41 by tharodon          #+#    #+#             */
/*   Updated: 2021/04/25 19:28:15 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	b;
	char	*r;

	i = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	r = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (r == NULL)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[b])
	{
		r[i] = s2[b];
		i++;
		b++;
	}
	r[i] = '\0';
	return (r);
}

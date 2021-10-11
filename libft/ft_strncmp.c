/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:40:20 by tharodon          #+#    #+#             */
/*   Updated: 2021/04/21 17:49:59 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t					i;
	unsigned const char		*m1;
	unsigned const char		*m2;

	i = 0;
	m1 = (unsigned const char *)s1;
	m2 = (unsigned const char *)s2;
	while (i < n)
	{
		if (m2[i] > m1[i])
			return (m1[i] - m2[i]);
		if (m1[i] > m2[i])
			return (m1[i] - m2[i]);
		if (m1[i] == '\0' && m2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

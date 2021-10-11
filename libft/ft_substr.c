/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:10:45 by tharodon          #+#    #+#             */
/*   Updated: 2021/04/28 18:56:17 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	b;
	char	*r;

	b = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *)s))
	{
		r = ft_calloc(1, sizeof(char *));
		return (r);
	}
	if (len > ft_strlen((char *)s))
		len = ft_strlen((char *)s) - start;
	r = (char *)malloc(len + 1);
	if (r == NULL)
		return (NULL);
	r[len] = '\0';
	while (len--)
		r[len] = s[start + len];
	return (r);
}

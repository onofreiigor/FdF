/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 12:15:14 by ionofrei          #+#    #+#             */
/*   Updated: 2016/10/18 18:42:32 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	int		j;
	int		s;

	i = 0;
	len = ft_strlen(dst);
	j = len;
	s = ft_strlen(src) + ft_strlen(dst);
	if (len + 1 > size)
		return (ft_strlen(src) + size);
	if (len + 1 == size)
		return (s);
	while (i < size - len - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (s);
}

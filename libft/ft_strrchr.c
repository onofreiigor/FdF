/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:38:11 by ionofrei          #+#    #+#             */
/*   Updated: 2016/10/18 18:43:34 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	last = NULL;
	i = ft_strlen(s);
	if (c == '\0')
		return ((char*)&s[i]);
	while (*s != '\0')
	{
		if (*s == c)
			last = (char*)s;
		s++;
	}
	return (last);
}

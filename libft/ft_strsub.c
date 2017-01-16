/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 19:58:27 by ionofrei          #+#    #+#             */
/*   Updated: 2016/10/25 15:22:24 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *p;

	if (!s)
		return (NULL);
	if (!(p = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(p, &s[start], len);
	p[len] = '\0';
	return (p);
}

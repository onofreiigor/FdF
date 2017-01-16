/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 20:16:29 by ionofrei          #+#    #+#             */
/*   Updated: 2016/10/25 14:26:01 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*p;
	int		size;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	size = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	while (s[i] && (s[size] == ' ' || s[size] == '\n' || s[size] == '\t'))
		size--;
	if (!(p = (char*)malloc(sizeof(char) * (size - i + 2))))
		return (NULL);
	while (i <= size)
	{
		p[j] = s[i];
		i++;
		j++;
	}
	p[j] = '\0';
	return (p);
}

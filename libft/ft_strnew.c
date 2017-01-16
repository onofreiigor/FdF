/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 18:50:38 by ionofrei          #+#    #+#             */
/*   Updated: 2016/10/24 18:56:58 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *p;

	if (!(p = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	else
		return (ft_memset((void*)p, '\0', size + 1));
}

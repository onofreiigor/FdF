/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:40:48 by ionofrei          #+#    #+#             */
/*   Updated: 2016/10/24 17:12:19 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_position(const char *str)
{
	int b;

	b = 0;
	while (str[b] == ' ' || str[b] == '\v' || str[b] == '\t'
			|| str[b] == '\n' || str[b] == '\f' || str[b] == '\r')
	{
		b++;
	}
	return (b);
}

int				ft_atoi(const char *str)
{
	int i;
	int sg;
	int rs;

	rs = 0;
	sg = 1;
	i = ft_position(str);
	if (str[i] == '-')
	{
		sg = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		sg = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rs = rs * 10 + (str[i] - '0');
		i++;
	}
	return (rs * sg);
}

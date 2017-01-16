/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 14:32:01 by ionofrei          #+#    #+#             */
/*   Updated: 2016/10/25 16:00:41 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int i;
	int word;
	int count;

	i = 0;
	word = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != c && str[i])
		{
			i++;
			word = 1;
		}
		if (str[i] == c || str[i] == '\0')
		{
			if (word == 1)
				count++;
			word = 0;
			i++;
		}
	}
	return (count);
}

static int	ft_size(const char *str, int i, char c)
{
	int count;

	count = 0;
	while (str[i] != c && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if ((str = (char**)malloc(8 * ft_count_words(s, c) + 1)) == NULL)
		return (NULL);
	while (s[i])
		if ((s[i] == c) && s[i])
			i++;
		else if (s[i])
		{
			k = 0;
			if ((str[j] = (char*)malloc(ft_size(s, i, c) + 1)) == NULL)
				return (NULL);
			while (s[i] != c && s[i])
				str[j][k++] = s[i++];
			str[j++][k] = '\0';
		}
	str[j] = NULL;
	return (str);
}

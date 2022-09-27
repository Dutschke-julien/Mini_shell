/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:40:10 by averon            #+#    #+#             */
/*   Updated: 2022/03/09 10:34:34 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	j = ft_strlen((char *)s1);
	k = j;
	l = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i] && char_set(s1[i], set) == 1)
			i++;
	while ((j > (i - 1))
		&& s1[j - 1]
		&& char_set(s1[j - 1], set) == 1)
	{
		j--;
		l++;
	}
	dst = ft_substr(s1, i, k - i - l);
	return (dst);
}

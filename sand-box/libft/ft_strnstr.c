/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:28:45 by averon            #+#    #+#             */
/*   Updated: 2022/03/16 13:50:19 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned int	j;
	unsigned int	x;

	i = 0;
	j = 0;
	if (needle[j] == '\0' && ft_strlen(needle) <= len)
		return ((char *)haystack);
	while (haystack[i] && (len > i))
	{
		if (needle[j] == haystack[i])
		{
			x = i;
			while (needle[j++] == haystack[i++])
			{
				if (needle[j] == '\0' && ft_strlen(needle) + x <= len)
					return ((char *)&haystack[x]);
			}
			i = x;
			j = 0;
		}
		i++;
	}
	return (0);
}

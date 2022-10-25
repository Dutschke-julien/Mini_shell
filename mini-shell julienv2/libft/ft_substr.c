/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:54:51 by averon            #+#    #+#             */
/*   Updated: 2022/03/09 13:37:45 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (start > ft_strlen(s))
		len = 0;
	dst = malloc(sizeof(*dst) * (len + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			dst[j] = s[i];
			j++;
		}
		i++;
	}
	dst[j] = '\0';
	return (dst);
}

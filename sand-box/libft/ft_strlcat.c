/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:58:33 by averon            #+#    #+#             */
/*   Updated: 2022/03/07 16:18:53 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			s;
	size_t			d;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	s = 0;
	d = 0;
	while (src[i])
		i++;
	while (dst[j])
		j++;
	if (dstsize <= j)
		return (i + dstsize);
	while (dst[d] && d < (dstsize - 1))
		d++;
	while (src[s] && d < (dstsize - 1))
	{
		dst[d++] = src[s++];
	}
	dst[d] = '\0';
	return (i + j);
}

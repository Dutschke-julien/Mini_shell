/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandreveron <alexandreveron@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:43:09 by averon            #+#    #+#             */
/*   Updated: 2022/03/04 19:36:44 by alexandreve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	dest = malloc (count * size);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, size * count);
	return (dest);
}

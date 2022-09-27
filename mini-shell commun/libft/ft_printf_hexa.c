/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:52:33 by averon            #+#    #+#             */
/*   Updated: 2022/04/29 11:59:17 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa_len(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i = 1;
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_printf_hexa(unsigned long nb, const char format)
{
	int	printf_len;

	if (format == 'x')
		ft_putnbr_base(nb, "0123456789abcdef");
	if (format == 'X')
		ft_putnbr_base(nb, "0123456789ABCDEF");
	printf_len = ft_hexa_len(nb);
	return (printf_len);
}

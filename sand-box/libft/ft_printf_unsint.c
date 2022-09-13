/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:05:52 by averon            #+#    #+#             */
/*   Updated: 2022/04/29 11:59:08 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsint_len(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i = 1;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_printf_unsint(unsigned long nb)
{
	int	printf_len;

	ft_putnbr_base(nb, "0123456789");
	printf_len = ft_unsint_len(nb);
	return (printf_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:52:33 by averon            #+#    #+#             */
/*   Updated: 2022/04/29 11:58:01 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printf_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i = 6;
		ft_putstr_fd("(null)", 1);
	}
	else
	{
		i = ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	return (i);
}

int	ft_int_len(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i = 1;
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_printf_int(int nb)
{
	int	printf_len;

	ft_putnbr_fd(nb, 1);
	printf_len = ft_int_len(nb);
	return (printf_len);
}

void	ft_putnbr_base(unsigned int nb, char *base)
{
	unsigned int	i;

	i = ft_strlen(base);
	if (nb >= 0 && nb < i)
		ft_putchar_fd(base[nb], 1);
	if (nb >= i)
	{	
		ft_putnbr_base(nb / i, base);
		ft_putnbr_base(nb % i, base);
	}
}

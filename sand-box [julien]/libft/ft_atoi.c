/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:46:52 by averon            #+#    #+#             */
/*   Updated: 2022/06/14 17:09:59 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	s;
	long long	r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] != '\0'
		&& (str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
			||str[i] == '\t' || str[i] == '\v' || str[i] == 32))
		i++;
	if (str [i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str [i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	r = r * s;
	return (r);
}

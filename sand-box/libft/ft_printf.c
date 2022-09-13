/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:33:21 by averon            #+#    #+#             */
/*   Updated: 2022/04/29 11:58:59 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format_len(va_list params, const char format)
{
	int	printf_len;

	printf_len = 0;
	if (format == 'c')
		printf_len = ft_printf_char(va_arg (params, int));
	else if (format == 's')
		printf_len = ft_printf_str(va_arg (params, char *));
	else if (format == 'p')
		printf_len = ft_printf_ptr((uintptr_t)va_arg (params, void *));
	else if (format == 'd')
		printf_len = ft_printf_int(va_arg (params, int));
	else if (format == 'i')
		printf_len = ft_printf_int(va_arg (params, int));
	else if (format == 'u')
		printf_len = ft_printf_unsint(va_arg (params, unsigned int));
	else if (format == 'x')
		printf_len = ft_printf_hexa(va_arg(params, unsigned int), format);
	else if (format == 'X')
		printf_len = ft_printf_hexa(va_arg(params, unsigned int), format);
	else if (format == '%')
		printf_len = ft_printf_char('%');
	return (printf_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		printf_len;

	printf_len = 0;
	va_start (params, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printf_len += ft_format_len(params, *format);
			format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
			printf_len++;
		}
	}
	va_end(params);
	return (printf_len);
}

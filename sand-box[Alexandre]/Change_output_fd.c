/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Change_output_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:13:16 by jdutschk          #+#    #+#             */
/*   Updated: 2022/10/25 17:51:05 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_output_fd(char **tab)
{
	int	i;
	int	fd;
	int	old_fd;

	i = 0;
	fd = 1;
	while (tab[i])
	{
		if (is_exit(tab[i]))
		{
			old_fd = fd;
			fd = open(&tab[i][1], O_RDWR | O_CREAT | O_TRUNC, 0777);
			if (fd != 1 && old_fd != 1)
				close(old_fd);
			delete_case(tab, i);
		}
		else
			i++;
	}
	return (fd);
}

int	is_exit(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == '2')
	{
		str[i] = '\0';
		return (1);
	}
	else
		return (0);
}

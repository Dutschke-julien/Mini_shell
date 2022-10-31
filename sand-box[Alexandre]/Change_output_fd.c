/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Change_output_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:13:16 by jdutschk          #+#    #+#             */
/*   Updated: 2022/10/26 16:19:15 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_output_fd(char **tab)
{
	int	i;
	int	fd;

	i = 0;
	fd = 1;
	while (tab[i])
	{
		if (is_dir_out(tab[i]))
		{
			fd = open(&tab[i][1], O_RDWR | O_CREAT | O_TRUNC, 0777);
			delete_case(tab, i);
		}
		else if (is_append(tab[i]))
		{
			fd = open(&tab[i][2], O_RDWR | O_CREAT | O_APPEND, 0777);
			delete_case(tab, i);
		}
		else
			i++;
	}
	return (fd);
}

int	is_dir_out(char *str)
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

int	is_append(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == '4')
	{
		str[i] = '\0';
		return (1);
	}
	else
		return (0);
}

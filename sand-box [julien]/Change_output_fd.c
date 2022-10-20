/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Change_output_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:13:16 by jdutschk          #+#    #+#             */
/*   Updated: 2022/10/20 14:10:27 by jdutschk         ###   ########.fr       */
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
		if (is_exit(tab[i]))
		{
			fd = open(&tab[i][1], O_RDWR | O_CREAT | O_TRUNC, 0777);
			printf("voice la chaine %s pour open\n", &tab[i][1]);
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

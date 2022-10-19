/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Change_input_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:36:43 by jdutschk          #+#    #+#             */
/*   Updated: 2022/10/19 17:48:18 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_input_fd(char **tab)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	while (tab[i])
	{
		if (is_enter(tab[i]))
		{
			fd = open(&tab[i][1], O_RDONLY);
			printf("voice la chaine %s pour open\n", &tab[i][1]);
			delete_case(tab, i);
			if (fd == -1)
				printf("erreur fichier non existant");
		}
		else
			i++;
	}
	return (fd);
}

void	delete_case(char **tab, int local_case)
{
	while (tab[local_case])
	{
		tab[local_case] = tab[local_case + 1];
		local_case++;
	}
}

int	is_enter(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == '1')
	{
		str[i] = '\0';
		return (1);
	}
	else
		return (0);
}

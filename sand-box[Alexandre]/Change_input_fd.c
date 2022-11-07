/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Change_input_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:36:43 by jdutschk          #+#    #+#             */
/*   Updated: 2022/11/07 19:23:05 by averon           ###   ########.fr       */
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
		if (is_dir_in(tab[i]))
		{
			fd = open(&tab[i][1], O_RDONLY);
			delete_case(tab, i);
		}
		else if (is_heredoc(tab[i]))
		{
			fd = heredoc(&tab[i][2]);
			fd = open(&tab[i][2], O_RDONLY);
			delete_case(tab, i);
		}
		if (fd == -1)
			printf("bash: No such file or directory\n");
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

int	is_dir_in(char *str)
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

int	is_heredoc(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == '3')
	{
		str[i] = '\0';
		return (1);
	}
	else
		return (0);
}

void	close_all_fd(void)
{
	int	i;

	i = 2;
	while (i != 256)
	{
		close(i);
		i++;
	}
}

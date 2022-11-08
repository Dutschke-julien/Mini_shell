/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_space_in_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:35:53 by jdutschk          #+#    #+#             */
/*   Updated: 2022/11/08 14:39:22 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	place_space_in_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == 4)
				tab[i][j] = ' ';
			j++;
		}
		j = 0;
		i++;
	}
}

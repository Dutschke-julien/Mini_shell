/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dollar_in_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:51:06 by averon            #+#    #+#             */
/*   Updated: 2022/10/20 13:32:21 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_str_token(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][ft_strlen(tab[i]) - 1] == '6')
			change_dollar_in_str(tab[i]);
		i++;
	}
}

void	change_dollar_in_str(char *str)
{
	int i;
}

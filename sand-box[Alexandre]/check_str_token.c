/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:51:06 by averon            #+#    #+#             */
/*   Updated: 2022/10/28 13:50:15 by averon           ###   ########.fr       */
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
	//int	i;

	//i = 0;
	(void)str;
}

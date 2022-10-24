/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:58:06 by jdutschk          #+#    #+#             */
/*   Updated: 2022/10/20 13:58:20 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	all_strlen(char **tab)
{
	int	i;
	int	longueur;

	i = 0;
	longueur = 0;
	while (tab[i])
	{
		longueur = longueur + ft_strlen(tab[i]);
		i++;
	}
	return (longueur);
}

char	*recreate_input(char **tab)
{
	char	*str;
	int		i;

	str = ft_calloc(1, 1);
	i = 0;
	while (tab[i])
	{
		str = ft_strjoin(str, tab[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	return (str);
}

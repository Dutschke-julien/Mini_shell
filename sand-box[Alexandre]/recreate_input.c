/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:58:06 by jdutschk          #+#    #+#             */
/*   Updated: 2022/11/10 14:01:30 by averon           ###   ########.fr       */
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

	str = ft_calloc(2, 1);
	i = 0;
	while (tab[i])
	{
		str = ft_strjoin_free(str, tab[i]);
		str = ft_strjoin_free(str, " ");
		i++;
	}
	ft_free(tab);
	return (str);
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*str;
	int		x;
	int		y;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc ((ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	x = -1;
	while (s1[++x])
		str[x] = s1[x];
	x = -1;
	y = ft_strlen(s1);
	while (s2[++x])
	{
		str[y] = s2[x];
		y++;
	}
	str[y] = '\0';
	free((char *)s1);
	return (str);
}

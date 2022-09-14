/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:54:54 by averon            #+#    #+#             */
/*   Updated: 2022/09/02 19:28:10 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cptr_mots(char const *s, char c)
{
	int	i;
	int	cptrm;

	i = 0;
	cptrm = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			cptrm++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cptrm);
}

static char	*init_chaine(char const *s, char c)
{
	char	*chaine;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	chaine = (char *)malloc(sizeof(char) * (i + 1));
	if (chaine == NULL)
		return (NULL);
	ft_strlcpy(chaine, s, i + 1);
	return (chaine);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		cptrm;
	int		j;

	j = 0;
	cptrm = cptr_mots(s, c);
	tab = (char **)malloc(sizeof(char *) * (cptrm + 1));
	if (tab == NULL || s == NULL)
		return (NULL);
	while (j < cptrm)
	{
		while (s[0] == c)
			s = s + 1;
		tab[j] = init_chaine(s, c);
		s = s + ft_strlen(tab [j]);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

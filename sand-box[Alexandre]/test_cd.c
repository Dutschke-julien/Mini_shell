/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:55:14 by averon            #+#    #+#             */
/*   Updated: 2022/09/22 12:34:26 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	dst = malloc(sizeof(*dst) * (i + j) + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}


int main ()
{
	char *input = "/Documents/Projets";
	char	tmp[2048];

	printf("HOME: %s\n", getenv("HOME"));
	input = ft_strjoin(getenv("HOME"), input);
	printf("input avec home: %s\n", input);
	printf("retour chdir: %d\n" ,chdir(input));
	printf("retour getcwd: %s\n" ,getcwd(tmp, sizeof(tmp)));



	//Apres cd, il faut mettre a jour les variables d'env 
	// PWD et OLDPWD

}

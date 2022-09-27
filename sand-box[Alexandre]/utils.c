/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:37:54 by averon            #+#    #+#             */
/*   Updated: 2022/09/09 16:45:06 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

int	ft_error(char *message)
{
	perror(message);
	exit(errno);
}

void	check_tab_char(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("check_tab <%s>\n", tab[i]);
		i++;
	}

}


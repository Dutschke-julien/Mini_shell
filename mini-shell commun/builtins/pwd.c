/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:26 by averon            #+#    #+#             */
/*   Updated: 2022/11/01 19:35:51 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_pwd(void)
{
	char	*wd;

	wd = malloc(1024);
	getcwd(wd, 1024);
	printf("%s\n", wd);
	free(wd);
	return (0);
}

void	update_pwd(char **envp)
{
	char	*wd;
	int		i;

	i = 0;
	wd = malloc(1024);
	getcwd(wd, 1024);
	while (envp[i] && ft_strncmp(envp[i], "PWD=", 4) != 0)
		i++;
	if (envp[i])
	{
		free(envp[i]);
		envp[i] = ft_strjoin("PWD=", wd);
	}
	free(wd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:26 by averon            #+#    #+#             */
/*   Updated: 2022/10/03 16:17:55 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_pwd(t_core *mini)
{
	update_pwd(mini->envp); //a ressortir de la fonction
	read_pwd(mini->envp);
	return (0);
}

void	read_pwd(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PWD=", 4) != 0)
		i++;
	if (envp[i])
		printf("%s\n", &envp[i][4]);
	else
		printf("no working directory !?\n");
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


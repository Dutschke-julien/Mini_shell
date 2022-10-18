/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:26 by averon            #+#    #+#             */
/*   Updated: 2022/10/17 10:28:32 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_pwd(t_core *mini)
{
	update_pwd(mini->envp); //a ressortir de la fonction
	print_pwd();
	return (0);
}

void	print_pwd(void)
{
	char	*wd;
	
	wd = malloc(1024);
	getcwd(wd, 1024);
	printf("%s\n", wd);	
	free(wd);
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

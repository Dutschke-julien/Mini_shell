/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:11:39 by averon            #+#    #+#             */
/*   Updated: 2022/11/13 16:01:03 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*save_pwd(char **envp)
{
	char	*temp_pwd;
	int		i;

	temp_pwd = NULL;
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PWD=", 4) != 0)
		i++;
	if (envp[i])
		temp_pwd = ft_strdup(&envp[i][4]);
	return (temp_pwd);
}

void	get_upper_dir(char **envp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (envp[i] && ft_strncmp(envp[i], "HOME=", 5) != 0)
		i++;
	while (envp[j] && ft_strncmp(envp[j], "PWD=", 4) != 0)
		j++;
	if (envp[i] && envp[j])
	{
		if (ft_strcmp(&envp[i][5], &envp[j][4]) == 0)
			return ;
		else
		{
			while (envp[j][k])
				k++;
			while (envp[j][k] != '/')
				k--;
			envp[j][k + 1] = 0;
			chdir(&envp[j][4]);
		}
	}
}

void	update_oldpwd(char **envp, char *temp_pwd)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "OLDPWD=", 7) != 0)
		i++;
	if (envp[i])
	{
		free(envp[i]);
		envp[i] = ft_strjoin("OLDPWD=", temp_pwd);
		free(temp_pwd);
	}
	else
		return ;
}

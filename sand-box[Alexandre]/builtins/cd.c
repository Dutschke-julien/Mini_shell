/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:33:45 by averon            #+#    #+#             */
/*   Updated: 2022/10/05 16:28:07 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_cd(t_core *mini)
{
	char	*temp_pwd;

	temp_pwd = NULL;
	temp_pwd = save_pwd(mini->envp);
	if (mini->tab_tok[1] == 0
		|| (strcmp(mini->tab_tok[1], "~") == 0 && mini->tab_tok[2] == 0))
	{	
		get_home(mini->envp);
		update_oldpwd(mini->envp, temp_pwd);
		update_pwd(mini->envp);
	}
	else if (ft_strcmp(mini->tab_tok[1], ".") == 0)
	{
		update_oldpwd(mini->envp, temp_pwd);
		return (0);
	}
	else if (ft_strcmp(mini->tab_tok[1], "..") == 0)
	{
		get_upper_dir(mini->envp);
		update_oldpwd(mini->envp, temp_pwd);
		update_pwd(mini->envp);
	}
	else if (mini->tab_tok[1])
	{	
		if ((chdir(mini->tab_tok[1]) == -1))
			printf("cd: no such file or directory: %s\n", mini->tab_tok[1]);
		update_oldpwd(mini->envp, temp_pwd);
		update_pwd(mini->envp);
	}
	return (0);
}

void	get_home(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "HOME=", 5) != 0)
		i++;
	if (envp[i])
		chdir(&envp[i][5]);
	else
		printf("no home directory !?");
}

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
	else
		printf("no working directory !?");
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
		envp[i] = ft_strjoin("OLDPWD=", ft_strdup(temp_pwd));
		free(temp_pwd);
	}
	else
		return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:33:45 by averon            #+#    #+#             */
/*   Updated: 2022/11/16 21:37:33 by averon           ###   ########.fr       */
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
		if (temp_pwd)
			update_oldpwd(mini->envp, temp_pwd);
		update_pwd(mini->envp);
	}
	else if (ft_strcmp(mini->tab_tok[1], ".") == 0)
	{
		update_oldpwd(mini->envp, temp_pwd);
		return (0);
	}
	else
		exec_cd2(mini, temp_pwd);
	return (0);
}

int	exec_cd2(t_core *mini, char *temp_pwd)
{
	if (ft_strcmp(mini->tab_tok[1], "..") == 0)
	{
		get_upper_dir(mini->envp);
		if (temp_pwd)
			update_oldpwd(mini->envp, temp_pwd);
		update_pwd(mini->envp);
	}
	else if (mini->tab_tok[1])
	{	
		if ((chdir(mini->tab_tok[1]) == -1))
		{
			printf("cd: %s: no such file or directory\n", mini->tab_tok[1]);
			g_exit_status = 1;
		}
		if (temp_pwd)
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
		printf("bash: HOME not set\n");
}

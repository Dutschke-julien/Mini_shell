/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:51:34 by averon            #+#    #+#             */
/*   Updated: 2022/11/13 15:02:26 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*bin_dir_cat(t_core *mini)
{
	int		i;
	char	*temp;

	i = 0;
	while (mini->path_tab[i])
	{
		temp = ft_strjoin(mini->path_tab[i], "/");
		mini->bin_dir = ft_strjoin(temp, mini->tab_tok[0]);
		free(temp);
		if (access(mini->bin_dir, F_OK) == 0)
			break ;
		else
			i++;
	}
	return (mini->bin_dir);
}

char	*get_var_path(t_core *mini)
{
	int		i;
	char	*path;

	path = NULL;
	i = 0;
	while (mini->envp[i] && ft_strncmp(mini->envp[i], "PATH=", 5) != 0)
		i++;
	if (mini->envp[i])
		path = ft_strdup(&mini->envp[i][5]);
	else
		return (NULL);
	return (path);
}

char	*get_path(t_core *mini)
{
	int		j;
	char	*path;

	path = get_var_path(mini);
	if (path == NULL)
		return (NULL);
	j = 0;
	if (mini->tab_tok[0][0] != '/' && strncmp(mini->tab_tok[0], "./", 2) != 0)
	{
		while (mini->tab_tok[0][j])
			j++;
		if (mini->tab_tok[0][--j] == '\n')
			mini->tab_tok[0][j] = 0;
		mini->path_tab = ft_split(path, ':');
		free(path);
		mini->bin_dir = bin_dir_cat(mini);
		ft_free(mini->path_tab);
		mini->tab_tok[0] = ft_strdup(mini->bin_dir);
		free(mini->bin_dir);
	}
	else
		free(path);
	return (mini->tab_tok[0]);
}

/*int	check_path(char *str)
{
	if (str == NULL)
	{	
		free(str);
		return (0);
	}
	return (1);
}*/
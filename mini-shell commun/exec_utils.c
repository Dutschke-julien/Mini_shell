/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:51:34 by averon            #+#    #+#             */
/*   Updated: 2022/11/07 18:43:29 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*bin_dir_cat(t_core *mini)
{
	int	i;

	i = 0;
	while (mini->path_tab[i] && access(mini->bin_dir, F_OK) != 0)
	{
		mini->bin_dir = malloc(sizeof(char)
				* (ft_strlen(mini->path_tab[i]) + 1
					+ ft_strlen(mini->tab_tok[0]) + 1));
		if (mini->bin_dir == NULL)
			break ;
		strcat(mini->bin_dir, mini->path_tab[i]);
		strcat(mini->bin_dir, "/");
		strcat(mini->bin_dir, mini->tab_tok[0]);
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
		printf("bash: %s: No such file or directory\n", mini->tab_tok[0]);
	return (path);
}

char	*get_path(t_core *mini)
{
	int		j;
	char	*path;

	path = get_var_path(mini);
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

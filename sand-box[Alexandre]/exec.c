/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:47:40 by averon            #+#    #+#             */
/*   Updated: 2022/09/09 16:45:07 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(t_core *mini, int i)
{
	mini->tab_tok = ft_split(mini->cmd[i], ' ');
	get_path(mini);
	if (execve(mini->tab_tok[0], mini->tab_tok, NULL) == -1)
	{
		perror("pb with execve\n");
	}
	ft_free(mini->tab_tok);
}

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
		//ft_printf("access %d. " ,temp = access(bin_dir, F_OK));
		i++;
	}
	return (mini->bin_dir);
}

char	*get_path(t_core *mini)
{
	int		j;
	char	*path; 

	j = 0;
	path = ft_strdup(getenv("PATH"));
	if (mini->tab_tok[0][0] != '/' && strncmp(mini->tab_tok[0], "./", 2) != 0)
	{
		while (mini->tab_tok[0][j])
			j++;
		if (mini->tab_tok[0][--j] == '\n')
			mini->tab_tok[0][j] = 0;// pour enlever le retour ligne
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

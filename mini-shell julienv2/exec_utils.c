/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:51:34 by averon            #+#    #+#             */
/*   Updated: 2022/11/01 15:08:50 by averon           ###   ########.fr       */
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
	printf("ctrl PATH: %s***\n", mini->tab_tok[0]);
	return (mini->tab_tok[0]);
}

void	exit_exec(t_core *mini)
{
	ft_putendl_fd("exit", 1);
	free(mini->input);
	exit(0);
}

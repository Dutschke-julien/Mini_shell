/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:51:06 by averon            #+#    #+#             */
/*   Updated: 2022/10/06 13:05:41 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_calc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	i = i - 1;
	return (i);
}

void	input_split(t_core *mini)
{
	
	printf("%s\n", update_input(mini->input, 0, 0));
	//mini->cmd = ft_split(mini->input, '|');
	//mini->nb_pipe = pipe_calc(mini->cmd);
}

/*
void	change_input_output(t_core *mini)
void	last_input(t_core *mini);
void	lst_output(t_core *mini);
*/














int get_tokens(char *str)
{
    int i;
    int cmpt;
    
    cmpt = 0;
    i = 0;
    while (str[i])
    {
        if (is_occurence(str[i]))
            cmpt++;
        i++;
    }
    return (cmpt);
}

int is_occurence(char c)
{
    if (c == '<' || c == '>'|| c == '$' || c == '"' || c == 39 || c == '|')
        return (1);
    else
        return (0);
}

char *cmd_with_space(char *str, int i, int j)
{
    char *s1;

    s1 = malloc(sizeof(char) * ft_strlen(str) + get_tokens(str) + 1);
    
    while(str[i])
    {
        if (is_occurence(str[i]))
            {
                s1[j] = ' ';
                j++;
                s1[j] = str[i];
                i++;
                j++;
            }
        else
        {
            s1[j] = str[i];
            j++;
            i++;
        }   
    }
    s1[j] = '\0';
    //add free(str)
    return (s1);
}

char *update_input(char *str, int i, int j)
{
    char *s1;
	str = cmd_with_space(str, 0, 0);
    s1 = malloc(sizeof(char) * ft_strlen(str) + cmpt_this(str, '|') + 1);
    
     while(str[i])
    {
        if (str[i] == '|')
            {
                s1[j] = str[i];
                i++;
                j++;
                s1[j] = ' ';
                j++;
            }
        else
        {
            s1[j] = str[i];
            j++;
            i++;
        }   
    }
    s1[j] = '\0';
    //add free(str)
    return (s1);
}

int cmpt_this(char *str, char c)
{
    int i;
    int cmpt;
    
    i = 0;
    cmpt = 0;
    while (str[i])
    {
        if (str[i] == c)
            cmpt++;
        i++;
    }
    return(cmpt);
}

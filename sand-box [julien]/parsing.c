/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:51:06 by averon            #+#    #+#             */
/*   Updated: 2022/10/11 23:02:11 by jdutschk         ###   ########.fr       */
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

void input_split(t_core *mini)  
{
   char **hello;
  // int i = 0;
   char *str;

	str = update_input(mini->input, 0, 0);  
    replace_all_symbol(str);
    change_spc(str, '"', '"');
    hello = ft_split(str, ' ');
    printf("%s\n", str);
  /* while (hello[i])
    {
        printf("hello[%d] = %s\n", i , hello[i]);
        i++;
    }
*/
	//mini->cmd = ft_split(mini->input, '|');
	//mini->nb_pipe = pipe_calc(mini->cmd);
}



int replace_all_symbol(char *str)
{
    int i = 10;
       while (i--)
    {
        replace_symbol(str, '<');   
        replace_symbol(str, '>');
    }
    replace_symbol2(str, '"');
    replace_symbol2(str, 47);
    change_spc(str, '"', '"');
    if (is_odd(str, '"'))
        return(printf("erreur\n"));
    
    return (0);
}


void change_spc(char *str, char first, char second)
{
    unsigned int i;

    i = 0;

    while (str[i])
    {
        while(str[i] != first && str[i])
            i++;
        i++;
        while(str[i] != second && str[i])
        {
            if (str[i] == ' ')
                str[i] = 'w';
            i++;
        }
    }
}















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

//replace tout les symboles correctement ('<' '>' )
void    replace_symbol(char *str, char symbol)
{
    int i = 0;
    
    while (str[i])
    {
        if (str[i] == symbol)
            {
                str[i] = ' ';
                while (str[i] && str[i] == ' ')
                    i++;
                str[i - 1] = symbol;
            }
        else 
            i++;
    }
}


void    replace_symbol2(char *str, char c)
{
    unsigned int i;
    unsigned int cmpt;

    i = 0;
    cmpt = 0;
    while (str[i])
    {
        if (str[i] == c)
        {
            cmpt++;
        if (cmpt % 2 == 0)
        {
            str[i - 1] = c;
            str[i] = ' ';
        }
        }
        i++;
    }
}


int is_odd(char *str, char c)
{
    unsigned int i;
    unsigned int cmpt;
    
    cmpt = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            cmpt++;
        i++;
    }
    if (cmpt % 2)
        return (1);
    return (0);
}

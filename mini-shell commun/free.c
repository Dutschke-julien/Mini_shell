/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:24:00 by averon            #+#    #+#             */
/*   Updated: 2022/10/05 16:28:08 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief This function will free all the memory allocated by the minishell.
 */

void	free_minishell(void)
{
	//prevoir de free tout la/les structures du minishell
	rl_clear_history();
}

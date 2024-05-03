/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:51:35 by soksak            #+#    #+#             */
/*   Updated: 2024/05/03 12:25:06 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_state	*state;

	state = (t_state *)malloc(sizeof(t_state));
	state->env = g_env(state, envp);
	printf("deneme");
	(void)argc;
	(void)argv;
	return (0);
}

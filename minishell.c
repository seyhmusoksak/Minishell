/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:51:35 by soksak            #+#    #+#             */
/*   Updated: 2024/08/07 16:12:18 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///export düzeltilecek	heredoc komutsuz düzeltilecek exec envsiz düzeltilecek
#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_state	*state;

	state = (t_state *)malloc(sizeof(t_state));
	state->pars = malloc(sizeof(t_parser));
	if (!state->pars || !state->lexer || !state)
		ft_error_mesage("Error: Malloc problem !");
	(void)argc;
	(void)argv;
	ft_init_signals();
	state->env = get_env(state, envp);
	state->exp = get_env(state, envp);
	state->envp = envp;
	state->error = 0;
	state->cluster = NULL;
	while (1)
	{
		sig_status = 0;
		ft_sep_path(state);
		state->pars->ptr_errno = &(state->error);
		state->line = readline("minishell>");
		if (state->line)
			add_history(state->line);
		if (ft_parser(state))
			break ;
		ft_free_double_str(state->sep_path);
		free(state->line);
		ft_all_cluster_free(state);
	}
	ft_full_free(state, 0);
	return (0);
}




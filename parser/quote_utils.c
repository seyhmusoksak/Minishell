/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:54:48 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/07/03 22:31:18 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_cut_dquote(char *str, int len, t_parser *pars)
{
	char	*tmp;
	int		c;

	tmp = NULL;
	c = -1;
	while (str[++pars->m] && pars->m < len)
	{
		if ((str[pars->m] == '"' || str[(pars->m) + 1] == '\0')
			&& pars->check == 0)
		{
			tmp = ft_substr(str, pars->k, (pars->m - pars->k) + 1);
			pars->check = 2;
			pars->k = pars->m;
			while (tmp[++c])
				if (tmp[c] == '\'')
					(pars->count_sq)++;
			break ;
		}
	}
	return (tmp);
}

char *ft_cut_squote(char *str, int len, t_parser *pars)
{
	char	*tmp;
	int		c;

	tmp = NULL;
	pars->m = pars->k;
	c = -1;
	while (str[++(pars->m)] && pars->m < len)
	{
		if ((str[pars->m] == '\'' || str[(pars->m) +1] == '\0')
			&& pars->check == 0)
		{
			tmp = ft_substr(str, pars->k, (pars->m - pars->k) + 1);
			pars->check = 1;
			pars->k = pars->m;
			while (tmp[++c])
				if (tmp[c] == '"')
					(pars->count_dq)++;
			break ;
		}
	}
	return (tmp);
}

int	ft_count_quote(char *str, int len, char quote_type)
{
	int	i;
	int	quote_len;

	quote_len = 0;
	i = 0;
	while (i < len)
	{
		if (str[i] == quote_type)
			quote_len++;
		i++;
	}
	return (quote_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:48:39 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/28 22:04:40 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static void	clear_list(t_tokenstream *tokens)
{
	t_tokenstream	*tmp;

	while (tokens)
	{
		tmp = tokens->next;
		free(tokens->token->t_name);
		free(tokens->token);
		free(tokens);
		tokens = tmp;
	}
}

void	exit_shell(t_mini **mini, t_tokenstream **tokens)
{
	free_env_table((*mini)->env_table);
	free(*mini);
	clear_list(*tokens);
	exit(0);
}

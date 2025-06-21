/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:11 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:11 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

void	cmd_exit(t_command *command)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (command->args[1])
	{
		ft_putstr_fd(SHELL_NAME": exit: ", STDERR_FILENO);
		ft_putstr_fd(command->args[1], STDERR_FILENO);
		ft_putstr_fd(": no option is available\n", STDERR_FILENO);
		free_command(command);
		exit(EXIT_INVALID_ARGS);
	}
	free_command(command);
	exit(EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:06:36 by mel-atti          #+#    #+#             */
/*   Updated: 2024/06/21 16:04:35 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_error(char *str)
{
	if (!str)
		exit(1);
	else
	{
		write(2, str, ft_strlen(str));
		exit (1);
	}
}

void	malloc_exit_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit_error("");
}

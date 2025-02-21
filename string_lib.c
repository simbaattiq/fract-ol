/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:06:12 by mel-atti          #+#    #+#             */
/*   Updated: 2024/07/01 16:18:34 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (!s1 || !s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && s1 && s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

int	ft_check_float(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] != '.' && str[i])
		{
			if (!ft_isdigit(str[i]))
				return (1);
			i++;
		}
		if (str[i] == '.')
			i++;
		while (str[i] && str[i] != '.')
		{
			if (!ft_isdigit(str[i]))
				return (1);
			i++;
		}
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
		i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:48:33 by mel-atti          #+#    #+#             */
/*   Updated: 2024/07/01 17:45:09 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_comp_num	square_comp_num(t_comp_num z)
{
	t_comp_num	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

t_comp_num	sum_comp_num(t_comp_num z, t_comp_num c)
{
	t_comp_num	result;

	result.x = z.x + c.x;
	result.y = z.y + c.y;
	return (result);
}

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) *(unscaled_num - old_min)
		/ (old_max - old_min) + new_min);
}

double	ft_atod(const char *str)
{
	long	int_part;
	double	frac_part;
	double	power;
	int		sign;

	frac_part = 0.0;
	sign = 1;
	power = 1.0;
	int_part = integer_handel(&str, &sign);
	if (*str == '.')
		str++;
	while (*str)
	{
		power /= 10;
		frac_part = frac_part + (*str++ - '0') * power;
	}
	return (sign * (int_part + frac_part));
}

long	integer_handel(const char **str, int *sign)
{
	long	int_part;

	int_part = 0;
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign *= -1;
		(*str)++;
	}
	while (**str != '.' && **str)
		int_part = (int_part * 10) + (*(*str)++ - '0');
	return (int_part);
}

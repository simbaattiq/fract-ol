/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:48:08 by mel-atti          #+#    #+#             */
/*   Updated: 2024/07/01 14:49:38 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;
	char		*error_msg;

	error_msg = ERROR_PART1 ERROR_PART2 ERROR_PART3 ERROR_PART4;
	if ((ac == 2 && ((ft_strncmp("mandelbrot", av[1], 10)) == 0))
		|| (ac == 4 && ((ft_strncmp("julia", av[1], 5)) == 0)))
	{
		fractol.name = av[1];
		if (!(ft_strncmp("julia", fractol.name, 5)) && !parse_ju_arg(av))
		{
			fractol.ju_x = ft_atod(av[2]);
			fractol.ju_y = ft_atod(av[3]);
			printf("\n [%f] \t [%f]\n", fractol.ju_x, fractol.ju_y);
		}
		initialize_fractol(&fractol);
		rendering_fractol(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
		exit_error(error_msg);
	return (0);
}

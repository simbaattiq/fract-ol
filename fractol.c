/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:48:54 by mel-atti          #+#    #+#             */
/*   Updated: 2024/07/01 17:38:41 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_fractol(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
		malloc_exit_error("Error with Malloc\n");
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection,
			WIDTH, HEIGHT, fractol->name);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		malloc_exit_error("Error with Malloc\n");
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection,
			WIDTH, HEIGHT);
	if (fractol->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		malloc_exit_error("Error with Malloc\n");
	}
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
	listen_to_events(fractol);
	initialize_data(fractol);
}

void	listen_to_events(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, KeyPress, KeyPressMask, key_func, fractol);
	mlx_hook(fractol->mlx_window, ButtonPress,
		ButtonPressMask, mouse_func, fractol);
	mlx_hook(fractol->mlx_window, DestroyNotify,
		StructureNotifyMask, close_func, fractol);
}

void	initialize_data(t_fractol *fractol)
{
	fractol->hypotenuse = 4;
	fractol->max_iter = 39;
	fractol->x_shift = 0;
	fractol->y_shift = 0;
	fractol->zoom_factor = 1.0;
}

int	parse_ju_arg(char **av)
{
	int		i;
	char	*error_msg;

	error_msg = ERROR_PART1 ERROR_PART2 ERROR_PART3 ERROR_PART4;
	i = 2;
	while (av[i])
	{
		if (ft_check_float(av[i]))
			exit_error(error_msg);
		i++;
	}
	return (0);
}

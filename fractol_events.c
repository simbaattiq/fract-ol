/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:45:41 by mel-atti          #+#    #+#             */
/*   Updated: 2024/07/01 17:39:41 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_func(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit(0);
}

int	key_func(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_func(fractol);
	if (keysym == XK_Right)
		fractol->x_shift += (0.3 * fractol->zoom_factor);
	else if (keysym == XK_Left)
		fractol->x_shift -= (0.3 * fractol->zoom_factor);
	else if (keysym == XK_Up)
		fractol->y_shift += (0.3 * fractol->zoom_factor);
	else if (keysym == XK_Down)
		fractol->y_shift -= (0.3 * fractol->zoom_factor);
	else if (keysym == XK_c)
		fractol->max_iter += 7;
	else if (keysym == XK_v)
		fractol->max_iter -= 7;
	else if (keysym == XK_a)
		fractol->zoom_factor *= 1.1;
	else if (keysym == XK_b)
		fractol->zoom_factor *= 0.9;
	rendering_fractol(fractol);
	return (0);
}

int	mouse_func(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == Button5)
		fractol->zoom_factor *= 1.01;
	else if (button == Button4)
		fractol->zoom_factor *= 0.09;
	else
		return (0);
	rendering_fractol(fractol);
	return (0);
}

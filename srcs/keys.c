/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:07:56 by fraalmei          #+#    #+#             */
/*   Updated: 2023/02/28 15:50:08 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// 
int	read_keys(int key_pressed, void *param)
{
	t_img	*img;

	img = (t_img *)param;
	if (key_pressed == ESC || !img)
		exit_program(&img->win);
	else if (key_pressed == ENTER)
		draw_square((t_square){0, 0, img->w, 0xFFFFFF}, *img);
	else if (key_pressed == FOLLOW)
		follow = !follow;
	else if (key_pressed == COLOR)
		get_color(1);
	else if (key_pressed == PENGUIN)
		penguin(img);
	else
		return (-1);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
	return (0);
}

int	continuous_read_keys(int key_pressed, void *param)
{
	t_img	*img;

	img = (t_img *)param;
	if (!img)
		exit_program(&img->win);
	else if (key_pressed == UP)
	{
		if(size <img->w / 4)
			size++;
	}
	else if (key_pressed == DOWN)
	{
		if (size > 1)
			size--;
	}
	else if (key_pressed == RAND_COLOR)
		get_color(1);
	return (0);
}
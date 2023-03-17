/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:36:48 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/17 17:41:24 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	read_keys(int key_pressed, void *param)
{
	static int		i;
	t_prog			*data;

	if (!i)
		i = 0;
	data = (t_prog *)param;
	if (key_pressed == ESC || !data->win.win_ptr)
		exit_program(&data->win, -1);
	else if (key_pressed == ENTER)
		mlx_clear_window(data->win.mlx_ptr, data->win.win_ptr);
	else if (key_pressed == UP || key_pressed == W)
		i += move_up(data);
	else if (key_pressed == DOWN || key_pressed == S)
		i += move_down(data);
	else if (key_pressed == LEFT || key_pressed == A)
		i += move_left(data);
	else if (key_pressed == RIGHT || key_pressed == D)
		i += move_right(data);
	else
		return (-1);
	ft_printf("%d\n", i);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:36:48 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/28 09:17:00 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// check the last number and compare with the new
	// and if changed print the new number andd return it
int	movements(int i, int s)
{
	if (s != i)
		ft_printf("%d\n", s);
	i = s;
	return (i);
}

	// function to read the keys pressed linked to mlx_key_hook
	// the param argument have to be casted depending the argument sent
int	read_keys(int key_pressed, void *param)
{
	static int		i;
	int				s;
	t_prog			*data;

	s = i;
	if (!i)
		s = 0;
	data = (t_prog *)param;
	if (key_pressed == ESC || !data->win.win_ptr)
		exit_program(&data->win, -1);
	else if (key_pressed == UP || key_pressed == W)
		s += move(data, 'N');
	else if (key_pressed == DOWN || key_pressed == S)
		s += move(data, 'S');
	else if (key_pressed == LEFT || key_pressed == A)
		s += move(data, 'W');
	else if (key_pressed == RIGHT || key_pressed == D)
		s += move(data, 'E');
	else
		return (-1);
	i = movements(i, s);
	return (0);
}

	/* else if (key_pressed == E)
		mlx_clear_window(data->win.mlx_ptr, data->win.win_ptr);
	else if (key_pressed == R)
		put_map_to_window(*data);
	else if (key_pressed == F)
		put_objects_map(*data); */

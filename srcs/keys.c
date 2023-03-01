/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:07:56 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/01 17:24:18 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// 
int	read_keys(int key_pressed, void *param)
{
	void	*win;

	win = (t_win *)param;
	if (key_pressed == ESC || !win)
		exit_program(win);
	else if (key_pressed == UP)
		exit_program(win);
	else if (key_pressed == DOWN)
		exit_program(win);
	else if (key_pressed == LEFT)
		exit_program(win);
	else if (key_pressed == RIGHT)
		exit_program(win);
	else
		return (-1);
	return (0);
}

int	continuous_read_keys(int key_pressed, void *param)
{
	void	*win;

	win = (t_win *)param;
	if (key_pressed == ESC || !win)
		exit_program(win);
	else if (key_pressed == UP || !win)
		ft_printf("win");
	return (0);
}

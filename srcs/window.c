/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:41:15 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/01 17:04:37 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// function to create the base of the program and the window
	// the height and width are needed and a name for the window
	// initialize the pointer of the program
	// and return a struct of the created window
t_win	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

	// functio to call the destroyer of the program and the window
int	exit_program(t_win *window)
{
	if (window)
		mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}

/* t_win	new_window(int w, int h, char *str)
{
	void	*mlx_ptr;
	t_win	win;

	mlx_ptr = mlx_init();
	win = (t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), \
		w, h, (t_rect){0, 0, w, h, 0x00a4ff32}};
	return (win);
}
 */
/* t_win	new_window(int w, int h, char *str) {
	void *	mlx_ptr;
	t_win	win;

	mlx_ptr = mlx_init();
	win = (t_win){mlx_ptr,
		mlx_new_window(mlx_ptr, w, h, str),
		w,
		h,
		(t_rect){0, 0, w, h, 0x00a4ff32}};
	return (win);
}
 */
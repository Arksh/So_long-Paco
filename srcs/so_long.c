/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:12:10 by fraalmei          #+#    #+#             */
/*   Updated: 2023/02/28 18:29:11 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	int		i;

	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Comemela");
	img.img_ptr = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_len, &img.endian);
	while (i++ < 40)
	{
		pixel_put(&img, 5 + i, 5, get_oppsite_color(0));
		pixel_put(&img, 5, 5 + i, get_oppsite_color(0));
		pixel_put(&img, 45, 5 + i, get_oppsite_color(0));
		pixel_put(&img, 5 + i, 45, get_oppsite_color(0));
	}
	ft_printf("color 65535 - oposite %d\n", get_oppsite_color(0));
	i = 0;
	while (i++ < 40)
	{
		pixel_put(&img, 55 + i, 5, 0);
		pixel_put(&img, 55, 5 + i, 0);
		pixel_put(&img, 95, 5 + i, 0);
		pixel_put(&img, 55 + i, 45, 0);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, 0);
	mlx_loop(mlx);
	return (0);
}

/* int	main(void)
{
	t_win	game;		// calling a struct for the program / window
	t_img	image;		// calling a struct for the image

	game = new_program(3000, 3000, "New Program");	// create and asign the new window
	if (!game.win_ptr)		// check if the new window are created correctly
		return (2);
	image = new_img(3000, 3000, game);	// create a new image
	//draw_square((t_square){120, 120, 4000, 0x00FF00}, image);	// create a square
	//mlx_put_image_to_window (image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);	// put the image to the window
	mlx_key_hook(game.win_ptr, read_keys, &image);
	mlx_mouse_hook(game.win_ptr, read_mouse, &image);
	mlx_hook(game.win_ptr, 2, 0, continuous_read_keys, &image);
	mlx_hook(game.win_ptr, 6, 0, follow_mouse, &image);
	mlx_hook(game.win_ptr, 17, 0, exit_program, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}*/

	// mlx_hook is a funtion to trigger on a event
	// mlx_hook (program.window, type_event, mask, function to call, &program)

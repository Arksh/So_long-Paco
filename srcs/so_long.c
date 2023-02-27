/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:12:10 by fraalmei          #+#    #+#             */
/*   Updated: 2023/02/27 17:00:54 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(void)
{
	t_win	game;
	t_img	image;

	game = new_program(300, 300, "New Program");
	if (!game.win_ptr)
		return (2);
	image = new_img(300, 300, game);
	put_pixel_img(image, 150, 150, 0x00FF0000);
	mlx_put_image_to_window (image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);
	mlx_loop(game.mlx_ptr);
	return (0);
}

/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		mlx_clear_w;
	int		mlx_destroy_w;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Comeme!");
	if (!mlx_win)
		return (2);
	mlx_loop(mlx);
	mlx_clear_w = mlx_clear_window(mlx, mlx_win);
	mlx_destroy_w = mlx_destroy_window(mlx, mlx_win);
}
*/
/*
static mlx_image_t* img;

void hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 5;
}

int32_t	main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return(EXIT_FAILURE);

	img = mlx_new_image(mlx, 128, 128);
	memset(img->pixels, 255, img->width * img->height * sizeof(int));
	mlx_image_to_window(mlx, img, 0, 0);

	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);

	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
*/
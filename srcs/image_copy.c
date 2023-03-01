/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:30:26 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/01 16:29:26 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// function to create a image
	// the height and width are needed and the pointer to the window
t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, \
			&(image.bpp), &(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

	// function to put a pixel into the image
	// addr_index = (line_len * y) + (x * (bpp / 8))
	// the address of the pixel into the image 
	// line_len * y is the start of the colum on the addr
	// x * (bpp / 8) is the colum of the pixel
void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

void	draw_square(t_square square, t_img img)
{
	unsigned short int		i;
	unsigned short int		j;

	i = 0;
	while (i < square.size && i + square.y < img.h)
	{
		j = 0;
		while (j < square.size && j + square.x < img.w)
		{
			put_pixel_img(img, j + square.x, i + square.y, square.color);
			j++;
		}
		i++;
	}
}

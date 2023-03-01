/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:32:13 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/01 17:10:36 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	draw_rect(t_rect rect, t_img img)
{
	unsigned short int		i;
	unsigned short int		j;

	i = 0;
	while (i < rect.size_h && i + rect.y < img.h)
	{
		j = 0;
		while (j < rect.size_w && j + rect.x < img.w)
		{
			put_pixel(img, j + rect.x, i + rect.y, rect.color);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_circle circle, t_img img)
{
	unsigned short int		i;
	unsigned short int		j;

	i = 0;
	while (i < circle.radius * 2 && i + circle.y < img.h)
	{
		j = 0;
		while (j < circle.radius * 2 && j + circle.x < img.w)
		{
			if (((j - circle.radius) * (j - circle.radius)) + \
					((i - circle.radius) * (i - circle.radius)) < \
					(circle.radius * circle.radius))
			{
				put_pixel(img, j + circle.x, i + circle.y, circle.color);
			}
			j++;
		}
		i++;
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
			put_pixel(img, j + square.x, i + square.y, square.color);
			j++;
		}
		i++;
	}
}

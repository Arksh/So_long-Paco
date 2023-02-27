/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:23:11 by fraalmei          #+#    #+#             */
/*   Updated: 2023/02/27 16:38:34 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// function to generate the color
	// return a integer (4 bytes)
	// every byte represents opacity, red, green and blue
	// if any of the values are wrong, return 0
	// else, set the parameters to the bytes
int	gen_trgb(int opacity, int red, int green, int blue)
{
	if (opacity > 255 || red > 255 || green > 255 || blue > 255)
		return (0);
	return (opacity << 24 | red << 16 | green << 8 | blue);
}

	// return a int of the required byte
int	get_opacity(int trgb)
{
	return ((trgb >> 24) & 0XFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0XFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0XFF);
}

int	get_b(int trgb)
{
	return (trgb & 0XFF);
}

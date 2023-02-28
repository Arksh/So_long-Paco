/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:37:19 by fraalmei          #+#    #+#             */
/*   Updated: 2023/02/28 17:45:13 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	create_trgb(unsigned char opacity, unsigned char red, \
		unsigned char green, unsigned char blue)
{
	if (opacity > 255 || red > 255 || green > 255 || blue > 255)
		return (0);
	return (*(int *)(unsigned char [4]){blue, green, red, opacity});
}

	// return a int of the required byte
unsigned char	get_opacity(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

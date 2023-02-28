/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:53:22 by fraalmei          #+#    #+#             */
/*   Updated: 2023/02/28 18:07:05 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	get_oppsite_color(int color)
{
	return (gen_trgb(get_opacity(color), 255 - get_r(color), \
			255 - get_g(color), 255 - get_b(color)));
}

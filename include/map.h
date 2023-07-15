/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:libft/ft_intlen.c
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:34:33 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/23 13:36:48 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// count the digits of a int
size_t	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}
========
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:27 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/11 13:02:09 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <so_long.h>
# include <window.h>



#endif
>>>>>>>> 36f35b83b776079048e96fb7aaf44dec9629781a:include/map.h

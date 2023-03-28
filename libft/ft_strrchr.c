/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:57:42 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 16:41:04 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// find the last coincidence of 'c' in "s"
	// and return a pointer to that position
char	*ft_strrchr(const char *s, int c)
{
	char	*l;

	l = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			l = ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (l);
}

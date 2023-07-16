/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:48:05 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 16:37:18 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// compare lexicologically "s1 and "s2", n chars
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	if (n == 0)
		return (0);
	while (j < n - 1 && s1[j] == s2[j] && s1[j] != '\0' && s2[j] != '\0')
		j++;
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}

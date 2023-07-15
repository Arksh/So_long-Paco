/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:48:05 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/28 13:34:29 by fraalmei         ###   ########.fr       */
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

int	ft_str_last_cmp(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(haystack) - 1;
	j = ft_strlen(needle) - 1;
	if (i < j)
		return (1);
	while (haystack[i] && needle[j])
	{
		if (haystack[i] != needle[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}

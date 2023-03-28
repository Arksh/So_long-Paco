/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:14:34 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 16:42:58 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// erase all chars of "s1" at start or end of "set"
	// and return the result
char	*ft_strtrim(char const *s1, char const *set)
{
	char			*s;
	unsigned int	i;

	if (set == NULL || s1 == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	s = ft_substr(s1, 0, i + 1);
	return ((char *)s);
}

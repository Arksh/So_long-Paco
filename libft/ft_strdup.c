/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:29:23 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 16:24:56 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// create and allocate space whit malloc and copy "s1" in it
char	*ft_strdup(const char *s1)
{
	char		*ptr;

	ptr = ft_calloc(sizeof(char), ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return ((char *)ptr);
}

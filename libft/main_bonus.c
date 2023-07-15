/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:12:05 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/23 13:29:46 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char *argv[])
{
	int		file;
	int		i;
	int		l;
	char	*c;

	i = argc;
	l = 0;
	file = open(argv[1], O_RDONLY);
	c = get_next_line(file);
	while (l < 10)
	{
		ft_printf ("%i	%s", l++, c);
		free (c);
		c = get_next_line(file);
	}
	close(file);
	return (0);
}

	//system ("leaks a.out");

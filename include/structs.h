/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:45 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/23 11:53:06 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <so_long.h>

typedef struct s_size
{
	size_t		width;
	size_t		height;
}				t_size;

typedef struct s_cords
{
	size_t		x;
	size_t		y;
}				t_cords;

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_size	size_map;
	struct s_size	size_img;
}					t_win;

typedef struct s_object
{
	void				*img;
	char				name;
	struct s_cords		cords;
	struct s_location	*loc;
}						t_object;

typedef struct s_location
{
	void				*img;
	char				name;
	struct s_object		*objt;
	struct s_cords		cords;
	struct s_location	*north;
	struct s_location	*south;
	struct s_location	*east;
	struct s_location	*west;
}						t_location;

typedef struct s_map
{
	struct s_location	*init;
	struct s_cords		cords;
	int					collectables;
}						t_map;

typedef struct s_prog
{
	t_win			win;
	t_map			*map;
	t_object		*player;
	t_object		*exit;
}					t_prog;

#endif

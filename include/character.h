/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:40:22 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/01 15:50:00 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

enum fig_type
{
	CIRCLE,
	RECT
};

typedef struct s_frame
{
	int		x;
	int		y;
	int		color;
	int		figure_size;
}			t_frame;

typedef struct s_animation
{
	t_list			frames;
	enum fig_type	fig_type;
	t_frame			current_frame;
	int				delay;
	int				_tmp_delay;
	int				current_frame_num;
	long int		fps;
	long int		last_updated;
	long int		frame_count;
}					t_animation;

typedef struct s_animator
{
	t_list		*animations;
	t_win		*win;
	t_img		*img;
}				t_animator;

int		update(t_animator *a);
t_animation * ball_animation1(int delay, int fps);

#endif

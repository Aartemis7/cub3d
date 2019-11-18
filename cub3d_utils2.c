/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braimbau <braimbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:58:52 by braimbau          #+#    #+#             */
/*   Updated: 2019/11/14 22:01:29 by braimbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		verif_set(t_set set)
{
	if (set.ceil == -1 || set.floor == -1 || set.map_x == 0 || set.map_y == 0 ||
	set.play_x == -1 || set.play_y == -1 || set.play_o == -1 ||
	set.res_x == -1 || set.res_y == -1 || set.tex_n == -1 || set.tex_e == -1 ||
	set.tex_s == -1 || set.tex_w == -1 || set.tex_p == -1)
		return (1);
	return (0);
}

t_play	init_play(t_set set)
{
	t_play play;

	play.unit = set.res_x / 5;
	play.o = set.play_o;
	play.x = set.play_x * play.unit + play.unit / 2;
	play.y = set.play_y * play.unit + play.unit / 2;
	play.res_x = set.res_x;
	play.res_y = set.res_y;
	play.map_x = set.map_x;
	play.map_y = set.map_y;
	return (play);
}

float	angle(int angle)
{
	float f;

	if (angle > 360000)
		angle = (angle - 360000);
	if (angle < 0)
		angle = (360000 + angle);
	f = (float) angle / 1000;
	return (f);
}
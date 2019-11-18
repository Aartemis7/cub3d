/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braimbau <braimbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:43:53 by braimbau          #+#    #+#             */
/*   Updated: 2019/11/18 14:33:15 by braimbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_frame(t_play play, int **map, void *mlx_ptr, void *win_ptr)
{
	int		row;
	int		line;
	int		dst;

	row = 0;
	while (row < play.res_x)
	{
		dst = find_dist(play, angle(play.o - 30000 + row * 60000 / play.res_x), map);
		row++;
	}
}

int		find_dist(t_play play, float angle, int **map)
{
	int	dst_v;
	int	dst_h;

	printf("Angle = %f\n", angle);
	dst_v = find_dist_v(play, angle, map);
	dst_h = find_dist_h(play, angle, map);
	return (0);
}

int		find_dist_v(t_play play, float angle, int **map)
{
	float x;
	float y;
	int i;

	if (angle > 270 || angle < 90)
		y = - play.y % play.unit;
	else
		y = play.y % play.unit;
	if (angle > 270 || angle < 90)
		x = tanf(angle * M_PI /180) * fabsf(y);
	else
		x = tanf((fabsf(180 - angle)) * M_PI /180) * (play.unit - y);
	i = 0;
	while (i < 5)
	{
		printf("X = %f Y = %f\n", play.x + x + i * play.unit * tanf(angle_r(angle)*M_PI / 180), play.y + y + i * play.unit * y / fabsf(y));
		if (hit_wall(map, play.x + x + i * play.unit/tanf(angle * M_PI / 180) * x / fabsf(x), play.y + y + i * play.unit * y / fabsf(y), play))
		{
			printf("HIT EN %d\n", i);
			return (1);
		}
		i++;
	}
	return (1);
}

int		find_dist_h(t_play play, float angle, int **map)
{
	return (0);
}

int hit_wall(int ** map, int x, int y, t_play play)
{
	return (0);
}

float angle_r(float angle)
{
	if (angle > 180)
		return (angle - 360);
	else
		return (angle);
	
}
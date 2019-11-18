/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braimbau <braimbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:08:07 by braimbau          #+#    #+#             */
/*   Updated: 2019/11/15 12:11:14 by braimbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_set	set;
	t_play	play;
	int		**map;
	void	*mlx_ptr;
	void	*win_ptr;

	if (display_errors(argv[1], &set, &map) == 1)
		return (1);
	//mlx_ptr = mlx_init();
	//win_ptr = mlx_new_window(mlx_ptr, set.res_x, set.res_y, "Cub3D");
	play = init_play(set);
	display_frame(play, map, mlx_ptr, win_ptr);
	//mlx_loop(mlx_ptr);
	return (0);
}

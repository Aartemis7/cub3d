/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braimbau <braimbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:21:04 by braimbau          #+#    #+#             */
/*   Updated: 2019/11/14 15:35:27 by braimbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_atoi(char *str)
{
	int i;
	int nbr;
	int sign;

	sign = 1;
	i = 0;
	nbr = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*r;

	if (!(r = (char *)malloc((ft_strlen(s1) +
	ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	n = 0;
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[n])
	{
		r[i + n] = s2[n];
		n++;
	}
	r[i + n] = 0;
	return (r);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str != 0)
	{
		i++;
		str++;
	}
	return (i);
}

void	remp_set(t_set *set)
{
	set->ceil = -1;
	set->floor = -1;
	set->map_x = 0;
	set->map_y = 0;
	set->play_x = -1;
	set->play_y = -1;
	set->play_o = -1;
	set->res_x = -1;
	set->res_y = -1;
	set->tex_n = -1;
	set->tex_e = -1;
	set->tex_s = -1;
	set->tex_w = -1;
	set->tex_p = -1;
}

int		display_errors(char *str, t_set *set, int ***map)
{
	char *ret;
	char *ret2;

	ret = read_set(open(str, O_RDONLY), set);
	if (!ret)
		ret2 = read_map(open(str, O_RDONLY), map, set);
	if (ret)
	{
		write(1, "Error\n", 6);
		write(1, ret, ft_strlen(ret));
		write(1, "\n", 1);
		return (1);
	}
	if (ret2)
	{
		write(1, "Error\n", 6);
		write(1, ret2, ft_strlen(ret2));
		write(1, "\n", 1);
		return (1);
	}
	if (verif_set(*set) != 0)
	{
		write(1, "Error\n", 6);
		write(1, "Missing some information in configuation file\n", 46);
		return (1);	
	}
	return (0);
}
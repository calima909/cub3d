/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:30:29 by akoutsou          #+#    #+#             */
/*   Updated: 2023/09/04 15:59:07 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_zero(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (!ft_check_vert_zero(map, i, j))
					return (0);
				if (!ft_check_horiz_zero(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_single_start(char **map)
{
	int	i;
	int	j;
	int	flg;

	i = -1;
	flg = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr_i("NSEW", map[i][j]) != -1 && flg == 0)
				flg = 1;
			else if (ft_strchr_i("NSEW", map[i][j]) != -1 && flg == 1)
				return (1);
		}
	}
	return (0);
}

int	ft_check_start(char **map)
{
	int	i;
	int	j;
	int	flg;

	i = 0;
	if (ft_check_single_start(map))
		return (0);
	while (map[i])
	{
		if (ft_strchars_i(map[i], "NSEW") != -1)
		{
			flg = 1;
			j = ft_strchars_i(map[i], "NSEW");
			if (i == 0 || !map[i + 1] || j == 0 || !map[i][j + 1])
				return (0);
		}
		i++;
	}
	if (flg == 1)
		return (1);
	return (0);
}

int	ft_check_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchars_i(map[i], "10NSEW") == -1)
			return (0);
		if (!ft_check_map_line_charset(map[i]))
			return (0);
		i++;
	}
	if (!ft_check_start(map))
		return (0);
	if (!ft_check_zero(map))
		return (0);
	return (1);
}

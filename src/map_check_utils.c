/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:33:39 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/24 18:42:51 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map_line_charset(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_vert_zero(char **map, int i, int j)
{
	int	k;

	k = i;
	if (i == 0 || !map[i + 1])
		return (0);
	while (map[k] && k >= 0)
	{
		if (map[k][j] == '1')
			return (1);
		k++;
	}
	k = i;
	while (map[k] && k >= 0)
	{
		if (map[k][j] == '1')
			return (1);
		k--;
	}
	return (0);
}

int	ft_check_horiz_zero(char **map, int i, int j)
{
	int	k;

	k = j;
	if (j == 0 || !map[i][j + 1])
		return (0);
	while (map[i][k] && map[i][k] != ' ')
	{
		if (map[i][k] == '1')
			return (1);
		k++;
	}
	if (map[i][k] && map[i][k] == ' ')
		return (0);
	k = j;
	while (map[i][k] && k >= 0 && map[i][k] != ' ')
	{
		if (map[i][k] == '1')
			return (1);
		k--;
	}
	return (0);
}

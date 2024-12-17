/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:57:56 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/23 19:07:55 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_direction(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	else
		return (0);
}

unsigned int	ft_color_converter(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

double	ft_degrees_to_radiants(double degrees)
{
	return (degrees * PI / 180);
}

unsigned int	ft_mlx_pixel_get(t_tex *data, int x, int y)
{
	char	*dst;

	dst = data->data + (y * data->size_line + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	ft_render_pixel(t_tex img, int x, int y, int color)
{
	char	*dst;

	dst = img.data + (y * img.size_line + x * (img.bpp / 8));
	*(unsigned int *) dst = color;
}

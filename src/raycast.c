/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:58:55 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/24 19:04:39 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_get_direction(t_program *prg, t_ray *ray)
{
	if (ray->raycos < 0)
		ray->raycos *= -1;
	if (ray->raysin < 0)
		ray->raysin *= -1;
	if (prg->map[(int)((ray->currenty)
			- ray->raysin)][(int)ray->currentx] != '1')
		ray->direction = 0;
	else if (prg->map[(int)((ray->currenty)
			+ ray->raysin)][(int)ray->currentx] != '1')
		ray->direction = 1;
	else if (prg->map[(int)(ray->currenty)][(int)((ray->currentx)
			+ ray->raycos)] != '1')
		ray->direction = 2;
	else if (prg->map[(int)(ray->currenty)][(int)((ray->currentx)
			- ray->raycos)] != '1')
		ray->direction = 3;
}

static t_column	ft_do_column(t_program *prg, t_ray ray, int raycount)
{
	t_column	res;

	res.sky_start = 0;
	res.sky_end = prg->half_h - ray.wallheight;
	if (res.sky_end < 0)
		res.sky_end = 0;
	res.sky_color = ft_color_converter(prg->color[1].r, prg->color[1].g,
			prg->color[1].b);
	res.wall_start = prg->half_h - ray.wallheight;
	if (res.wall_start < 0)
		res.wall_start = 0;
	res.wall_end = prg->half_h + ray.wallheight;
	if (res.wall_end >= prg->size.y)
		res.wall_end = prg->size.y;
	res.direction = ray.direction;
	res.floor_start = prg->half_h + ray.wallheight;
	if (res.floor_start >= prg->size.y)
		res.floor_start = prg->size.y;
	res.floor_end = prg->size.y;
	res.colnbr = raycount;
	res.currentx = ray.currentx;
	res.currenty = ray.currenty;
	res.floor_color = ft_color_converter(prg->color[0].r, prg->color[0].g,
			prg->color[0].b);
	return (res);
}

static void	ft_init_ray(t_program *prg, t_ray *ray)
{
	ray->currentx = prg->spawn_x;
	ray->currenty = prg->spawn_y;
	ray->raycos = cos(ft_degrees_to_radiants(ray->ray_angle))
		/ prg->rc_precision;
	ray->raysin = sin(ft_degrees_to_radiants(ray->ray_angle))
		/ prg->rc_precision;
}

static void	ft_raycasting2(t_program *prg, t_ray *ray)
{
	int	wall;

	wall = 48;
	ft_init_ray(prg, ray);
	while (wall == 48 || ft_is_direction(wall) == 1)
	{
		ray->currentx += ray->raycos;
		ray->currenty += ray->raysin;
		wall = prg->map[(int)floor(ray->currenty)][(int)floor(ray->currentx)];
	}
}

void	ft_raycasting(t_program *prg)
{
	int			raycount;
	t_ray		ray;
	t_column	currentcol;

	raycount = 0;
	ray.ray_angle = prg->angle - prg->half_fov;
	while (raycount < prg->size.x)
	{
		ft_raycasting2(prg, &ray);
		ray.dist = sqrt(pow(prg->spawn_x - ray.currentx, 2) + pow(prg->spawn_y
					- ray.currenty, 2));
		ray.dist = ray.dist * cos(ft_degrees_to_radiants(ray.ray_angle
					- prg->angle));
		ray.wallheight = floor(prg->half_h / ray.dist);
		ft_get_direction(prg, &ray);
		currentcol = ft_do_column(prg, ray, raycount);
		ft_render_full_column(prg, prg->img, currentcol);
		ray.ray_angle += prg->rc_incrementing;
		raycount++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:58:12 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/31 14:06:02 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_down(t_program *prg, double playercos, double playersin)
{
	double	newx;
	double	newy;

	newx = prg->spawn_x - playercos;
	newy = prg->spawn_y - playersin;
	if (prg->map[(int)floor(newy)][(int)floor(newx)] == 48
		|| ft_is_direction(prg->map[(int)floor(newy)][(int)floor(newx)]) == 1)
	{
		prg->spawn_x = newx;
		prg->spawn_y = newy;
	}
}

void	ft_move_up(t_program *prg, double playercos, double playersin)
{
	double	newx;
	double	newy;

	newx = prg->spawn_x + playercos;
	newy = prg->spawn_y + playersin;
	if (prg->map[(int)floor(newy)][(int)floor(newx)] == 48
		|| ft_is_direction(prg->map[(int)floor(newy)][(int)floor(newx)]) == 1)
	{
		prg->spawn_x = newx;
		prg->spawn_y = newy;
	}
}

void	ft_move_right(t_program *prg, double playercos, double playersin)
{
	double	newx;
	double	newy;

	newx = prg->spawn_x - playersin;
	newy = prg->spawn_y + playercos;
	if (prg->map[(int)floor(newy)][(int)floor(newx)] == 48
		|| ft_is_direction(prg->map[(int)floor(newy)][(int)floor(newx)]) == 1)
	{
		prg->spawn_x = newx;
		prg->spawn_y = newy;
	}
}

void	ft_move_left(t_program *prg, double playercos, double playersin)
{
	double	newx;
	double	newy;

	newx = prg->spawn_x + playersin;
	newy = prg->spawn_y - playercos;
	if (prg->map[(int)floor(newy)][(int)floor(newx)] == 48
		|| ft_is_direction(prg->map[(int)floor(newy)][(int)floor(newx)]) == 1)
	{
		prg->spawn_x = newx;
		prg->spawn_y = newy;
	}
}

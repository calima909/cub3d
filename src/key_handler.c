/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:30:15 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/24 18:58:29 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_move_wasd(t_program *prg, int flag)
{
	double	playercos;
	double	playersin;

	playercos = cos(ft_degrees_to_radiants(prg->angle)) * 0.2;
	playersin = sin(ft_degrees_to_radiants(prg->angle)) * 0.2;
	if (flag == 0)
		ft_move_up(prg, playercos, playersin);
	else if (flag == 1)
		ft_move_down(prg, playercos, playersin);
	else if (flag == 2)
		ft_move_right(prg, playercos, playersin);
	else if (flag == 3)
		ft_move_left(prg, playercos, playersin);
}

int	ft_handlekeys(int ks, t_program *prg)
{
	mlx_clear_window(prg->mlx, prg->win_ptr);
	if (ks == KEY_A)
		ft_move_wasd(prg, 3);
	if (ks == KEY_D)
		ft_move_wasd(prg, 2);
	if (ks == KEY_W)
		ft_move_wasd(prg, 0);
	if (ks == KEY_S)
		ft_move_wasd(prg, 1);
	if (ks == KEY_LEFT)
		prg->angle -= 5;
	if (ks == KEY_RIGHT)
		prg->angle += 5;
	if (ks == KEY_ESC)
		ft_close(prg);
	ft_raycasting(prg);
	mlx_put_image_to_window(prg->mlx, prg->win_ptr, prg->img.ptr, 0, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 04:02:42 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/20 18:44:43 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_images(t_game *game)
{
	int	width;
	int	height;

	game->img_grass = mlx_xpm_file_to_image(game->mlx, \
					"./images/Grass.xpm", &width, &height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, \
					"./images/Wall.xpm", &width, &height);
	game->img_nick = mlx_xpm_file_to_image(game->mlx, \
					"./images/Nick.xpm", &width, &height);
	game->img_bluederry = mlx_xpm_file_to_image(game->mlx, \
					"./images/Blueberry.xpm", &width, &height);
	game->img_judy_ok = mlx_xpm_file_to_image(game->mlx, \
					"./images/Judy_OK.xpm", &width, &height);
	game->img_judy_no = mlx_xpm_file_to_image(game->mlx, \
					"./images/Judy_NO.xpm", &width, &height);
}

void	put_image_to_map(t_game *game, t_maps *maps)
{
	int	x;
	int	y;

	y = -1;
	while (++y < maps->height)
	{
		x = -1;
		while (++x < maps->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, \
				game->img_grass, x * 64, y * 64);
			if (maps->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
					game->img_wall, x * 64, y * 64);
			else if (maps->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
					game->img_bluederry, x * 64, y * 64);
			else if (maps->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, \
					game->img_nick, x * 64, y * 64);
			else if (maps->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
					game->img_judy_no, x * 64, y * 64);
		}
	}
}

void	modify_image(t_game *game, int position, int x, int y)
{
	if (position == GROUD)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->img_grass, x * 64, y * 64);
	else if (position == MOVE)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->img_nick, x * 64, y * 64);
	else if (position == GET)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->img_grass, x * 64, y * 64);
		mlx_put_image_to_window(game->mlx, game->win, \
			game->img_nick, x * 64, y * 64);
	}
	else if (position == DONE)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->img_grass, x * 64, y * 64);
		mlx_put_image_to_window(game->mlx, game->win, \
			game->img_judy_ok, x * 64, y * 64);
	}
}

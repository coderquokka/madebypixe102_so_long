/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:55:42 by aperez-b          #+#    #+#             */
/*   Updated: 2021/07/29 11:05:30 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/game.h"
#include "../libft/lib/libft.h"
#include <mlx.h>
#include <stdio.h>

void	init_game(char **map, t_lay *lay)
{
	t_game	game;

	game = ft_newgame(map, *lay);
	print_map(&game);
}
	
t_mlx	start_mlx(t_lay lay)
{
	t_mlx	mlx;

	mlx.id = mlx_init();
	mlx.window_id = mlx_new_window(mlx.id, lay.nCol * SPRITE_SIZE, lay.nRow * SPRITE_SIZE, "Pac-Man Game");
	return(mlx);
}

t_game	ft_newgame(char **map, t_lay lay)
{
	t_game	newgame;

	newgame.wndw_size = ft_newvector(lay.nCol * SPRITE_SIZE, lay.nRow * SPRITE_SIZE);
	newgame.map = map;
	newgame.mlx = start_mlx(lay);
	return (newgame);
}

void	print_map(t_game *game)
{
	int		x;
	int		y;
	char	*c;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			c = ft_chartostr(game->map[y][x]);
			mlx_string_put(game->mlx.id, game->mlx.window_id, x * SPRITE_SIZE, y * SPRITE_SIZE + 10, 0xFDD663, c);
			free(c);
			x++;
		}
		y++;
	}
	mlx_loop(game->mlx.id);
}

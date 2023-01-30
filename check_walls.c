/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:49:34 by oufisaou          #+#    #+#             */
/*   Updated: 2023/01/30 18:52:01 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/*
    This function checks if a wall is there to no go through it
*/

void check_walls1(t_all *cub, int flag, double angle)
{
    double	x;
	double	y;

    if(flag == 1)
    {
       x = (cub->player.x + (cos(angle) * cub->player.speed)) / CUBE;
       y = (cub->player.y + (sin(angle) * cub->player.speed)) / CUBE;
       if(cub->walls[(int)y][(int)x] != '1' && (cub->walls[(int)y][(int)cub->player.x / CUBE] != '1' && cub->walls[(int)cub->player.y / CUBE][(int)x] != '1')) //ta9ato3
        {
            cub->player.x = x * CUBE;
            cub->player.y = y * CUBE;
        }
    }
    else if(flag == 0)
    {
        x = (cub->player.x - (cos(angle) * cub->player.speed)) / CUBE;
        y =  (cub->player.y - (sin(angle) * cub->player.speed)) / CUBE;
        if(cub->walls[(int)y][(int)x] != '1' && (cub->walls[(int)y][(int)cub->player.x / CUBE] != '1' && cub->walls[(int)cub->player.y / CUBE][(int)x] != '1')) //ta9ato3
        {
            cub->player.x = x * CUBE;
            cub->player.y = y * CUBE;
        }
    }
}

/*
    This function checks if a wall is there to no go through it
*/

void check_walls2(t_all *cub, int flag)
{
    int	x;
	int	y;
    int speed;
    
    speed = cub->player.speed * -1;
    if(flag == 1)
    {
       x = cub->player.x + (cos(cub->player.ang) * cub->player.speed);
       y = cub->player.y + (sin(cub->player.ang) * cub->player.speed);
       if(cub->walls[(int)y / CUBE][(int)x / CUBE] != '1' && (cub->walls[(int)y / CUBE][(int)cub->player.x / CUBE] != '1' && cub->walls[(int)cub->player.y / CUBE][(int)x / CUBE] != '1'))
       {
           cub->player.x = x;
           cub->player.y = y;
       }
    }
    else if(flag == 0)
    {
        x = cub->player.x + (cos(cub->player.ang) * speed);
        y =  cub->player.y + (sin(cub->player.ang) * speed);
        if(cub->walls[(int)y / CUBE][(int)x / CUBE] != '1' && (cub->walls[(int)y / CUBE][(int)cub->player.x / CUBE] != '1' && cub->walls[(int)cub->player.y / CUBE][(int)x / CUBE] != '1'))
        {
            cub->player.x = x;
            cub->player.y = y;
        }
    }
}
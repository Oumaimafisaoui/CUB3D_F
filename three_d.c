/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:55:40 by oufisaou          #+#    #+#             */
/*   Updated: 2023/01/30 19:56:21 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void generate_3d(t_all *cub)
{

     
     int w;
     int h,bits_per_pixel,line_length,endian;
     int i;
     i = 0;
     void * img = mlx_xpm_file_to_image(cub->mlx, "parsing/xpmfile/wall4.xpm", &w, &h);
     if (!img)
     {
          printf("Error xpm file\n");
          exit(1);
     }
     unsigned int *adr1 = (unsigned int *)mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian); 
     while(i < cub->var_d.num_rays)
     {
          cub->three.d_player_pro = (WINDOW_W / 2) / tan(FEILD / 2);
          cub->three.ray_distance = cub->ray[i].distance * (cos(cub->ray[i].angle  - cub->player.ang));
          cub->three.wall_projection = (CUBE / cub->three.ray_distance) * cub->three.d_player_pro;

          double wall_height = cub->three.wall_projection;
          double wall_top_pix = (WINDOW_H / 2) - (wall_height / 2);
          
          // if(wall_top_pix < 0)
          //      wall_top_pix = 0;
          // else
          //      wall_top_pix += 0;
               
          double wall_bott_pix = (WINDOW_H / 2) + (wall_height / 2);

          
          //  if(wall_bott_pix < 0)
          //      wall_bott_pix = 0;
          // else
          //      wall_bott_pix += 0;
          
          for (int x = 0; x < wall_top_pix; x++)
          {
                my_mlx_pixel_put3(cub, i, x, create_trgb(1 ,cub->map.r_C, cub->map.g_C, cub->map.b_C));
          }

          int f = 0;int k = 0;
          double j = wall_top_pix;
          while (j < wall_bott_pix  && f < 64)
          {
               k = 0;
               while (k < (wall_bott_pix - wall_top_pix) / 64)
               {
                    my_mlx_pixel_put3(cub, i, (int)j + k, *(adr1 +  (int)(f * 64 + fmod( cub->ray[i].x + cub->ray[i].y, 64)) ));
                    k++;
                    
               }
               f++;
               j += (wall_bott_pix - wall_top_pix) / 64;
              
          }
          // double j = wall_top_pix;
          // double o_x;
          
          // if (cub->ray->hor == true)
          //      o_x = (int)cub->var_d.x1 % 64;
          // else
          //      o_x = (int)cub->var_d.y1 % 64;
          // // printf("%f\n", o_x); 
          // double save = wall_top_pix;
          // double o_y;
          // while (j < wall_bott_pix)
          // {
          //      o_y = (j - save) * ((double)64 / wall_height);
          //      my_mlx_pixel_put3(cub, i, (int)j, *(adr1 + (unsigned int)((o_y * 64 ) + o_x)));
          //      j++;
          // }

          
          for(int y = wall_bott_pix; y < WINDOW_H; y++)
          {

               my_mlx_pixel_put3(cub, i, y, create_trgb(1 ,cub->map.r_F, cub->map.g_F, cub->map.b_F));
          }
          i++;
     }
}
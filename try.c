
int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}


void ft_putstr_fd(char *str, int fd)
{
    if(!str)
        return ;
     write(fd, str, ft_strlen(str));
}


int ft_error(char *str)
{
   ft_putstr_fd("Error: ",2);
   ft_putstr_fd(str); 
   exit(1);
}

cub->mlx = mlx_init();
if(!cub->mlx)
    ft_error("problem in mlx");
cub->mlx_win = mlx_new_window(cub->mlx, WINDOW_W, WINDOW_H, "Cube3d");
if(!mlx_win)
    ft_error("problem in window");

cub->img = mlx_new_image(cub->mlx, cub->map-w, cub->map_h);
cub->addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel, &cub->line_length, &cub->endian);

cub->img1 = mlx_new_image(cub->mlx,WINDOW_W, WINDOW_H);
cub->addr1 = mlx_get_data_addr(cub->img1, &cub->bits_per_pixel1, &cub->line_length1, &cub->endian1);


void draw_minmap(t_all *cub)
{
    while(cub->map_i < cub->map_h / CUBE) // i <= 1
    {
        cub->map_j = 0;
        while(cub->map_j < cub->map_w / CUBE) // j <= 1
        {
            cub->map_y = cub->map_i * CUBE; 
            while(cub->map_y < cub->map_i * CUBE + CUBE)
            {   
                    if(cub->walls[cub->map_i][cub->map_j] == '1')
                    {
                        while(cub->map_x < cub->map_j * CUBE + CUBE)
                        {
                            cub->map_x = cub->map_j * CUBE;
                            if(cub->map_x % CUBE == 0 || cub->map_y % CUBE == 0)
                                my_mlx_put_pixel1(cub->img, cub->map_x, cub->map_y, cub->black);
                            else
                                 my_mlx_put_pixel1(cub->img, cub->map_x, cub->map_y, cub->yellow);
                            cub->map_x++;
                        }
                   cub->map_y++;     
                }
                cub->map_j++;
            }
            cub->map_i++;
        }
        reset_variables(cub);
        return ;
    }

}


void my_mlx_pixel_put2(void *mlx, double x, double y, int color)
{
    char *adress;

    if(x = 0 && x < cub->map_w && y >= 0 && y < cub->map_h)
    {
        adress = cub->adrr + (y * cub->line_length) + (x * (cub->bits_per_pixel / 8));
        *(unsigned int *)(adress) = color;
    }
}




void get_player_coord(t_all * cub)
{
    int i = 0;
    int j;
    while(i < cub->map_h / CUBE)
    {
        j = 0;
        while(j < cub->map_w / CUBE)
        {
            if(cub->walls[i][j] == 'S' || 'N' || 'E' || 'W')
            {
                cub->player.x = (i * CUBE) + CUBE / 2;
                cub->player.y = (j * CUBE) + CUBE / 2;
            }
            j++;
        }
        i++;
    }
}

void draw_big_cercle(t_all *cub)
{
    double h;
    double angle;
    double xs;
    double ys;
    double i = 1;
    h = 0;

    my_mlx_put_pixel1(cub->img, cub->player.x, cub->player.y, cub->purple);
    while(h < 5)
    {
        angle = 0;
        while(angle < 360)
        {
            xs = cos(angle) * h + cub->player.x;
            ys = sin(angle) * h + cub->player.y;
            my_mlx_put_pixel1(cub->img, xs, ys, cub->purple);
            angle++;
        }
        h++;
    }
}





void event_left_right(t_all *cub, int key)
{
    double angle;

    if(key == right)
    {
        
    }
}


















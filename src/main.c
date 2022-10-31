#include "mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_rect(t_data img, int x, int y)
  {
	int a = x;
	int b = y;
	while (a > 0)
    {
	    my_mlx_pixel_put(&img, a, 0, 0x00FF0000);
		my_mlx_pixel_put(&img, a, b, 0x00FF0000);
        a--;
    }
	a = x;
	while (b > 0)
	{
		my_mlx_pixel_put(&img, 0, b, 0x00FF0000);
		my_mlx_pixel_put(&img, a, b, 0x00FF0000);
        b--;
	}
}
void draw_retc_col(t_data img, int x, int y)
{
	int a;
	int b;
	a = x;
		while (a > 0 )
	{
		b = y;
		while (b > 0)
		{
			my_mlx_pixel_put(&img, a, b, 0x00FF0000);
			b--;
		}
		a--;
	}
}

void draw_trian_col(t_data img, int x, int y)
{
	int a;
	int b;
	a = x;
	while (a > 0 )
	{
		b = y;
		while (b > 0)
		{
			if(a <= b)
				my_mlx_pixel_put(&img, a, b, 0x00FF0000);
			b--;
		}
		a--;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	int x = 1920;
	int y = 1080;
	int a;
	int b;
	a = x;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);


	while (a > 500 )
	{
		b = y;
		while (b > 500)
		{
			if((a * a) + (b * b) == 1000)
				my_mlx_pixel_put(&img, a, b, 0x00FF0000);
			b--;
		}
		a--;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 500);
	mlx_loop(mlx);
}

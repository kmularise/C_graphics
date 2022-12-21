#include "so_long.h"



int main()
{
	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;			
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img1 = mlx_xpm_file_to_image(mlx, "./images/floor.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img1, 0, 0);
	img1 = mlx_xpm_file_to_image(mlx, "./images/character_right.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img1, 0, 0);
	img1 = mlx_xpm_file_to_image(mlx, "./images/floor.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img1, 64, 0);
	img1 = mlx_xpm_file_to_image(mlx, "./images/tomato.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img1, 64, 0);
	// img2 = mlx_xpm_file_to_image(mlx, "./images/collective.xpm", &img_width, &img_height);
	// img3 = mlx_xpm_file_to_image(mlx, "./images/floor.xpm", &img_width, &img_height);
	// img4 = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &img_width, &img_height);
	// img5 = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &img_width, &img_height);

	// mlx_put_image_to_window(mlx, win, img1, 0, 0);
	// mlx_put_image_to_window(mlx, win, img2, 64, 0);
	// mlx_put_image_to_window(mlx, win, img3, 128, 0);
	// mlx_put_image_to_window(mlx, win, img4, 192, 0);
	// mlx_put_image_to_window(mlx, win, img5, 256, 0);

	mlx_loop(mlx);
}
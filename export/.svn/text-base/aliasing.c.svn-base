/*
** aliasing.c for aliasing in /home/knocka_a/repositories/rt
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Jun  1 16:43:30 2012 antoine knockaert
** Last update Sat Jun  2 18:38:12 2012 antoine knockaert
*/

#include	"../rt.h"

void		get_pixel(int x, int y, unsigned char *data, unsigned char *color)
{
  int		i;

  i = (y * LARGEUR * 4) + (x * 4);
  color[0] = data[i];
  color[1] = data[i + 1];
  color[2] = data[i + 2];
  color[3] = data[i + 3];
}

void		set_pixel(int x, int y, unsigned char *data, unsigned char *color)
{
  int		i;

  i = (y * LARGEUR * 4) + (x * 4);
  data[i] = color[0];
  data[i + 1] = color[1];
  data[i + 2] = color[2];
  data[i + 3] = color[3];
}

void		pix_aliasing(int x, int y, unsigned char *data,
			     unsigned char *color_new)
{
  unsigned char	color[4];
  unsigned char	color_t[4];
  unsigned char	color_l[4];
  unsigned char	color_b[4];
  unsigned char	color_r[4];

  get_pixel(x, y, data, color);
  get_pixel(x, y + 1, data, color_b);
  get_pixel(x - 1, y, data, color_l);
  get_pixel(x + 1, y, data, color_r);
  get_pixel(x, y - 1, data, color_t);
  color_new[0] = (color[0] + 2 * color_t[0] + 2 * color_l[0] + 2 * color_r[0] +
		  2 * color_b[0])
    / 9;
  color_new[1] = (color[1] + 2 * color_t[1] + 2 * color_l[1] + 2 * color_r[1] +
		  2 * color_b[1])
    / 9;
  color_new[2] = (color[2] + 2 * color_t[2] + 2 * color_l[2] + 2 * color_r[2] +
		  2 * color_b[2])
    / 9;
  color_new[3] = (color[3] + 2 * color_t[3] + 2 * color_l[3] + 2 * color_r[3] +
		  2 * color_b[3])
    / 9;
}

int		is_to_set(unsigned char *color, unsigned char *new_color)
{
  int		sum;
  unsigned char tmp[4];

  sum = 0;
  while (sum < 4)
    {
      tmp[sum] = new_color[sum] - color[sum];
      sum++;
    }
  if (tmp[0] > 100 || tmp[1] > 100 || tmp[2] > 100)
    return (1);
  return (0);
}

void		aliasing(t_mlx *init)
{
  unsigned char *data;
  int		x;
  int		y;
  unsigned char color[4];
  unsigned char	color_new[4];

  y = 0;
  data = init->data;
  while (y < HAUTEUR)
    {
      x = 0;
      while (x < LARGEUR)
	{
	  if (x > 0 && y > 0 && x < (LARGEUR - 1) && y < (HAUTEUR - 1))
	    {
	      get_pixel(x, y, data, color);
	      pix_aliasing(x, y, data, color_new);
	      if (is_to_set(color, color_new))
		set_pixel(x, y, data, color_new);
	    }
	  x++;
	}
      y++;
    }
  gere_expose(init);
}

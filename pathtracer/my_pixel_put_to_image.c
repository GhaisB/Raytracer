/*
** my_pixel_put_to_image.c for AZD in /home/duez_a//rtv1/tp
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue Feb 14 17:58:29 2012 guillaume duez
** Last update Sun Jun  3 12:23:08 2012 guillaume boell
*/

#include "../rt.h"

static unsigned char	get_moy(int x, int y, int radius, t_mlx *init)
{
  int			rx;
  int			ry;
  int			n;
  int			tot;

  n = 0;
  tot = 0;
  rx = (x / 4) - radius - 1;
  ry = y - radius - 1;
  while (++ry <= y + radius)
    {
      while (++rx <= (x / 4) + radius)
	if ((rx) >= 0 && ry >= 0 && (rx) < LARGEUR && ry < HAUTEUR)
	    {
	      tot += init->data[x % 4 + (rx + (ry * LARGEUR)) * 4];
	      n++;
	    }
      rx = (x / 4) - radius - 1;
    }
  if (!n)
    return (0);
  return (tot / n);
}

void			tent_filter_pt(int x, int y, t_mlx *init, int poids)
{
  int			pds;
  int			a;

  a = (x + (y * LARGEUR)) * 4;
  if (y < HAUTEUR)
    if (x < LARGEUR)
      if (y >= 0 && y < HAUTEUR && x >= 0 && x < LARGEUR &&
	  ((int)init->data[a] && poids < 10000))
	{
	  poids -= init->dist_focus;
	  pds = abs(poids / init->scale_focus);
	    pds *= init->blur_power;
	  if (abs(pds) < 0)
	    pds = 0;
	  if (pds > 20)
	    pds = 20;
	  init->data[a] = (get_moy((x * 4), y, pds, init));
	  init->data[a + 1] = (get_moy((x * 4) + 1, y, pds, init));
	  init->data[a + 2] = (get_moy((x * 4) + 2, y, pds, init));
	}
}

void			put_pix(t_cod *cor, t_mlx *init, double *color, int pass)
{
  int			a;

  a = (cor->x + (cor->y * LARGEUR) * 4);
  cor->col_final[0] += color[0];
  cor->col_final[1] += color[1];
  cor->col_final[2] += color[2];
  if (cor->frames_left == FRAME_PER_PIX)
    {
      color[0] = cor->col_final[0] / FRAME_PER_PIX;
      color[1] = cor->col_final[1] / FRAME_PER_PIX;
      color[2] = cor->col_final[2] / FRAME_PER_PIX;
      if (((init->data[a] + (int)(color[0]) / ((pass) + 1 + 4))) >= 255)
	init->data[a] = 255;
      else
	init->data[a] = ((init->data[a] + (int)(color[0]) / ((pass) + 1 + 4)));
      if (((init->data[a + 1] + (int)(color[1]) / ((pass) + 1 + 4))) >= 255)
	init->data[a + 1] = 255;
      else
	init->data[a + 1] = ((init->data[a + 1] + (int)color[1] / ((pass) + 5)));
      if (((init->data[a + 2] + (int)(color[2]) / ((pass) + 1 + 4))) >= 255)
	init->data[a + 2] = 255;
      else
	init->data[a + 2] = ((init->data[a + 2] + (int)color[2] / ((pass) + 5)));
  }
}

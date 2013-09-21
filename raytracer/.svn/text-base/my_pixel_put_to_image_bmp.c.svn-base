/*
** my_pixel_put_to_image_bmp.c for rt in /home/dell-a_f/rt
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Fri Jun  1 13:30:31 2012 florian dell'aiera
** Last update Sun Jun  3 19:47:42 2012 florian dell'aiera
*/

#include	"../rt.h"

void		my_pixel_put_to_image_bmp(int x, int y, t_mlx *init,
					  unsigned char *color)
{
  int		a;

  a = x  + (y * LARGEUR * 4);
  init->data[a] = (int)color[init->cpt++];
  init->data[a + 1] =  (int)color[init->cpt++];
  init->data[a + 2] = (int)color[init->cpt++];
  init->data[a + 3] = 0;
}

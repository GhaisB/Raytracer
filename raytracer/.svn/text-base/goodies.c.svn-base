/*
** goodies.c for goodies in /home/knocka_a/repositories/rt/raytracer
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat May 26 12:30:44 2012 antoine knockaert
** Last update Sat Jun  2 18:50:18 2012 antoine knockaert
*/

#include	"../rt.h"

void		black_white(t_mlx *init)
{
  int		j;
  unsigned char	moy;

  j = 0;
  while (j < (HAUTEUR * (LARGEUR * 4)))
    {
      moy = (init->data[j] + init->data[j + 1] + init->data[j + 2]) / 3;
      init->data[j] = moy;
      init->data[j + 1] = moy;
      init->data[j + 2] = moy;
      j += 4;
    }
  gere_expose(init);
}

void		lumens_mode(t_mlx *init, int type)
{
  int		j;

  j = 0;
  while (j < (HAUTEUR * (LARGEUR * 4)))
    {
      if ((init->data[j] + type) <= 255 && (init->data[j] + type) >= 0)
	init->data[j] = init->data[j] + type;
      if ((init->data[j + 1] + type) <= 255 && (init->data[j + 1] + type) >= 0)
	init->data[j + 1] = init->data[j + 1] + type;
      if ((init->data[j + 2] + type) <= 255 && (init->data[j + 2] + type) >= 0)
	init->data[j + 2] = init->data[j + 2] + type;
      j += 4;
    }
  gere_expose(init);
}

void		reverse_mode(t_mlx *init)
{
  int		j;

  j = 0;
  while (j < (HAUTEUR * (LARGEUR * 4)))
    {
      init->data[j] = 255 - init->data[j];
      init->data[j + 1] = 255 - init->data[j + 1];
      init->data[j + 2] = 255 - init->data[j + 2];
      j += 4;
    }
  gere_expose(init);
}

void	stock_k(t_obj *obc, double k1, double k2)
{
  obc->xtmp = k1;
  obc->ytmp = k2;
}

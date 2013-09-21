/*
** func_download.c for d in /home/duez_a//rtv1/tp
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Sat Mar 10 10:46:45 2012 guillaume duez
** Last update Sun Jun  3 12:56:12 2012 guillaume boell
*/

#include "../rt.h"

void		func_download(int y, int hight, t_mlx *init)
{
  double	tmp;
  int		load;

  if (y % 100 == 0)
    {
      tmp = ((double)y / (double)hight) * 100.;
      load = (int)tmp;
      my_put_nbr(load);
      my_putstr("%\n");
      gere_expose(init);
    }
}

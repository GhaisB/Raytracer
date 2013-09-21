/*
** func_for_coordonne.c for ze in /home/duez_a//rtv1/tp
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Wed Feb 22 11:38:58 2012 guillaume duez
** Last update Sun Jun  3 13:00:22 2012 guillaume boell
*/

#include "../rt.h"

void	func_for_coordonne(t_cod *cor)
{
  cor->x = 0;
  cor->y = 0;
  cor->spx = -100;
  cor->spy = 0;
  cor->spz = 200;
  cor->color_sp = xmalloc(3 * sizeof(double));
  cor->color_sp[0] = 255;
  cor->color_sp[1] = 255;
  cor->color_sp[2] = 255;
  cor->l_x = xmalloc(3 * sizeof(double));
}

double	*list_for_O(double *list)
{
  list[0] = -350;
  list[1] = 0;
  list[2] = 150;
  return (list);
}

void	malloc_tmp(t_tmp *tmp)
{
  tmp->l_v = xmalloc(3 * sizeof(double));
  tmp->l_c = xmalloc(3 * sizeof(double));
}

void	init_obc(t_obj *obc)
{
  obc->p = xmalloc(3 * sizeof(double));
  obc->n = xmalloc(3 * sizeof(double));
  obc->coeff_k = 100000;
  obc->color = 0;
  init_ptr_func_inter(obc);
  init_ptr_func_normal(obc);
  init_ptr_func_shadow(obc);
}

void	calcul_X1(int x, int y, double *l_x)
{
  l_x[0] = ((double)LARGEUR / 2.0) / tanf((35.0 * M_PI) / 180.0);
  l_x[1] = (double)LARGEUR / 2.0 - (double)x;
  l_x[2] = (double)HAUTEUR / 2.0 - (double)y;
}

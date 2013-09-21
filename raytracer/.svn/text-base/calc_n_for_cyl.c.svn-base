/*
** calc_n_for_cyl.c for header in /home/duez_a//rtv1/tp
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Fri Mar  9 14:22:12 2012 guillaume duez
** Last update Sun Jun  3 12:54:02 2012 guillaume boell
*/

#include "../rt.h"

#define RA(x) ((x * M_PI) / 180)

void	calc_n_for_con(t_obj *obc, double *p, t_sph *obj_a)
{
  obc->n[0] = p[0];
  obc->n[1] = p[1];
  obc->n[2] = (p[2] * -obj_a->r);
  obj_a->xro = obj_a->xro * -1;
  obj_a->yro = obj_a->yro * -1;
  obj_a->zro = obj_a->zro * -1;
  rotate_x(obj_a->xro, obj_a->yro, obj_a->zro, obc->n);
  obj_a->xro = obj_a->xro * -1;
  obj_a->yro = obj_a->yro * -1;
  obj_a->zro = obj_a->zro * -1;
}

void	calc_n_for_cyl(t_obj *obc, double *p, t_sph *obj_a)
{
  obc->n[0] = p[0];
  obc->n[1] = p[1];
  obc->n[2] = 0;
  obj_a->xro = obj_a->xro * -1;
  obj_a->yro = obj_a->yro * -1;
  obj_a->zro = obj_a->zro * -1;
  rotate_x(obj_a->xro, obj_a->yro, obj_a->zro, obc->n);
  obj_a->xro = obj_a->xro * -1;
  obj_a->yro = obj_a->yro * -1;
  obj_a->zro = obj_a->zro * -1;
}

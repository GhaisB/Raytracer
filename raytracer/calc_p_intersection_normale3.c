/*
** calc_p_intersection_normale3.c for rt in /home/dell-a_f/rt/raytracer
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Fri Jun  1 13:11:08 2012 florian dell'aiera
** Last update Sun Jun  3 12:54:58 2012 guillaume boell
*/

#include "../rt.h"

#define RA(x) ((x * M_PI) / 180)
#define X2(x) (x * x)
#define X3(x) (x * x * x)

void		calc_n_for_tore(t_obj *obc, double *p, t_sph *obj_a)
{
  double	tmp;

  tmp = X2(p[0]) + X2(p[1]) + X2(p[2]) + X2(obj_a->r) - X2((obj_a->r / 3));
  obc->n[0] = 4 * p[0] * tmp - (8. * X2(obj_a->r) * p[0]);
  obc->n[1] = 4 * p[1] * tmp - (8. * X2(obj_a->r) * p[1]);
  obc->n[2] = 4 * p[2] * tmp;
}

void		calc_n_for_parabo(t_obj *obc, double *p, t_sph *obj_a)
{
  p = p;
  obc->n[0] = p[0];
  obc->n[1] = p[1];
  obc->n[2] = tan(obj_a->r) * -1;
  rotate_x(obj_a->xro, obj_a->yro, obj_a->zro, obc->n);
}

void		calc_n_for_triangle(t_obj *obc, double *p, t_sph *obj_a)
{
  p = p;
  obc->n[0] = 0;
  obc->n[1] = 0;
  obc->n[2] = 100;
  rotate_x(obj_a->xro, obj_a->yro, obj_a->zro, obc->n);
}

void		calc_n_for_para(t_obj *obc, double *p, t_sph *obj_a)
{
  p = p;
  obc->n[0] = 0;
  obc->n[1] = 0;
  obc->n[2] = 100;
  rotate_x(obj_a->xro, obj_a->yro, obj_a->zro, obc->n);
}

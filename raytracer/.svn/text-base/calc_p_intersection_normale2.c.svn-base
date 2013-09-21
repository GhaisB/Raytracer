/*
** calc_p_intersection_normale2.c for rt in /home/dell-a_f/rt/raytracer
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Fri Jun  1 13:09:47 2012 florian dell'aiera
** Last update Sat Jun  2 10:25:43 2012 guillaume duez
*/

#include "../rt.h"

#define RA(x) ((x * M_PI) / 180)
#define X2(x) (x * x)
#define X3(x) (x * x * x)

void		calc_n_for_disque(t_obj *obc, double *p, t_sph *obj_a)
{
  p = p;
  obj_a = obj_a;
  obc->n[0] = 0;
  obc->n[1] = 0;
  obc->n[2] = 100;
}

void		calc_n_for_hyperbo(t_obj *obc, double *p, t_sph *obj_a)
{
  obj_a = obj_a;
  obc->n[0] = p[0];
  obc->n[1] = p[1];
  obc->n[2] = -2 * p[2];
}

void		calc_n_for_plan(t_obj *obc, double *p, t_sph *obj_a)
{
  p = p;
  obc->n[0] = 0;
  obc->n[1] = 0;
  obc->n[2] = 100;
  rotate_x(obj_a->xro, obj_a->yro, obj_a->zro, obc->n);
}

void		calc_n_for_sphere(t_obj *obc, double *p, t_sph *obj_a)
{
  p = p;
  obj_a = obj_a;
  obc->n[0] = p[0];
  obc->n[1] = p[1];
  obc->n[2] = p[2];
}

void		calc_n_for_cube(t_obj *obc, double *p, t_sph *obj_a)
{
  rotate_x(obj_a->xro, obj_a->yro, obj_a->zro, obc->p);
  obc->n[0] = X3(p[0]) - (10 * p[0]);
  obc->n[1] = X3(p[1]) - (10 * p[1]);
  obc->n[2] = X3(p[2]) - (10 * p[2]);
}

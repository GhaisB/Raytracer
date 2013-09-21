/*
** cube_hole_shadow.c for rt in /home/dell-a_f/rt/raytracer
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Fri Jun  1 12:57:38 2012 florian dell'aiera
** Last update Sun Jun  3 12:55:30 2012 guillaume boell
*/

#include "../rt.h"

#define X2(x) (x * x)
#define X3(x) (x * x * x)
#define X4(x) (x * x * x * x)

int		cube_hole_shadow(t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	d0;
  double	d1;
  double	d2;
  double	p0;
  double	p1;
  double	p2;

  modif_p_l(obc, tmp, obj_a);
  d0 = tmp->l_v[0];
  d1 = tmp->l_v[1];
  d2 = tmp->l_v[2];
  p0 = tmp->l_c[0];
  p1 = tmp->l_c[1];
  p2 = tmp->l_c[2];
  tmp->l_v[0] = X4(d0) + X4(d1) + X4(d2);
  tmp->l_v[1] = 4 * ((X3(d0) * p0) + (X3(d1) * p1) + (X3(d2) * p2));
  tmp->l_v[2] = 6 * (X2(d0) * X2(p0) + (X2(d1) * X2(p1)) + (X2(d2) * X2(p2)));
  tmp->l_v[2] = tmp->l_v[2] - (5 * (X2(d0) + X2(d1) + X2(d2)));
  tmp->l_c[0] = 4 * ((X3(p0) * d0) + (X3(p1) * d1) + (X3(p2) * d2));
  tmp->l_c[0] = tmp->l_c[0] - (10 * ((d0 * p0) + (d1 * p1) + (d2 * p2)));
  tmp->l_c[1] = X4(p0) + X4(p1) + X4(p2);
  tmp->l_c[1] = tmp->l_c[1] - (5 * (X2(p0) + X2(p1) + X2(p2))) + 11.8;
  return (ferari(tmp, obc));
}

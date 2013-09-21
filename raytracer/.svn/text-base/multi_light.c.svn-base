/*
** multi_light.c for header in /home/duez_a//rt/raytracer
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Fri Jun  1 16:53:28 2012 guillaume duez
** Last update Sat Jun  2 10:37:37 2012 guillaume duez
*/

#include "../rt.h"

#define X2(x) (x * x)

void		calc_cos_x(t_obj *obc, t_tmp *tmp)
{
  double	n;
  double	l;

  obc->cos_x = (obc->n[0] * tmp->l_v[0]) + (obc->n[1] * tmp->l_v[1])
    + (obc->n[2] * tmp->l_v[2]);
  n = sqrt(X2(obc->n[0]) + X2(obc->n[1]) + X2(obc->n[2]));
  l = sqrt(X2(tmp->l_v[0]) + X2(tmp->l_v[1]) + X2(tmp->l_v[2]));
  obc->cos_x = (obc->cos_x / (n * l));
}

void		stock_l(t_obj *obc, t_tmp *tmp)
{
  obc->n[0] = tmp->l_v[0];
  obc->n[1] = tmp->l_v[1];
  obc->n[2] = tmp->l_v[2];
}

void		return_temp(t_obj *obc, double *n2, int *poid)
{
  obc->n[0] = n2[0];
  obc->n[1] = n2[1];
  obc->n[2] = n2[2];
  *poid = *poid + 1;
}

void		recup_l(t_sph *light, t_obj *obc, t_tmp *tmp)
{
  tmp->l_v[0] = (light->x) - obc->p[0];
  tmp->l_v[1] = (light->y) - obc->p[1];
  tmp->l_v[2] = (light->z) - obc->p[2];
}

double		calc_k_for_cone(double *k1, double b, double delta, double a)
{
  double	k2;

  *k1 = (- b - sqrt(delta)) / (2 * a);
  k2 = (- b + sqrt(delta)) / (2 * a);
  return (k2);
}

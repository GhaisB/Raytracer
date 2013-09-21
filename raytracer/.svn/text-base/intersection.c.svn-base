/*
** intersection.c for rt in /home/dell-a_f/rt/raytracer
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Fri Jun  1 11:35:59 2012 florian dell'aiera
** Last update Sat Jun  2 11:07:37 2012 guillaume duez
*/

#include	"../rt.h"

#define X2(x) (x * x)

int		inter_cyl(t_cod *cor, t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	k1;
  double	k2;

  modif_lX(cor, obj_a, tmp);
  a = X2(tmp->l_v[0]) + X2(tmp->l_v[1]);
  b = 2 * (tmp->l_c[0] * tmp->l_v[0] + tmp->l_c[1] * tmp->l_v[1]);
  c = X2(tmp->l_c[0]) + X2(tmp->l_c[1]) - X2(obj_a->r);
  delta = b * b - (4 * a * c);
  k1 = (- b - sqrt(delta)) / (2 * a);
  k2 = (- b + sqrt(delta)) / (2 * a);
  obc->xtmp = k1;
  obc->ytmp = k2;
  objet_limited(obj_a, obc, tmp, &delta);
  if (k1 < k2 && k1 > 0 && k1 < obc->coeff_k && delta >= 0)
    obc->coeff_k = k1;
  else if (k2 > 0 && k2 < obc->coeff_k && delta >= 0)
    obc->coeff_k = k2;
  else
    return (0);
  return (1);
}

int		inter_sphere(t_cod *cor, t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	k1;
  double	k2;

  modif_lX(cor, obj_a, tmp);
  a = X2(tmp->l_v[0]) + X2(tmp->l_v[1]) + X2(tmp->l_v[2]);
  b = 2 * (tmp->l_c[0] * tmp->l_v[0] + tmp->l_c[1] * tmp->l_v[1]
	   + tmp->l_c[2] * tmp->l_v[2]);
  c = X2(tmp->l_c[0]) + X2(tmp->l_c[1]) + X2(tmp->l_c[2]) - X2(obj_a->r);
  delta = X2(b) - 4 * a * c;
  k1 = (- b - sqrt(delta)) / (2 * a);
  k2 = (- b + sqrt(delta)) / (2 * a);
  obc->xtmp = k1;
  obc->ytmp = k2;
  objet_limited(obj_a, obc, tmp, &delta);
  if (k1 < k2 && k1 > 0 && k1 < obc->coeff_k && delta >= 0)
    obc->coeff_k = k1;
  else if (k2 > 0 && k2 < obc->coeff_k && delta >= 0)
    obc->coeff_k = k2;
  else
    return (0);
  return (1);
}

int		inter_para(t_cod *cor, t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	delta;

  modif_lX(cor, obj_a, tmp);
  delta = (- 1 * tmp->l_c[2]) / tmp->l_v[2];
  obc->xtmp = delta;
  obc->ytmp = delta;
  objet_limited(obj_a, obc, tmp, &delta);
  para(obj_a, obc, tmp, &delta);
  if (delta > 0 && delta < obc->coeff_k)
    {
      obc->coeff_k = delta;
      return (1);
    }
  else
    return (0);
}

int		inter_triangle(t_cod *cor, t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	delta;

  modif_lX(cor, obj_a, tmp);
  delta = (- 1 * tmp->l_c[2]) / tmp->l_v[2];
  obc->xtmp = delta;
  obc->ytmp = delta;
  objet_limited(obj_a, obc, tmp, &delta);
  triangle(obj_a, obc, tmp, &delta);
  if (delta > 0 && delta < obc->coeff_k)
    {
      obc->coeff_k = delta;
      return (1);
    }
  else
    return (0);
}

int		inter_plan(t_cod *cor, t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	delta;

  modif_lX(cor, obj_a, tmp);
  delta = (- 1 * tmp->l_c[2]) / tmp->l_v[2];
  obc->xtmp = delta;
  obc->ytmp = delta;
  objet_limited(obj_a, obc, tmp, &delta);
  if (delta > 0 && delta < obc->coeff_k)
    {
      obc->coeff_k = delta;
      return (1);
    }
  else
    return (0);
}

/*
** intersection.c for zd in /home/duez_a//rtv1/tp
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon Feb 27 18:24:35 2012 guillaume duez
** Last update Sat Jun  2 10:36:04 2012 guillaume duez
*/

#include "../rt.h"

#define X2(x) (x * x)

int		inter_hyperbo_sha(t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	k1;
  double	k2;

  modif_p_l(obc, tmp, obj_a);
  a = X2(tmp->l_v[0]) + X2(tmp->l_v[1]) - 2 * X2(tmp->l_v[2]);
  b = 2 * (tmp->l_c[0] * tmp->l_v[0] + tmp->l_c[1] *
	   tmp->l_v[1] - 2 * tmp->l_c[2] * tmp->l_v[2]);
  c = X2(tmp->l_c[0]) + X2(tmp->l_c[1]) - 2 * X2(tmp->l_c[2]) - 1000;
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

int		inter_para_sha(t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	k1;
  double	k2;

  modif_p_l(obc, tmp, obj_a);
  a = X2(tmp->l_v[0]) + X2(tmp->l_v[1]);
  b = 2 * (tmp->l_c[0] * tmp->l_v[0] + tmp->l_c[1] * tmp->l_v[1]) -
    (tan(obj_a->r) * 5) * tmp->l_v[2];
  c = X2(tmp->l_c[0]) + X2(tmp->l_c[1]) - tan(obj_a->r) * tmp->l_c[2];
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

int		inter_parale_sha(t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	delta;

  modif_p_l(obc, tmp, obj_a);
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

int		inter_triangle_sha(t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	delta;

  modif_p_l(obc, tmp, obj_a);
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

int		inter_con_sha(t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	k1;
  double	k2;

  modif_p_l(obc, tmp, obj_a);
  a = X2(tmp->l_v[0]) + X2(tmp->l_v[1])
    - (X2(tmp->l_v[2]) * X2(tan(obj_a->r)));
  b = 2 * (tmp->l_c[0] * tmp->l_v[0] + tmp->l_c[1] * tmp->l_v[1]
	   - (tmp->l_c[2] * tmp->l_v[2] * X2(tan(obj_a->r))));
  c = X2(tmp->l_c[0]) + X2(tmp->l_c[1])
    - (X2(tmp->l_c[2]) * X2(tan(obj_a->r)));
  delta = X2(b) - 4 * a * c;
  k2 = calc_k_for_cone(&k1, b, delta, a);
  stock_k(obc, k1, k2);
  objet_limited(obj_a, obc, tmp, &delta);
  if (k1 < k2 && k1 > 0 && k1 < obc->coeff_k && delta >= 0)
    obc->coeff_k = k1;
  else if (k2 > 0 && k2 < obc->coeff_k && delta >= 0)
    obc->coeff_k = k2;
  else
    return (0);
  return (1);
}

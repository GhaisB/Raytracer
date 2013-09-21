/*
** intersection2.c for header in /home/duez_a//rt
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Sat Jun  2 10:32:55 2012 guillaume duez
** Last update Sat Jun  2 11:07:13 2012 guillaume duez
*/

#include	"../rt.h"

#define X2(x) (x * x)

int		inter_hyperbo(t_cod *cor, t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	k1;
  double	k2;

  modif_lX(cor, obj_a, tmp);
  a = X2(tmp->l_v[0]) + X2(tmp->l_v[1]) - 2 * X2(tmp->l_v[2]);
  b = 2 * (tmp->l_c[0] * tmp->l_v[0] + tmp->l_c[1] * tmp->l_v[1] - 2 *
	   tmp->l_c[2] * tmp->l_v[2]);
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

int		inter_selle(t_cod *cor, t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  cor = cor;
  tmp = tmp;
  obc = obc;
  obj_a = obj_a;
  return (0);
}

int		inter_parabo(t_cod *cor, t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	k1;
  double	k2;

  modif_lX(cor, obj_a, tmp);
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

int		inter_con(t_cod *cor, t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	k1;
  double	k2;

  modif_lX(cor, obj_a, tmp);
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

int		inter_disq(t_cod *cor, t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	delta;

  modif_lX(cor, obj_a, tmp);
  delta = (- 1 * tmp->l_c[2]) / tmp->l_v[2];
  obc->p[0] = tmp->l_c[0] + (delta * tmp->l_v[0]);
  obc->p[1] = tmp->l_c[1] + (delta * tmp->l_v[1]);
  obc->p[2] = tmp->l_c[2] + (delta * tmp->l_v[2]);
  obc->xtmp = delta;
  obc->ytmp = delta;
  objet_limited(obj_a, obc, tmp, &delta);
  if (X2(obc->p[0]) + X2(obc->p[1]) < X2(obj_a->r) &&
      delta > 0 && delta < obc->coeff_k)
    {
      obc->coeff_k = delta;
      return (1);
    }
  return (0);
}

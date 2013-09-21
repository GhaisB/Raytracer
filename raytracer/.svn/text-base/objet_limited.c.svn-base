/*
** objet_limited.c for rt in /home/dell-a_f/rt/raytracer
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Fri Jun  1 11:31:10 2012 florian dell'aiera
** Last update Sun Jun  3 20:01:01 2012 antoine knockaert
*/

#include "../rt.h"

void			objet_limited(t_sph *obj_a, t_obj *obc, t_tmp *tmp,
				      double *delta)
{
  obj_a = obj_a;
  if (obc->xtmp < obc->ytmp && obc->xtmp > 0 && obc->xtmp < obc->coeff_k)
    obc->ztmp = obc->xtmp;
  else if (obc->ytmp > 0 && obc->ytmp < obc->coeff_k)
    obc->ztmp = obc->ytmp;
  else
    {
      *delta = -1;
      return ;
    }
  obc->xtmp = tmp->l_c[0] + (obc->ztmp * tmp->l_v[0]);
  obc->ytmp = tmp->l_c[1] + (obc->ztmp * tmp->l_v[1]);
  obc->ztmp = tmp->l_c[2] + (obc->ztmp * tmp->l_v[2]);
  if ((obj_a->limit_max[0] != -1 && obc->xtmp > obj_a->limit_max[0])
      || (obj_a->limit_max[1] != -1 && obc->ytmp > obj_a->limit_max[1]))
    *delta = -1;
  if (obj_a->limit_max[2] != -1 && obc->ztmp > obj_a->limit_max[2])
    *delta = -1;
  if (obj_a->limit_min[0] != -1 && obc->xtmp < obj_a->limit_min[0])
    *delta = -1;
  if (obj_a->limit_min[1] != -1 && obc->ytmp < obj_a->limit_min[1])
    *delta = -1;
  if (obj_a->limit_min[2] != -1 && obc->ztmp < obj_a->limit_min[2])
    *delta = -1;
}

static inline void	init_para(double *a, double *b, double *c)
{
  a[0] = -100;
  a[1] = 60;
  b[0] = 45;
  b[1] = -20;
  c[0] = 50;
  c[1] = 40;
}

void			para(t_sph *obj_a, t_obj *obc, t_tmp *tmp, double *delta)
{
  double		k1;
  double		k2;
  double		v1[2];
  double		a[2];
  double		b[2];
  double		c[2];
  double		v2[2];

  obj_a = obj_a;
  obc->ytmp = tmp->l_c[0] + (*delta * tmp->l_v[0]);
  obc->ztmp = tmp->l_c[1] + (*delta * tmp->l_v[1]);
  init_para(a, b, c);
  v2[0] = b[0] - a[0];
  v2[1] = b[1] - a[1];
  v1[0] = c[0] - a[0];
  v1[1] = c[1] - a[1];
  k2 = ((v1[0] * obc->ztmp) - (obc->ytmp * v1[1])) / ((v2[1] * v1[0]) -
						      (v1[1] * v2[0]));
  k1 = (obc->ytmp - (k2 * v2[0])) / v1[0];
  if ((k1 < 0 || k1 > 1) || (k2 < 0 || k2 > 1))
    *delta = -1;
}

static inline void	init_a_b(double *a, double *b, double *c)
{
  a[0] = -100;
  a[1] = 60;
  b[0] = 45;
  b[1] = -20;
  c[0] = 50;
  c[1] = 40;
}

void			triangle(t_sph *obj_a, t_obj *obc, t_tmp *tmp, double *delta)
{
  double		k1;
  double		k2;
  double		v1[2];
  double		a[2];
  double		b[2];
  double		c[2];
  double		v2[2];

  obj_a = obj_a;
  obc->ytmp = tmp->l_c[0] + (*delta * tmp->l_v[0]);
  obc->ztmp = tmp->l_c[1] + (*delta * tmp->l_v[1]);
  init_a_b(a, b, c);
  v2[0] = b[0] - a[0];
  v2[1] = b[1] - a[1];
  v1[0] = c[0] - a[0];
  v1[1] = c[1] - a[1];
  k2 = ((v1[0] * obc->ztmp) - (obc->ytmp * v1[1])) /
    ((v2[1] * v1[0]) - (v1[1] * v2[0]));
  k1 = (obc->ytmp - (k2 * v2[0])) / v1[0];
  if ((k1 < 0 || k1 > 1) || (k2 < 0 || k2 > 1) || (k1 + k2 > 1))
    *delta = -1;
}

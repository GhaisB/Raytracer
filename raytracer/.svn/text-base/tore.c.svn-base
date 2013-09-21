/*
** tore.c for header in /home/duez_a//rt
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Sat Jun  2 10:19:44 2012 guillaume duez
** Last update Sun Jun  3 13:09:24 2012 guillaume boell
*/

#include "../rt.h"

#define X2(x) (x * x)
#define X3(x) (x * x * x)
#define X4(x) (x * x * x * x)

inline void	init_p(t_tmp *tmp, double *p0, double *p1, double *p2)
{
  *p0 = tmp->l_c[0];
  *p1 = tmp->l_c[1];
  *p2 = tmp->l_c[2];
}

inline void	init_d(t_tmp *tmp, double *d0, double *d1, double *d2)
{
  *d0 = tmp->l_v[0];
  *d1 = tmp->l_v[1];
  *d2 = tmp->l_v[2];
}

inline void	init_R_r(t_sph *obj_a, double *R, double *r)
{
  *R = obj_a->r;
  *r = obj_a->r / 3;
}

int		inter_tore(t_cod *cor, t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	d0;
  double	d1;
  double	d2;
  double	p0;
  double	p1;
  double	p2;
  double	R;
  double	r;
  double	tmp2[4];

  modif_lX(cor, obj_a, tmp);
  init_d(tmp, &d0, &d1, &d2);
  init_R_r(obj_a, &R, &r);
  init_p(tmp, &p0, &p1, &p2);
  tmp2[0] = X2(d0) + X2(d1) + X2(d2);
  tmp2[1] = d0 * p0 + d1 * p1 + d2 * p2;
  tmp2[2] = X2(p0) + X2(p1) + X2(p2) + X2(R) - X2(r);
  tmp->l_v[0] = X2(tmp2[0]);
  tmp->l_v[1] = 4 * tmp2[0] * tmp2[1];
  tmp->l_v[2] = 2 * tmp2[0] * tmp2[2] + (4. * X2(tmp2[1])) -
    (4. * X2(R) * (X2(d0) + X2(d1)));
  tmp->l_c[0] = 4 * tmp2[1] * tmp2[2] - (8. * X2(R) * ((d0 * p0) + (d1 * p1)));
  tmp->l_c[1] = X2(tmp2[2]) - (4. * X2(R) * (X2(p0) + X2(p1)));
  return (ferari(tmp, obc));
}

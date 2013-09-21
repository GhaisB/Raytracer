/*
** ferari.c for header in /home/duez_a//rt
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Sat Jun  2 10:33:44 2012 guillaume duez
** Last update Sun Jun  3 12:42:53 2012 guillaume boell
*/

#include "../rt.h"

#define X2(x) (x * x)
#define X3(x) (x * x * x)
#define X4(x) (x * x * x * x)

static double		final_x(double x1, double x2, double x3, double x4)
{
  if (x1 > 0 && ((x1 <= x3 || x3 <= 0) || x3 != x3) &&
      ((x1 <= x2 || x2 <= 0) || x2 != x2)
      && ((x1 <= x4 || x4 <= 0) || x4 != x4))
    return (x1);
  if (x2 > 0 && ((x2 <= x1 || x1 <= 0) || x1 != x1) &&
      ((x2 <= x3 || x3 <= 0) || x3 != x3)
      && ((x2 <= x4 || x4 <= 0) || x4 != x4))
    return (x2);
  if (x3 > 0 && ((x3 <= x1 || x1 <= 0) || x1 != x1) &&
      ((x3 <= x2 || x2 <= 0) || x2 != x2)
      && ((x3 <= x4 || x4 <= 0) || x4 != x4))
    return (x3);
  if (x4 > 0 && ((x4 <= x1 || x1 <= 0) || x1 != x1) &&
      ((x4 <= x2 || x2 <= 0) || x2 != x2) &&
      ((x4 <= x3 || x3 <= 0) || x3 != x3))
    return (x4);
  return (-1);
}

static double		calc_delta(double p, t_obj *obc, double q, double r)
{
  double		a;
  double		b;
  double		x1;
  double		x2;
  double		x3;
  double		x4;
  double		delta[2];

  x1 = x2 = x3 = x4 = 0;
  a = sqrt((2 * obc->xtmp) - p);
  if (2 * obc->xtmp - p != 0 && a == a)
    b = - q / (2. * a);
  else
    b = sqrt(X2(obc->xtmp) - r);
  if ((delta[0] = X2(a) - (4 * (obc->xtmp + b))) > 0)
    {
      x1 = (-a + sqrt(delta[0])) / 2. + obc->ztmp;
      x2 = (-a - sqrt(delta[0])) / 2. + obc->ztmp;
    }
  if ((delta[1] = X2(a) - (4 * (obc->xtmp - b))) > 0)
    {
      x3 = (a + sqrt(delta[1])) / 2. + obc->ztmp;
      x4 = (a - sqrt(delta[1])) / 2. + obc->ztmp;
    }
  return (final_x(x1, x2, x3, x4));
}

static inline void	init_abc(t_tmp *tmp, double *a, double *b, double *c)
{
  *a = tmp->l_v[0];
  *b = tmp->l_v[1];
  *c = tmp->l_v[2];
}

static inline void	init_dey(t_tmp *tmp, double *d, double *e, double *y)
{
  *d = tmp->l_c[0];
  *e = tmp->l_c[1];
  *y = - 1;
}

int			ferari(t_tmp *tmp, t_obj *obc)
{
  double		p;
  double		r;
  double		q;
  double		y;
  double		a;
  double		b;
  double		c;
  double		d;
  double		e;

  init_abc(tmp, &a, &b, &c);
  init_dey(tmp, &d, &e, &y);
  obc->ztmp = - b / (4. * a);
  p = (- 3. * X2(b)) / (8. * X2(a)) + (c / a);
  q = X3(b * 0.5) / X3(a) - ((0.5 * b * c) / X2(a)) + (d / a);
  r = - 3. * X4((b * 0.25) / a) + (c * (X2((b * 0.25)) / X3(a)))
    - ((0.25 * b * d) / X2(a)) + (e / a);
  cardran(obc, - 4 * p, - 8 * r, (4 * r * p) - X2(q));
  y = calc_delta(p, obc, q, r);
  if (y >= 0 && y < obc->coeff_k)
    obc->coeff_k = y;
  else
    return (0);
  return (1);
}

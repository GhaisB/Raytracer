/*
** cardran.c for header in /home/duez_a//rtv1/tp/save/lololo
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu Apr 26 11:47:34 2012 guillaume duez
** Last update Sun Jun  3 12:46:08 2012 guillaume boell
*/

#include "../rt.h"

#define X2(x) (x * x)
#define X3(x) (x * x * x)

int		delta_neg(double p, double q, t_obj *obc, double z)
{
  double	x1;
  double	x2;
  double	x3;

  x1 = 2. * sqrt(-p / 3) * cos(1. / 3. * acos((-q / 2.) * sqrt( 27. / X3(-p))))
    - z;
  x2 = 2. * sqrt(-p / 3) * cos(1. / 3. * acos((-q / 2.) * sqrt( 27. / X3(-p)))
			       + ((2 * M_PI) / 3.)) - z;
  x3 = 2. * sqrt(-p / 3) * cos(1. / 3. * acos((-q / 2.) * sqrt( 27. / X3(-p)))
			       + ((4 * M_PI) / 3.)) - z;
  if (x1 > 0 && ((x1 >= x3  || x3 != x3)) &&
      ((x1 >= x2 || x2 != x2)))
    obc->xtmp = x1;
  else if (x2 > 0 && ((x2 >= x1 || x1 != x1)) &&
	   ((x2 >= x3 || x3 != x3)))
    obc->xtmp = x2;
  else if (x3 > 0 && ((x3 >= x1 || x1 != x1)) &&
	   ((x3 >= x2 || x2 != x2)))
    obc->xtmp = x3;
  else
    obc->xtmp = x1;
  return (1);
}

static int	find_right_x(double p, double q, t_obj *obc, double z)
{
  double	k1;
  double	k2;
  double	delta;

  delta = X2(q) + ((4. / 27.) * X3(p));
  if (delta > 0)
    {
      obc->xtmp = cbrt((-q + sqrt(delta)) / 2.)
	+ cbrt((-q - sqrt(delta)) / 2.) - z;
    }
  else if (delta == 0)
    {
      k1 = (3 * q) / p - z;
      k2 = (-3 * q) / (2 * p) - z;
      if ((k1 < k2 || k2 < 0) && k1 > 0)
	obc->xtmp = k1;
      else if (k2 > 0 && (k2 <= k1 || k1 < 0))
	obc->xtmp = k2;
      else
	obc->xtmp = k1;
    }
  else if (delta < 0)
    return (delta_neg(p, q, obc, z));
  return (1);
}

int		cardran(t_obj *obc, double b, double c, double d)
{
  double	p;
  double	q;
  double	a;
  double	z;

  a = 8;
  z = b / (3 * a);
  p = - X2(b) / (3. * X2(a)) + (c / a);
  q = b / (27. * a) * (((2. * X2(b)) / X2(a)) - ((9. * c) / a)) + (d / a);
  return (find_right_x(p, q, obc, z));
}

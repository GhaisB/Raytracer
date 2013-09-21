/*
** vect_work.c for pt in /home/knocka_a/repositories/rt/pathtracer
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Jun  1 15:58:04 2012 antoine knockaert
** Last update Sun Jun  3 12:36:09 2012 guillaume boell
*/

#include "../rt.h"

inline void		normalize(double *v)
{
  double		n;

  n = sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2));
  v[0] = v[0] / n;
  v[1] = v[1] / n;
  v[2] = v[2] / n;
}

inline void		mult_vect_vect(double *t1, double *t2)
{
  t1[0] = t1[0] * t2[0];
  t1[1] = t1[1] * t2[1];
  t1[2] = t1[2] * t2[2];
}

inline void		mult_vect_cons(double *t1, double cons)
{
  t1[0] = t1[0] * cons;
  t1[1] = t1[1] * cons;
  t1[2] = t1[2] * cons;
}

inline void		rand_vec(double **t, double demi_a)
{
  double		a;

  a = demi_a;
  demi_a /= 2;
  rotate_x((drand48() * a) - demi_a, (drand48() * a) -
	   demi_a, (drand48() * a) - demi_a, *t);
}

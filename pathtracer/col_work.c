/*
** col_work.c for pt in /home/knocka_a/repositories/rt/pathtracer
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Jun  1 15:57:14 2012 antoine knockaert
** Last update Sun Jun  3 12:19:47 2012 guillaume boell
*/

#include "../rt.h"

#define RA(x) ((x * M_PI) / 180)
#define AR(x) ((x / M_PI) * 180)

inline void		add_col(double *c, int *s, double factor)
{
  unsigned char		*ss;

  ss = (unsigned char *)s;
  c[0] += (ss[0] / factor);
  c[1] += (ss[1] / factor);
  c[2] += (ss[2] / factor);
}

inline void		add_col_char(double *c, double col)
{
  c[0] += col;
  c[1] += col;
  c[2] += col;
}

inline void		mult_col(unsigned char *c, double *f, double mult,
				 unsigned char *lum_col)
{
  f[0] += (double)c[0] * (mult * lum_col[0] / 255);
  f[1] += (double)c[1] * (mult * lum_col[1] / 255);
  f[2] += (double)c[2] * (mult * lum_col[2] / 255);
}

/*
** light.c for pt in /home/knocka_a/repositories/rt/pathtracer
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Jun  1 15:57:41 2012 antoine knockaert
** Last update Sun Jun  3 12:15:49 2012 guillaume boell
*/

#include "../rt.h"

#define RA(x) ((x * M_PI) / 180)
#define AR(x) ((x / M_PI) * 180)

inline void		init_light(t_cod *cor, double *old_lx, double *old_n)
{
  old_lx[0] = cor->l_x[0];
  old_lx[1] = cor->l_x[1];
  old_lx[2] = cor->l_x[2];
  old_n[0] = cor->n[0];
  old_n[1] = cor->n[1];
  old_n[2] = cor->n[2];
}

inline void		de_init_light(t_cod *cor, double *old_lx, double *old_n)
{
  cor->n[0] = old_n[0];
  cor->n[1] = old_n[1];
  cor->n[2] = old_n[2];
  cor->l_x[0] = old_lx[0];
  cor->l_x[1] = old_lx[1];
  cor->l_x[2] = old_lx[2];
}

inline void		set_ray(t_cod *cor, t_sph *obj_a, t_obj *obc)
{
  obc->bounce += 80;
  cor->l_x[0] = (obj_a->x - obc->p[0]);
  cor->l_x[1] = (obj_a->y - obc->p[1]);
  cor->l_x[2] = (obj_a->z - obc->p[2]);
  cor->l_o[0] = obc->p[0];
  cor->l_o[1] = obc->p[1];
  cor->l_o[2] = obc->p[2];
  obc->coeff_k = 99999999;
}

inline void		brdf(t_cod *cor, t_sph *obj_hit, t_obj *obc, double omeg)
{
  mult_col((unsigned char *)&obj_hit->color,
	   cor->ray_col, fabs(
			     obc->bri / 100 *
			     (
					  (cor->n[0] * cor->l_x[0]) +
					  (cor->n[1] * cor->l_x[1]) +
					  (cor->n[2] * cor->l_x[2])
			      ) * omeg) * M_1_PI,
	   (unsigned char *)&obc->color);
}

inline void		set_r_d(double *r, double *d, t_obj *obc, t_sph *obj_a)
{
  *r = obj_a->r;
  *d = sqrt(pow((obj_a->x - obc->p[0]), 2) + pow((obj_a->y - obc->p[1]), 2)
	   + pow((obj_a->z - obc->p[2]), 2));
}

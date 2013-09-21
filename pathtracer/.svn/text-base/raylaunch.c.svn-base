/*
** raylaunch.c for pt in /home/knocka_a/repositories/rt/pathtracer
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Jun  1 15:56:50 2012 antoine knockaert
** Last update Sun Jun  3 12:35:14 2012 guillaume boell
*/

#include "../rt.h"

#define RA(x) ((x * M_PI) / 180)
#define AR(x) ((x / M_PI) * 180)

static inline void	diffus_bounce(t_cod *cor)
{
  cor->l_x[0] = cor->n[0] * 1000;
  cor->l_x[1] = cor->n[1] * 1000;
  cor->l_x[2] = cor->n[2] * 1000;
  rand_vec(&(cor->l_x), (double)90);
}

static inline void	spec_bounce(t_cod *cor, t_obj *obc)
{
  float			f;

  normalize(cor->l_x);
  normalize(cor->n);
  f = -2 * ((cor->n[0] * cor->l_x[0]) +
	    (cor->n[1] * cor->l_x[1]) + (cor->n[2] * cor->l_x[2]));
  cor->l_x[0] = ((cor->l_x[0]) + (f * cor->n[0])) * 100000;
  cor->l_x[1] = ((cor->l_x[1]) + (f * cor->n[1])) * 100000;
  cor->l_x[2] = ((cor->l_x[2]) + (f * cor->n[2])) * 100000;
  if (obc->nt->ref_flou)
    rand_vec(&(cor->l_x), obc->nt->ref_flou);
}

static inline void	do_intersection(t_tmp *tmp, t_obj *obc, t_cod *cor,
					t_sph *obj_a)
{
  while (obj_a != NULL)
    {
      if (obj_a->type >= 0 && obj_a->type < 20 && obc->inter[obj_a->type]
	  && obc->inter[obj_a->type](cor, tmp, obc, obj_a) == 1)
	obc->nt = obj_a;
      obj_a = obj_a->nt;
    }
}

double			*calc_pt(t_tmp *tmp, t_obj *obc, t_cod *cor, t_sph *obj_a)
{
  t_sph			*tm;

  tm = obj_a;
  obc->nt = NULL;
  if (!obc->bounce)
    {
      rotate_x(cor->l_o[3], cor->l_o[4], cor->l_o[5], cor->l_x);
      cor->ray_col[0] = cor->ray_col[1] = cor->ray_col[2] = 0;
      obc->color = 0;
    }
  do_intersection(tmp, obc, cor, obj_a);
  calc_p_n_color(cor, obc, obc->nt, tmp);
  if (obc->bounce <= 4 && obc->nt)
    {
      obc->bounce = obc->bounce + 1;
      get_light(tmp, *obc, *cor, tm);
      if (obc->nt->bri || obc->nt->mat_type == 1)
	diffus_bounce(cor);
      else if (obc->mat_type == 2)
	spec_bounce(cor, obc);
      calc_pt(tmp, obc, cor, tm);
    }
  return (cor->ray_col);
}

int			calc_k(t_tmp *tmp, t_obj *obc, t_cod *cor, t_sph *obj_a)
{
  obc->nt = NULL;
  if (!obc->bounce)
    {
      rotate_x(cor->l_o[3], cor->l_o[4], cor->l_o[5], cor->l_x);
      cor->ray_col[0] = cor->ray_col[1] = cor->ray_col[2] = 0;
      obc->color = 0;
    }
  while (obj_a != NULL)
    {
      if (obj_a->type >= 0 && obj_a->type < 20 && obc->inter[obj_a->type]
	  && obc->inter[obj_a->type](cor, tmp, obc, obj_a) == 1)
	obc->nt = obj_a;
      obj_a = obj_a->nt;
    }
   calc_p_n_color(cor, obc, obc->nt, tmp);
   return ((int)(obc->coeff_k * 50));
}

/*
** calc_p_intersection_normale.c for rt in /home/dell-a_f/rt/raytracer
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Fri Jun  1 13:09:14 2012 florian dell'aiera
** Last update Sun Jun  3 12:44:51 2012 guillaume boell
*/

#include "../rt.h"

#define RA(x) ((x * M_PI) / 180)
#define X2(x) (x * x)
#define X3(x) (x * x * x)

inline double	*rot_tran_inverse(t_sph *obj_a, double *p)
{
  obj_a->xro = obj_a->xro * -1;
  obj_a->yro = obj_a->yro * -1;
  obj_a->zro = obj_a->zro * -1;
  rotate_x(obj_a->xro, obj_a->yro, obj_a->zro, p);
  obj_a->xro = obj_a->xro * -1;
  obj_a->yro = obj_a->yro * -1;
  obj_a->zro = obj_a->zro * -1;
  p[0] = p[0] + (obj_a->x * 1);
  p[1] = p[1] + (obj_a->y * 1);
  p[2] = p[2] + (obj_a->z * 1);
  return (p);
}

static void	func_damier(t_obj *obc, t_sph *obj_a)
{
  if ((int) abs(obc->p[0] - 9000) % 100 < 50
      && (int) abs(obc->p[1] - 9000) % 100 < 50)
    {
	obc->color = obj_a->damier_color[0];
    }
  if ((int) abs(obc->p[0] - 9000) % 100 > 50
      && (int) abs(obc->p[1] - 9000) % 100 > 50)
    {
	obc->color = obj_a->damier_color[1];
    }
}

static void	pertub_normal(t_obj *obc, t_sph *obj_a)
{
  double	n;

  n = sqrt(X2(obc->n[0]) + X2(obc->n[1]) + X2(obc->n[2]));
  if (obj_a->perturb[0] != -1)
    obc->n[0] = obc->n[0] + (cos(obc->p[0]) / 10.) * (n / 10.)
      * obj_a->perturb[0];
  if (obj_a->perturb[1] != -1)
    obc->n[1] = obc->n[1] + (cos(obc->p[1]) / 10.) * (n / 10.)
      * obj_a->perturb[1];
  if (obj_a->perturb[2] != -1)
    obc->n[2] = obc->n[2] + (cos(obc->p[2]) / 10.) * (n / 10.)
      * obj_a->perturb[2];
}

void		calc_p_n_color(t_cod *cor, t_obj *obc, t_sph *obj_a, t_tmp *tmp)
{
  if (obj_a != NULL)
    {
      obc->bri = obj_a->bri;
      if (obc->bounce < 78)
	{
	  obc->mat_type = obj_a->mat_type;
	  obc->color = obj_a->color;
	  modif_lX(cor, obj_a, tmp);
	  obc->p[0] = tmp->l_c[0] + 0.9999 * (obc->coeff_k * tmp->l_v[0]);
	  obc->p[1] = tmp->l_c[1] + 0.9999 * (obc->coeff_k * tmp->l_v[1]);
	  obc->p[2] = tmp->l_c[2] + 0.9999 * (obc->coeff_k * tmp->l_v[2]);
	  if (obj_a->type >= 0 && obj_a->type < 20 && obc->normale[obj_a->type])
	    obc->normale[obj_a->type](obc, obc->p, obj_a);
	  if (obj_a->damier == 1)
	    func_damier(obc, obj_a);
	  cor->n = obc->n;
	  obc->p = rot_tran_inverse(obj_a, obc->p);
	  if (obj_a->perturb[0] != -1 || obj_a->perturb[1] != -1
	      || obj_a->perturb[2] != -1)
	    pertub_normal(obc, obj_a);
	}
    }
}

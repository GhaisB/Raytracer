/*
** cube.c for header in /home/duez_a//rt/raytracer
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Fri May 11 21:06:01 2012 guillaume duez
** Last update Sun Jun  3 12:43:41 2012 guillaume boell
*/

#include "../rt.h"

static void	unbuff_obj(t_sph *obj_a, int a)
{
  if (a >= 1)
    obj_a->yro = obj_a->yro - 90;
  if (a >= 2)
    obj_a->x = obj_a->x - (2 * obj_a->r);
  if (a >= 3)
    {
      obj_a->x = obj_a->x + (2 * obj_a->r);
      obj_a->z = obj_a->z - (2 * obj_a->r);
      obj_a->yro = obj_a->yro + 90;
    }
  if (a >= 4)
    {
      obj_a->y = obj_a->y - (2 * obj_a->r);
      obj_a->xro = obj_a->xro - 90;
    }
  if (a >= 5)
    {
      obj_a->y = obj_a->y  + (2 * obj_a->r);
    }
}

static void	modif_obj(t_sph *obj_a, int a)
{
  if (a == 0)
    obj_a->yro = obj_a->yro + 90;
  if (a == 1)
    obj_a->x = obj_a->x +  (2 * obj_a->r);
  if (a == 2)
    {
      obj_a->x = obj_a->x - (2 * obj_a->r);
      obj_a->z = obj_a->z + (2 * obj_a->r);
      obj_a->yro = obj_a->yro - 90;
    }
  if (a == 3)
    {
      obj_a->y = obj_a->y + (2 * obj_a->r);
      obj_a->xro = obj_a->xro + 90;
      if (a == 4)
	{
	  obj_a->y = obj_a->y  - (2 * obj_a->r);
	}
    }
}

static void	init_cube(int *a, int *check)
{
  *a = 0;
  *check = 0;
}

int		inter_cube(t_cod *cor, t_tmp *tmp, t_obj *obc, t_sph *obj_a)
{
  double	delta;
  int		a;
  int		check;

  init_cube(&a, &check);
  while (a != 6)
    {
      modif_lX(cor, obj_a, tmp);
      delta = (- 1 * tmp->l_c[2]) / tmp->l_v[2];
      obc->p[0] = tmp->l_c[0] + (delta * tmp->l_v[0]);
      obc->p[1] = tmp->l_c[1] + (delta * tmp->l_v[1]);
      obc->p[2] = tmp->l_c[2] + (delta * tmp->l_v[2]);
      if (obc->p[0] < (obj_a->r * 2) && obc->p[0] > 0 &&
	  obc->p[1] < (obj_a->r * 2) &&
	  obc->p[1] > 0 && delta < obc->coeff_k && delta > 0)
	{
	  obc->coeff_k = delta;
	  calc_n_for_plan(obc, obc->p, obj_a);
	  check = 1;
	}
      modif_obj(obj_a, a);
      a++;
    }
  unbuff_obj(obj_a, a);
  return (check);
}

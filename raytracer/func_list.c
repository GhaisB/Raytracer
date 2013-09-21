/*
** func_list.c for rt in /home/dell-a_f/rt/raytracer
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Fri Jun  1 11:45:49 2012 florian dell'aiera
** Last update Sun Jun  3 20:01:31 2012 antoine knockaert
*/

#include "../rt.h"

t_sph		*ad_to_beg(t_sph *sph, double *cod, double *rot_ra,
			   int *color_type)
{
  t_sph		*elem;

  elem = xmalloc(sizeof(t_sph));
  elem->x = cod[0];
  elem->y = cod[1];
  elem->z = cod[2];
  elem->xro = rot_ra[0];
  elem->yro = rot_ra[1];
  elem->zro = rot_ra[2];
  elem->r = rot_ra[3];
  elem->type = color_type[1];
  elem->bri = cod[3];
  elem->nt = sph;
  elem->color = color_type[0];
  free(cod);
  free(rot_ra);
  return (elem);
}

double		*rot_ra(double xro, double yro, double zro, double rayon)
{
  double	*list;

  list = xmalloc(4 * sizeof(double));
  list[0] = xro * - 1;
  list[1] = yro * - 1;
  list[2] = zro * - 1;
  list[3] = rayon;
  return (list);
}

double		*l_cod(double x, double y, double z, double bri)
{
  double	*list;

  list = xmalloc(4 * sizeof(double));
  list[0] = x;
  list[1] = y;
  list[2] = z;
  list[3] = bri;
  return (list);
}

int		*func_color_type(int color, int type)
{
  int		*list;

  list = xmalloc(2 * sizeof(int));
  list[0] = color;
  list[1] = type;
  return (list);
}

t_sph		*create_list_for_sph(t_sph *obj_a)
{
  obj_a = ad_to_beg(obj_a, l_cod(0, 0, 5, 0.4), rot_ra(0, 0, 0, 0),
                    func_color_type(0xf05d7b, 2));
  obj_a = ad_to_beg(obj_a, l_cod(150, 100, 80, 0.08), rot_ra(90, 0, 90, 90),
                    func_color_type(0xFF00FF, 9));
  obj_a = ad_to_beg(obj_a, l_cod(-100, 200, 40, 0.001), rot_ra(0, 0, 0, 0.8),
  		    func_color_type(0xf7f50d, 8));
  obj_a = ad_to_beg(obj_a, l_cod(700, 0, 0, 0.1), rot_ra(0, 90, 0, 0),
                    func_color_type(0x11f3ec, 2));
  obj_a = ad_to_beg(obj_a, l_cod(500, 0, 0, 0.0001), rot_ra(0, 0, 0, 1000),
		    func_color_type(0xffffff, 0));
  obj_a = ad_to_beg(obj_a, l_cod(-50, -50, 200, 0.08), rot_ra(90, 0, 90, 90),
                    func_color_type(0xFF00FF, 6));
  return (obj_a);
}

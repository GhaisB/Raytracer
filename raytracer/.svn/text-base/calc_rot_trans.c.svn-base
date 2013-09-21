/*
** calc_rot_trans.c for shzs in /home/duez_a//rtv1/tp
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon Feb 20 15:37:25 2012 guillaume duez
** Last update Sun Jun  3 12:18:13 2012 guillaume boell
*/

#include "../rt.h"

#define RA(x) ((x * M_PI) / 180)

inline void	rotate_x(double xro, double yro, double zro, double *l_OT)
{
  double	l_tmp[3];

  l_tmp[1] = l_OT[1] * cos(RA(xro)) + l_OT[2] * -sin(RA(xro));
  l_tmp[2] = l_OT[1] * sin(RA(xro)) + l_OT[2] * cos(RA(xro));
  l_OT[1] = l_tmp[1];
  l_OT[2] = l_tmp[2];
  l_tmp[0] = l_OT[0] * cos(RA(yro)) + l_OT[2] * sin(RA(yro));
  l_tmp[2] = l_OT[0] * -sin(RA(yro)) + l_OT[2] * cos(RA(yro));
  l_OT[0] = l_tmp[0];
  l_OT[2] = l_tmp[2];
  l_tmp[0] = l_OT[0] * cos(RA(zro)) + l_OT[1] * -sin(RA(zro));
  l_tmp[1] = l_OT[0] * sin(RA(zro)) + l_OT[1] * cos(RA(zro));
  l_OT[0] = l_tmp[0];
  l_OT[1] = l_tmp[1];
}

inline void	modif_lX(t_cod *cor, t_sph *obj_a, t_tmp *tmp)
{
  tmp->l_c[0] = cor->l_o[0] + (obj_a->x * -1);
  tmp->l_c[1] = cor->l_o[1] + (obj_a->y * -1);
  tmp->l_c[2] = cor->l_o[2] + (obj_a->z * -1);
  tmp->l_v[0] = cor->l_x[0];
  tmp->l_v[1] = cor->l_x[1];
  tmp->l_v[2] = cor->l_x[2];
  rotate_x(obj_a->xro, obj_a->yro, obj_a->zro, tmp->l_c);
  rotate_x(obj_a->xro, obj_a->yro, obj_a->zro, tmp->l_v);
}

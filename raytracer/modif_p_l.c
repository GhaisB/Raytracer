/*
** modif_p_l.c for harder in /home/duez_a//rtv1/tp
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Sat Mar 10 16:20:15 2012 guillaume duez
** Last update Sat Jun  2 10:37:15 2012 guillaume duez
*/

#include "../rt.h"

void	modif_p_l(t_obj *obc, t_tmp *tmp, t_sph *obj_a)
{
  tmp->l_c[0] = obc->p[0] + (obj_a->x * - 1);
  tmp->l_c[1] = obc->p[1] + (obj_a->y * - 1);
  tmp->l_c[2] = obc->p[2] + (obj_a->z * - 1);
  tmp->l_v[0] = obc->n[0];
  tmp->l_v[1] = obc->n[1];
  tmp->l_v[2] = obc->n[2];
  rotate_x(obj_a->xro, obj_a->yro, obj_a->zro, tmp->l_c);
  rotate_x(obj_a->xro, obj_a->yro, obj_a->zro, tmp->l_v);
}
